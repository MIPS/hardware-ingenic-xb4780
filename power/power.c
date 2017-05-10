/*
 * Copyright (C) 2012 The Android Open Source Project
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
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOG_TAG "XB4780 PowerHAL"
#include <utils/Log.h>

#include <hardware/hardware.h>
#include <hardware/power.h>

static void sysfs_write(char *path, char *s)
{
    char buf[80];
    int len;
    int fd = open(path, O_WRONLY);

    if (fd < 0) {
        strerror_r(errno, buf, sizeof(buf));
        ALOGE("Error opening %s: %s\n", path, buf);
        return;
    }

    len = write(fd, s, strlen(s));
    if (len < 0) {
        strerror_r(errno, buf, sizeof(buf));
        ALOGE("Error writing to %s: %s\n", path, buf);
    }

    close(fd);
}

static void power_init(struct power_module *module)
{
    sysfs_write("/sys/devices/system/cpu/cpufreq/interactive/timer_rate",
                "20000");
    sysfs_write("/sys/devices/system/cpu/cpufreq/interactive/min_sample_time",
                "100000");
    sysfs_write("/sys/devices/system/cpu/cpufreq/interactive/go_hispeed_load",
                "85");
    sysfs_write("/sys/devices/system/cpu/cpufreq/interactive/input_boost",
		"1");
}

static void power_set_interactive(struct power_module *module, int on)
{
}

static void power_hint(struct power_module *module, power_hint_t hint,
                       void *data) {

    switch (hint) {
    case POWER_HINT_VSYNC:

        break;
    default:
        break;
    }
}

static int power_open(const hw_module_t *module, const char *name,
                            hw_device_t **device)
{
    ALOGD("%s: enter; name=%s", __FUNCTION__, name);
    int retval = 0; /* 0 is ok; -1 is error */

    if (strcmp(name, POWER_HARDWARE_MODULE_ID) == 0) {
        struct power_module *dev = (struct power_module *)calloc(1,
                sizeof(struct power_module));

        if (dev) {
            /* Common hw_device_t fields */
            dev->common.tag = HARDWARE_MODULE_TAG;
            dev->common.module_api_version = POWER_MODULE_API_VERSION_0_2;
            dev->common.hal_api_version = HARDWARE_HAL_API_VERSION;

            dev->init = power_init;
            dev->setInteractive = power_set_interactive;
            dev->powerHint = power_hint;

            *device = (hw_device_t*)dev;
        } else
            retval = -ENOMEM;
    } else {
        retval = -EINVAL;
    }

    ALOGD("%s: exit %d", __FUNCTION__, retval);
    return retval;
}

static struct hw_module_methods_t power_module_methods = {
    .open = power_open,
};

struct power_module HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .module_api_version = POWER_MODULE_API_VERSION_0_2,
        .hal_api_version = HARDWARE_HAL_API_VERSION,
        .id = POWER_HARDWARE_MODULE_ID,
        .name = "XB4780 Power HAL",
        .author = "The Android Open Source Project",
        .methods = &power_module_methods,
        .dso = NULL,
        .reserved = {0},
    },

    .init = power_init,
    .setInteractive = power_set_interactive,
    .powerHint = power_hint,
};
