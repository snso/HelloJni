#include "../s5pv210.h"
#include "led.h"
#include "../log.h"


int fd;   //文件标识符

#define DEVICE_NAME  "/dev/leds"   //这是linux下面的设备节点，Android应用程序就是通过这个来识别驱动程序的


#define IOCTL_GPIO_ON           1
#define IOCTL_GPIO_OFF          0


void Led_Blink()				//LED 闪烁
{

}

int Led_Init()
{
	fd = open(DEVICE_NAME,O_RDWR);//打开设备
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


