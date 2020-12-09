// Code generated by protoc-gen-go-grpc. DO NOT EDIT.

package helloworld

import (
	context "context"
	grpc "google.golang.org/grpc"
	codes "google.golang.org/grpc/codes"
	status "google.golang.org/grpc/status"
)

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion7

// GreeterClient is the client API for Greeter service.
//
// For semantics around ctx use and closing/ending streaming RPCs, please refer to https://pkg.go.dev/google.golang.org/grpc/?tab=doc#ClientConn.NewStream.
type GreeterClient interface {
	// Sends a greeting
	SayHello(ctx context.Context, in *HelloRequest, opts ...grpc.CallOption) (*HelloReply, error)
}

type greeterClient struct {
	cc grpc.ClientConnInterface
}

func NewGreeterClient(cc grpc.ClientConnInterface) GreeterClient {
	return &greeterClient{cc}
}

func (c *greeterClient) SayHello(ctx context.Context, in *HelloRequest, opts ...grpc.CallOption) (*HelloReply, error) {
	out := new(HelloReply)
	err := c.cc.Invoke(ctx, "/helloworld.Greeter/SayHello", in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// GreeterServer is the server API for Greeter service.
// All implementations must embed UnimplementedGreeterServer
// for forward compatibility
type GreeterServer interface {
	// Sends a greeting
	SayHello(context.Context, *HelloRequest) (*HelloReply, error)
	mustEmbedUnimplementedGreeterServer()
}

// UnimplementedGreeterServer must be embedded to have forward compatible implementations.
type UnimplementedGreeterServer struct {
}

func (UnimplementedGreeterServer) SayHello(context.Context, *HelloRequest) (*HelloReply, error) {
	return nil, status.Errorf(codes.Unimplemented, "method SayHello not implemented")
}
func (UnimplementedGreeterServer) mustEmbedUnimplementedGreeterServer() {}

// UnsafeGreeterServer may be embedded to opt out of forward compatibility for this service.
// Use of this interface is not recommended, as added methods to GreeterServer will
// result in compilation errors.
type UnsafeGreeterServer interface {
	mustEmbedUnimplementedGreeterServer()
}

func RegisterGreeterServer(s grpc.ServiceRegistrar, srv GreeterServer) {
	s.RegisterService(&_Greeter_serviceDesc, srv)
}

func _Greeter_SayHello_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(HelloRequest)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(GreeterServer).SayHello(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/helloworld.Greeter/SayHello",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(GreeterServer).SayHello(ctx, req.(*HelloRequest))
	}
	return interceptor(ctx, in, info, handler)
}

var _Greeter_serviceDesc = grpc.ServiceDesc{
	ServiceName: "helloworld.Greeter",
	HandlerType: (*GreeterServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "SayHello",
			Handler:    _Greeter_SayHello_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "helloworld.proto",
}

// SecureGreeterClient is the client API for SecureGreeter service.
//
// For semantics around ctx use and closing/ending streaming RPCs, please refer to https://pkg.go.dev/google.golang.org/grpc/?tab=doc#ClientConn.NewStream.
type SecureGreeterClient interface {
	SecureSayHello(ctx context.Context, in *SecureHelloRequest, opts ...grpc.CallOption) (*SecureHelloReply, error)
}

type secureGreeterClient struct {
	cc grpc.ClientConnInterface
}

func NewSecureGreeterClient(cc grpc.ClientConnInterface) SecureGreeterClient {
	return &secureGreeterClient{cc}
}

func (c *secureGreeterClient) SecureSayHello(ctx context.Context, in *SecureHelloRequest, opts ...grpc.CallOption) (*SecureHelloReply, error) {
	out := new(SecureHelloReply)
	err := c.cc.Invoke(ctx, "/helloworld.SecureGreeter/SecureSayHello", in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// SecureGreeterServer is the server API for SecureGreeter service.
// All implementations must embed UnimplementedSecureGreeterServer
// for forward compatibility
type SecureGreeterServer interface {
	SecureSayHello(context.Context, *SecureHelloRequest) (*SecureHelloReply, error)
	mustEmbedUnimplementedSecureGreeterServer()
}

// UnimplementedSecureGreeterServer must be embedded to have forward compatible implementations.
type UnimplementedSecureGreeterServer struct {
}

func (UnimplementedSecureGreeterServer) SecureSayHello(context.Context, *SecureHelloRequest) (*SecureHelloReply, error) {
	return nil, status.Errorf(codes.Unimplemented, "method SecureSayHello not implemented")
}
func (UnimplementedSecureGreeterServer) mustEmbedUnimplementedSecureGreeterServer() {}

// UnsafeSecureGreeterServer may be embedded to opt out of forward compatibility for this service.
// Use of this interface is not recommended, as added methods to SecureGreeterServer will
// result in compilation errors.
type UnsafeSecureGreeterServer interface {
	mustEmbedUnimplementedSecureGreeterServer()
}

func RegisterSecureGreeterServer(s grpc.ServiceRegistrar, srv SecureGreeterServer) {
	s.RegisterService(&_SecureGreeter_serviceDesc, srv)
}

func _SecureGreeter_SecureSayHello_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(SecureHelloRequest)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(SecureGreeterServer).SecureSayHello(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/helloworld.SecureGreeter/SecureSayHello",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(SecureGreeterServer).SecureSayHello(ctx, req.(*SecureHelloRequest))
	}
	return interceptor(ctx, in, info, handler)
}

var _SecureGreeter_serviceDesc = grpc.ServiceDesc{
	ServiceName: "helloworld.SecureGreeter",
	HandlerType: (*SecureGreeterServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "SecureSayHello",
			Handler:    _SecureGreeter_SecureSayHello_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "helloworld.proto",
}
