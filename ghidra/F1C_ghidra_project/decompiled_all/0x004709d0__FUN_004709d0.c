// Function: FUN_004709d0 @ 004709d0
// Strings:  [Selected Season, Time Scaled, Normal]


undefined4 * __fastcall FUN_004709d0(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a0600;
  param_1[199] = &DAT_007ceaec;
  param_1[0xc9] = 3;
  param_1[0xca] = 0;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  param_1[0xcd] = 0x192;
  FUN_00486f30(&PTR_DAT_005be704,0xffffffff);
  FUN_00486f30(s_Normal_005c6e74,0xffffffff);
  FUN_00486f30(s_Time_Scaled_005c6e68,0xffffffff);
  FUN_00486f30(s_Selected_Season_005c6e58,0xffffffff);
  return param_1;
}


