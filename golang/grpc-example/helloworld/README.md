# HelloWorld gRPC

To regenerate grpcs:

```shell script
#  in helloworld directory
protoc --go_out=. --go_opt=paths=source_relative \
    --go-grpc_out=. --go-grpc_opt=paths=source_relative \
    helloworld.proto
```
