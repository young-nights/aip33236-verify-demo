/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-09-09     RT-Thread    first version
 */

#include <rtthread.h>
#include "bsp_sys.h"


#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

int main(void)
{
    /* iic初始化 */
    aip33236_device_init();
    /* 相关引脚初始化 */
    AIP33236_GPIO_Config();
    /* 设置占空比 */
    AIP33236_PWM_Duty_Set(aip33236_u1_dev,0x96,1);

    for(;;)
    {

        rt_thread_mdelay(500);
    }

    return RT_EOK;
}




