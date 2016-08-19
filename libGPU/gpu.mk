GPU_SGX540_LOCAL_PATH := hardware/ingenic/xb4780/libGPU

PRODUCT_COPY_FILES += \
	$(GPU_SGX540_LOCAL_PATH)/libglslcompiler.so:$(TARGET_COPY_OUT_VENDOR)/lib/libglslcompiler.so           \
	$(GPU_SGX540_LOCAL_PATH)/libIMGegl.so:$(TARGET_COPY_OUT_VENDOR)/lib/libIMGegl.so                       \
	$(GPU_SGX540_LOCAL_PATH)/libpvr2d.so:$(TARGET_COPY_OUT_VENDOR)/lib/libpvr2d.so                         \
	$(GPU_SGX540_LOCAL_PATH)/libpvrANDROID_WSEGL.so:$(TARGET_COPY_OUT_VENDOR)/lib/libpvrANDROID_WSEGL.so   \
	$(GPU_SGX540_LOCAL_PATH)/libPVRScopeServices.so:$(TARGET_COPY_OUT_VENDOR)/lib/libPVRScopeServices.so   \
	$(GPU_SGX540_LOCAL_PATH)/libsrv_init.so:$(TARGET_COPY_OUT_VENDOR)/lib/libsrv_init.so                   \
	$(GPU_SGX540_LOCAL_PATH)/libsrv_um.so:$(TARGET_COPY_OUT_VENDOR)/lib/libsrv_um.so                       \
	$(GPU_SGX540_LOCAL_PATH)/libusc.so:$(TARGET_COPY_OUT_VENDOR)/lib/libusc.so                             \
	$(GPU_SGX540_LOCAL_PATH)/libdbm.so:$(TARGET_COPY_OUT_VENDOR)/lib/libdbm.so                             \
	$(GPU_SGX540_LOCAL_PATH)/libcreatesurface.so:$(TARGET_COPY_OUT_VENDOR)/lib/libcreatesurface.so         \
	$(GPU_SGX540_LOCAL_PATH)/hw/gralloc.xxx.so:$(TARGET_COPY_OUT_VENDOR)/lib/hw/gralloc.xb4780.so          \
	$(GPU_SGX540_LOCAL_PATH)/hw/hwcomposer.xxx.so:$(TARGET_COPY_OUT_VENDOR)/lib/hw/hwcomposer.xb4780.so    \
	$(GPU_SGX540_LOCAL_PATH)/hw/memtrack.xxx.so:$(TARGET_COPY_OUT_VENDOR)/lib/hw/memtrack.xb4780.so        \
	$(GPU_SGX540_LOCAL_PATH)/egl/libEGL_POWERVR_SGX540_130.so:$(TARGET_COPY_OUT_VENDOR)/lib/egl/libEGL_POWERVR_SGX540_130.so              \
	$(GPU_SGX540_LOCAL_PATH)/egl/libGLESv1_CM_POWERVR_SGX540_130.so:$(TARGET_COPY_OUT_VENDOR)/lib/egl/libGLESv1_CM_POWERVR_SGX540_130.so  \
	$(GPU_SGX540_LOCAL_PATH)/egl/libGLESv2_POWERVR_SGX540_130.so:$(TARGET_COPY_OUT_VENDOR)/lib/egl/libGLESv2_POWERVR_SGX540_130.so        \
	$(GPU_SGX540_LOCAL_PATH)/pvrsrvctl:$(TARGET_COPY_OUT_VENDOR)/bin/pvrsrvctl

