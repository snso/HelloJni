LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS += -llog

APP_STL := c++_static 

LOCAL_MODULE    := HelloWorld
LOCAL_SRC_FILES := HelloWorld.cpp \
status/status.cpp \
led/led.cpp \
pwm/pwm.cpp \
key/key.c

include $(BUILD_SHARED_LIBRARY)
