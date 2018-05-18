//
//  CObject.h
//  O
//
//  Created by wangqinghai on 2018/3/16.
//  Copyright © 2018年 wangqinghai. All rights reserved.
//

#ifndef CObject_h
#define CObject_h

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#ifndef C_TARGET_DEFINE
#define C_TARGET_DEFINE

#if __APPLE__
#define C_TARGET_OS_DARWIN       1
#define C_TARGET_OS_LINUX        0
#define C_TARGET_OS_WINDOWS      0
#define C_TARGET_OS_BSD          0
#define C_TARGET_OS_ANDROID      0
#define C_TARGET_OS_CYGWIN       0
#elif __ANDROID__
#define C_TARGET_OS_DARWIN       0
#define C_TARGET_OS_LINUX        1
#define C_TARGET_OS_WINDOWS      0
#define C_TARGET_OS_BSD          0
#define C_TARGET_OS_ANDROID      1
#define C_TARGET_OS_CYGWIN       0
#elif __linux__
#define C_TARGET_OS_DARWIN       0
#define C_TARGET_OS_LINUX        1
#define C_TARGET_OS_WINDOWS      0
#define C_TARGET_OS_BSD          0
#define C_TARGET_OS_ANDROID      0
#define C_TARGET_OS_CYGWIN       0
#elif __CYGWIN__
#define C_TARGET_OS_DARWIN       0
#define C_TARGET_OS_LINUX        1
#define C_TARGET_OS_WINDOWS      0
#define C_TARGET_OS_BSD          0
#define C_TARGET_OS_ANDROID      0
#define C_TARGET_OS_CYGWIN       1
#elif _WIN32 || _WIN64
#define C_TARGET_OS_DARWIN       0
#define C_TARGET_OS_LINUX        0
#define C_TARGET_OS_WINDOWS      1
#define C_TARGET_OS_BSD          0
#define C_TARGET_OS_ANDROID      0
#elif __unix__
#define C_TARGET_OS_DARWIN       0
#define C_TARGET_OS_LINUX        0
#define C_TARGET_OS_WINDOWS      0
#define C_TARGET_OS_BSD          1
#define C_TARGET_OS_ANDROID      0
#else
#error unknown operating system
#endif

