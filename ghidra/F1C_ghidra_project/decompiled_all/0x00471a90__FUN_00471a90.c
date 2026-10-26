// Function: FUN_00471a90 @ 00471a90
// Strings:  [Upshifts, Downshifts]


undefined4 * __fastcall FUN_00471a90(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a15c0;
  param_1[199] = &DAT_007ce8a4;
  param_1[0xc9] = 3;
  param_1[0xca] = 0;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  param_1[0xcd] = 0xf6;
  FUN_00486f30(&PTR_DAT_005be704,0xffffffff);
  FUN_00486f30(s_Upshifts_005c32b0,0xffffffff);
  FUN_00486f30(s_Downshifts_005c32bc,0xffffffff);
  FUN_00486f30(&DAT_005c32c8,0xffffffff);
  FUN_004670e0();
  return param_1;
}


