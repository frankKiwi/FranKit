//
//  AppDelegate+SDMemory.m
//  FrankKit
//
//  Created by LWW on 2018/12/6.
//  Copyright © 2018 LWW. All rights reserved.
//

#import "AppDelegate+SDMemory.h"
#import <SDWebImage/SDWebImageManager.h>

@implementation AppDelegate (SDMemory)

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application{
    NSLog(@"@Frank内存警告了⚠️⚠️⚠️⚠️⚠️⚠️⚠️");
    SDWebImageManager *mgr = [SDWebImageManager sharedManager];
    [mgr cancelAll];
    [mgr.imageCache clearMemory];
}
@end
