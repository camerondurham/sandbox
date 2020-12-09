/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

// Package main implements a server for Greeter service.
package main

import (
	"context"
	"errors"
	"google.golang.org/grpc/metadata"
	"log"
	"net"
	"time"

	"google.golang.org/grpc"
	pb "google.golang.org/grpc/examples/helloworld/helloworld"
)

const (
	port = ":50051"
)

// server is used to implement helloworld.GreeterServer.
type server struct {
	pb.UnimplementedGreeterServer
	pb.UnimplementedSecureGreeterServer
}


type JWTManager struct {
	secretKey     string
	tokenDuration time.Duration
}

// Server auth
type AuthInterceptor struct {
	jwtManager    *JWTManager
	authSecretKey string
}

func NewJWTManager(secretKey string, tokenDuration time.Duration) *JWTManager {
	return &JWTManager{secretKey, tokenDuration}
}

func NewAuthInterceptor(secretKey string, authSecretKey string, tokenDuration time.Duration) *AuthInterceptor {
	return &AuthInterceptor{
		jwtManager:    NewJWTManager(secretKey, tokenDuration),
		authSecretKey: authSecretKey,
	}
}

// SayHello implements helloworld.GreeterServer
func (s *server) SayHello(ctx context.Context, in *pb.HelloRequest) (*pb.HelloReply, error) {
	log.Printf("Received: %v", in.GetName())
	return &pb.HelloReply{Message: "Hello " + in.GetName()}, nil
}

func (s *server) 	SecureSayHello(ctx context.Context, in *pb.SecureHelloRequest) (*pb.SecureHelloReply, error) {
	log.Printf("Received: %v - %v", in.GetName(), in.GetUsername())
	return &pb.SecureHelloReply{
		Message:  "(Secure) Hello " + in.GetName(),
		Username: in.GetUsername(),
	}, nil
}

func (interceptor *AuthInterceptor) Unary() grpc.UnaryServerInterceptor {
	return func(
		ctx context.Context,
		req interface{},
		info *grpc.UnaryServerInfo,
		handler grpc.UnaryHandler,
	) (interface{}, error) {
		log.Println("--> unary interceptor: ", info.FullMethod)
		// TODO: implement authorization
		err := interceptor.authorize(ctx, info.FullMethod)

		if err != nil {
			return nil, err
		}
		return handler(ctx, req)
	}
}

func (interceptor *AuthInterceptor) authorize(ctx context.Context, fullMethod string) error {
	md, ok := metadata.FromIncomingContext(ctx)
	if !ok {
		return errors.New("metadata is not provided")
	}
	values := md["authorization"]
	if len(values) == 0 {
		return errors.New("authorization not provided")
	}
	accessToken := values[0]
	if accessToken != interceptor.jwtManager.secretKey {
		return errors.New("unauthenticated")
	}

	// todo: some minimal role checking

	return nil
}
func main() {
	lis, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}

	interceptor := NewAuthInterceptor("access-token", "access-token", 5 * time.Second )

	opts := []grpc.ServerOption{
		grpc.UnaryInterceptor(interceptor.Unary()),
	}

	s := grpc.NewServer(opts...)
	pb.RegisterGreeterServer(s, &server{})
	pb.RegisterSecureGreeterServer(s, &server{})
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}
