//
//  Bridge.m
//  CObjectDemo
//
//  Created by wangqinghai on 2018/4/19.
//  Copyright © 2018年 wangqinghai. All rights reserved.
//

#import "Bridge.h"
#import "CObject.h"

@implementation Bridge






+ (void)t {


    
    
}

@end

void MyCCCustomDeinitMemoryDeinit(struct __CCCustomDeinitMemory * _Nonnull obj) {
    
    printf("deinit\n");
    
}

void COTest(void) {
    long ONE_MB = 1024 * 1024;
        long num_procs;
        long page_size;
        long num_pages;
        long free_pages;
        long long mem;
        long long free_mem;
        num_procs = sysconf (_SC_NPROCESSORS_CONF);
        printf ("CPU 个数为: %ld 个\n", num_procs);
        page_size = sysconf (_SC_PAGESIZE);
        printf ("系统页面的大小为: %ld K\n", page_size / 1024 );
        num_pages = sysconf (_SC_PHYS_PAGES);
        printf ("系统中物理页数个数: %ld 个\n", num_pages);
//        free_pages = sysconf (_SC_AVPHYS_PAGES);
//        printf ("系统中可用的页面个数为: %ld 个\n", free_pages);
        mem = (long long) ((long long)num_pages * (long long)page_size);
        mem /= ONE_MB;
        free_mem = (long long)free_pages * (long long)page_size;
        free_mem /= ONE_MB;
        printf ("总共有 %lld MB 的物理内存, 空闲的物理内存有: %lld MB\n", mem, free_mem);
    
    
//    CObjectModuleInit();
    CCString_o const * str = CCStringInit("asfd");
    CMRetain(str);
    CMRelease(str);
    CMRelease(str);
    
    CMAutoreleasePool(^{
        CCCustomDeinitMemory_o * m = CCCustomDeinitMemoryInit(1000, MyCCCustomDeinitMemoryDeinit);
        
        CMRetain(m);
        CMRelease(m);
        CMAutorelease(m);

    });
    printf("-1pagesize: %ld\n", CMGetFilePageSize());
    printf("-2pagesize: %ld\n", CMGetMemoryPageSize());

    NSThread * thread = [[NSThread alloc] initWithBlock:^{
        CMAutoreleasePool(^{
            CCCustomDeinitMemory_o * m = CCCustomDeinitMemoryInit(1000, MyCCCustomDeinitMemoryDeinit);
            
            CMRetain(m);
            CMRelease(m);
            CMAutorelease(m);
            
        });
    }];
    [thread start];
    
    
}
