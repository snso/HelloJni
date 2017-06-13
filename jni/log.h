/*
 * log.h
 *
 *  Created on: 2017Äê3ÔÂ26ÈÕ
 *      Author: Administrator
 */

#ifndef LOG_H_
#define LOG_H_


#include <android/log.h>

#define LOG_TAG "JNI"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

#endif /* LOG_H_ */
