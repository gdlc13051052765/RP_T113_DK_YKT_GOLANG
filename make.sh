rm -rf T113-DK-YKT-GOLANG
CGO_ENABLED=1 GOOS=linux GOARCH=arm GOARM=5 CC=/home/T113/sdk/t133_linux_v1.0/out/t113/evb1_auto/longan/buildroot/host/opt/ext-toolchain/bin/arm-linux-gnueabi-gcc go build 

