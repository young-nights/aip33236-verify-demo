/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-09-09     18452       the first version
 */
#ifndef APPLICATIONS_AIP33236_DRIVER_H_
#define APPLICATIONS_AIP33236_DRIVER_H_

#include "bsp_sys.h"


//-----------寄存器定义------------------
typedef struct
{
    uint8_t  ID_SOFTWARE_SWITCH;     // 设置：软件关断寄存器
    uint8_t  ID_DUTY_CHANNEL1_ADDR;  // 设置：OUT1通道PWM占空比设置寄存器地址
    uint8_t  ID_DUTY_CHANNEL2_ADDR;  
    uint8_t  ID_DUTY_CHANNEL3_ADDR;  
    uint8_t  ID_DUTY_CHANNEL4_ADDR;  
    uint8_t  ID_DUTY_CHANNEL5_ADDR;  
    uint8_t  ID_DUTY_CHANNEL6_ADDR;  
    uint8_t  ID_DUTY_CHANNEL7_ADDR;  
    uint8_t  ID_DUTY_CHANNEL8_ADDR;  
    uint8_t  ID_DUTY_CHANNEL9_ADDR;  
    uint8_t  ID_DUTY_CHANNEL10_ADDR; 
    uint8_t  ID_DUTY_CHANNEL11_ADDR; 
    uint8_t  ID_DUTY_CHANNEL12_ADDR; 
    uint8_t  ID_DUTY_CHANNEL13_ADDR; 
    uint8_t  ID_DUTY_CHANNEL14_ADDR; 
    uint8_t  ID_DUTY_CHANNEL15_ADDR; 
    uint8_t  ID_DUTY_CHANNEL16_ADDR; 
    uint8_t  ID_DUTY_CHANNEL17_ADDR; 
    uint8_t  ID_DUTY_CHANNEL18_ADDR; 
    uint8_t  ID_DUTY_CHANNEL19_ADDR; 
    uint8_t  ID_DUTY_CHANNEL20_ADDR; 
    uint8_t  ID_DUTY_CHANNEL21_ADDR; 
    uint8_t  ID_DUTY_CHANNEL22_ADDR; 
    uint8_t  ID_DUTY_CHANNEL23_ADDR; 
    uint8_t  ID_DUTY_CHANNEL24_ADDR; 
    uint8_t  ID_DUTY_CHANNEL25_ADDR; 
    uint8_t  ID_DUTY_CHANNEL26_ADDR; 
    uint8_t  ID_DUTY_CHANNEL27_ADDR; 
    uint8_t  ID_DUTY_CHANNEL28_ADDR; 
    uint8_t  ID_DUTY_CHANNEL29_ADDR; 
    uint8_t  ID_DUTY_CHANNEL30_ADDR; 
    uint8_t  ID_DUTY_CHANNEL31_ADDR; 
    uint8_t  ID_DUTY_CHANNEL32_ADDR; 
    uint8_t  ID_DUTY_CHANNEL33_ADDR; 
    uint8_t  ID_DUTY_CHANNEL34_ADDR; 
    uint8_t  ID_DUTY_CHANNEL35_ADDR; 
    uint8_t  ID_DUTY_CHANNEL36_ADDR;
    uint8_t  ID_CHANNEL_DATA_UPDATE;      // 设置：更新 nP[7:0]、nI[7:0]、nE寄存器值到输出端
    uint8_t  ID_CURRENT_SWITCH_CHANNEL1;  // 设置：OUT1通道输出电流以及开关控制寄存器地址
    uint8_t  ID_CURRENT_SWITCH_CHANNEL2;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL3;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL4;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL5;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL6;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL7;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL8;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL9;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL10;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL11;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL12;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL13;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL14;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL15;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL16;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL17;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL18;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL19;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL20;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL21;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL22;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL23;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL24;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL25;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL26;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL27;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL28;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL29;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL30;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL31;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL32;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL33;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL34;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL35;
    uint8_t  ID_CURRENT_SWITCH_CHANNEL36;
    uint8_t  ID_ENABLE_ALL_CHANNEL_RES;     // 使能所有通道
    uint8_t  ID_PWM_FREQUENCY_SET;          // PWM设置
    uint8_t  ID_HARDWARE_RESET;             // 软件复位
}AIP33236_IC_REG;
extern AIP33236_IC_REG aip33236_reg;




typedef enum
{
    aip33236_u1_soft = 1,
    aip33236_u2_soft,
}AIP33236_SWITCH_MODE;


typedef enum
{
    aip33236_u1_dev = 1,
    aip33236_u2_dev,
}AIP33236_DEV_NUM;


typedef enum
{
    RGB_LED_1 = 1,
    RGB_LED_2,
    RGB_LED_3,
    RGB_LED_4,
    RGB_LED_5,
    RGB_LED_6,
    RGB_LED_7,
    RGB_LED_8,
    RGB_LED_9,
    RGB_LED_10,
    RGB_LED_11,
    RGB_LED_12,
    RGB_LED_13,
    RGB_LED_14,
    RGB_LED_15,
    RGB_LED_16,
    RGB_LED_17,
    RGB_LED_18,
    RGB_LED_19,
    RGB_LED_20
}RGB_LED_NUMBER;


typedef enum
{
    RGB_RED = 1,
    RGB_BLUE,
    RGB_CUSTOM
}RGB_COLOR_NUMBER;


// 函数声明---------------------------------------------
void AIP33236_GPIO_Config(void);
void AIP33236_Software_Switch(AIP33236_SWITCH_MODE mode, rt_uint8_t power);
void AIP33236_PWM_Duty_Set(AIP33236_DEV_NUM dev, rt_uint8_t duty, rt_uint8_t channel);
void AIP33236_PWM_Switch_Current_Set(AIP33236_DEV_NUM dev, rt_uint8_t cmd, rt_uint8_t channel);
void AIP33236_Channel_Data_Update(AIP33236_DEV_NUM dev);
void AIP33236_Enable_all_Channel_Res(AIP33236_DEV_NUM dev, rt_uint8_t data);
void AIP33236_PWM_Frequency_Set(AIP33236_DEV_NUM dev, rt_uint8_t data);
void AIP33236_Hardware_Reset(AIP33236_DEV_NUM dev);



#endif /* APPLICATIONS_AIP33236_DRIVER_H_ */
