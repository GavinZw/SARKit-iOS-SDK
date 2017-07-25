//
//  SARSCNView.h
//  SARKit
//
//  Created by Gavin on 17/7/24.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SARKit/SARSession.h>

NS_ASSUME_NONNULL_BEGIN

typedef UIView SSCNView;

@interface SARSCNView : SSCNView

/**
 The session that the view uses to update the scene.
 */
@property (nonatomic, strong) SARSession *session;

@end

NS_ASSUME_NONNULL_END
