//
//  MySkyARUnity.h
//  Gavin
//
//  Created by Gavin on 2017/6/29.
//
//

#import <Foundation/Foundation.h>
#if __has_include(<SARKit/SARKit.h>)
#import <SARKit/SARKit.h>
#else
#import "SARKit.h"
#endif

#if UNITY_VERSION >= 430
#import "AppDelegateListener.h"
#import "UnityAppController.h"
@interface MySkyARUnity : NSObject<SAREngineDelegate,AppDelegateListener> {
#else
  @interface MySkyARUnity : NSObject<SAREngineDelegate> {
#endif
    BOOL displayLinkPaused;
#if TARGET_OS_IPHONE && TARGET_OS_IOS
    UIInterfaceOrientation currentOrientation;
#endif
  }

+ (MySkyARUnity *)sharedInstance;
  
@end

