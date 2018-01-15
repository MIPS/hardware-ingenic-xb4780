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

LOCAL_STATIC_LIBRARIES := android.hardware.camera.common@1.0-helper

LOCAL_SHARED_LIBRARIES:= \
	libui \
	libskia \
	libandroid_runtime \
	libandroid \
	libbinder \
	libcutils \
	libutils \
	libexif \
	liblog \
	libc++ \
	libmedia \
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
	-DCAMERA_INFO_MANUFACTURER='"$(PRODUCT_MANUFACTURER)"' \
	-g0 \
	-fno-integrated-as \
	-Wa,-mmxu \

LOCAL_CPPFLAGS := -std=c++11 -Wno-tautological-pointer-compare -Wno-c++11-narrowing

#camera version config
ifeq ($(CAMERA_VERSION), 1)
LOCAL_SRC_FILES += \
	WorkQueue.cpp \
	CameraHal1.cpp \
	JZCameraParameters.cpp \

LOCAL_CFLAGS += \
	-DCAMERA_VERSION1
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
	-DCAMERA_VERSION2
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
