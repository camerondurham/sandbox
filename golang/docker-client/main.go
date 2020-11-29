package main

import (
	"archive/tar"
	"bytes"
	"context"
	"fmt"
	"io"
	"log"
	"os"
	"path/filepath"

	"github.com/docker/docker/api/types"
	"github.com/docker/docker/client"
)

const (
	testDir        = "dockerfile-test"
	dockerfileName = "Dockerfile.alpine"
)

func main() {
	cli, err := client.NewEnvClient()
	if err != nil {
		panic(err)
	}

	ListRunning(cli)

	// build image

	contextPath, err := filepath.Abs(testDir)
	if err != nil {
		log.Fatalf("error finding abs path: %v", err)
	}

	contextTarball := fmt.Sprintf("/tmp/%s.tar", filepath.Base(contextPath))

	if _, ok := os.LookupEnv("DEBUG"); ok {
		fmt.Printf("dockerfile context file: %s\n", contextPath)
		fmt.Printf("output filename: %s\n", contextTarball)
	}

	// err = TarTar(contextTarball, []string{contextPath})
	contextTarReader, err := ContextReader(contextPath)
	if err != nil {
		log.Fatal(err)
	}

	buildResponse, err := cli.ImageBuild(context.Background(), contextTarReader, types.ImageBuildOptions{
		Context:    contextTarReader,
		Tags:       []string{"simple-alpine-test-tar-read"},
		Dockerfile: dockerfileName,
	})

	if err != nil {
		log.Fatal("unable to build docker image: ", err)
	}

	defer buildResponse.Body.Close()

	fmt.Println(buildResponse.OSType)

	_, err = io.Copy(os.Stdout, buildResponse.Body)
	if err != nil {
		log.Fatal(err, " : unable to read image build response")
	}
}

// ListRunning lists running containers like docker ps
func ListRunning(cli *client.Client) {
	containers, err := cli.ContainerList(context.Background(), types.ContainerListOptions{})
	if err != nil {
		log.Fatal(err)
	}

	for _, container := range containers {
		fmt.Printf("%s %s\n", container.ID[:10], container.Image)
	}
}

// ContextReader reads path in to tar buffer
func ContextReader(contextPath string) (contextReader *bytes.Reader, err error) {
	buf := new(bytes.Buffer)
	tw := tar.NewWriter(buf)
	defer tw.Close()

	// validate path
	path := filepath.Clean(contextPath)
	// absPath, err := filepath.Abs(path)
	if err != nil {
		fmt.Println(err)
	}

	walker := func(file string, finfo os.FileInfo, err error) error {
		if err != nil {
			return err
		}

		// fill in header info using func FileInfoHeader
		hdr, err := tar.FileInfoHeader(finfo, finfo.Name())
		if err != nil {
			return err
		}
		relFilePath := file
		if filepath.IsAbs(path) {
			relFilePath, err = filepath.Rel(path, file)
			if err != nil {
				return err
			}
		}

		// ensure header has relative file path
		hdr.Name = relFilePath

		if err := tw.WriteHeader(hdr); err != nil {
			return err
		}

		// if file is a dir, don't continue
		if finfo.Mode().IsDir() {
			return nil
		}

		// add file to tar
		srcFile, err := os.Open(file)
		if err != nil {
			return err
		}
		defer srcFile.Close()
		_, err = io.Copy(tw, srcFile)
		if err != nil {
			return err
		}
		return nil
	}

	// build tar
	if err := filepath.Walk(path, walker); err != nil {
		fmt.Printf("failed to add %s to tar buffer: %s\n", path, err)
	}

	contextTarReader := bytes.NewReader(buf.Bytes())

	return contextTarReader, nil
}

// TarTar walks paths to create tar file tarName
func TarTar(tarName string, paths []string) (err error) {
	tarFile, err := os.Create(tarName)
	if err != nil {
		return err
	}
	defer func() {
		err = tarFile.Close()
	}()

	absTar, err := filepath.Abs(tarName)
	if err != nil {
		return err
	}

	// enable compression if file ends in .gz
	tw := tar.NewWriter(tarFile)
	defer tw.Close()

	// walk each specified path and add encountered file to tar
	for _, path := range paths {

		// validate path
		path = filepath.Clean(path)
		absPath, err := filepath.Abs(path)
		if err != nil {
			fmt.Println(err)
			continue
		}
		if absPath == absTar {
			fmt.Printf("tar file %s cannot be the source\n", tarName)
			continue
		}
		if absPath == filepath.Dir(absTar) {
			fmt.Printf("tar file %s cannot be in source %s\n", tarName, absPath)
			continue
		}

		walker := func(file string, finfo os.FileInfo, err error) error {
			if err != nil {
				return err
			}

			// fill in header info using func FileInfoHeader
			hdr, err := tar.FileInfoHeader(finfo, finfo.Name())
			if err != nil {
				return err
			}

			relFilePath := file
			if filepath.IsAbs(path) {
				relFilePath, err = filepath.Rel(path, file)
				if err != nil {
					return err
				}
			}
			// ensure header has relative file path
			hdr.Name = relFilePath

			if err := tw.WriteHeader(hdr); err != nil {
				return err
			}
			// if path is a dir, dont continue
			if finfo.Mode().IsDir() {
				return nil
			}

			// add file to tar
			srcFile, err := os.Open(file)
			if err != nil {
				return err
			}
			defer srcFile.Close()
			_, err = io.Copy(tw, srcFile)
			if err != nil {
				return err
			}
			return nil
		}

		// build tar
		if err := filepath.Walk(path, walker); err != nil {
			fmt.Printf("failed to add %s to tar: %s\n", path, err)
		}
	}
	return nil
}
