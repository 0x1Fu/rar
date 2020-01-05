https://github.com/0x1Fu/rar.git

______________________
rar-android-580.78.apk

BackgroundFragment.onCreate(Bundle paramBundle) {
  BackgroundFragment.startTask
    BackgroundFragment.BackgroundAsyncTask.taskBenchmark

private void taskBenchmark() {
  (new RarJni()).libBenchmark(BackgroundFragment.this.cmdData);
}

void doMenuCommand(int paramInt) {
  case 2131231020:
    libCmdData = new RarJni.LibCmdData();
...
    intent2.putExtra("cmddata", libCmdData);
}

BackgroundFragment.onCreate {
    this.cmdData = (RarJni.LibCmdData)paramBundle.getParcelable("cmddata");
    this.cmdData.hostFragment = this;
}

public LibCmdData() {
      this.arcNameCount = 0;
      this.threads = SystemF.getCpuNumber();
}

https://github.com/pmachapman/unrar/blob/master/unpack.cpp
https://github.com/pmachapman/unrar/blob/bfb9920b05a2f0edd11051c282f1f390ede9b3d8/rdwrfn.cpp

public void totalProgress(int param1Int, long param1Long1, long param1Long2) {
      BackgroundFragment backgroundFragment = this.hostFragment;
      if (backgroundFragment != null)
        backgroundFragment.api.totalProgress(param1Int, param1Long1, param1Long2); 
    }

__________________
JNI IMPLEMENTATION

Program received signal SIGSEGV, Segmentation fault.
0x0000000000000000 in ?? ()
(gdb) bt
#0  0x0000000000000000 in ?? ()
#1  0x0000007fb7c74224 in JniInitApi(_JNIEnv*, _jobject*) ()
   from target:/data/local/tmp/librarlab_rar.so
#2  0x0000007fb7c78f4c in Java_com_rarlab_rar_RarJni_libBenchmark ()
   from target:/data/local/tmp/librarlab_rar.so
#3  0x0000005555555970 in main ()

   0x0000007fb7c74218 <+56>:    mov     x1, x20
   0x0000007fb7c7421c <+60>:    ldr     x8, [x8,#248] # => GetObjectClass
   0x0000007fb7c74220 <+64>:    blr     x8
   0x0000007fb7c74224 <+68>:    ldr     x8, [x19]

___
RUN

# rar <threads> <loops>

$ adb shell "cd /data/local/tmp; LD_LIBRARY_PATH=. ./rar 1 8"

RAR
 THREADS = 1
 LOOPS = 8
progress(4194304, -1, -1, 0)
progress(8388608, -1, -1, 0)
progress(12582912, -1, -1, 0)
progress(16777216, 495, -1, 0)
progress(20971520, 499, -1, 0)
progress(25165824, 495, -1, 0)
progress(29360128, 499, -1, 0)
progress(33554432, 495, -1, 0)
