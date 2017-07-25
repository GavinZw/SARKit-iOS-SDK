//
//  SARKit.h
//  SARKit
//
//  Created by Gavin on 2017/6/29.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for SARKit.
FOUNDATION_EXPORT double SARKitVersionNumber;

//! Project version string for SARKit.
FOUNDATION_EXPORT const unsigned char SARKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SARKit/SARKit.h>
#if __has_include(<SARKit/SARKit.h>)
#import <SARKit/SARManage.h>
#import <SARKit/SARLogMacros.h>
#import <SARKit/SARError.h>

#import <SARKit/SARSCNView.h>
#import <SARKit/SARSession.h>
#import <SARKit/SARCamera.h>

#import <SARKit/SARObjectNotification.h>

#else
#import "SARManage.h"
#import "SARLogMacros.h"
#import "SARError.h"

#import "SARSCNView.h"
#import "SARSession.h"
#import "SARCamera.h"

#import "SARObjectNotification.h"
#endif




