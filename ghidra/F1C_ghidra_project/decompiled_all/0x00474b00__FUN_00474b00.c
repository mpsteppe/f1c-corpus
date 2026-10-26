// Function: FUN_00474b00 @ 00474b00
// Strings:  [Cable/DSL/WiFi/Mobile, Modem 56K, Modem < 56K]


undefined4 * __fastcall FUN_00474b00(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a3f00;
  param_1[199] = &DAT_007d0e50;
  param_1[0xca] = 0;
  param_1[0xc9] = 4;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  param_1[0xcd] = 0x194;
  FUN_00486f30(s_Modem_<_56K_005c70d4,0xffffffff);
  FUN_00486f30(s_Modem_56K_005c70ca,0xffffffff);
  FUN_00486f30(&DAT_005c70c5,0xffffffff);
  FUN_00486f30(s_Cable_DSL_WiFi_Mobile_005c70ad,0xffffffff);
  FUN_00486f30(&DAT_005c70a9,0xffffffff);
  FUN_004670e0();
  return param_1;
}


