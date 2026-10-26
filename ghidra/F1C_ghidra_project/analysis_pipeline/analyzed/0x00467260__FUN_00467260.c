// Function: FUN_00467260 @ 00467260
// Size (bytes): 86


undefined4 * __thiscall FUN_00467260(undefined4 *param_1,int param_2,undefined4 param_3)

{
  FUN_0048c070(0);
  param_1[0xc9] = param_2;
  *param_1 = &PTR_FUN_0059f4f8;
  param_1[200] = &DAT_007c6270 + param_2 * 0x40;
  param_1[199] = param_3;
  param_1[0xca] = 0xb;
  param_1[0xcb] = 4;
  *(undefined1 *)((int)param_1 + 0x305) = 0;
  return param_1;
}


