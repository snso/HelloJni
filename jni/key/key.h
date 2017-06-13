/*
 * key.h
 *
 *  Created on: 2017Äê3ÔÂ27ÈÕ
 *      Author: Administrator
 */

#ifndef KEY_H_
#define KEY_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <string.h>


#ifdef __cplusplus

extern "C" {
#endif

int keyInit();
unsigned char scanKey();

#ifdef __cplusplus
}
#endif





#endif /* KEY_H_ */
