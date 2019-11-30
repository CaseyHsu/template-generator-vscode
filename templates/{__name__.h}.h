/*
                             *******************
******************************* C HEADER FILE *********************************
**                           *******************
**
** project   : {__project__}
** filename  : {__name__}.h
** version   : 0.0.0.1
** date      : {__date__}
**
*******************************************************************************
**
** Copyright (c) 2016-{__year__}, {__company__}
** All rights reserved.
**
*******************************************************************************

*/

#ifndef __{__UpperSnakeCaseName__}_INCLUDED
#define __{__UpperSnakeCaseName__}_INCLUDED

/******************************************************************************/
/**                                                                          **/
/**                     MODULES USED                                         **/
/**                                                                          **/
/******************************************************************************/
#include "F28x_Project.h"

/******************************************************************************/
/**                                                                          **/
/**                     DEFINITIONS AND MACROS                               **/
/**                                                                          **/
/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**                     TYPEDEFS AND STRUCTURES                              **/
/**                                                                          **/
/******************************************************************************/

/******************************************************************************/
/**                                                                          **/
/**                     EXPORTED VARIABLES                                   **/
/**                                                                          **/
/******************************************************************************/
#ifdef __{__UpperSnakeCaseName__}_SRC
#define EXTERN_{__UpperSnakeCaseName__} /* nothing */
#else
#define EXTERN_{__UpperSnakeCaseName__} extern
#endif

/******************************************************************************/
/**                                                                          **/
/**                     EXPORTED FUNCTIONS                                   **/
/**                                                                          **/
/******************************************************************************/

/******************************************************************************/
float32 ExportedFuncTemplate1(int16 input1, int16 input2);
/******************************************************************************/
/*
 * @brief  This is a commnet block for explaining function parameters and
 *         return values.
 * @param  input1 is ...
 * @param  input2 is ...
 *
 * return calculate value
 *
 */

#endif
/******************************************************************************/
/**                                                                          **/
/**                               EOF                                        **/
/**                                                                          **/
/******************************************************************************/
