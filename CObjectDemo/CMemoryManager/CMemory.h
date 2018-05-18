//
//  CMemory.h
//  CObjectDemo
//
//  Created by wangqinghai on 2018/4/19.
//  Copyright © 2018年 wangqinghai. All rights reserved.
//

#ifndef CMemory_h
#define CMemory_h

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

/********************************* memory *********************************/
static size_t const CObjectMemoryMaxContentSize = SIZE_T_MAX - 16;

static inline void * _Nonnull CMalloc(size_t size) {
    assert(size != 0);
    void * ptr = malloc(size);
    assert(ptr);
    return ptr;
}
static inline void CFree(void * _Nonnull ptr) {
    assert(ptr);
    free(ptr);
}
#endif /* CMemory_h */
