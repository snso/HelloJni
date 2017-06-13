#include <jni.h>
#include "com_snso_helloworld_GetCinfo.h"

#include <stdio.h>
#include "status/status.h"
#include "led/led.h"
#include "log.h"

#include "key/key.h"



JNIEXPORT jstring JNICALL Java_com_snso_helloworld_GetCinfo_getStr
  (JNIEnv *env, jclass)
{
	return env->NewStringUTF("12121212");
}


/*
 * Class:     com_snso_helloworld_GetCinfo
 * Method:    getInt
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_snso_helloworld_GetCinfo_getInt
  (JNIEnv *env, jclass)
{
	LOGE("LED ctrl");

	int result = Led_Init();

	if(result < 0)
	{
		LOGE("open led");
		return 0;
	}


	keyInit();

	return status::getNum();
}


/*
 * Class:     com_snso_helloworld_GetCinfo
 * Method:    LedCtrl
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_snso_helloworld_GetCinfo_LedCtrl
  (JNIEnv *, jclass, jint status, jint)
{

	switch (status) {
		case 1:
			Led_On();
			break;
		case 0:
			Led_OFF();
			break;
		default:
			break;
	}

}

JNIEXPORT void JNICALL Java_com_snso_helloworld_GetCinfo_PwmCtrl
  (JNIEnv *, jclass)
{

}

/*
 * Class:     com_snso_helloworld_GetCinfo
 * Method:    callBack
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_snso_helloworld_GetCinfo_callBack
  (JNIEnv *env, jclass jcls, jobject interObj)
{
	//C ����  java
	//1. �õ���

	//2.�õ�����ID
	jmethodID jmatchID = env->GetMethodID(jcls, "cback", "(Lcom/snso/helloworld/GetCinfo$CBackInterface;I)V");

	//3 ʵ����
	jobject jobj = env->AllocObject(jcls);

	//4���÷���

	while(1)
	{

		jint scanResult = (int)scanKey();
		env->CallVoidMethod(jobj, jmatchID, interObj, scanResult);

//		usleep(5000);
		sleep(1);
	}





}



