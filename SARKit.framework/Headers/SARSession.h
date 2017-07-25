//
//  SARSession.h
//  MySky
//
//  Created by Gavin on 2017/6/28.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SARSessionObject;
@class SARSessionErrorObject;
@protocol SARSessionDelegate;

API_AVAILABLE(ios(8.0))
typedef NS_ENUM(NSUInteger, SARSessionStates){
  /** The conversation is waiting. */
  SARSessionState_Waiting,
  
  /** The conversation is processing. */
  SARSessionState_Processing,
  
  /** The conversation is pause. */
  SARSessionState_Pause,
  
  /** The conversation is destroy. */
  SARSessionState_Destroy,
}NS_SWIFT_NAME(SARSession.States);


/**
 The SARSession class.
 */
API_AVAILABLE(ios(8.0))
@interface SARSession : NSObject

/**
 A delegate for receiving SARSession updates.
 */
@property (nonatomic, weak) id <SARSessionDelegate> delegate;

/**
 SARSession States.
 */
@property (nonatomic, getter=isStates, readonly) SARSessionStates states;

/**
 The dispatch queue on which the delegate calls are performed.
 @discussion If not provided or nil, delegate calls will be performed on the main queue.
 */
@property (nonatomic, strong, nullable) dispatch_queue_t delegateQueue;

/**
 Start the session.
 */
- (void)start;

/**
 Pauses the session.
 */
- (void)pause;

@end

#pragma mark - SARSessionDelegate


API_AVAILABLE(ios(8.0))
@protocol SARSessionDelegate <NSObject>

/** message will either be an NSString if the server is using text
 or NSData if the server is using binary. */
- (void)session:(SARSession *)session didReceiveMessage:(NSArray<SARSessionObject *>*)messages;

@optional

/**
 The current session state has changed.
 
 @param session session.
 @param state state.
 */
- (void)session:(SARSession *)session didChangeState:(SARSessionStates)state;

/**
 There was an error in the current session.
 
 @param session session.
 @param error SARSessionErrorObject.
 */
- (void)session:(SARSession *)session didFailWithError:(SARSessionErrorObject *)error;


@end

NS_ASSUME_NONNULL_END
