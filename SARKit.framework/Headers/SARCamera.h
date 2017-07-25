//
//  SARCamera.h
//  MySky
//
//  Created by Gavin on 2017/6/28.
//
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIApplication.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(8.0))
typedef NS_ENUM(NSInteger, SARGameraState) {
  
  /** Gamera is not available. */
  SARGameraStateNotAvailable,
  
  /** Gamera is limited. See tracking reason for details. */
  SARGameraStateLimited,
  
  /** Gamera is Normal. */
  SARGameraStateNormal,
} NS_REFINED_FOR_SWIFT;

/**
 A model representing the camera and its parameters.
 */
API_AVAILABLE(ios(8.0))
@interface SARCamera : NSObject

/**
 The current camera state.
 */
@property (nonatomic, readonly) SARGameraState state;

/**
 The camera image resolution in pixels.
 */
@property (nonatomic, readonly) CGSize imageResolution;

@end


@interface SARCamera (Unavailable)

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
