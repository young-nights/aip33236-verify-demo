/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-09-09     18452       the first version
 */
#ifndef APPLICATIONS_AIP33236_IIC_H_
#define APPLICATIONS_AIP33236_IIC_H_
#include "bsp_sys.h"


/* 软件iic配置参数结构体 */
typedef struct {
    char        i2c_name[16];
    uint8_t     i2c_addr_u1;
    uint8_t     i2c_addr_u2;
    struct rt_i2c_bus_device    *i2c_bus;
}iicStructure_t;
extern iicStructure_t aip33236_iic;



typedef enum
{
    aip33236_u1 = 1,
    aip33236_u2,
}AIP33236_DEV_NUM;




// 函数声明--------------------------------------------

void aip33236_device_init(void);
rt_err_t iic_aip33236_write_reg(struct rt_i2c_bus_device *bus, rt_uint8_t *i2c_reg, AIP33236_DEV_NUM udev);
rt_err_t iic_aip33236_write_reg_nbytes(struct rt_i2c_bus_device *bus,rt_uint8_t reg,rt_uint8_t *data,rt_size_t n,AIP33236_DEV_NUM udev);
rt_err_t iic_aip33236_write_reg_datas(struct rt_i2c_bus_device *bus,rt_uint8_t* data_buf,AIP33236_DEV_NUM udev);
rt_err_t iic_aip33236_read_reg(struct rt_i2c_bus_device *bus, rt_uint8_t len,rt_uint8_t* i2c_dat, AIP33236_DEV_NUM udev);



#endif /* APPLICATIONS_AIP33236_IIC_H_ */
