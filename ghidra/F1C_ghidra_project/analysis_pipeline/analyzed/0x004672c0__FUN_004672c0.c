// Function: FUN_004672c0 @ 004672c0
// Size (bytes): 84


undefined4 * __thiscall FUN_004672c0(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  FUN_0048c070(0);
  param_1[200] = &DAT_007c5770 + (param_2 * 0xb + param_3) * 0x40;
  param_1[0xcb] = param_2;
  *param_1 = &PTR_FUN_0059f4f8;
  param_1[199] = param_4;
  param_1[0xc9] = 0x37;
  param_1[0xca] = param_3;
  return param_1;
}


