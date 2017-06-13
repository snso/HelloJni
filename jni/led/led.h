/*
 * led.h
 *
 *  Created on: 2017年3月26日
 *      Author: Administrator
 *
 *      在驱动的基础上实现LED点亮--------------实际上就是操作文件
 */

#ifndef __LED_H_
#define __LED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> /*包括文件操作，如open() read() close() write()等*/

int Led_Init();
void Led_Close();
void Led_On();
void Led_OFF();


#endif /* LED_H_ */
