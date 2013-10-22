# File: Android.mk
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Name of the lib
LOCAL_MODULE    := WriteModule
LOCAL_SRC_FILES := WriteModule_wrap.cpp WriteModule.cpp
LOCAL_CFLAGS    := -frtti
LOCAL_C_INCLUDES := inc

include $(BUILD_SHARED_LIBRARY)
