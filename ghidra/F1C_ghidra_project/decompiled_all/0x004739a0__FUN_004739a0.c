// Function: FUN_004739a0 @ 004739a0
// Strings:  [Imperial, Metric]


undefined4 * __fastcall FUN_004739a0(undefined4 *param_1)

{
  FUN_0048c070(1);
  *param_1 = &PTR_FUN_005a2d00;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0;
  param_1[199] = 0x115;
  FUN_00486f30(s_Metric_005c7078,0xffffffff);
  FUN_00486f30(s_Imperial_005c706c,0xffffffff);
  return param_1;
}


