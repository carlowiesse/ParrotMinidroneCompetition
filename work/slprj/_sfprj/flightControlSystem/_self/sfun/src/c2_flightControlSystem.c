/* Include files */

#include "flightControlSystem_sfun.h"
#include "c2_flightControlSystem.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "flightControlSystem_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[4] = { "nargin", "nargout", "u", "y" };

static const char_T c2_cv0[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
  'l', 'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

/* Function Declarations */
static void initialize_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void enable_c2_flightControlSystem(SFc2_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_b_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_y, const char_T *c2_identifier, boolean_T
  c2_c_y[19200]);
static void c2_c_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T c2_b_y[19200]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_bwmorph(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_bwin[19200], real_T c2_varargin_1, boolean_T c2_bw[19200]);
static void c2_bwmorphApplyOnce(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_bw[19200], boolean_T c2_b_bw[19200]);
static void c2_lutthin1(SFc2_flightControlSystemInstanceStruct *chartInstance);
static void c2_bwlookup(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_bwin[19200], boolean_T c2_B[19200]);
static void c2_lutthin2(SFc2_flightControlSystemInstanceStruct *chartInstance);
static void c2_b_bwlookup(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_bwin[19200], boolean_T c2_B[19200]);
static boolean_T c2_isequal(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_varargin_1[19200], boolean_T c2_varargin_2[19200]);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_flightControlSystem, const
  char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_bwmorphApplyOnce(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_bw[19200]);
static void init_dsm_address_info(SFc2_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c2_fEmlrtCtx, "Image_Toolbox", 2);
  setLegacyDebuggerFlag(chartInstance->S, true);
  setDebuggerFlag(chartInstance->S, true);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_flightControlSystem(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_flightControlSystem = 0U;
}

static void initialize_params_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_flightControlSystem(SFc2_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void ext_mode_exec_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createcellmatrix(2, 1), false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", *chartInstance->c2_y, 11, 0U, 1U, 0U,
    2, 120, 160), false);
  sf_mex_setcell(c2_b_y, 0, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_flightControlSystem;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_b_y, 1, c2_d_y);
  sf_mex_assign(&c2_st, c2_b_y, false);
  return c2_st;
}

static void set_sim_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_b_u;
  boolean_T c2_bv0[19200];
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 0)),
                        "y", c2_bv0);
  for (c2_i0 = 0; c2_i0 < 19200; c2_i0++) {
    (*chartInstance->c2_y)[c2_i0] = c2_bv0[c2_i0];
  }

  chartInstance->c2_is_active_c2_flightControlSystem = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 1)),
     "is_active_c2_flightControlSystem");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_flightControlSystem(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c2_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void sf_gateway_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  uint32_T c2_debug_family_var_map[4];
  boolean_T c2_b_u[19200];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_b_y[19200];
  int32_T c2_i4;
  boolean_T c2_c_u[19200];
  boolean_T c2_bv1[19200];
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0, chartInstance->c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 19200; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_u)[c2_i1], 0U);
  }

  for (c2_i2 = 0; c2_i2 < 19200; c2_i2++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U, (real_T)
                      (*chartInstance->c2_u)[c2_i2]);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i3 = 0; c2_i3 < 19200; c2_i3++) {
    c2_b_u[c2_i3] = (*chartInstance->c2_u)[c2_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_u, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_y, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  for (c2_i4 = 0; c2_i4 < 19200; c2_i4++) {
    c2_c_u[c2_i4] = c2_b_u[c2_i4];
  }

  c2_bwmorph(chartInstance, c2_c_u, rtInf, c2_bv1);
  for (c2_i5 = 0; c2_i5 < 19200; c2_i5++) {
    c2_b_y[c2_i5] = c2_bv1[c2_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i6 = 0; c2_i6 < 19200; c2_i6++) {
    (*chartInstance->c2_y)[c2_i6] = c2_b_y[c2_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i7 = 0; c2_i7 < 19200; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_y)[c2_i7], 1U);
  }

  for (c2_i8 = 0; c2_i8 < 19200; c2_i8++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U, (real_T)
                      (*chartInstance->c2_y)[c2_i8]);
  }
}