#if __x86_64__
#define CPTARGET_CPU_PPC          0
#define CPTARGET_CPU_PPC64        0
#define CPTARGET_CPU_X86          0
#define CPTARGET_CPU_X86_64       1
#define CPTARGET_CPU_ARM          0
#define CPTARGET_CPU_ARM64        0
#define CPTARGET_CPU_MIPS         0
#define CPTARGET_CPU_MIPS64       0
#define CPTARGET_CPU_S390X        0
#elif __arm64__ || __aarch64__
#define CPTARGET_CPU_PPC          0
#define CPTARGET_CPU_PPC64        0
#define CPTARGET_CPU_X86          0
#define CPTARGET_CPU_X86_64       0
#define CPTARGET_CPU_ARM          0
#define CPTARGET_CPU_ARM64        1
#define CPTARGET_CPU_MIPS         0
#define CPTARGET_CPU_MIPS64       0
#define CPTARGET_CPU_S390X        0
#elif __mips64__
#define CPTARGET_CPU_PPC          0
#define CPTARGET_CPU_PPC64        0
#define CPTARGET_CPU_X86          0
#define CPTARGET_CPU_X86_64       0
#define CPTARGET_CPU_ARM          0
#define CPTARGET_CPU_ARM64        0
#define CPTARGET_CPU_MIPS         0
#define CPTARGET_CPU_MIPS64       1
#define CPTARGET_CPU_S390X        0
#elif __powerpc64__
#define CPTARGET_CPU_PPC          0
#define CPTARGET_CPU_PPC64        1
#define CPTARGET_CPU_X86          0
#define CPTARGET_CPU_X86_64       0
#define CPTARGET_CPU_ARM          0
#define CPTARGET_CPU_ARM64        0
#define CPTARGET_CPU_MIPS         0
#define CPTARGET_CPU_MIPS64       0
#define CPTARGET_CPU_S390X        0
#elif __i386__
#define CPTARGET_CPU_PPC          0
#define CPTARGET_CPU_PPC64        0
#define CPTARGET_CPU_X86          1
#define CPTARGET_CPU_X86_64       0
#define CPTARGET_CPU_ARM          0
#define CPTARGET_CPU_ARM64        0
#define CPTARGET_CPU_MIPS         0
#define CPTARGET_CPU_MIPS64       0
#define CPTARGET_CPU_S390X        0
#elif __arm__
#define CPTARGET_CPU_PPC          0
#define CPTARGET_CPU_PPC64        0
#define CPTARGET_CPU_X86          0
#define CPTARGET_CPU_X86_64       0
#define CPTARGET_CPU_ARM          1
#define CPTARGET_CPU_ARM64        0
#define CPTARGET_CPU_MIPS         0
#define CPTARGET_CPU_MIPS64       0
#define CPTARGET_CPU_S390X        0
#elif __mips__
#define CPTARGET_CPU_PPC          0
#define CPTARGET_CPU_PPC64        0
#define CPTARGET_CPU_X86          0
#define CPTARGET_CPU_X86_64       0
#define CPTARGET_CPU_ARM          0
#define CPTARGET_CPU_ARM64        0
#define CPTARGET_CPU_MIPS         1
#define CPTARGET_CPU_MIPS64       0
#define CPTARGET_CPU_S390X        0
#elif __powerpc__
#define CPTARGET_CPU_PPC          1
#define CPTARGET_CPU_PPC64        0
#define CPTARGET_CPU_X86          0
#define CPTARGET_CPU_X86_64       0
#define CPTARGET_CPU_ARM          0
#define CPTARGET_CPU_ARM64        0
#define CPTARGET_CPU_MIPS         0
#define CPTARGET_CPU_MIPS64       0
#define CPTARGET_CPU_S390X        0
#elif __s390x__
#define CPTARGET_CPU_PPC          0
#define CPTARGET_CPU_PPC64        0
#define CPTARGET_CPU_X86          0
#define CPTARGET_CPU_X86_64       0
#define CPTARGET_CPU_ARM          0
#define CPTARGET_CPU_ARM64        0
#define CPTARGET_CPU_MIPS         0
#define CPTARGET_CPU_MIPS64       0
#define CPTARGET_CPU_S390X        1
#else
#error unknown architecture
#endif

#if __LITTLE_ENDIAN__
#define CPTARGET_RT_LITTLE_ENDIAN 1
#define CPTARGET_RT_BIG_ENDIAN    0
#elif __BIG_ENDIAN__
#define CPTARGET_RT_LITTLE_ENDIAN 0
#define CPTARGET_RT_BIG_ENDIAN    1
#else
#error unknown endian
#endif

#if __LP64__
#define CPTARGET_RT_64_BIT        1
#else
#define CPTARGET_RT_64_BIT        0
#endif

#if C_TARGET_OS_WINDOWS || C_TARGET_OS_CYGWIN
#error unsuport system
#endif

#endif /* CPDefine_h */


#if __GNUC__
#define CMemoryBarrier()  __asm__ __volatile__("" ::: "memory");
#else
#define CMemoryBarrier()  do { } while (0);
#endif



#ifndef CMemoryHeaderAligent64
    #if CPTARGET_RT_64_BIT
        static size_t const CMMaxContentSize = (SIZE_T_MAX / 8 - 128) * 8;
        #define CMemoryHeaderAligent64 1
    #else
    static size_t const CMMaxContentSize = (SIZE_T_MAX / 4 - 128) * 4;
        #define CMemoryHeaderAligent64 0
    #endif
#endif


#pragma mark - base

/********************************* CMemoryManage *********************************/
typedef struct __CMemoryManager {
    uint64_t ptrCount;
    uint64_t usedMemory;
    void (* _Nullable zeroSizeErrorHandler)(struct __CMemoryManager * _Nonnull manager, void * _Nonnull * _Nullable ptr);
    void (* _Nullable oomHandler)(struct __CMemoryManager * _Nonnull manager, size_t size);
} CMemoryManager_t;
static CMemoryManager_t CMemoryManagerDefault = {};

long CMGetFilePageSize(void);
long CMGetMemoryPageSize(void);

static inline void * _Nullable CMUIntptrToVoidPtr(uintptr_t p) {
    return (void *)p;

}
static inline uintptr_t CMVoidPtrToUIntptr(void * _Nullable ptr) {
    return (uintptr_t)ptr;
//    return *((uintptr_t *)(&ptr));
}


