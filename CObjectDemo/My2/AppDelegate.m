//
//  AppDelegate.m
//  My2
//
//  Created by wangqinghai on 2018/5/4.
//  Copyright © 2018年 wangqinghai. All rights reserved.
//

#import "AppDelegate.h"
#import "Bridge.h"

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    
    
    COTest();

//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        COTest();
//        
//    });

    
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
