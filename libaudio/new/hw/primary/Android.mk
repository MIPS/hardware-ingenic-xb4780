#
# Audio HW
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

ifeq ($(CI20_AUDIO), true)
LOCAL_CFLAGS += \
	-DCI20_AUDIO
endif

LOCAL_MODULE := audio.primary.xb4780
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR_SHARED_LIBRARIES)/hw
LOCAL_SRC_FILES := audio_hw.c
LOCAL_SHARED_LIBRARIES := liblog libcutils
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
