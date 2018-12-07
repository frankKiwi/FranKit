# FranKit

一,iOS解决图片十几兆几十兆,内存暴涨闪退问题.

1.pod 'FranKit', '~> 1.0.3'

2.在APP添加category SDMemory 引入 #import "AppDelegate+SDMemory.h",添加注册内存释放通知

3.在消耗内存加载大量图片的类引入 [ regisinDepressForSd];


- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [FranKitTool regisinDepressForSd];
}

4.在出该类的时候引入 [ resetDepressForSd];

- (void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    [FranKitTool resetDepressForSd]
}

二. 疯狂点击崩溃

1. 在点击的地方引入 FResolveRepeatClickTime(0.5);
