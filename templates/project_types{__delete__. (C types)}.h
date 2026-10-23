/*
                             *******************
******************************* C HEADER FILE *********************************
**                           *******************
**
** project   : {__project__}
** filename  : project_types.h
** version   : 0.0.0.1
** date      : {__date__}
**
*******************************************************************************
**
** Copyright (c) 2016-{__year__}, {__company__}
** All rights reserved.
**
*******************************************************************************
**
** Fixed-width types shared by all modules, independent of any device header.
** The TI C2000 style names (int16, Uint16, float32, ...) are kept so existing
** code and TI examples compile unchanged; they are built on <stdint.h> so the
** same modules also compile on a host PC for unit testing.
**
*******************************************************************************

*/

#ifndef PROJECT_TYPES_H_
#define PROJECT_TYPES_H_

/******************************************************************************/
/**                                                                          **/
/**                     MODULES USED                                         **/
/**                                                                          **/
/******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/******************************************************************************/
/**                                                                          **/
/**                     TYPEDEFS AND STRUCTURES                              **/
/**                                                                          **/
/******************************************************************************/
/* Same guard as the TI C2000 device headers: whichever is included first
 * defines the types, so this file and F28x_Project.h can be mixed freely. */
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int16_t     int16;
typedef int32_t     int32;
typedef int64_t     int64;
typedef uint16_t    Uint16;
typedef uint32_t    Uint32;
typedef uint64_t    Uint64;
typedef float       float32;
#if defined(__TMS320C28XX__)
typedef long double float64;    /* C28x: long double is 64-bit */
#else
typedef double      float64;
#endif
#endif

/* Compile-time size checks (C89/C99 compatible). */
typedef char PROJECT_TYPES_CHECK_FLOAT32[(sizeof(float32) * CHAR_BIT == 32) ? 1 : -1];
typedef char PROJECT_TYPES_CHECK_FLOAT64[(sizeof(float64) * CHAR_BIT == 64) ? 1 : -1];

#endif /* PROJECT_TYPES_H_ */
/******************************************************************************/
/**                                                                          **/
/**                               EOF                                        **/
/**                                                                          **/
/******************************************************************************/
