LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
MXU-COMMON :=
MXU-COMMON-yes :=
AUDIO_CODEC=no
VIDEO_CODEC=yes
MPLAYER_DEMUXER=no
OBJS :=
OBJS-yes:=
LUME_PATH := $(LUME_TOP)

#	LOCAL_MXU_SRC_FILES = file.c
#
#	LOCAL_MXU_CFLAGS = 
#
#	LOCAL_MXU_ASFLAGS = 

include $(LUME_PATH)/codec_config.mak
include $(LOCAL_PATH)/codec.mak


SUBDIR := libavcodec
OBJS      += $(OBJS-yes)
OBJS := $(sort $(OBJS) )

OBJS      := $(addprefix $(SUBDIR)/,$(OBJS))


MY_SRC_FILES := $(OBJS:.o=.c)
MY_SRC_FILES += lumecodecs.c

MXU-COMMON-SRC =$(sort $(MXU-COMMON) )
LOCAL_MXU_SRC_FILES = $(MXU-COMMON-SRC)

LOCAL_SRC_FILES = $(filter-out $(MXU-COMMON-SRC),$(MY_SRC_FILES))
#LOCAL_SRC_FILES =
LOCAL_SRC_FILES += ../../libaf/format.c ../../fmt-conversion.c

LOCAL_MODULE := libstagefright_vlumedecoder
JZC_CFG := $(LUME_PATH)/libjzcommon/com_config.h

LOCAL_CFLAGS := $(PV_CFLAGS) -DHAVE_AV_CONFIG_H -ffunction-sections  -Wmissing-prototypes -Wundef -Wdisabled-optimization -Wno-pointer-sign -Wdeclaration-after-statement -std=gnu99 -Wall -Wno-switch -Wpointer-arith -Wredundant-decls -O2 -pipe -ffast-math -UNDEBUG -UDEBUG -fno-builtin -DVIDEO_CODEC -D__LINUX__ -imacros $(JZC_CFG)

REAL_UNSUPPORTED := $(findstring real,$(LUME_UNSUPPORTED))
ifeq ($(strip $(REAL_UNSUPPORTED)),real)
LOCAL_CFLAGS += -DLUME_REAL_UNSUPPORTED
endif

WMV_UNSUPPORTED := $(findstring wmv,$(LUME_UNSUPPORTED))
ifeq ($(strip $(WMV_UNSUPPORTED)),wmv)
LOCAL_CFLAGS += -DLUME_WMV_UNSUPPORTED
endif

LOCAL_AFLAGS = $(LOCAL_CFLAGS)

LOCAL_STATIC_LIBRARIES := 

LOCAL_SHARED_LIBRARIES := 

LOCAL_C_INCLUDES := \
	$(LUME_PATH)  \
	$(LUME_PATH)/libavutil \
	$(LUME_PATH)/libavcodec \
	$(LUME_PATH)/libswscale \
	$(PV_INCLUDES)

LOCAL_COPY_HEADERS_TO := $(PV_COPY_HEADERS_TO)

LOCAL_COPY_HEADERS := \

include $(BUILD_STATIC_LIBRARY)
