// Function: FUN_00471490 @ 00471490
// Strings:  [Custom, Medium]


undefined4 * __fastcall FUN_00471490(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a0d80;
  param_1[0xcd] = 0xeb;
  FUN_00486f30(s_Custom_005c670c,0xffffffff);
  FUN_00486f30(&PTR_DAT_005be704,0xffffffff);
  FUN_00486f30(&PTR_DAT_005c32a4,0xffffffff);
  FUN_00486f30(s_Medium_005c6eb8,0xffffffff);
  FUN_00486f30(&DAT_005c32a8,0xffffffff);
  FUN_00486f30(&DAT_005c6eb0,0xffffffff);
  param_1[199] = &DAT_007ce73c;
  param_1[0xc9] = 5;
  param_1[0xca] = 1;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  return param_1;
}


