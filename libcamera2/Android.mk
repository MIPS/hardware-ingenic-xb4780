ifeq ($(BOARD_HAS_CAMERA), true)

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

ifeq (ci20,$(TARGET_DEVICE))
LOCAL_CFLAGS += \
	-DCI20_NATIVE_CAMERA
endif

LOCAL_SRC_FILES:= \
	CameraV4L2Device.cpp \
	CameraCompressor.cpp \
	CameraColorConvert.cpp \
	CameraHalSelector.cpp \
	CameraHWModule.cpp \
	skiasupport/SkStream.cpp \
	skiasupport/SkData.cpp \
	skiasupport/SkEventTracer.cpp \
	skiasupport/SkString.cpp \
	skiasupport/SkOSFile_stdio.cpp \
	skiasupport/SkMemory_malloc.cpp \
	skiasupport/SkUtils.cpp \
	skiasupport/SkOSFile_posix.cpp \
	skiasupport/SkDebug_android.cpp \
	skiasupport/YuvToJpegEncoder.cpp \
	skiasupport/SkJPEGWriteUtility.cpp \

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/include \
	$(LOCAL_PATH)/skiasupport/include/core \
	$(LOCAL_PATH)/skiasupport/include/private \
	system/media/camera/include \
	hardware/libhardware/include \
	hardware/ingenic/xb4780/libdmmu \
	hardware/ingenic/xb4780/libjzipu \
	hardware/ingenic/xb4780/libGPU \
	hardware/ingenic/xb4780/include/media \
	hardware/ingenic/xb4780/jhead \
	kernel/drivers/video

LOCAL_STATIC_LIBRARIES := android.hardware.camera.common@1.0-helper

LOCAL_SHARED_LIBRARIES:= \
	libui \
	libbinder \
	libcutils \
	libutils \
	libexif \
	liblog \
	libc++ \
	libdmmu \
	libdl \
	libjzipu \
	libjhead.xb4780 \
	libion \
	libhardware

ifeq ($(USE_GMS_LIBS),true)
	LOCAL_SHARED_LIBRARIES += libjpeg_old
else
	LOCAL_SHARED_LIBRARIES += libjpeg
endif

LOCAL_CFLAGS += \
	-Wno-non-virtual-dtor \
	-DCAMERA_INFO_MODULE='"$(PRODUCT_MODEL)"' \
	-DCAMERA_INFO_MANUFACTURER='"$(PRODUCT_MANUFACTURER)"' \
	-g0 \
	-fno-integrated-as \
	-Wa,-mmxu \

LOCAL_CPPFLAGS := -std=c++11 -Wno-tautological-pointer-compare -Wno-c++11-narrowing

LOCAL_SRC_FILES += \
	WorkQueue.cpp \
	CameraHal1.cpp \
	JZCameraParameters.cpp \

LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR_SHARED_LIBRARIES)/hw

LOCAL_MODULE:= camera.xb4780
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
endif