static void mdl_start_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  static const uint32_T c2_decisionTxtEndIdx = 0U;
  chartInstance->c2_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    7U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 48);
}

static void initSimStructsc2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_b_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargin;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_nargin = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargin), &c2_thisId);
  sf_mex_destroy(&c2_nargin);
  *(real_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i9;
  int32_T c2_i10;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i11;
  boolean_T c2_b_u[19200];
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 160; c2_i10++) {
    for (c2_i11 = 0; c2_i11 < 120; c2_i11++) {
      c2_b_u[c2_i11 + c2_i9] = (*(boolean_T (*)[19200])c2_inData)[c2_i11 + c2_i9];
    }

    c2_i9 += 120;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 11, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_b_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_y, const char_T *c2_identifier, boolean_T
  c2_c_y[19200])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_b_y);
}

static void c2_c_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T c2_b_y[19200])
{
  boolean_T c2_bv2[19200];
  int32_T c2_i12;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_bv2, 1, 11, 0U, 1, 0U, 2,
                120, 160);
  for (c2_i12 = 0; c2_i12 < 19200; c2_i12++) {
    c2_b_y[c2_i12] = c2_bv2[c2_i12];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_c_y[19200];
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_b_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_b_y);
  c2_i13 = 0;
  for (c2_i14 = 0; c2_i14 < 160; c2_i14++) {
    for (c2_i15 = 0; c2_i15 < 120; c2_i15++) {
      (*(boolean_T (*)[19200])c2_outData)[c2_i15 + c2_i13] = c2_c_y[c2_i15 +
        c2_i13];
    }

    c2_i13 += 120;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_bwmorph(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_bwin[19200], real_T c2_varargin_1, boolean_T c2_bw[19200])
{
  real_T c2_n;
  int32_T c2_i16;
  real_T c2_iter;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  boolean_T c2_last_aout[19200];
  int32_T c2_i20;
  boolean_T c2_b_bw[19200];
  boolean_T exitg1;
  c2_n = c2_varargin_1;
  if (c2_n < 1.0) {
    for (c2_i16 = 0; c2_i16 < 19200; c2_i16++) {
      c2_bw[c2_i16] = c2_bwin[c2_i16];
    }
  } else if (c2_n == 1.0) {
    for (c2_i17 = 0; c2_i17 < 19200; c2_i17++) {
      c2_bw[c2_i17] = c2_bwin[c2_i17];
    }

    c2_b_bwmorphApplyOnce(chartInstance, c2_bw);
    0;
  } else {
    c2_iter = 0.0;
    for (c2_i18 = 0; c2_i18 < 19200; c2_i18++) {
      c2_bw[c2_i18] = c2_bwin[c2_i18];
    }

    exitg1 = false;
    while ((!exitg1) && (c2_iter < c2_n)) {
      for (c2_i19 = 0; c2_i19 < 19200; c2_i19++) {
        c2_last_aout[c2_i19] = c2_bw[c2_i19];
      }

      c2_b_bwmorphApplyOnce(chartInstance, c2_bw);
      0;
      c2_iter++;
      for (c2_i20 = 0; c2_i20 < 19200; c2_i20++) {
        c2_b_bw[c2_i20] = c2_bw[c2_i20];
      }

      if (c2_isequal(chartInstance, c2_last_aout, c2_b_bw)) {
        exitg1 = true;
      }
    }
  }
}

static void c2_bwmorphApplyOnce(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_bw[19200], boolean_T c2_b_bw[19200])
{
  int32_T c2_i21;
  for (c2_i21 = 0; c2_i21 < 19200; c2_i21++) {
    c2_b_bw[c2_i21] = c2_bw[c2_i21];
  }

  c2_b_bwmorphApplyOnce(chartInstance, c2_b_bw);
  0;
}

static void c2_lutthin1(SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_x;
  static real_T c2_b_x[512] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

  boolean_T c2_b;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  (void)chartInstance;
  for (c2_k = 0; c2_k < 512; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_x = c2_b_x[(int32_T)c2_b_k - 1];
    c2_b = muDoubleScalarIsNaN(c2_x);
    if (c2_b) {
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_b_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_c_y)));
    }
  }
}

