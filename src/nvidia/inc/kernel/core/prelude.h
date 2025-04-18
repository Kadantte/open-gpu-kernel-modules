/*
 * SPDX-FileCopyrightText: Copyright (c) 1993-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef __PRELUDE_H__
#define __PRELUDE_H__

/* ------------------------ C library --------------------------------------- */
#include <stddef.h>                 // NULL

/* ------------------------ SDK includes ------------------------------------ */

#include "nvtypes.h"
#include "nvrangetypes.h"
#include "nvstatus.h"
#include "nvmisc.h"
#include "nvlimits.h"
#include "nvos.h"

#include "nvctassert.h"

/* ------------------------ RM library and utils ---------------------------- */
#include "nvport/nvport.h"
#include "nvoc/object.h"
#include "core/printf.h"
#include "core/strict.h"
#include "utils/nvassert.h"

/* ------------------------ Code-generation --------------------------------- */
#include "rmconfig.h"               // RMCONFIG header generated by config/rmconfig.pl
#include "g_rmconfig_private.h"     // resman-private hal setup such as: IsGK104(), etc.
#include "g_nvh_state.h"            // pass enable/disable state to NVOC headers
#include "g_odb.h"
#include "g_hal.h"

#include "rmcd.h"

/* ------------------------ Common types ------------------------------------ */
typedef NvU64 RmPhysAddr;           // A physical address should be 64 bits

typedef struct THREAD_STATE_NODE THREAD_STATE_NODE; // FW declare thread state

/* ------------------------ Utility Macros ---------------------------------- */

//
// Power of 2 alignment.
//    (Will give unexpected results if 'gran' is not a power of 2.)
//    (v - v + gran) ensures that gran is upcasted to match v before
//    the ~ operation, without explicitly having to typecast it.
//
#define RM_ALIGN_DOWN(v, gran)          ((v) & ~(((v) - (v) + (gran)) - 1))
#define RM_ALIGN_UP(v, gran)            (((v) + ((gran) - 1)) & ~(((v) - (v) + (gran))-1))
#define RM_IS_ALIGNED(v, gran)          ((((gran) - 1) & (v)) == 0)

#define RM_ALIGN_PTR_DOWN(p, gran)      ((void *) RM_ALIGN_DOWN(((NvUPtr)p), (gran)))
#define RM_ALIGN_PTR_UP(p, gran)        ((void *) RM_ALIGN_UP(((NvUPtr)p), (gran)))

#define RM_PAGE_ALIGN_DOWN(value)       RM_ALIGN_DOWN((value), RM_PAGE_SIZE)
#define RM_PAGE_ALIGN_UP(value)         RM_ALIGN_UP((value), RM_PAGE_SIZE)

#define NV_DELTA(a, b)                  (NV_MAX((a), (b)) - NV_MIN((a), (b)))       // Okay for unsigned or signed

#define NV_ROUNDUP(a,b)                 ((NV_CEIL(a,b))*(b))
#define NV_ROUND_TO_QUANTA(a, quanta)   (((quanta) == 0) ? (a): ((((a) + ((quanta) >> 1)) / (quanta)) *  (quanta)))
#define NV_FLOOR_TO_QUANTA(a, quanta)   (((a) / (quanta)) *  (quanta))
#define NV_BYTESWAP16(a)                ((((a) & 0xff00)>>8)      |  \
                                         (((a) & 0x00ff)<<8))
#define NV_BYTESWAP32(a)                ((((a) & 0xff000000)>>24) |  \
                                         (((a) & 0x00ff0000)>>8)  |  \
                                         (((a) & 0x0000ff00)<<8)  |  \
                                         (((a) & 0x000000ff)<<24))
#define NV_TO_LOWER(c)                  (((c)>='A'&&(c)<='Z')?(c)+('a'-'A'):(c))
#define NV_TO_UPPER(c)                  (((c)>='a'&&(c)<='z')?((c)-'a'+'A'):(c))

/*!
 *  Creates a byte mask for a word at given offset.
 *  offset = 0   0xffffff00
 *  offset = 1   0xffff00ff
 *  offset = 2   0xff00ffff
 *  offset = 3   0x00ffffff
 *
 *  @param[in]  offset  Offset for the mask.
 */
#define NV_BYTE_MASK(offset)            (~(0xff << ((offset)<<3)))

//
// note: the following trick fails if (z-1) * y > max_int
//
// since the calculation contains (x % z) * y,
// and the maximum value of (x % z) is (z-1).
//
// selecting the smaller of x and y to be y reduces the chances
// of problems, but for big enough z, the problem will return...
//
#define OVERFLOW_CAREFUL_MUL_DIV(x, y, z) \
    ((x) > (y)) ? (((x) / (z)) * (y) + (((x) % (z)) * (y)) / (z)) : (((y) / (z)) * (x) + (((y) % (z)) * (x)) / (z))

#define MASK_BITS(n)                    (~(0xFFFFFFFF << (n)))

#endif /* __PRELUDE_H__ */
