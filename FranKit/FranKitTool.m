//
//  FranKitTool.m
//  FrankKit
//
//  Created by LWW on 2018/12/6.
//  Copyright © 2018 LWW. All rights reserved.
//

#import "FranKitTool.h"
#import <SDWebImage/SDWebImageManager.h>
#import <mach/mach.h>

@implementation FranKitTool

static BOOL SDImageCacheOldShouldDecompressImages = YES;
static BOOL SDImagedownloderOldShouldDecompressImages = YES;

+(void)regisinDepressForSd{
    SDImageCache *canche = [SDImageCache sharedImageCache];
    SDImageCacheOldShouldDecompressImages = canche.config.shouldDecompressImages;
    canche.config.shouldDecompressImages = NO;
    
    SDWebImageDownloader *downloder = [SDWebImageDownloader sharedDownloader];
    SDImagedownloderOldShouldDecompressImages = downloder.shouldDecompressImages;
    downloder.shouldDecompressImages = NO;
}
+(void)resetDepressForSd{
    SDImageCache *canche = [SDImageCache sharedImageCache];
    canche.config.shouldDecompressImages = SDImageCacheOldShouldDecompressImages;
    SDWebImageDownloader *downloder = [SDWebImageDownloader sharedDownloader];
    downloder.shouldDecompressImages = SDImagedownloderOldShouldDecompressImages;
    SDWebImageManager *mgr = [SDWebImageManager sharedManager];

    if ([self memoryUsage]/(1024*1024) > 300) {
        [mgr.imageCache clearMemory];
        if ([self memoryUsage]/(1024*1024) > 500) {
            [mgr cancelAll];
            [mgr.imageCache clearMemory];
        }
    }
    
}
+ (int64_t)memoryUsage {
    int64_t memoryUsageInByte = 0;
    task_vm_info_data_t vmInfo;
    mach_msg_type_number_t count = TASK_VM_INFO_COUNT;
    kern_return_t kernelReturn = task_info(mach_task_self(), TASK_VM_INFO, (task_info_t) &vmInfo, &count);
    if(kernelReturn == KERN_SUCCESS) {
        memoryUsageInByte = (int64_t) vmInfo.phys_footprint;
    } else {
        NSLog(@"Error with task_info(): %s", mach_error_string(kernelReturn));
    }
    return memoryUsageInByte;
}


@end
