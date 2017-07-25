//
//  MySkyARGlesSupport.h
//  Gavin
//
//  Created by Gavin on 2017/7/4.
//

#if UNITY_VERSION >= 410
#include "GlesHelper.h"
#include "EAGLContextHelper.h"
#else
#include "iPhone_GlesSupport.h"
#endif


#if UNITY_VERSION >= 420
#import "UnityAppController.h"
#else
#import "AppController.h"
#endif
#if UNITY_VERSION >= 500
#import "OrientationSupport.h"
#elif UNITY_VERSION >= 400
#import "iPhone_OrientationSupport.h"
#endif
#if UNITY_VERSION >= 430
#import "UnityInterface.h"
#endif


// libiPhone
extern GLint gDefaultFBO;

extern bool UnityUse32bitDisplayBuffer();
extern int UnityGetDesiredMSAASampleCount(int defaultSampleCount);
extern void UnityGetRenderingResolution(unsigned *w, unsigned *h);

extern void UnityBlitToSystemFB(unsigned tex, unsigned w, unsigned h, unsigned sysw, unsigned sysh);

extern void UnityPause(bool pause);

#if UNITY_VERSION >= 430
extern void UnitySetScreenOrientation(int /*ScreenOrientation*/ orientation);
#else
extern ScreenOrientation ConvertToUnityScreenOrientation(int hwOrient, EnabledOrientation *outAutorotOrient);
extern void UnitySetScreenOrientation(ScreenOrientation orientation);
#endif
