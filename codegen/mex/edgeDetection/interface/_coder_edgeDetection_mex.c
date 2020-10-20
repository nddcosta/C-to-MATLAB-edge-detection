/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_edgeDetection_mex.c
 *
 * Code generation for function '_coder_edgeDetection_mex'
 *
 */

/* Include files */
#include "_coder_edgeDetection_mex.h"
#include "_coder_edgeDetection_api.h"
#include "edgeDetection.h"
#include "edgeDetection_data.h"
#include "edgeDetection_initialize.h"
#include "edgeDetection_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void edgeDetection_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
void edgeDetection_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[2])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        13, "edgeDetection");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "edgeDetection");
  }

  /* Call the function. */
  edgeDetection_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(edgeDetection_atexit);

  /* Module initialization. */
  edgeDetection_initialize();

  /* Dispatch the entry-point. */
  edgeDetection_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  edgeDetection_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_edgeDetection_mex.c) */
