// Function: FUN_00471c50 @ 00471c50
// Strings:  [Steering, Braking]


undefined4 * __fastcall FUN_00471c50(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a1800;
  param_1[199] = &DAT_007d2068;
  param_1[0xc9] = 2;
  param_1[0xca] = 0;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  FUN_00486f30(s_Braking_005c6f3c,0xffffffff);
  FUN_00486f30(s_Steering_005c6f30,0xffffffff);
  param_1[0xcd] = 0xf9;
  return param_1;
}


