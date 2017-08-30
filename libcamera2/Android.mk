ifeq ($(BOARD_HAS_CAMERA), true)

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

ifeq (ci20,$(TARGET_DEVICE))
LOCAL_CFLAGS += \
	-DCI20_NATIVE_CAMERA
endif

LOCAL_SRC_FILES:= \
	SensorListener.cpp \
	CameraV4L2Device.cpp \
	CameraCompressor.cpp \
	CameraColorConvert.cpp \
	CameraFaceDetect.cpp \
	CameraHalSelector.cpp \
	CameraHWModule.cpp

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/include \
	external/jpeg \
	external/jhead \
	external/skia/include/core/ \
	external/skia/include/images \
	external/neven/FaceRecEm/common/src/b_FDSDK \
	system/core/include \
	system/media/camera/include \
	frameworks/native/include \
	frameworks/native/include/media/hardware \
	frameworks/av/include \
	frameworks/av/services/camera/libcameraservice \
	frameworks/av/media/libstagefright \
	frameworks/base/core/jni/android/graphics \
	frameworks/native/include/media/openmax \
    hardware/libhardware/include \
	hardware/ingenic/xb4780/libdmmu \
	hardware/ingenic/xb4780/libjzipu \
	hardware/ingenic/xb4780/libGPU \
	hardware/ingenic/xb4780/include/media \
	kernel/drivers/video

LOCAL_SHARED_LIBRARIES:= \
	libui \
	libsensor \
	libskia \
	libandroid_runtime \
	libandroid \
	libbinder \
	libcutils \
	libutils \
	libexif \
	liblog \
	libcamera_client \
	libc++ \
	libmedia \
	libFFTEm \
	libdmmu \
	libdl \
	libjzipu \
	libjhead \
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
	-DCAMERA_INFO_MANUFACTURER='"$(PRODUCT_MANUFACTURER)"'

LOCAL_CPPFLAGS := -std=c++11 -Wno-tautological-pointer-compare -Wno-c++11-narrowing

#camera version config
ifeq ($(CAMERA_VERSION), 1)
LOCAL_SRC_FILES += \
	WorkQueue.cpp \
	CameraHal1.cpp \
	JZCameraParameters.cpp \

LOCAL_CFLAGS += \
	-DCAMERA_VERSION1 \
	-DSOFTWARE_VALUE=\"Android4.1\"
endif

ifeq ($(CAMERA_VERSION), 2)
LOCAL_SRC_FILES += \
	CameraHal2.cpp \
	JZCameraParameters2.cpp
LOCAL_C_INCLUDES += \
	system/media/camera/include

LOCAL_SHARED_LIBRARIES += \
	libcamera_metadata \
	libcameraservice

LOCAL_CFLAGS += \
	-DCAMERA_VERSION2 \
	-DSOFTWARE_VALUE=\"Android4.2\"
endif

#camera face detect config
ifeq ($(FRONT_CAMERA_FACEDETECT),true)
LOCAL_CFLAGS += \
	-DCAMERA_FACEDETECT=\"3\"
else
LOCAL_CFLAGS += \
	-DCAMERA_FACEDETECT=\"0\"
endif

ifeq ($(BACK_CAMERA_FACEDETECT),true)
LOCAL_CFLAGS += \
	-DCAMERA_FACEDETECT=\"3\"
else
LOCAL_CFLAGS += \
	-DCAMERA_FACEDETECT=\"0\"
endif

# camera video snap short config
ifeq ($(CAMERA_SUPPORT_VIDEOSNAPSHORT), true)
LOCAL_CFLAGS += \
	-DCAMERA_SUPPORT_VIDEOSNAPSHORT
#	-DCOMPRESS_JPEG_USE_HW

LOCAL_SHARED_LIBRARIES += \
	libstagefright_vlume 

LOCAL_SRC_FILES += \
	CameraCompressorHW.cpp
endif

#camera recording use memcpy config
ifeq ($(CAMERA_COPY_MODE_RECORDING), true)
LOCAL_CFLAGS += \
	-DCOPY_RECORDING_MODE
endif

LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR_SHARED_LIBRARIES)/hw

LOCAL_MODULE:= camera.xb4780
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
endif
