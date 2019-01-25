package com.example.ttran.android;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import static android.opengl.GLES30.*;
import static java.lang.Boolean.TRUE;
import static java.lang.Boolean.FALSE;

import android.opengl.GLSurfaceView;
import android.opengl.GLSurfaceView.Renderer;
import android.app.ActivityManager;
import android.content.Context;
import android .content.pm.ConfigurationInfo;
import android.view.MotionEvent;

import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.concurrent.TimeUnit;
import javax.microedition.khronos.opengles.GL10;
import javax.microedition.khronos.egl.EGLConfig;

public class RendererWrapper implements Renderer {
    long VBO;
    long vao;
    boolean state= TRUE;
    float vertices[] = {
            -0.1f, 1.0f, 0.0f,
            0.1f, 1.0f, 0.0f,
            0.0f,  1.1f, 0.0f,
    };

    public float [] updatePosition(float [] vertices){
        float [] new_vertices = new float [9];
        for (int i=0;i<9;i++){
            if(i%3==1){
                new_vertices[i]=vertices[i]-0.005f;
            }
            else{
                new_vertices[i]=vertices[i];
            }
        }
        if (new_vertices[7] < -1.0f){
            float ini_vertices[] = {
                    -0.1f, 1.0f, 0.0f,
                    0.1f, 1.0f, 0.0f,
                    0.0f,  1.1f, 0.0f,
            };
            new_vertices = ini_vertices.clone();
        }
        return new_vertices;
    }

    public static boolean updateState(boolean state){
        boolean state_return;
        if(state){
            state_return =FALSE;
        }
        else{
            state_return=TRUE;
        }
        return state_return;
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        GameLibJNIWrapper.on_surface_created();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        GameLibJNIWrapper.on_surface_changed(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        String infoLog = GameLibJNIWrapper.on_draw_frame(VBO, vao,vertices);
        if(state) {
            vertices = updatePosition(vertices);
        }
        //System.out.println(infoLog);
    }
}

