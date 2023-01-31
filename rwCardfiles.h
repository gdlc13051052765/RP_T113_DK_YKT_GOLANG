#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//侦测卡片是否在依然存在
uint8_t Detect_Card(void);
//测试是否有卡
uint8_t RequestCard(void);
//读卡的公共信息
uint8_t ReadCardCommonDatas(void);
uint8_t   SearchPurseBalnanceDatas(uint8_t,uint8_t, uint8_t *,uint8_t *);//查找钱包;
//消费过程控制，包含写卡和写累计
uint8_t ConsumPocess(void);
//拔卡重新插入后的校验
uint8_t CheckCardPrinterNum(void);