// Function: FUN_00474980 @ 00474980
// Strings:  [Swingman, Cockpit, TV Cockpit]


undefined4 * __fastcall FUN_00474980(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a3d80;
  param_1[199] = &DAT_007cfdc4;
  param_1[0xc9] = 3;
  param_1[0xca] = 0;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  param_1[0xcd] = 399;
  FUN_00486f30(s_TV_Cockpit_005c709e,0xffffffff);
  FUN_00486f30(s_Cockpit_005c7096,0xffffffff);
  FUN_00486f30(&DAT_005c7091,0xffffffff);
  FUN_00486f30(s_Swingman_005c7088,0xffffffff);
  FUN_004670e0();
  return param_1;
}


