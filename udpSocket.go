package main

/*
#include <stdio.h>
#include "udp_data_analyse.h"
#cgo CFLAGS: -I./
#cgo LDFLAGS: -L./ -lsqlite3  -lm
*/
import "C"
import (
	"encoding/hex"
	"fmt"
	"net"
	"strconv"
	"time"
	"unsafe"
)

//udp socket 句柄
var pUdpSocket net.Conn

/*==================================================================================
* 函 数 名： udp_client_test
* 参    数：
* 功能描述:  udp 客户端发送测试函数
* 返 回 值： None
* 备    注：
* 作    者： lc
* 创建时间： 2021-05-25
==================================================================================*/
func init_udp_client(ipaddr string) {
	var err error
	pUdpSocket, err = net.Dial("udp", ipaddr)
	if err != nil {
		fmt.Println("连接失败!", err)
		return
	}
}

/*==================================================================================
* 函 数 名： udp_client_task
* 参    数：
* 功能描述:  udp 客户端任务
* 返 回 值： None
* 备    注：
* 作    者： lc
* 创建时间： 2021-05-25
==================================================================================*/
var udpSendData []byte
var sendFlag bool = false

func udp_client_task(localipaddr string, remoteipaddr string, port int) {
	var err error

	//不指定本地IP
	reportIpPort := remoteipaddr + ":" + strconv.Itoa(port)
	fmt.Println("远端ip = ", reportIpPort)
	pUdpSocket, err = net.Dial("udp", reportIpPort)
	if err != nil {
		fmt.Println("连接失败!", err)
		return
	}

	//指定本地远端IP
	// localip := net.ParseIP(localipaddr)
	// remoteip := net.ParseIP(remoteipaddr)
	// lAddr := &net.UDPAddr{IP: localip, Port: port}
	// rAddr := &net.UDPAddr{IP: remoteip, Port: port}
	// pUdpSocket, err = net.DialUDP("udp", lAddr, rAddr)
	// if err != nil {
	// 	fmt.Println(err)
	// }

	buf := make([]byte, 1024)
	for {
		_, err := pUdpSocket.Read(buf)
		if err != nil {
			fmt.Println("conn.Read err:", err)
			//return
		}
		//fmt.Printf("收到服务器数据:{%s}\n", ByteToHex(buf[:len(buf)]))
		C.ReceiveSub((*C.char)(unsafe.Pointer(&buf[0]))) //byte转C语言的char*,C代码调用，命令处理
		time.Sleep(50 * time.Millisecond)
	}
}

/*==================================================================================
* 函 数 名： udp_send_data
* 参    数：
* 功能描述:  udp 客户端发送数据
* 返 回 值： None
* 备    注：
* 作    者： lc
* 创建时间： 2021-05-25
==================================================================================*/
//export udp_send_data
func udp_send_data(data *C.char) {
	str := C.GoString(data)
	udpSendData, err := hex.DecodeString(str)
	if err != nil {
		fmt.Println("错误的16进制字符串！")
	}
	fmt.Printf("udp发送数据:{%s}\n", ByteToHex(udpSendData))
	pUdpSocket.Write(udpSendData)
}

/*==================================================================================
* 函 数 名： udp_client_test
* 参    数：
* 功能描述:  udp 客户端发送测试函数
* 返 回 值： None
* 备    注：
* 作    者： lc
* 创建时间： 2021-05-25
==================================================================================*/
// func udp_client_test() {
// 	// 创建连接
// 	socket, err := net.DialUDP("udp4", nil, &net.UDPAddr{
// 		IP:   net.IPv4(192, 168, 3, 37),
// 		Port: 8080,
// 	})
// 	if err != nil {
// 		fmt.Println("连接失败!", err)
// 		return
// 	}
// 	defer socket.Close()

// 	// 发送数据
// 	senddata := []byte("hello server!")
// 	_, err = socket.Write(senddata)
// 	if err != nil {
// 		fmt.Println("发送数据失败!", err)
// 		return
// 	}

// 	// 接收数据
// 	data := make([]byte, 4096)
// 	read, remoteAddr, err := socket.ReadFromUDP(data)
// 	if err != nil {
// 		fmt.Println("读取数据失败!", err)
// 		return
// 	}
// 	fmt.Println(read, remoteAddr)
// 	fmt.Printf("%s\n", data)
// }
