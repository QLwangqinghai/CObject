//
//  AppDelegate.swift
//  CObjectDemo
//
//  Created by wangqinghai on 2018/3/21.
//  Copyright © 2018年 wangqinghai. All rights reserved.
//

import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    @IBOutlet weak var window: NSWindow!


    func applicationDidFinishLaunching(_ aNotification: Notification) {
        // Insert code here to initialize your application
        
//        Bridge.t()
        
        var data = Data(count: 40);
        
        for index in 0 ..< 26 {
            data[index] = UInt8(65 + index)
        }
        let str = String(data: data, encoding: String.Encoding.utf8)!
        
        print(str)
        print(str.lengthOfBytes(using: String.Encoding.utf8))
    }

    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }


}

