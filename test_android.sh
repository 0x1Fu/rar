adb push libs/arm64-v8a/rar /data/local/tmp
adb push librarlab_rar.so /data/local/tmp
adb shell "chmod +x /data/local/tmp/rar"

# rar <threads> <loops>
adb shell "cd /data/local/tmp; LD_LIBRARY_PATH=. ./rar 1 8"

#adb push obj/local/arm64-v8a/rar /data/local/tmp
#adb push librarlab_rar.so /data/local/tmp
#adb shell "chmod +x /data/local/tmp/rar"
#adb shell "cd /data/local/tmp; LD_LIBRARY_PATH=. ./gdbserver :1234 ./rar 1 1"
