//
//  FranKitTool.h
//  FrankKit
//
//  Created by LWW on 2018/12/6.
//  Copyright © 2018 LWW. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FranKitTool : NSObject
/**
 * @Frank 图片下载的时候不解压 降低内存消耗 在APPdelegate里面注册
 */
/**
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application{
NSLog(@"@Frank内存警告了⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
SDWebImageManager *mgr = [SDWebImageManager sharedManager];
[mgr cancelAll];
[mgr.imageCache clearMemory];
}
**/
/**
 * @Frank 图片下载的时候不解压 降低内存消耗
 */
+(void)regisinDepressForSd;
/**
 * @Frank 图片下载的时候不解压 降低内存消耗 还原配置
 */
+(void)resetDepressForSd;
@end

NS_ASSUME_NONNULL_END
