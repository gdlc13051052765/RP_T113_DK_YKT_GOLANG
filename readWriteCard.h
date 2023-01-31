
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "iso7816.h"
#include "delay.h"
#include "CalucationFile.h"



//int ReadCardCommonDatas(uint8_t *scidcode, uint8_t *CardSerialNum,uint8_t usesectornum,uint8_t *CardPrinterNum,uint8_t *LimtConsumeData_CPU);
//写入脱机限额
char WriteNoNetLimitMoney(char *buf,char *scidcode, char *CardSerialNum,char usesectornum,char *CardPrinterNum);
/*==================================================================================
* 函 数 名： read_card_data_form_config_db
* 参    数： 
* 功能描述:  从配置数据库读取卡配置信息
* 返 回 值： None
* 备    注： 创建成功返回0
* 作    者： lc
* 创建时间： 2021-09-27
==================================================================================*/
int read_card_data_form_config_db(void);

uint8_t ReWriteCardSub_M1(uint8_t bbit);

//读出卡号及卡种类
uint8_t ReadCardCommonDatas_M1(void);
uint8_t ReadCard_DaySumConsumMoney_M1(void);//读出累计日消费额
uint8_t ReadCardBalanceDatas_M1(uint8_t RdSector);//读出卡金额及余额比较
uint8_t WriteBalanceToCard_M1(uint8_t bbit, uint8_t WrSector);//写卡

void CalEncryptDatas(uint8_t bbit,uint8_t * S_Datas ,uint8_t * KeyDatas ,uint8_t *  T_Datas ,uint8_t Len );
