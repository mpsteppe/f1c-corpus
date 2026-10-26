// Function: FUN_00472890 @ 00472890
// Strings:  [Custom, Selected Season, Casual]


undefined4 * __fastcall FUN_00472890(undefined4 *param_1)

{
  FUN_0048c070(1);
  *param_1 = &PTR_FUN_005a2100;
  param_1[199] = 0x105;
  FUN_00486f30(s_Custom_005c670c,0xffffffff);
  FUN_00486f30(s_Casual_005c6fa4,0xffffffff);
  FUN_00486f30(s_Selected_Season_005c6e58,0xffffffff);
  FUN_00472930();
  return param_1;
}


