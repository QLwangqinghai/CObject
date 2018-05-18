//
//  CObjectPrivate.h
//  O
//
//  Created by wangqinghai on 2018/3/16.
//  Copyright © 2018年 wangqinghai. All rights reserved.
//

#ifndef CObjectPrivate_h
#define CObjectPrivate_h

#include "CObject.h"
#include <stdlib.h>
#include <pthread/pthread.h>

static inline void * _Nullable CBaseAlloc(size_t size) {
    void * ptr = NULL;
    
    if (size == 0) {
        abort();
    }

    ptr = malloc(size);
    if (NULL != ptr) {
        __CMAdd(size);
    }
    printf("alloc %p\n", ptr);
    
    return ptr;
}

static inline void CBaseFree(void * _Nonnull obj, size_t size) {
    assert(obj);
    printf("cfree %p\n", obj);

    free(obj);
    __CMRemove(size);
}

#if CMemoryHeaderAligent64

static size_t CMContentSizeByteCount = sizeof(uint64_t);
static inline void __CMStoreContentSize(void * _Nonnull ptr, size_t size) {
    uint64_t * p = (uint64_t *)ptr;
    uint64_t value = (uint64_t)size;
    *p = value;
    CMemoryBarrier();
}

static inline void CMInfoStorageStore(CMInfoStorage_s * _Nonnull ptr, CMType _Nonnull type, CMActiveInfo_s * _Nonnull activeInfo) {
    uintptr_t typeValue = (uintptr_t)type;
    uint64_t infoValue = *(uint64_t *)(activeInfo);
    atomic_store(&(ptr->type), typeValue);
    atomic_store(&(ptr->activeInfo), infoValue);
}

#else

static size_t CMContentSizeByteCount = sizeof(uint32_t);
static inline void __CMStoreContentSize(void * _Nonnull ptr, size_t size) {
    uint32_t * p = (uint32_t *)ptr;
    uint32_t value = size;
    *p = value;
    CMemoryBarrier();
}

static inline void CMInfoStorageStore(CMInfoStorage_s * _Nonnull ptr, CMType _Nonnull type, CMActiveInfo_s * _Nonnull activeInfo) {
    uintptr_t typeValue = (uintptr_t)type;
    uint32_t infoValue = *(uint32_t *)(activeInfo);
    atomic_store(&(ptr->type), typeValue);
    atomic_store(&(ptr->activeInfo), infoValue);
}

#endif





#endif



