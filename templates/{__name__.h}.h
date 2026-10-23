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

#ifndef {__UpperSnakeCaseName__}_H_
#define {__UpperSnakeCaseName__}_H_

/******************************************************************************/
/**                                                                          **/
/**                     MODULES USED                                         **/
/**                                                                          **/
/******************************************************************************/
/* Only portable types here; device headers (F28x_Project.h) belong in the
 * .c files of HAL/driver modules, not in module interfaces. */
#include "project_types.h"

#ifdef __cplusplus
extern "C" {
#endif

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
/* Configuration, set once by {__PascalCaseName__}_init(). */
typedef struct
{
    float32 gain;               /* example parameter */
} {__PascalCaseName__}_Params;

/* Module instance. Declared by the caller (static allocation, no malloc);
 * members are private: access them only through the functions below. */
typedef struct
{
    {__PascalCaseName__}_Params params;
    float32 out;                /* example state */
} {__PascalCaseName__}_Obj;

/******************************************************************************/
/**                                                                          **/
/**                     EXPORTED FUNCTIONS                                   **/
/**                                                                          **/
/******************************************************************************/

/******************************************************************************/
void {__PascalCaseName__}_init({__PascalCaseName__}_Obj *obj, const {__PascalCaseName__}_Params *params);
/******************************************************************************/
/*
 * @brief  Copy the parameters into the instance and reset its state.
 * @param  obj    instance to initialize
 * @param  params configuration
 */

/******************************************************************************/
void {__PascalCaseName__}_reset({__PascalCaseName__}_Obj *obj);
/******************************************************************************/
/*
 * @brief  Clear the internal state, keeping the parameters.
 * @param  obj    instance
 */

/******************************************************************************/
float32 {__PascalCaseName__}_run({__PascalCaseName__}_Obj *obj, float32 input);
/******************************************************************************/
/*
 * @brief  Execute one step. May be called from an ISR: must not block.
 * @param  obj    instance
 * @param  input  ...
 *
 * return output of this step
 */

#ifdef __cplusplus
}
#endif

#endif /* {__UpperSnakeCaseName__}_H_ */
/******************************************************************************/
/**                                                                          **/
/**                               EOF                                        **/
/**                                                                          **/
/******************************************************************************/
