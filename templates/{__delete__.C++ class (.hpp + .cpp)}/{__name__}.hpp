/*
                             *******************
******************************* C++ HEADER FILE *******************************
**                           *******************
**
** project   : {__project__}
** filename  : {__name__}.hpp
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

#ifndef {__UpperSnakeCaseName__}_HPP_
#define {__UpperSnakeCaseName__}_HPP_

/******************************************************************************/
/**                                                                          **/
/**                     MODULES USED                                         **/
/**                                                                          **/
/******************************************************************************/
/* Same portable types as the C modules; no device headers in interfaces. */
#include "project_types.h"

/******************************************************************************/
/**                                                                          **/
/**                     CLASS DECLARATION                                    **/
/**                                                                          **/
/******************************************************************************/
/*
 * Embedded rules for this class: no exceptions, no RTTI, no heap allocation,
 * no virtual calls on the ISR path. Instances are allocated statically by
 * the caller; init() is explicit so the start-up order stays under control.
 */
class {__PascalCaseName__}
{
public:
    /* Configuration, set once by init(). */
    struct Params
    {
        float32 gain;           /* example parameter */
    };

    {__PascalCaseName__}();

    /*
     * @brief  Copy the parameters and reset the state.
     * @param  params configuration
     */
    void init(const Params &params);

    /*
     * @brief  Clear the internal state, keeping the parameters.
     */
    void reset();

    /*
     * @brief  Execute one step. May be called from an ISR: must not block.
     * @param  input  ...
     *
     * return output of this step
     */
    float32 run(float32 input);

    float32 output() const { return out_; }

private:
    Params  params_;
    float32 out_;               /* example state */
};

#endif /* {__UpperSnakeCaseName__}_HPP_ */
/******************************************************************************/
/**                                                                          **/
/**                               EOF                                        **/
/**                                                                          **/
/******************************************************************************/
