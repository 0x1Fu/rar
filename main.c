// https://github.com/0x1Fu/rar.git

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <memory.h>

#include "jni.h"

#ifdef DEBUG
#define DBG(fmt, ...) stderr(stdout, fmt, __VA_ARGS__)
#else
#define DBG(fmt, ...)
#endif

#define OBJECT_LibCmdData        2
#define METHOD_benchmarkProgress 2

JNIEnv jniEnv;
int threads;
int loops;
int loop;

jclass GetObjectClass(JNIEnv* env, jobject obj) {
    DBG("GetObjectClass(%p)\n", obj);
    return (jclass)1;
}

jboolean ExceptionCheck(JNIEnv* env) {
    DBG("ExceptionCheck()\n");
    return 0;
}

jmethodID GetMethodID(JNIEnv* env, jclass cls, const char* p1, const char* p2) {
    DBG("GetMethodID(%p, %s, %s)\n", cls, p1, p2);
    if (strcmp(p1, "benchmarkProgress") == 0) {
        return (jmethodID)METHOD_benchmarkProgress;
    }
    return (jmethodID)1;
}

void DeleteLocalRef(JNIEnv* env, jobject obj) {
    DBG("DeleteLocalRef(%p)\n", obj);
}

jfieldID GetFieldID(JNIEnv* env, jclass cls, const char* p1, const char* p2) {
    DBG("GetFieldID(%p, %s, %s)\n", cls, p1, p2);
    return (jfieldID)1;
}

jobject GetObjectField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    DBG("GetObjectField(%p, %p)\n", obj, fieldID);
    return (jobject)1;
}

const jchar* GetStringChars(JNIEnv* env, jstring str, jboolean* r) {
    DBG("GetStringChars(%p, %p)\n", str, r);
    return (jchar*)1;
}

jsize GetStringLength(JNIEnv* env, jstring str) {
    DBG("GetStringLength(%p)\n", str);
    return (jsize)0;
}

void ReleaseStringChars(JNIEnv* env, jstring str, const jchar* c) {
    DBG("ReleaseStringChars(%p, %p)\n", str, c);
}

jsize GetArrayLength(JNIEnv* env, jarray ary) {
    DBG("GetArrayLength(%p)\n", ary);
    return (jsize)0;
}

jlong GetLongField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    DBG("GetLongField(%p, %p)\n", obj, fieldID);
    return (jlong)0;
}

jboolean GetBooleanField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    DBG("GetBooleanField(%p, %p)\n", obj, fieldID);
    return (jboolean)0;
}

jint GetIntField(JNIEnv* env, jobject obj, jfieldID fieldID) {
    DBG("GetIntField(%p, %p)\n", obj, fieldID);
    return (jint)threads;
}

void CallVoidMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    // public void benchmarkProgress(long param1Long1, long param1Long2, long param1Long3, boolean param1Boolean)
    DBG("CallVoidMethodV(%p, %p)\n", obj, methodID);

    long param1 = va_arg(args, long);
    long param2 = va_arg(args, long);
    long param3 = va_arg(args, long);
    jboolean param4 = (jboolean)va_arg(args, int);
    fprintf(stderr, "progress(%ld, %ld, %ld, %d)\n", param1, param2, param3, param4);

    loop++;
}

jboolean CallBooleanMethodV(JNIEnv* env, jobject obj, jmethodID methodID, va_list args) {
    // public boolean isAborted()
    DBG("CallBooleanMethodV(%p, %p)\n", obj, methodID);

    return (jboolean)(loop >= loops ? 1 : 0);
}

struct JNINativeInterface nativeInterface = {
    .GetObjectClass = GetObjectClass,
    .ExceptionCheck = ExceptionCheck,
    .GetMethodID = GetMethodID,
    .DeleteLocalRef = DeleteLocalRef,
    .GetFieldID = GetFieldID,
    .GetObjectField = GetObjectField,
    .GetStringChars = GetStringChars,
    .GetStringLength = GetStringLength,
    .ReleaseStringChars = ReleaseStringChars,
    .GetArrayLength = GetArrayLength,
    .GetLongField = GetLongField,
    .GetBooleanField = GetBooleanField,
    .GetIntField = GetIntField,
    .CallVoidMethodV = CallVoidMethodV,
    .CallBooleanMethodV = CallBooleanMethodV,
};

JNIEnv jniEnv = &nativeInterface;

uint64_t Java_com_rarlab_rar_RarJni_libBenchmark(JNIEnv *env, jobject rarJni, jobject paramLibCmdData);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: rar <threads> <loops>\n");
        exit(-1);
    }

    threads = atoi(argv[1]);
    loops = atoi(argv[2]);

    fprintf(stderr, "RAR\n");
    fprintf(stderr, " THREADS = %d\n", threads);
    fprintf(stderr, " LOOPS = %d\n", loops);

    Java_com_rarlab_rar_RarJni_libBenchmark(&jniEnv, (jobject)0, (jobject)OBJECT_LibCmdData);

    return 0;
}
