/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "../main/cpp/game.h"
#include <stdlib.h>
#include <string.h>
/* Header for class com_example_ttran_android_GameLibJNIWrapper */

#ifndef _Included_com_example_ttran_android_GameLibJNIWrapper
#define _Included_com_example_ttran_android_GameLibJNIWrapper
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_ttran_android_GameLibJNIWrapper
 * Method:    on_surface_created
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_ttran_android_GameLibJNIWrapper_on_1surface_1created
        (JNIEnv *, jclass){
        on_surface_created();
};

/*
 * Class:     com_example_ttran_android_GameLibJNIWrapper
 * Method:    on_surface_changed
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_example_ttran_android_GameLibJNIWrapper_on_1surface_1changed
        (JNIEnv *, jclass, jint ,jint){
    on_surface_changed();
};

/*
 * Class:     com_example_ttran_android_GameLibJNIWrapper
 * Method:    on_draw_frame
 * Signature: ()V
 */
JNIEXPORT jstring JNICALL Java_com_example_ttran_android_GameLibJNIWrapper_on_1draw_1frame
        (JNIEnv *env, jclass, jfloatArray vertices, jlong vertices_array_size){
    char * infoLog;
    jfloat * vertices_cpp= env->GetFloatArrayElements(vertices,0);
    infoLog = on_draw_frame(vertices_cpp,vertices_array_size);
    jstring infoLog_jstring = env->NewStringUTF(infoLog);
    return infoLog_jstring;

};

#ifdef __cplusplus
}
#endif
#endif