#if CMemoryHeaderAligent64

#pragma pack(push)
#pragma pack(1)
static size_t const CMMaxContentSizeInActiveInfo = 0xFFFF;

typedef struct {
    uint64_t contentSize: 16;
    uint64_t deallocing: 1;//on this time, deinit
    uint64_t prepareDealloc: 1;
    uint64_t autoDealloc: 1;
    uint64_t refrenceCount: 45;
} CMActiveInfo_s;
typedef struct {
    _Atomic(uintptr_t) type;
    _Atomic(uint_fast64_t) activeInfo;
} CMInfoStorage_s;
typedef struct {
    void const * _Nonnull type;
    CMActiveInfo_s activeInfo;
} CMInfo_s;

#pragma pack(pop)
static uint64_t const CMRefrenceStaticFlag = 0x1FFFFFFFFFFFLLU;
static size_t const CMContentAligentBlock = sizeof(uint64_t);

#else

#pragma pack(push)
#pragma pack(1)
static size_t const CMMaxContentSizeInActiveInfo = 0x1;

typedef struct {
    uint32_t contentSize: 1;
    uint32_t deallocing: 1;
    uint32_t prepareDealloc: 1;
    uint32_t autoDealloc: 1;
    uint32_t refrenceCount: 28;
} CMActiveInfo_s;
typedef struct {
    _Atomic(uintptr_t) type;
    _Atomic(uint_fast32_t) activeInfo;
} CMInfoStorage_s;

typedef struct {
    void const * _Nonnull type;
    CMActiveInfo_s activeInfo;
} CMInfo_s;

#pragma pack(pop)
static size_t const CMContentAligentBlock = sizeof(uint32_t);
static uint64_t const CMRefrenceStaticFlag = 0xFFFFFFFLU;
#endif

static uint32_t const CMInfoStoreSize = sizeof(CMInfoStorage_s);
typedef void const * CMObject;

#pragma pack(push)
#pragma pack(1)

typedef struct __CMTypeBaseInfo {
    uint32_t isImmutable: 1;//是否不可变
    uint32_t domain: 24;
    uint32_t contentHasPadding: 1;
    uint32_t customInfoSize: 6;// * CMContentAligentBlock
    size_t contentBaseSize;// * 1
    char * _Nonnull name;
    void const * _Nullable superType;
    void const * _Nullable alloctor;//CMAlloctor_s *
    void (* _Nullable deinit)(void * _Nonnull object);//有子类向父类递归调用
} CMTypeBaseInfo_s;

typedef struct __CMLifeCycleCallback_s {
    void (* _Nullable didRetain)(void const * _Nonnull typeInfo, CMObject _Nonnull obj);
    void (* _Nullable didRelease)(void const * _Nonnull typeInfo, CMObject _Nonnull obj);
    void (* _Nullable didPrepareDealloc)(void const * _Nonnull typeInfo, CMObject _Nonnull obj);
    void (* _Nullable willDealloc)(void const * _Nonnull typeInfo, CMObject _Nonnull obj);
    void (* _Nullable didResignActive)(void const * _Nonnull typeInfo, CMObject _Nonnull ptr);
} CMLifeCycleCallback_s;
typedef struct __CMType {
    CMTypeBaseInfo_s base;
    CMLifeCycleCallback_s * _Nullable callbacks;
    void * _Nullable context;
} CMType_s;

typedef struct __CMHeader {
    CMInfoStorage_s info;
    CMType_s type;
} CMHeader_s;

typedef CMType_s const * CMType;
static uint32_t const CCTypeDomain = 1;

typedef struct {
    CMInfo_s info;
    CMType_s type;
} CMTypeLayout_s;

#pragma pack(pop)


static CMTypeLayout_s const CMTypeStorage_Type = {
#if CMemoryHeaderAligent64
    .info = {
        .type = NULL,
        .activeInfo = {
            .contentSize = 0,
            .deallocing = 0,
            .prepareDealloc = 0,
            .autoDealloc = 0,
            .refrenceCount = CMRefrenceStaticFlag,
        }
    },
#else
    .info = {
        .type = NULL,
        .activeInfo = {
            .contentSize = 0,
            .deallocing = 0,
            .prepareDealloc = 0,
            .autoDealloc = 0,
            .refrenceCount = CMRefrenceStaticFlag,
        }
    },
#endif
    .type = {
        .base = {
            .isImmutable = 1,
            .domain = CCTypeDomain,
            .contentHasPadding = 0,
            .customInfoSize = 0,
            .contentBaseSize = sizeof(CMType_s),
            .name = "Type",
            .superType = NULL,
            .alloctor = NULL,
            .deinit = NULL,
        },
        .callbacks = NULL,
        .context = NULL,
    },
};

