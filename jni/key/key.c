/*
 * key.c
 *
 *  Created on: 2017��3��27��
 *      Author: Administrator
 */
#include "key.h"
#include "../s5pv210.h"
#include "../log.h"


int key_fd = 0;
int keyInit()
{
	key_fd = open("/dev/input", O_RDWR);
	return key_fd;
}

unsigned char scanKey()
{
	unsigned char key;

	/*
	read(key_fd, &key, 1);

	LOGI("The key = %x\n", key);

	return key;

	*/

	unsigned long  dat = GPH1DAT;
	if(dat & (1<<0)) // KEY1 �����£��� LED1 �������� LED1 ��
		key = 0;
	if(dat & (1<<1)) // KEY2 �����£��� LED2 �������� LED2 ��
		key = 1;
	if(dat & (1<<2)) // KEY3 �����£��� LED3 �������� LED3 ��
		key = 2;
	if(dat & (1<<3)) // KEY4 �����£��� LED4 �������� LED4 ��
		key = 3;

	LOGI("KEY %d",key);

	return key;
}

void closeKey()
{
	close(key_fd);
}



