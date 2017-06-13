/*
 * key.c
 *
 *  Created on: 2017年3月27日
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
	if(dat & (1<<0)) // KEY1 被按下，则 LED1 亮，否则 LED1 灭
		key = 0;
	if(dat & (1<<1)) // KEY2 被按下，则 LED2 亮，否则 LED2 灭
		key = 1;
	if(dat & (1<<2)) // KEY3 被按下，则 LED3 亮，否则 LED3 灭
		key = 2;
	if(dat & (1<<3)) // KEY4 被按下，则 LED4 亮，否则 LED4 灭
		key = 3;

	LOGI("KEY %d",key);

	return key;
}

void closeKey()
{
	close(key_fd);
}