#define CMType_Type (&(CMTypeStorage_Type.type))

//static CMType_s const CMType_Type = {
//    .base = {
//        .isImmutable = 1,
//        .domain = CCTypeDomain,
//        .contentHasPadding = 0,
//        .customInfoSize = 0,
//        .contentBaseSize = sizeof(CMType_s),
//        .name = "Type",
//        .superType = NULL,
//        .alloctor = NULL,
//        .deinit = NULL,
//    },
//    .callbacks = NULL,
//    .context = NULL,
//};


#define CMInfoDefaultTypeInfo {\
    .type = CMType_Type,\
    .activeInfo = {\
        .contentSize = 0,\
        .deallocing = 0,\
        .prepareDealloc = 0,\
        .autoDealloc = 0,\
        .refrenceCount = CMRefrenceStaticFlag,\
    }\
}\




static inline void CMSuperDidRetain(CMType _Nonnull Self, CMObject _Nonnull obj) {
    assert(Self);
    assert(obj);
    
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;

    do {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    } while (Super->callbacks == NULL || Super->callbacks->didRetain == NULL);
    Super->callbacks->didRetain(Super, obj);
}
static inline void CMSuperDidRelease(CMType _Nonnull Self, CMObject _Nonnull obj) {
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    do {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    } while (Super->callbacks == NULL || Super->callbacks->didRelease == NULL);
    Super->callbacks->didRelease(Super, obj);
}
static inline void CMSuperDidPrepareDealloc(CMType _Nonnull Self, CMObject _Nonnull obj) {
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    do {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    } while (Super->callbacks == NULL || Super->callbacks->didPrepareDealloc == NULL);
    Super->callbacks->didPrepareDealloc(Super, obj);
}
static inline void CMSuperWillDealloc(CMType _Nonnull Self, CMObject _Nonnull obj) {
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    do {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    } while (Super->callbacks == NULL || Super->callbacks->willDealloc == NULL);
    Super->callbacks->willDealloc(Super, obj);
}
static inline void CMSuperDidResignActive(CMType _Nonnull Self, CMObject _Nonnull obj) {
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    do {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    } while (Super->callbacks == NULL ||Super->callbacks->didResignActive == NULL);
    Super->callbacks->didResignActive(Super, obj);
}

static inline void CMDidRetainDispatch(CMType _Nonnull Self, CMObject _Nonnull obj) {
    assert(Self);
    assert(obj);
    
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    while (Super->callbacks == NULL || Super->callbacks->didRetain == NULL) {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    }
    Super->callbacks->didRetain(Super, obj);
}
static inline void CMDidReleaseDispatch(CMType _Nonnull Self, CMObject _Nonnull obj) {
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    while (Super->callbacks == NULL ||Super->callbacks->didRelease == NULL) {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    };
    Super->callbacks->didRelease(Super, obj);
}
static inline void CMDidPrepareDeallocDispatch(CMType _Nonnull Self, CMObject _Nonnull obj) {
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    while (Super->callbacks == NULL ||Super->callbacks->didPrepareDealloc == NULL) {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    };
    Super->callbacks->didPrepareDealloc(Super, obj);
}
static inline void CMWillDeallocDispatch(CMType _Nonnull Self, CMObject _Nonnull obj) {
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    while (Super->callbacks == NULL ||Super->callbacks->willDealloc == NULL) {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    };
    Super->callbacks->willDealloc(Super, obj);
}
static inline void CMDidResignActiveDispatch(CMType _Nonnull Self, CMObject _Nonnull obj) {
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    while (Super->callbacks == NULL ||Super->callbacks->didResignActive == NULL) {
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    };
    Super->callbacks->didResignActive(Super, obj);
}

