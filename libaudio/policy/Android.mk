# Copyright (C) 2014 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH := $(call my-dir)

##################################
# Audio Policy Manager
##################################
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    XB4780AudioPolicyManager.cpp

LOCAL_SHARED_LIBRARIES := \
    libbinder \
    libaudiopolicymanagerdefault

LOCAL_C_INCLUDES := \
    $(TOPDIR)frameworks/av/services/audiopolicy \
    $(TOPDIR)frameworks/av/services/audiopolicy/common/include \
    $(TOPDIR)frameworks/av/services/audiopolicy/common/managerdefinitions/include \
    $(TOPDIR)frameworks/av/services/audiopolicy/engine/interface

LOCAL_MODULE := libaudiopolicymanager
LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS += -Werror

ifeq (ci20,$(TARGET_DEVICE))
	LOCAL_CFLAGS += \
		-DCI20_AUDIO
endif

ifeq (npm801,$(TARGET_DEVICE))
	LOCAL_CFLAGS += \
		-DNPM801_AUDIO
endif

include $(BUILD_SHARED_LIBRARY)
