//
//  ViewController.swift
//  My1
//
//  Created by wangqinghai on 2018/5/4.
//  Copyright © 2018年 wangqinghai. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        DispatchQueue.global().asyncAfter(deadline: DispatchTime.now() + 3, execute: {
            COTest()

        })
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