static inline void CMDeinitDispatch(CMType _Nonnull Self, CMObject _Nonnull obj) {
    CMType Super = Self;
    int hasRing = -1;//-1 未知， 0: 没有, 1: 有环
    CMType QuickSuper = Self;
    
    while (Super != NULL) {
        if (Super->base.deinit != NULL) {
            Super->base.deinit(obj);
        }
        Super = (CMType)(Super->base.superType);
        if (Super == NULL) {
            return;
        }
        if (hasRing == -1) {
            QuickSuper = QuickSuper->base.superType;
            if (QuickSuper) {
                QuickSuper = QuickSuper->base.superType;
                if (Super == QuickSuper) {
                    hasRing = 1;
                    printf("class error, class list has ring! \n");
                    abort();
                }
            } else {
                hasRing = 0;
            }
        }
    };
}

typedef struct {
    void * _Nonnull address;
    void * _Nullable customInfo;
    size_t customInfoSize;
    size_t contentSize;
    CMInfoStorage_s * _Nonnull info;
    void * _Nonnull object;
} CMInfoWrapper_s;

size_t CMGetStoreSizeWithType(CMType _Nonnull obj, size_t paddingSize);
size_t CMGetStoreSize(void * _Nonnull obj);
CMInfoStorage_s * _Nonnull CMGetInfo(void const * _Nonnull obj);


typedef struct __CMAllocedMemory {
    void * _Nonnull ptr;
    size_t size;
} CMAllocedMemory_s;

typedef struct __CMAlloctor {
    CMAllocedMemory_s (* _Nonnull memoryAlloc)(struct __CMAlloctor const * _Nonnull alloctor, size_t size);
    void (* _Nonnull memoryDealloc)(struct __CMAlloctor const * _Nonnull alloctor, void * _Nonnull ptr, size_t size);

//    CMAllocedMemory_s (* _Nonnull alloc)(struct __CMAlloctor const * _Nonnull alloctor, CMType _Nonnull type, size_t contentPaddingSize);
//    CMObject _Nonnull (* _Nonnull init)(CMAllocedMemory_s memory, _Bool autoDealloc, _Bool isStatic);
    void * _Nonnull (* _Nonnull allocInit)(struct __CMAlloctor const * _Nonnull alloctor, CMType _Nonnull type, size_t contentMutableSize, _Bool autoDealloc, _Bool isStatic);
    void (* _Nonnull dealloc)(struct __CMAlloctor const * _Nonnull alloctor, CMObject _Nonnull obj);
    void * _Nullable context;
} CMAlloctor_s;

CMAlloctor_s const * _Nonnull CMAlloctorGetDefault(void);

static inline size_t CMAlignContentSize(size_t size) {
    if (size == 0) {
        return CMContentAligentBlock;
    }
    size_t result = size;
    size_t rsize = result % CMContentAligentBlock;
    if (rsize > 0) {
        result += CMContentAligentBlock - rsize;
    }
    return result;
}



static inline void __CMAdd(size_t size) {
    
}
static inline void __CMRemove(size_t size) {
    
}


CMAllocedMemory_s CMBaseAlloc(struct __CMAlloctor const * _Nonnull alloctor, size_t size);
void CMBaseDealloc(struct __CMAlloctor const * _Nonnull alloctor, void * _Nonnull ptr, size_t size);
void * _Nonnull CMAllocInit(struct __CMAlloctor const * _Nonnull alloctor, CMType _Nonnull type, size_t contentPaddingSize, _Bool autoDealloc, _Bool isStatic);
CMAllocedMemory_s CMAlloc(struct __CMAlloctor const * _Nonnull alloctor, CMType _Nonnull type, size_t contentPaddingSize);
void * _Nonnull CMInit(void * _Nonnull ptr, CMType _Nonnull type, size_t contentPaddingSize, _Bool autoDealloc, _Bool isStatic);


void CMDealloc(struct __CMAlloctor const * _Nonnull alloctor, CMObject _Nonnull obj);







//void * _Nonnull CMAlloc(uint32_t domain, uint32_t typeIdentifier, size_t size, uint32_t customInfo, _Bool autoDealloc, _Bool isStatic);


/********************************* object *********************************/
#pragma mark - object

static inline CMActiveInfo_s CMActiveInfoMake(_Bool autoDealloc, uint32_t refrenceCount) {
    CMActiveInfo_s info;
    if (autoDealloc) {
        info.prepareDealloc = 1;
    } else {
        info.prepareDealloc = 0;
    }
    info.refrenceCount = refrenceCount;
    return info;
}

