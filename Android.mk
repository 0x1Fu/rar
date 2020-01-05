LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := rar
LOCAL_SRC_FILES :=  main.c
LOCAL_LDLIBS := -lrarlab_rar -L.
include $(BUILD_EXECUTABLE)
