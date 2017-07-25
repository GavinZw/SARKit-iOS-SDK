//
//  SARObjectNotification.h
//  MySky
//
//  Created by Gavin on 2017/6/30.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SARError;

#define SARIS_NOTICE_OBJ(s1, s2) ([s1 isEqualToString:s2])

typedef NSInteger SARObjectErrorDomain;

API_AVAILABLE(ios(8.0))
typedef NS_ENUM(SARObjectErrorDomain,  SARObjErrorType) {
  /** Indicates that the current object is valid. */
  SARObjErrorNone = 1000,
  
   /** The returned data is invalid. */
  SARObjErrorInvalidData = 1001,
  
   /** The requested API is invalid. */
  SARObjErrorInvlidAPI = 1002,
  
   /** Error is not defined. */
  SARObjErrorUnknown,
}NS_SWIFT_NAME(SARObjErrorType.Type);

/**
 The notification object base class.
 */
API_AVAILABLE(ios(8.0))
@interface SARObjectNotification : NSObject

/** Error type. 
    The current error type is notified by the SARSessionErrorObject object, 
    and the other notification object is this value of SARObjErrorNone.
 */
@property (nonatomic, assign)   SARObjErrorType  errorType;

@property (nonatomic, assign)   NSInteger  identifier;

@end

/**
  Session notification body.
 */
@interface SARSessionObject : SARObjectNotification

@property (nonatomic, copy)  NSString *event; /** session event type */

@property (nonatomic, copy)  NSString *fun;   /** session API */

@property (nonatomic, copy)  NSString *funId; /** session id */

@property (nonatomic, copy)  NSString *command_type; /** command type */

@property (nonatomic, strong)  id message; /** session message */

@end


/**
 Session error notification body.
 */
@interface SARSessionErrorObject : SARObjectNotification

@property (nonatomic, strong) SARError *error;

@end

NS_ASSUME_NONNULL_END
