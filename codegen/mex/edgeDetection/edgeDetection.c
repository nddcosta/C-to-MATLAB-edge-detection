/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * edgeDetection.c
 *
 * Code generation for function 'edgeDetection'
 *
 */

/* Include files */
#include "edgeDetection.h"
#include "rt_nonfinite.h"

/* Custom Source Code */
#include "edge_detection.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "edgeDetection",                     /* fcnName */
  "/Users/NathanCosta/Documents/MATLAB/edge_detection/edgeDetection.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 35,  /* lineNo */
  "fprintf",                           /* fcnName */
  "/Applications/MATLAB_R2019b.app/toolbox/eml/lib/matlab/iofun/fprintf.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 60,    /* lineNo */
  18,                                  /* colNo */
  "fprintf",                           /* fName */
  "/Applications/MATLAB_R2019b.app/toolbox/eml/lib/matlab/iofun/fprintf.m"/* pName */
};

static emlrtRSInfo c_emlrtRSI = { 60,  /* lineNo */
  "fprintf",                           /* fcnName */
  "/Applications/MATLAB_R2019b.app/toolbox/eml/lib/matlab/iofun/fprintf.m"/* pathName */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_feval_, const char_T *identifier);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_feval_, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_feval_), &thisId);
  emlrtDestroyArray(&a__output_of_feval_);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m, 3, pArrays, "feval", true, location);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void edgeDetection(const emlrtStack *sp, real_T x[119140], int32_T imsize[2],
                   real_T y[119140])
{
  const mxArray *b_y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 7 };

  static const char_T u[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *c_y;
  const mxArray *m1;
  const mxArray *d_y;
  const mxArray *m2;
  static const int32_T iv1[2] = { 1, 41 };

  static const char_T b_u[41] = { 'R', 'u', 'n', 'n', 'i', 'n', 'g', ' ', 'c',
    'u', 's', 't', 'o', 'm', ' ', 'e', 'd', 'g', 'e', ' ', 'd', 'e', 't', 'e',
    'c', 't', 'i', 'o', 'n', ' ', 'c', 'o', 'd', 'e', '.', '.', '.', '\\', 'n',
    '\\', 'n' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &b_emlrtRSI;
  b_y = NULL;
  m = emlrtCreateCharArray(2, iv);
  emlrtInitCharArrayR2013a(&b_st, 7, m, &u[0]);
  emlrtAssign(&b_y, m);
  c_y = NULL;
  m1 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&c_y, m1);
  d_y = NULL;
  m2 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(&b_st, 41, m2, &b_u[0]);
  emlrtAssign(&d_y, m2);
  c_st.site = &c_emlrtRSI;
  emlrt_marshallIn(&c_st, feval(&c_st, b_y, c_y, d_y, &emlrtMCI),
                   "<output of feval>");
  edge_detection(x, imsize, y);
}

/* End of code generation (edgeDetection.c) */
