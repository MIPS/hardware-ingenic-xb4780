#ifndef ISTRIDE_H
#define ISTRIDE_H

#include <hardware/hardware.h>

extern const IMG_gralloc_module_public_t *module;

static inline int iStride(const IMG_native_handle_t *nativeHandle) {
    const IMG_buffer_format_public_t *format, *formats;
    int width       = nativeHandle->iWidth;
    int height      = nativeHandle->iHeight;
    int stride      = nativeHandle->iWidth;
    int vstride     = nativeHandle->iHeight;
    unsigned long planeOffset = 0;
    static int warnings = 0;
    int err;

    if (module == NULL) {
        err = hw_get_module(GRALLOC_HARDWARE_MODULE_ID, (const hw_module_t **)&module);
        if (err) {
            ALOGE("Error: failed to load graphics HAL");
            abort();
        }
    }

    if (module->GetBufferFormats == NULL) {
        ALOGE("%s: Error Unexpected module->GetBufferFormats == NULL", __func__);
        abort();
    } else {
        formats = module->GetBufferFormats();

        for(format = formats; format; format = format->psNext) {
            if(format->iHalPixelFormat == nativeHandle->iFormat)
                break;
        }
        if (!format) {
            ALOGE("%s: Error: handle had invalid buffer format", __func__);
            abort();
        }
        err = format->pfnComputeParams(0, &width, &height, &stride, &vstride, &planeOffset);
        if (err) {
            ALOGE("%s: Error: failed to compute buffer stride", __func__);
            abort();
        }
        if (stride > width) {
            ALOGE("%s: stride:%d > nativeHandle->iWidth:%d", __func__,
                       stride,     nativeHandle->iWidth);
            abort();
        }
    }
    return(stride);
}

#endif /* ISTRIDE_H */
