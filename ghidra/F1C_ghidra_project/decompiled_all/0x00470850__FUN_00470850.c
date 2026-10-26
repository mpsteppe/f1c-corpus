// Function: FUN_00470850 @ 00470850
// Strings:  [Selected Season, Time Scaled, Normal]


undefined4 * __fastcall FUN_00470850(undefined4 *param_1)

{
  FUN_0048c070(1);
  *param_1 = &PTR_FUN_005a0540;
  param_1[199] = 0x191;
  FUN_00486f30(&PTR_DAT_005be704,0xffffffff);
  FUN_00486f30(s_Normal_005c6e74,0xffffffff);
  FUN_00486f30(s_Time_Scaled_005c6e68,0xffffffff);
  FUN_00486f30(s_Selected_Season_005c6e58,0xffffffff);
  FUN_00470960();
  return param_1;
}