#if CMemoryHeaderAligent64
static inline uint64_t CMActiveInfoBridgeTo(CMActiveInfo_s info) {
    return *(uint64_t *)(&info);
}
static inline CMActiveInfo_s CMActiveInfoBridgeFrom(uint64_t value) {
    return *(CMActiveInfo_s *)(&value);
}
#else
static inline uint32_t CMActiveInfoBridgeTo(CMActiveInfo_s info) {
    return *(uint32_t *)(&info);
}
static inline CMActiveInfo_s CMActiveInfoBridgeFrom(uint32_t value) {
    return *(CMActiveInfo_s *)(&value);
}
#endif


static inline CMActiveInfo_s CMGetActiveInfo(CMInfoStorage_s * _Nonnull object) {
    assert(object);
    
#if CMemoryHeaderAligent64
    uint64_t content = atomic_load(&(object->activeInfo));
    return CMActiveInfoBridgeFrom(content);
#else
    uint32_t content = atomic_load(&(object->activeInfo));
    return CMActiveInfoBridgeFrom(content);
#endif
}
static inline CMType_s * _Nonnull CMGetType(CMInfoStorage_s * _Nonnull object) {
    assert(object);
    uintptr_t content = atomic_load(&(object->type));
    assert(content != 0);
    return (CMType_s *)((void *)content);
}

static inline _Bool CMCASSetActiveInfo(CMInfoStorage_s * _Nonnull header, CMActiveInfo_s oldValue, CMActiveInfo_s newValue) {
    assert(header);
    
#if CMemoryHeaderAligent64
    uint64_t oldContent = CMActiveInfoBridgeTo(oldValue);
    uint64_t newContent = CMActiveInfoBridgeTo(newValue);
    return atomic_compare_exchange_weak(&(header->activeInfo), &oldContent, newContent);
#else
    uint32_t oldContent = CMActiveInfoBridgeTo(oldValue);
    uint32_t newContent = CMActiveInfoBridgeTo(newValue);
    return atomic_compare_exchange_weak(&(header->activeInfo), &oldContent, newContent);
#endif
}

//COMemoryManager_t * _Nonnull CObjectManagerGetMemoryManager(CObjectManager_t const * _Nonnull manager);
//
//
//CObjectManager_t const * _Nonnull CObjectManagerGetDefault(void);
//COMemoryManager_t const * _Nonnull COMemoryManagerGetDefault(void);
//
//
////init
//CObject_o * _Nonnull CObjectManagerCreateObject(CObjectManager_t const * _Nonnull manager, uint32_t detailInfo, CMActiveInfo_s activeInfo, size_t contentSize);
//
//
///********************************* COMemoryManagerAPI *********************************/
//
//#pragma mark - COMemoryManagerAPI don't use
//CObject_o * _Nonnull COMemoryManagerMalloc(CObjectManager_t const * _Nonnull manager, uint32_t detailInfo, CMActiveInfo_s activeInfo, size_t contentSize);
//void COMemoryManagerDealloc(CObjectManager_t const * _Nonnull manager, CObject_o * _Nonnull object);
//
//#pragma mark - CObjectBaseAPI
//CObject_o * _Nullable CODefaultRetain(CObjectManager_t const * _Nonnull manager, CObject_o * _Nonnull obj);
//CMActiveInfo_s CODefaultRelease(CObjectManager_t const * _Nonnull manager, CObject_o * _Nonnull obj);
//void CODefaultDidResignActive(CObjectManager_t const * _Nonnull manager, CObject_o * _Nonnull obj);
//int32_t CODefaultPrepareDealloc(CObjectManager_t const * _Nonnull manager, CObject_o * _Nonnull obj);
//int32_t CODefaultSetDeallocingFlag(CObjectManager_t const * _Nonnull manager, CObject_o * _Nonnull obj);
//void CODefaultDeinit(CObjectManager_t const * _Nonnull manager, CObject_o * _Nonnull obj);


/********************************* COAutoreleasePool *********************************/

#pragma mark - COAutoreleasePool
void CMAutoreleasePool(void(^_Nonnull block)(void));

