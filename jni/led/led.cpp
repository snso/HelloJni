#include "../s5pv210.h"
#include "led.h"
#include "../log.h"


int fd;   //�ļ���ʶ��

#define DEVICE_NAME  "/dev/leds"   //����linux������豸�ڵ㣬AndroidӦ�ó������ͨ�������ʶ�����������


#define IOCTL_GPIO_ON           1
#define IOCTL_GPIO_OFF          0


void Led_Blink()				//LED ��˸
{

}

int Led_Init()
{
	fd = open(DEVICE_NAME,O_RDWR);//���豸
	return fd;
}

void Led_Close()
{
	close(fd);
}

void Led_On()
{

	LOGI("LED ON ");
	ioctl(fd, IOCTL_GPIO_ON, 0);
	ioctl(fd, IOCTL_GPIO_ON, 1);
	ioctl(fd, IOCTL_GPIO_ON, 2);
	ioctl(fd, IOCTL_GPIO_ON, 3);


}

void Led_OFF()				
{
	LOGI("LED OFF ");
	ioctl(fd, IOCTL_GPIO_OFF, 0);
	ioctl(fd, IOCTL_GPIO_OFF, 1);
	ioctl(fd, IOCTL_GPIO_OFF, 2);
	ioctl(fd, IOCTL_GPIO_OFF, 3);
//	ioctl(fd, IOCTL_GPIO_OFF, 4);
}


