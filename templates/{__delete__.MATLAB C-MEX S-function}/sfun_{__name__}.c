/*
                             *******************
******************************* C SOURCE FILE *********************************
                             *******************
**
** project   : {__project__}
** filename  : sfun_{__name__}.c
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
** Level-2 C MEX S-function wrapping the C module {__name__}.c/.h for Simulink.
** Build (in MATLAB):  mex sfun_{__name__}.c {__name__}.c
** Block dialog parameters: gain, Ts (sample time, > 0); both non-tunable,
** because {__PascalCaseName__}_init() copies them once at simulation start.
**
*******************************************************************************

*/

#define S_FUNCTION_NAME  sfun_{__name__}
#define S_FUNCTION_LEVEL 2

/******************************************************************************/
/**                                                                          **/
/**                     MODULES USED                                         **/
/**                                                                          **/
/******************************************************************************/
#include <stdlib.h>
#include "simstruc.h"
#include "{__name__}.h"

/******************************************************************************/
/**                                                                          **/
/**                     DEFINITIONS AND MACROS                               **/
/**                                                                          **/
/******************************************************************************/
#define NUM_PARAMS          2
#define GAIN_PARAM(S)       ssGetSFcnParam(S, 0)
#define TS_PARAM(S)         ssGetSFcnParam(S, 1)

#define IS_REAL_SCALAR(p)   (mxIsDouble(p) && !mxIsComplex(p) && mxGetNumberOfElements(p) == 1)

/******************************************************************************/
/**                                                                          **/
/**                     S-FUNCTION METHODS                                   **/
/**                                                                          **/
/******************************************************************************/

#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
/******************************************************************************/
static void mdlCheckParameters(SimStruct *S)
/******************************************************************************/
{
    if (!IS_REAL_SCALAR(GAIN_PARAM(S))) {
        ssSetErrorStatus(S, "gain must be a real double scalar");
        return;
    }
    if (!IS_REAL_SCALAR(TS_PARAM(S)) || mxGetScalar(TS_PARAM(S)) <= 0.0) {
        ssSetErrorStatus(S, "Ts must be a positive real double scalar");
        return;
    }
}
#endif

/******************************************************************************/
static void mdlInitializeSizes(SimStruct *S)
/******************************************************************************/
{
    int_T i;

    ssSetNumSFcnParams(S, NUM_PARAMS);
#if defined(MATLAB_MEX_FILE)
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Simulink reports the parameter count mismatch */
    }
    mdlCheckParameters(S);
    if (ssGetErrorStatus(S) != NULL) {
        return;
    }
#endif
    for (i = 0; i < NUM_PARAMS; i++) {
        ssSetSFcnParamTunable(S, i, false);
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    if (!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortRequiredContiguous(S, 0, true);
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S, 1)) return;
    ssSetOutputPortWidth(S, 0, 1);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 1);        /* PWork[0]: {__PascalCaseName__}_Obj instance */
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* The instance lives behind a PWork pointer, which Simulink cannot save.
     * Releases before the operating-point API: ssSetSimStateCompliance(S, DISALLOW_SIM_STATE). */
    ssSetOperatingPointCompliance(S, DISALLOW_OPERATING_POINT);

    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

/******************************************************************************/
static void mdlInitializeSampleTimes(SimStruct *S)
/******************************************************************************/
{
    ssSetSampleTime(S, 0, mxGetScalar(TS_PARAM(S)));
    ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_START
#if defined(MDL_START)
/******************************************************************************/
static void mdlStart(SimStruct *S)
/******************************************************************************/
{
    /* calloc/free, not mxCalloc/mxFree: memory must outlive MEX calls. */
    {__PascalCaseName__}_Obj *obj = ({__PascalCaseName__}_Obj *) calloc(1, sizeof({__PascalCaseName__}_Obj));
    {__PascalCaseName__}_Params params;

    if (obj == NULL) {
        ssSetErrorStatus(S, "out of memory");
        return;
    }
    ssGetPWork(S)[0] = obj;

    params.gain = (float32) mxGetScalar(GAIN_PARAM(S));
    {__PascalCaseName__}_init(obj, &params);
}
#endif

/******************************************************************************/
static void mdlOutputs(SimStruct *S, int_T tid)
/******************************************************************************/
{
    {__PascalCaseName__}_Obj *obj = ({__PascalCaseName__}_Obj *) ssGetPWork(S)[0];
    const real_T *u = (const real_T *) ssGetInputPortSignal(S, 0);
    real_T *y = ssGetOutputPortRealSignal(S, 0);

    (void) tid;
    /* {__PascalCaseName__}_run() also advances the module state. With a single discrete
     * sample time this runs once per sample hit, like the target ISR.
     * The module computes in float32, matching the target's precision. */
    y[0] = (real_T) {__PascalCaseName__}_run(obj, (float32) u[0]);
}

/******************************************************************************/
static void mdlTerminate(SimStruct *S)
/******************************************************************************/
{
    free(ssGetPWork(S)[0]);     /* NULL if mdlStart failed: free(NULL) is a no-op */
    ssGetPWork(S)[0] = NULL;
}

/******************************************************************************/
/**                                                                          **/
/**                     SIMULINK INTERFACE                                   **/
/**                                                                          **/
/******************************************************************************/
#ifdef MATLAB_MEX_FILE
#include "simulink.c"           /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"            /* Code generation registration function */
#endif

/******************************************************************************/
/**                                                                          **/
/**                               EOF                                        **/
/**                                                                          **/
/******************************************************************************/
