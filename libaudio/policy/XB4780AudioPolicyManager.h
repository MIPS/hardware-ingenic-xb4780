/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <managerdefault/AudioPolicyManager.h>

#ifndef ANDROID_XB4780_AUDIO_POLICY_MANAGER_H
#define ANDROID_XB4780_AUDIO_POLICY_MANAGER_H

namespace android {

class XB4780AudioPolicyManager: public AudioPolicyManager
{
public:
    XB4780AudioPolicyManager(AudioPolicyClientInterface *clientInterface);
    virtual ~XB4780AudioPolicyManager() {}

    virtual audio_devices_t getDeviceForInputSource(audio_source_t inputSource);
};

}  // namespace android
#endif  // ANDROID_XB4780_AUDIO_POLICY_MANAGER_H