static void c2_bwlookup(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_bwin[19200], boolean_T c2_B[19200])
{
  int32_T c2_i22;
  real_T c2_dv0[2];
  static boolean_T c2_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, true, true, false, false, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, false,
    false, true, true, false, false, true, true, false, false, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, false, false, false, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true, true, true,
    true, true, false, false, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, false, false, false, true, false, false, true, true, false, false,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, false, false, true, false, false, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true };

  (void)chartInstance;
  for (c2_i22 = 0; c2_i22 < 2; c2_i22++) {
    c2_dv0[c2_i22] = 120.0 + 40.0 * (real_T)c2_i22;
  }

  bwlookup_tbb_boolean(c2_bwin, c2_dv0, 2.0, c2_lut, 512.0, c2_B);
}

static void c2_lutthin2(SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_x;
  static real_T c2_b_x[512] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
    1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0 };

  boolean_T c2_b;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  (void)chartInstance;
  for (c2_k = 0; c2_k < 512; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_x = c2_b_x[(int32_T)c2_b_k - 1];
    c2_b = muDoubleScalarIsNaN(c2_x);
    if (c2_b) {
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 19),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_b_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_c_y)));
    }
  }
}

static void c2_b_bwlookup(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_bwin[19200], boolean_T c2_B[19200])
{
  int32_T c2_i23;
  real_T c2_dv1[2];
  static boolean_T c2_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, true, false, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, false, true, true, true, false, false, true, true, false, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, false, false, true, false, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, true, true, true, false,
    false, true, true, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, false, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, false, false,
    true, false, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, true, true, true, false, false, true, true,
    false, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, false, true, false, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, true, true, true, false, false, true, true, false, true, true, true };

  (void)chartInstance;
  for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
    c2_dv1[c2_i23] = 120.0 + 40.0 * (real_T)c2_i23;
  }

  bwlookup_tbb_boolean(c2_bwin, c2_dv1, 2.0, c2_lut, 512.0, c2_B);
}

static boolean_T c2_isequal(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_varargin_1[19200], boolean_T c2_varargin_2[19200])
{
  boolean_T c2_p;
  boolean_T c2_b_p;
  int32_T c2_k;
  real_T c2_b_k;
  boolean_T c2_x1;
  boolean_T c2_x2;
  boolean_T c2_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c2_p = false;
  c2_b_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 19200)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_x1 = c2_varargin_1[(int32_T)c2_b_k - 1];
    c2_x2 = c2_varargin_2[(int32_T)c2_b_k - 1];
    c2_c_p = ((int32_T)c2_x1 == (int32_T)c2_x2);
    if (!c2_c_p) {
      c2_b_p = false;
      exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (!c2_b_p) {
  } else {
    c2_p = true;
  }

  return c2_p;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_b_y;
  int32_T c2_i24;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i24, 1, 6, 0U, 0, 0U, 0);
  c2_b_y = c2_i24;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_b_y;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_flightControlSystem, const
  char_T *c2_identifier)
{
  uint8_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_flightControlSystem), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_flightControlSystem);
  return c2_b_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_b_y = c2_u0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_b_bwmorphApplyOnce(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_bw[19200])
{
  int32_T c2_i25;
  boolean_T c2_b_bw[19200];
  boolean_T c2_image_iter1[19200];
  c2_lutthin1(chartInstance);
  for (c2_i25 = 0; c2_i25 < 19200; c2_i25++) {
    c2_b_bw[c2_i25] = c2_bw[c2_i25];
  }

  c2_bwlookup(chartInstance, c2_b_bw, c2_image_iter1);
  c2_lutthin2(chartInstance);
  c2_b_bwlookup(chartInstance, c2_image_iter1, c2_bw);
}

