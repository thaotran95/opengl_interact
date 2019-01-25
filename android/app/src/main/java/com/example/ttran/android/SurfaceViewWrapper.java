package com.example.ttran.android;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

public class SurfaceViewWrapper extends GLSurfaceView{
    RendererWrapper renderer_;
    public SurfaceViewWrapper (Context context){
        super(context);
        renderer_ = new RendererWrapper();
        setEGLContextClientVersion(2);
        setRenderer(renderer_);
    }
    @Override
    public boolean onTouchEvent(MotionEvent e) {
        renderer_.state = renderer_.updateState(renderer_.state);
        System.out.println(renderer_.state);
        return super.onTouchEvent(e);
    }
}
