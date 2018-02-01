LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
        HardOMXPlugin.cpp

LOCAL_C_INCLUDES += \
	$(TOP)/frameworks/native/include/media/hardware \
        $(TOP)/frameworks/native/include/media/openmax

LOCAL_SHARED_LIBRARIES :=               \
        libbinder                       \
        libutils                        \
        libui                           \
        libcutils                       \
        libstagefright_foundation       \
        libdl                           \
        liblog

LOCAL_MODULE:= libstagefrighthw
LOCAL_VENDOR_MODULE := true

include $(BUILD_SHARED_LIBRARY)

################################################################################

include $(call all-makefiles-under,$(LOCAL_PATH))
