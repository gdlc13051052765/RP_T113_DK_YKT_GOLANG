#include <stdbool.h>  
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

#include "sqliteTask.h"
#include "msgTask.h"
#include "debug_print.h"
#include "MFRC522.h"
#include "ExternVariableDef.h"
#include "rewrCardTask.h"
#include "udp_data_analyse.h"

#define	RUN 	1
#define STOP	0

static pthread_t thread[10];  //两个线程
#define TASK_DELAY   1000 //线程间延时

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static int iotThreadStatus = STOP;
/*==================================================================================
功能描述:  读写盘线程任务
* 返 回 值：
* 备    注： 调用C代码里面的读写盘任务函数
* 作    者： lc
* 创建时间： 2021/4/16
==================================================================================*/
static void *write_plate_thread(void *args) 
{
	InitRc522Driver();
	MFRC522_Initializtion();

	//未采记录指针
	NoCollectRecordIndex = sqlite3_consume_query_RecordIndex_db(0);
	printf_debug("未采记录指针=%d \r\n",NoCollectRecordIndex);
	SaveRecordIndex = sqlite3_consume_query_RecordIndex_db(1);//存储记录指针
	printf_debug("存储记录指针 = %d\n", SaveRecordIndex);
	while(1) 
	{
		pos_consume_task();
		if(NoCollectRecordIndex>SaveRecordIndex)
		{
			NoCollectRecordIndex = sqlite3_consume_query_RecordIndex_db(0);
		}
		SaveRecordIndex = query_last_record_index();
		SaveRecordIndex++;
		printf_debug("存储记录指针 = %d\n", SaveRecordIndex);
		//sleep(3);
	}
}

/*==================================================================================
* 函 数 名： send_qt_msg_thread
* 参    数： Non
* 功能描述:  发送数据到qt进程通讯消息队列
* 返 回 值：
* 备    注： 调用C代码里面任务函数
* 作    者： lc
* 创建时间： 2021/4/16
==================================================================================*/
static void *send_qt_msg_thread(void *args) 
{
	uint32_t temp;

	while(1) 
	{
		temp = get_msg_task_delay();
		usleep(temp);
		send_qt_msg_data_task(); 
	}
}

/*==================================================================================
* 函 数 名： receive_qt_msg_thread
* 参    数： Non
* 功能描述:  接收qt信息进程通讯消息队列
* 返 回 值：
* 备    注： 调用C代码里面任务函数
* 作    者： lc
* 创建时间： 2021/4/16
==================================================================================*/
static void *receive_qt_msg_thread(void *args) 
{
	uint32_t temp;

	while(1) 
	{
		temp = get_msg_task_delay();
		usleep(temp);
		receive_qt_msg_data_task();
	}
}

/*==================================================================================
* 函 数 名： response_udp_cmd_thread
* 参    数： Non
* 功能描述:  udp数据应答
* 返 回 值：
* 备    注： 调用C代码里面任务函数
* 作    者： lc
* 创建时间： 2021/4/16
==================================================================================*/
static void *response_udp_cmd_thread(void *args) 
{
	uint32_t temp;

	while(1) 
	{
		temp = get_msg_task_delay();
		usleep(temp);
		udp_pop_one_frame();
	}
}

/*==================================================================================
* 函 数 名： app_wrplate_create_thread
* 参    数： Non
* 功能描述:  创建多线程任务
* 返 回 值：
* 备    注： 
* 作    者： lc
* 创建时间： 2021/5/6
==================================================================================*/
void app_wrplate_create_thread(void)
{
	int temp;
	memset(&thread, 0, sizeof(thread));          
	pthread_mutex_init(&mtx,NULL);//初始化互斥锁
	pthread_cond_init(&cond, NULL);

	//未采记录指针
	NoCollectRecordIndex = sqlite3_consume_query_RecordIndex_db(0);
	printf_debug("未采记录指针=%d \r\n",NoCollectRecordIndex);
	SaveRecordIndex = sqlite3_consume_query_RecordIndex_db(1);//存储记录指针
	printf_debug("存储记录指针 = %d\n", SaveRecordIndex);

	printf_debug("线程。。。。。。。。。。。。。app_wrplate_create_thread\n");
	if((temp = pthread_create(&thread[1], NULL, write_plate_thread, NULL)) != 0)//读写盘线程任务
		printf_debug("线程1创建失败\n");
	else
		printf_debug("线程1被创建\n");
		
	// if((temp = pthread_create(&thread[2], NULL, send_qt_msg_thread, NULL)) != 0)//发送数据到qt进程通讯消息队列
	// 	printf_debug("线程2创建失败\n");
	// else
	// 	printf_debug("线程2被创建\n");

	// if((temp = pthread_create(&thread[3], NULL, receive_qt_msg_thread, NULL)) != 0)//接收qt信息进程通讯消息队列
	// 	printf_debug("线程3创建失败\n");
	// else
	// 	printf_debug("线程3被创建\n");	

	// if((temp = pthread_create(&thread[4], NULL, response_udp_cmd_thread, NULL)) != 0)//应答udp数据
	// 	printf_debug("线程4创建失败\n");
	// else
	// 	printf_debug("线程4被创建\n");	
}
