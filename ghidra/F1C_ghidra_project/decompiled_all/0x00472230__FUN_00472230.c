// Function: FUN_00472230 @ 00472230
// Strings:  [Steering, Throttle]


undefined4 * __fastcall FUN_00472230(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a1c80;
  param_1[199] = &DAT_007d2044;
  param_1[0xc9] = 2;
  param_1[0xca] = 0;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  FUN_00486f30(s_Throttle_005c6f6c,0xffffffff);
  FUN_00486f30(s_Steering_005c6f30,0xffffffff);
  param_1[0xcd] = 0xff;
  return param_1;
}


