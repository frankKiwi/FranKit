//
//  FranKitHeader.h
//  FrankKit
//
//  Created by LWW on 2018/12/6.
//  Copyright © 2018 LWW. All rights reserved.
//

#ifndef FranKitHeader_h
#define FranKitHeader_h

#define Screen_wide    [UIScreen mainScreen].bounds.size.width
#define Screen_heigth  [UIScreen mainScreen].bounds.size.height

//适配 iPhonex
#define  ios_iPhoneX (Screen_wide == 375.f && Screen_heigth == 812.f ? YES : NO)
#define  TabbarSafeBottomMargin         (IS_IPhoneX_All ? 34.f : 0.f)

#define SafeAreaTopHeight (IS_IPhoneX_All ?88    : 64)

#define SafeAreaTabBarHeight (IS_IPhoneX_All ? 83 : 49)

#define FR_W(width) Screen_wide*(width/375.0)
#define FR_H(height) height/375.0f*Screen_wide

// @Frank 字典解析
#define FRDIC(dic,valuer) [dic objectForKey:valuer]==[NSNull null]?@"":[dic objectForKey:valuer]
// @Frank Model 解析的时候字段值转化为string
#define FRModelToSafeString(objStr)  [NSString stringWithFormat:@"%@",objStr]

// @Frank 防止多次调用
#define FResolveRepeatClickTime(_seconds_) \
static BOOL shouldPrevent; \
if (shouldPrevent) return; \
shouldPrevent = YES; \
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)((_seconds_) * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{ \
shouldPrevent = NO; \
}); \

#endif /* FranKitHeader_h */