static void init_dsm_address_info(SFc2_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_u = (boolean_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_y = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
void sf_c2_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(97378398U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(516567507U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3653214652U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4131820789U);
}

mxArray *sf_c2_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  return(mxcell3p);
}

mxArray *sf_c2_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("bwlookup_tbb_boolean");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI6BcAsiqh4QILH/LtV3CgTD/E/g"
    "AC7ldAcT+En1kcn5hcklmWGp9sFJ+Wk5meUeKcn1dSlJ8TXFlckpoL8x8AZoIctg=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_flightControlSystemInstanceStruct *chartInstance =
      (SFc2_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _flightControlSystemMachineNumber_,
           2,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_flightControlSystemMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_flightControlSystemMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _flightControlSystemMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 160U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 160U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _flightControlSystemMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_flightControlSystemInstanceStruct *chartInstance =
      (SFc2_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_y);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s3Rth7WWo4R195uyboBNLZE";
}

static void sf_opaque_initialize_c2_flightControlSystem(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_flightControlSystem
    ((SFc2_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_flightControlSystem(void *chartInstanceVar)
{
  enable_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_flightControlSystem(void *chartInstanceVar)
{
  disable_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c2_flightControlSystem
    ((SFc2_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_flightControlSystem(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    finalize_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_flightControlSystem
      ((SFc2_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_flightControlSystem_get_post_codegen_info(void)
{
  return
    (
     "eNrtVTuP00AQdqJw4iQ4pTiJhiId0PEUUHHkJSLlLtH5HhLNsbEn8SrrXbOP3IWW30FPT4Gg5Q8"
     "gCn4HJSVjx0ksJ3buCJyEhKXNep1vvnnujFVo7Vr4bOH6ij8buF/FVbQmz5X4XEisyfeSdSs+Hy"
     "KIG79LJPGVlftw4sM+KMGMpoK3eF8shVHeBwncQWwgpM5iU9Q3jPJh03An5FPHHnU82xOGuVWUJ"
     "W6HszGyBUZ3kadOJTi6CeBqTwoz8JqMDGYWS31a88AZKuPnuaBA2yYIzVK7hmkaMGicgdPiShO0"
     "WM1tszXRUNNnmW6Gnip7ChR+wCjhS731iLIhwABrOAxc/O0YjU6lYY5HpK6CR0ag2nQYcQoOaU6"
     "q8I8e5UQLSQlr+KwWCi7a1mVoz65wgeUEBG2rSiDDQFCus/NvN9HTBic9BnXomUE2mw2vTZj8Iw"
     "qnIDPj1q+JEUgygA7PVBoFpHEWZWtWJYswTX04IvK5g/lT4GZWL1aOsgnmCQ5QIgsGkZMtdSDpC"
     "MObyWb8VliZq66M8SfJVqtgEVtjBHlZmLE1HV4jjKlM2IEI2jACFrHWiSb5sAnrclwgRUAGWLUu"
     "Bjks8ZrgLl3IhWOUFn4Ny63ebu9hp1hu3BzW4hpknziw7N4qxwPXMEBHsTPpSN0SUpeqMFsrUHF"
     "OV6Es1Te8firkEB3NufZzF8Ic5PWHsC/fteZ9+do5+vJULr3fTvAUlvBYiT2td7OYr7eIb4VYbi"
     "chdz2lp5SSC3FlXJ/f6O93ts2rztsvn959+/hhHf3vixebY1vx+ea0YczKabSQxRD7ImFXaQn/j"
     "QR/OT6rB/vae3x8LB7u33v6yIx7orrXftmI+H4W8u0tpuydfq+EnWscRH1ISaflxgM2PBMzGTsh"
     "/5OEvRsr4rEZf588P56tJ7+9k85jaYV8Gd/Gqbr9ff2VnfXkJ/q7K+yvpPJdiebTCcFpM4IT5/5"
     "Jn9GBFzY9LQWzx0qDv/UH7tlF5axLlvtX7Pwfl7/v33nm1mXLWZcst65/F53f68z7dJ+zUvjyGn"
     "r+Nj65/wIYD1Jv"
     );
}

static void mdlSetWorkWidths_c2_flightControlSystem(SimStruct *S)
{
  sf_set_work_widths(S, sf_c2_flightControlSystem_get_post_codegen_info());
  ssSetChecksum0(S,(3597957818U));
  ssSetChecksum1(S,(1618285609U));
  ssSetChecksum2(S,(3116598095U));
  ssSetChecksum3(S,(3015168669U));
}

static void mdlRTW_c2_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_flightControlSystem(SimStruct *S)
{
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc2_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_flightControlSystem;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_flightControlSystem;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_flightControlSystem;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0, NULL, NULL);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_flightControlSystem(chartInstance);
}

void c2_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
