/*
                             *******************
******************************* C SOURCE FILE *********************************
                             *******************
**
** project   : {__project__}
** filename  : mex_{__name__}.c
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
** VERSION HISTORY:
** ----------------
**
** Version     : 0.0.0.1
** Date        : {__date__}
** Created by  : {__author__} ({__email__})
** Revised by  : {__author__}
** Description : Original version.
**
*******************************************************************************
**
** MEX function wrapping the C module {__name__}.c/.h, callable from MATLAB:
**
**     y = mex_{__name__}(gain, u)
**
** Initializes one instance with gain, then calls {__PascalCaseName__}_run() for each
** element of u in order (u = input sequence, one sample per element).
** y has the size of u. No state is kept between calls.
**
** Build (in MATLAB, R2018a or later):  mex -R2018a mex_{__name__}.c {__name__}.c
**
*******************************************************************************

*/

/******************************************************************************/
/**                                                                          **/
/**                     MODULES USED                                         **/
/**                                                                          **/
/******************************************************************************/
#include "mex.h"
#include "{__name__}.h"

/******************************************************************************/
/**                                                                          **/
/**                     DEFINITIONS AND MACROS                               **/
/**                                                                          **/
/******************************************************************************/
#if !MX_HAS_INTERLEAVED_COMPLEX
#error "Build with the interleaved complex API: mex -R2018a ..."
#endif

#define IS_REAL_DOUBLE(p)   (mxIsDouble(p) && !mxIsComplex(p) && !mxIsSparse(p))

/******************************************************************************/
/**                                                                          **/
/**                     MEX GATEWAY                                          **/
/**                                                                          **/
/******************************************************************************/

/******************************************************************************/
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
/******************************************************************************/
{
    {__PascalCaseName__}_Obj obj;
    {__PascalCaseName__}_Params params;
    const mxDouble *u;
    mxDouble *y;
    mwSize i, n;

    if (nrhs != 2) {
        mexErrMsgIdAndTxt("mex_{__name__}:nrhs", "Usage: y = mex_{__name__}(gain, u)");
    }
    if (nlhs > 1) {
        mexErrMsgIdAndTxt("mex_{__name__}:nlhs", "Too many output arguments.");
    }
    if (!IS_REAL_DOUBLE(prhs[0]) || mxGetNumberOfElements(prhs[0]) != 1) {
        mexErrMsgIdAndTxt("mex_{__name__}:gain", "gain must be a real double scalar.");
    }
    if (!IS_REAL_DOUBLE(prhs[1])) {
        mexErrMsgIdAndTxt("mex_{__name__}:u", "u must be a real double array.");
    }

    params.gain = (float32) mxGetScalar(prhs[0]);
    {__PascalCaseName__}_init(&obj, &params);

    u = mxGetDoubles(prhs[1]);
    n = mxGetNumberOfElements(prhs[1]);
    plhs[0] = mxCreateDoubleMatrix(mxGetM(prhs[1]), mxGetN(prhs[1]), mxREAL);
    y = mxGetDoubles(plhs[0]);

    /* The module computes in float32, matching the target's precision. */
    for (i = 0; i < n; i++) {
        y[i] = (mxDouble) {__PascalCaseName__}_run(&obj, (float32) u[i]);
    }
}

/******************************************************************************/
/**                                                                          **/
/**                               EOF                                        **/
/**                                                                          **/
/******************************************************************************/
