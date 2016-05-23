/*
 ============================================================================
 Name        : qetag.h
 Author      : Qiniu.com
 Copyright   : 2012(c) Shanghai Qiniu Information Technologies Co., Ltd.
 Description : 
 ============================================================================
 */

#include "base.h"

#ifndef QINIU_QETAG_H
#define QINIU_QETAG_H

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(1)

struct _Qiniu_Qetag_Context;
struct _Qiniu_Qetag_Block;

// 底层函数
Qiniu_Error Qiniu_Qetag_New(struct _Qiniu_Qetag_Context ** ctx, unsigned int concurrency);
Qiniu_Error Qiniu_Qetag_Reset(struct _Qiniu_Qetag_Context * ctx);
void Qiniu_Qetag_Destroy(struct _Qiniu_Qetag_Context * ctx);
Qiniu_Error Qiniu_Qetag_Update(struct _Qiniu_Qetag_Context * ctx, const char * buf, size_t bufSize);
Qiniu_Error Qiniu_Qetag_Final(struct _Qiniu_Qetag_Context * ctx, char ** digest);

Qiniu_Error Qiniu_Qetag_AllocateBlock(struct _Qiniu_Qetag_Context * ctx, struct _Qiniu_Qetag_Block ** blk, size_t * blkCapacity);
Qiniu_Error Qiniu_Qetag_UpdateBlock(struct _Qiniu_Qetag_Block * blk, const char * buf, size_t bufSize, size_t * blkCapacity);
void Qiniu_Qetag_CommitBlock(struct _Qiniu_Qetag_Context * ctx, struct _Qiniu_Qetag_Block * blk);

// 单线程计算 QETAG
Qiniu_Error Qiniu_Qetag_DigestFile(const char * localFile, char ** digest);
Qiniu_Error Qiniu_Qetag_DigestBuffer(const char * buf, size_t fsize, char ** digest);

#pragma pack()

#ifdef __cplusplus
}
#endif

#endif /* QINIU_QETAG_H */