CMObject _Nullable CMRetain(void const * _Nullable obj);
void CMRelease(void const * _Nullable obj);
void CMAutorelease(void const * _Nullable obj);



/********************************* CObjectManager *********************************/

#pragma mark - CObjectManager

//int CObjectManagerKeyCreate(uint8_t * _Nonnull keyRef, CObjectManager_t * _Nonnull manager);
//CObjectManager_t const * _Nullable CObjectManagerGet(uint8_t key);
//CObjectManager_t const * _Nullable CObjectGetObjectManager(CObject_o * _Nonnull object);
//



/********************************* init module *********************************/

#pragma mark - init module

__attribute__((constructor(201)))
void CObjectModuleInit(void);


/********************************* CConstantObject *********************************/

typedef struct _CCWeakContainerFlag {
    uint32_t useFlag;

} CCWeakContainerFlag_t;


//static uint32_t const CCQueueInfoMaxSize = 0x1FFFFE;
#pragma pack(push)
#pragma pack(1)
typedef struct _CCQueueInfo {
    uint32_t size: 32;
    uint32_t offset: 32;
} CCQueueInfo_t;
typedef struct _CCQueue {
    _Atomic(uint_fast32_t) bufferSize;
    _Atomic(uint_fast64_t) info;
    void * _Nonnull content;
    _Atomic(uintptr_t) buffer[0];
} CCQueue_t;
#pragma pack(pop)

static int32_t CCQueueAdd(CCQueue_t * _Nonnull queue, void * _Nonnull object) {
    assert(queue);
    assert(object);
    
    CCQueueInfo_t info = {};
    CCQueueInfo_t newInfo = {};
    uint32_t bufferSize = atomic_load(&(queue->bufferSize));
    uint64_t infoValue = 0;
    uint64_t newInfoValue = 0;
    
    do {
        infoValue = atomic_load(&(queue->info));
        info = *(CCQueueInfo_t *)&infoValue;
        newInfo.size = info.size + 1;
        
#if DEBUG
        if (info.size > bufferSize) {
            abort();
        } else if (info.size == queue->bufferSize) {
            return -1;
        }
#else
        if (info.size >= bufferSize) {
            return -1;
        }
#endif
        //        info.size += 1;
        //        offset + index = realIndex
        newInfoValue = *(uint64_t *)&newInfo;
        
    } while (!atomic_compare_exchange_weak(&(queue->info), &infoValue, newInfoValue));
    
    uint32_t lastIndex = (newInfo.size + newInfo.offset - 1) % bufferSize;
    
    uintptr_t ptr = (uintptr_t)object;
    
    atomic_store(&(queue->buffer[lastIndex]), ptr);
    return 0;
}
static void * _Nullable CCQueueRemove(CCQueue_t * _Nonnull queue) {
    assert(queue);
    CCQueueInfo_t info = {};
    CCQueueInfo_t newInfo = {};
    uint32_t bufferSize = atomic_load(&(queue->bufferSize));
    uint64_t infoValue = 0;
    uint64_t newInfoValue = 0;
    uintptr_t ptr = 0;

    do {
        infoValue = atomic_load(&(queue->info));
        info = *(CCQueueInfo_t *)&infoValue;
        if (info.size == 0) {
            return NULL;
        }
        newInfo.offset += 1;

        if (newInfo.offset == bufferSize) {
            newInfo.offset = 0;
        }
        newInfo.size = info.size - 1;
        newInfoValue = *(uint64_t *)&newInfo;
        
        uint32_t firstIndex = (newInfo.size + newInfo.offset - 1) % bufferSize;
        ptr = atomic_load(&(queue->buffer[firstIndex]));
        if (ptr == 0) {
            return NULL;
        }
    } while (!atomic_compare_exchange_weak(&(queue->info), &infoValue, newInfoValue));
    
    return *(void **)&ptr;
}


//typedef struct _CCQueue {
//    uint32_t const bufferSize;
//    uint32_t size;
//    _Atomic(uint_fast32_t) offset;
//    _Atomic(uint_fast32_t) offset;
//
//    unsigned int in;    /* data is added at offset (in % size) */
//    unsigned int out;    /* data is extracted from off. (out % size) */
//    uintptr_t buffer[0];
//} CCQueue_T;


typedef struct __CCWeakContainer {
    
    _Atomic(uintptr_t) content;
    
    struct _CCWeakContainer * _Nullable prev;
    struct _CCWeakContainer * _Nullable next;
} _CCWeakContainer_o;

