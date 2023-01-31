package main

/*
#include <stdio.h>
#include "sqliteTask.h"
#include "msgTask.h"
#include "cAppTask.h"
#include "udp_data_analyse.h"
#include "debug_print.h"
#include "CalucationFile.h"
#include "sysTime.h"
#cgo CFLAGS: -I./
#cgo LDFLAGS: -L./ -lsqlite3  -lm
*/
import "C"
import (
	"bufio"
	"fmt"
	"os/exec"
	"strings"
	"time"
)

var version string = "YKT_APP_0.0.1"

/*==================================================================================
* 函 数 名： query_kswapd0_log_task
* 参    数：
* 功能描述:  top命令查询kswapd0，查询到重启golang
* 返 回 值：
* 备    注： None
* 作    者： lc
* 创建时间： 2021/6/29
==================================================================================*/
func query_kswapd0_log_task() {
	cmd := exec.Command("/bin/sh", "-c", "top") //不加第一个第二个参数会报错
	stdout, _ := cmd.StdoutPipe()               //创建输出管道
	defer stdout.Close()
	if err := cmd.Start(); err != nil {
		fmt.Println("cmd start")
	}
	//使用带缓冲的读取器
	outputBuf := bufio.NewReader(stdout)
	outputBuf.Reset(stdout)
	for {
		//一次获取一行,_ 获取当前行是否被读完
		output, _, err := outputBuf.ReadLine()
		if err != nil {
			// 判断是否到文件的结尾了否则出错
			if err.Error() != "EOF" {
				fmt.Println("Error eof :%s\n", err)
			}
		}
		if err := strings.Index(string(output), "unknown"); err != -1 {
			fmt.Println("unknown = %s\n", string(output))
		} else {
			fmt.Println(string(output))
			if (strings.Contains(string(output), "kswapd0")) == true {
				// cmd1 := exec.Command("/bin/sh", "-c", "free - m")  //不加第一个第二个参数会报错
				// if err := cmd1.Start(); err != nil {
				// 	fmt.Println("cmd start")
				// }
				// if err := cmd1.Wait(); err != nil {
				// 	fmt.Println(err)
				// //	return err
				// }

				// cmd1 := exec.Command("/bin/sh", "-c", "/root/regolang.sh")  //不加第一个第二个参数会报错
				// if err := cmd1.Start(); err != nil {
				// 	fmt.Println("cmd1 start")
				// }
			}
		}
		time.Sleep(1 * time.Second)
	}
}

/*==================================================================================
* 函 数 名： free_m_task
* 参    数：
* 功能描述:  释放虚拟内存
* 返 回 值：
* 备    注： None
* 作    者： lc
* 创建时间： 2021/6/29
==================================================================================*/
func free_m_task() error {
	for {
		cmd := exec.Command("/bin/sh", "-c", "free - m") //不加第一个第二个参数会报错
		if err := cmd.Start(); err != nil {
			fmt.Println("cmd start")
		}
		if err := cmd.Wait(); err != nil {
			fmt.Println(err)
			return err
		}
		time.Sleep(3 * time.Second)
	}
}

/*==================================================================================
                      全局变量
==================================================================================*/

//主流程
func main() {
	fmt.Printf("MCT写盘器软件版本 == %s\n", version)

	//go query_kswapd0_log_task()
	//go free_m_task()
	//初始化
	pos_app_init()
	time.Sleep(1 * time.Second)
	//

	for {
		//主任务
		time.Sleep(1 * time.Second)
	}
}
