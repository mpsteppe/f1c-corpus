// Function: FUN_00471cc0 @ 00471cc0
// Strings:  [Game Pad, Joystick, Wheel]


undefined4 * __fastcall FUN_00471cc0(undefined4 *param_1)

{
  FUN_0048c070(1);
  *param_1 = &PTR_FUN_005a18c0;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0;
  param_1[199] = 0xfa;
  FUN_00486f30(&DAT_005c6f64,0xffffffff);
  FUN_00486f30(s_Wheel_005c6f5c,0xffffffff);
  FUN_00486f30(s_Joystick_005c6f50,0xffffffff);
  FUN_00486f30(s_Game_Pad_005c6f44,0xffffffff);
  FUN_00471dc0();
  return param_1;
}


