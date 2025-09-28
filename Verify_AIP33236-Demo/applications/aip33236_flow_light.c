/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-09-28     18452       the first version
 */
#include "aip33236_flow_light.h"



/* 流水灯状态机静态变量 */
static struct {
    RGB_LED_NUMBER  cur_led;        /* 1~10 */
    AIP33236_DEV_NUM cur_dev;       /* aip33236_u1_dev / aip33236_u2_dev */
    RGB_COLOR_NUMBER cur_color;     /* RGB_RED ~ RGB_ORANGE */
} flow_state = {
    .cur_led   = RGB_LED_1,
    .cur_dev   = aip33236_u1_dev,
    .cur_color = RGB_RED
};

static uint8_t color_cnt = 0;       /* 已完成的颜色个数 */
static rt_bool_t all_gold = RT_FALSE; /* 标志：是否已全白 */


static void all_led_seashell(void)
{
    for (int dev = aip33236_u1_dev; dev <= aip33236_u2_dev; dev++) {
        for (int led = RGB_LED_1; led <= RGB_LED_12; led++) {
            AIP33236_LED_ON(dev, led, RGB_Seashell);
        }
    }
}


static void all_led_gold(void)
{
    for (int dev = aip33236_u1_dev; dev <= aip33236_u2_dev; dev++) {
        for (int led = RGB_LED_1; led <= RGB_LED_12; led++) {
            AIP33236_LED_ON(dev, led, RGB_Gold);
        }
    }
}

/* 单步流水：颜色跑完后自动切换，5 色全跑完则全白常亮 */
void AIP33236_Flow_Light(void)
{
    if (all_gold) return;          /* 已完成，不再动作 */

    static RGB_LED_NUMBER last_led   = RGB_LED_1;
    static AIP33236_DEV_NUM last_dev = aip33236_u1_dev;

    /* 熄灭上一颗灯 */
    AIP33236_LED_OFF(last_dev, last_led);

    /* 点亮当前灯（当前颜色） */
    AIP33236_LED_ON(flow_state.cur_dev, flow_state.cur_led, flow_state.cur_color);

    /* 更新 last 记录 */
    last_led = flow_state.cur_led;
    last_dev = flow_state.cur_dev;

    /* 步进到下一颗灯 */
    if (flow_state.cur_dev == aip33236_u1_dev) {
        if (flow_state.cur_led < RGB_LED_12) {
            flow_state.cur_led++;
        } else {                       /* U1 完成，切到 U2 */
            flow_state.cur_dev = aip33236_u2_dev;
            flow_state.cur_led = RGB_LED_1;
        }
    } else {                           /* 当前在 U2 */
        if (flow_state.cur_led < RGB_LED_10) {
            flow_state.cur_led++;
        } else {                       /* 一种颜色流水完毕 */
            color_cnt++;               /* 完成一种颜色 */

            /* 如果 7 色都跑完，进入全白模式 */
            if (color_cnt >= 7) {
                all_gold = RT_TRUE;
                all_led_gold();
                return;
            }

            /* 切换到下一种颜色，复位指针 */
            flow_state.cur_color++;
            if (flow_state.cur_color >= RGB_CUSTOM)
                flow_state.cur_color = RGB_RED;

            flow_state.cur_dev = aip33236_u1_dev;
            flow_state.cur_led = RGB_LED_1;
            /* last_* 保持原值即可，下次会熄灭新 last */
        }
    }
}







