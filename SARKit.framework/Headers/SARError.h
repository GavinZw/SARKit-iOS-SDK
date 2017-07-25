//
//  SARError.h
//  MySky
//
//  Created by Gavin on 2017/6/28.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSInteger SARErrorDomain;

API_AVAILABLE(ios(8.0))
typedef NS_ENUM(SARErrorDomain, SARErrorCode) {
//  * Unsupported session configuration.
  SARErrorCodeUnsupportedConfiguration   = 100,
  
  /** A sensor required to run the session is not available. */
  SARErrorCodeSensorUnavailable          = 101,
  
  /** A sensor failed to provide the required input. */
  SARErrorCodeSensorFailed               = 102,
  
  /** World tracking has encountered a fatal error. */
  SARErrorCodeWorldTrackingFailed        = 200,
};

@interface SARError : NSError

@end

NS_ASSUME_NONNULL_END
