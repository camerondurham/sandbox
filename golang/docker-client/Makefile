all: simple-test

install: 
	go get -t \
		github.com/docker/docker/api/types \
		github.com/docker/docker/api/types/container \
		github.com/docker/docker/client \
		github.com/docker/docker/pkg/stdcopy

simple-test:
	DEBUG=true go run main.go