/*
 * led.h
 *
 *  Created on: 2017��3��26��
 *      Author: Administrator
 *
 *      �������Ļ�����ʵ��LED����--------------ʵ���Ͼ��ǲ����ļ�
 */

#ifndef __LED_H_
#define __LED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> /*�����ļ���������open() read() close() write()��*/

int Led_Init();
void Led_Close();
void Led_On();
void Led_OFF();


#endif /* LED_H_ */
