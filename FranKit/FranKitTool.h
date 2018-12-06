//
//  FranKitTool.h
//  FrankKit
//
//  Created by LWW on 2018/12/6.
//  Copyright © 2018 LWW. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AppDelegate+SDMemory.h"

NS_ASSUME_NONNULL_BEGIN

@interface FranKitTool : NSObject
/**
 * @Frank 图片下载的时候不解压 降低内存消耗
 */
+(void)regisinDepressForSd;
+(void)resetDepressForSd;
@end

NS_ASSUME_NONNULL_END
