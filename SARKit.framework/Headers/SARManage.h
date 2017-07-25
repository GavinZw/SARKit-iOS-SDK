//
//  SARManage.h
//  MySky
//
//  Created by Gavin on 2017/6/28.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define SAR_MANAGE [SARManage sharedAR]

@class SARSession;
@protocol SAREngineDelegate;

NS_CLASS_AVAILABLE(10_7, 8_0)
@interface SARManage : NSObject

/*!
 Returns the singleton instance of this class.
 */
+ (instancetype)sharedAR;

+ (instancetype)initWithDelegate:(id<SAREngineDelegate>)engineDelegate;

#pragma makr - Properties

@property (nonatomic, copy) NSString *apiKey; /** Need to bind the corresponding bundle id. */
@property (nonatomic, copy, readonly) NSString *GameObjectName;
@property (nonatomic, copy, readonly) NSString *GameObjectMethodName;

/** Get the current version number. */
- (NSString *)currentVersion;

- (void)arEngineSendMethod:(NSString *)method data:(id)data;
- (void)arEngineReceiveMessage:(id)message effective:(BOOL)effective;

@end

@protocol SAREngineDelegate <NSObject>
- (void)arSceneShown;
- (void)arSceneHidden;
- (UIView *)arGLSceneView;
@required
- (void)arEngineSendOnMethod:(NSString *)method data:(id)data;

@end

/**
 Global Options
 */
@interface SARManage (GlobalOptions)

//  启用或禁用详细日志记录. Defaults to NO.
+ (void)setVerboseLoggingEnabled:(BOOL)loggingEnabled;

// 返回当前详细日志启用状态.
+ (BOOL)isVerboseLoggingEnabled;

//  如果开启日志,上线的时候请关闭.
+ (void)verboseLogFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);

@end
