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

#include "XB4780AudioPolicyManager.h"

namespace android {

// ----------------------------------------------------------------------------
// Common audio policy manager code is implemented in AudioPolicyManager class
// ----------------------------------------------------------------------------

// ---  class factory

extern "C" AudioPolicyInterface* createAudioPolicyManager(
        AudioPolicyClientInterface *clientInterface)
{
    return new XB4780AudioPolicyManager(clientInterface);
}

extern "C" void destroyAudioPolicyManager(AudioPolicyInterface *interface)
{
    delete interface;
}

XB4780AudioPolicyManager::XB4780AudioPolicyManager(
        AudioPolicyClientInterface *clientInterface)
    : AudioPolicyManager(clientInterface)
{
}

audio_devices_t XB4780AudioPolicyManager::getDeviceForInputSource(audio_source_t inputSource)
{
    audio_devices_t device = AudioPolicyManager::getDeviceForInputSource(inputSource);

	if(device == AUDIO_DEVICE_NONE) {
#ifdef CI20_AUDIO
		device = AUDIO_DEVICE_IN_WIRED_HEADSET;
#elif NPM801_AUDIO
		device = AUDIO_DEVICE_IN_BUILTIN_MIC;
#else
		#error "No default input"
#endif
	}

    return device;
}

}  // namespace android