typedef struct _CCWeakContainer {
    uint8_t content[sizeof(_CCWeakContainer_o)];
} CCWeakContainer_t;

typedef struct {
    CCWeakContainer_t * _Nonnull (* _Nonnull init)(void * _Nonnull object);
    void * _Nullable (* _Nonnull retainedContent)(CCWeakContainer_t * _Nonnull object);
//    void (* _Nonnull didContentDealloc)(CCWeakContainer_o * _Nonnull object);
} CCWeakContainer_c;

extern CMType _Nonnull CMType_CCNull;
extern CMType _Nonnull CMType_CCString;
extern CMType _Nonnull CMType_CCData;



typedef struct {
    uint32_t __unused__;
} CCNull_o;

typedef struct {
    uint32_t privateValue;
    uint32_t const length;
    uint64_t const cUtf8StringLength;
    char const cUtf8String[0];
} CCString_o;

typedef struct {
    uint32_t privateValue;
    uint64_t const byteLength;
    uint8_t const byte[0];
} CCData_o;

typedef struct {
    int64_t high;
    uint64_t low;
} CCSInteger_o;

typedef struct {
    uint64_t high;
    uint64_t low;
} CCUInteger_o;

typedef float float32_t;
typedef double float64_t;

typedef struct {
    float32_t content;
} CCFloat32_o;

typedef struct {
    float64_t content;
} CCFloat64_o;

typedef struct {
    uint32_t const contentSize;
    uint8_t byte[0];
} CCMemory_o;

typedef struct __CCCustomDeinitMemory {
    void (* _Nullable deinit)(struct __CCCustomDeinitMemory * _Nonnull obj);
    uint32_t const contentSize;
    uint8_t byte[0];
} CCCustomDeinitMemory_o;
typedef CCNull_o const * CCNull;
typedef CCString_o const * CCString;
typedef CCData_o const * CCData;


//_Bool CCObjectContain(void * _Nonnull object);
//
CCNull_o const * _Nonnull CCNullShare(void);
CCString_o const * _Nonnull CCStringInit(char const * _Nullable cUtf8String);
CCString_o const * _Nullable CCStringInitWithUtf8Byte(uint8_t const * _Nullable byte, uint32_t byteLength);
CCData_o * _Nonnull CCStringGetUtf8Data(CCString_o const * _Nonnull string);


CCData_o * _Nullable CCDataInit(uint8_t const * _Nullable byte, uint64_t byteLength);

CCSInteger_o * _Nonnull CCSIntegerInit(int64_t high, uint64_t low);
CCSInteger_o * _Nonnull CCSIntegerInitWithSInt64(int64_t number);
CCSInteger_o * _Nonnull CCSIntegerInitWithUInt64(uint64_t number);

CCUInteger_o * _Nonnull CCUIntegerInit(uint64_t high, uint64_t low);
CCUInteger_o * _Nonnull CCUIntegerInitUInt64(uint64_t number);

CCFloat32_o * _Nonnull CCFloat32Init(float32_t number);
CCFloat64_o * _Nonnull CCFloat64Init(float64_t number);

CCMemory_o * _Nonnull CCMemoryInit(uint32_t byteLength);
CCCustomDeinitMemory_o * _Nonnull CCCustomDeinitMemoryInit(uint32_t byteLength, void (* _Nullable deinit)(struct __CCCustomDeinitMemory * _Nonnull obj));



/********************************* COString *********************************/

typedef struct {
    uint32_t bigchar;
} CStringScalar;

_Bool CStringScalarInit(CStringScalar * _Nonnull scalar, uint32_t code);
//返回 CStringScalar 个数
_Bool CStringCheckUtf8Byte(const uint8_t * _Nonnull utf8StringByte, size_t length, size_t * _Nullable scalarCountRef, size_t * _Nullable validByteCountRef);
_Bool CStringCheckUtf8String(const char * _Nonnull utf8String, size_t * _Nullable scalarCount, size_t * _Nullable validByteCountRef);
_Bool CStringCheckUtf8StringWithLength(const char * _Nonnull utf8String, size_t length, size_t * _Nullable scalarCount, size_t * _Nullable validByteCountRef);


#endif /* CObjectBase_h */
