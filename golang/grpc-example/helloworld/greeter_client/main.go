/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

// Package main implements a client for Greeter service.
package main

import (
	"context"
	"fmt"
	"google.golang.org/grpc/metadata"
	"log"
	"os"
	"time"

	"google.golang.org/grpc"
	pb "google.golang.org/grpc/examples/helloworld/helloworld"
)

const (
	address     = "localhost:50051"
	defaultName = "Elongated Muskrat"
)

type SecureGreeterClient struct {
	service pb.SecureGreeterClient
}

type AuthGreeterClient struct {
	service  pb.GreeterClient
	username string
}

type AuthInterceptor struct {
	greeterClient *AuthGreeterClient
	authMethods   map[string]bool
	secretKey     string
}

func main() {

	// Contact the server and print out its response.
	name := defaultName
	if len(os.Args) > 1 {
		name = os.Args[1]
	}

	// Set up a connection to the server.
	cc1, err := grpc.Dial(address, grpc.WithInsecure(), grpc.WithBlock())
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer cc1.Close()
	greeterClient := NewGreeterClient(cc1, "admin")

	interceptor, err := NewAuthInterceptor(greeterClient, authMethods(), "access-token")

	cc2, err := grpc.Dial(address, grpc.WithInsecure(), grpc.WithUnaryInterceptor(interceptor.Unary()))
	if err != nil {
		log.Fatal("cannot dial server: ", err)
	}

	sgc := NewSecureGreeterClient(cc2)

	ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
	defer cancel()

	r, err := sgc.service.SecureSayHello(ctx, &pb.SecureHelloRequest{Name: name, Username: "admin"})

	if err != nil {
		log.Fatalf("could not greet: %v", err)
	}
	log.Printf("Greeting: %s", r.GetMessage())
}

func NewGreeterClient(cc *grpc.ClientConn, username string) *AuthGreeterClient {
	service := pb.NewGreeterClient(cc)
	return &AuthGreeterClient{
		service:  service,
		username: username,
	}
}

func (client *AuthGreeterClient) Handshake() (string, error) {
	ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
	defer cancel()

	req := &pb.HelloRequest{Name: client.username}

	res, err := client.service.SayHello(ctx, req)
	if err != nil {
		return "", err
	} else {
		return res.GetMessage(), nil
	}
}
func NewSecureGreeterClient(cc *grpc.ClientConn) *SecureGreeterClient {
	service := pb.NewSecureGreeterClient(cc)
	return &SecureGreeterClient{
		service: service,
	}
}

func NewAuthInterceptor(ac *AuthGreeterClient, authMethods map[string]bool, accessTok string) (*AuthInterceptor, error) {
	interceptor := &AuthInterceptor{
		greeterClient: ac,
		authMethods:   authMethods,
		secretKey:     accessTok,
	}
	err := interceptor.authFlow("admin")
	if err != nil {
		return nil, err
	} else {
		return interceptor, nil
	}
}

func (interceptor *AuthInterceptor) Unary() grpc.UnaryClientInterceptor {
	return func(
		ctx context.Context,
		method string,
		req, reply interface{},
		cc *grpc.ClientConn,
		invoker grpc.UnaryInvoker,
		opts ...grpc.CallOption,
	) error {
		log.Printf("--> unary interceptor: %s", method)
		// TODO check stuff
		if interceptor.authMethods[method] {
			return invoker(interceptor.attachToken(ctx), method, req, reply, cc, opts...)
		}
		return invoker(ctx, method, req, reply, cc, opts...)
	}
}

func (interceptor *AuthInterceptor) authFlow(username string) error {
	if username == "admin" {
		return nil
	} else {
		return fmt.Errorf("not authenticated")
	}
}

func (interceptor *AuthInterceptor) attachToken(ctx context.Context) context.Context {
	return metadata.AppendToOutgoingContext(ctx, "authorization", interceptor.secretKey)
}

func authMethods() map[string]bool {
	const greeterPath = "/helloworld.SecureGreeter/"

	return map[string]bool{
		greeterPath + "SecureSayHello":   true,
	}
}
