// Function: FUN_004712e0 @ 004712e0
// Strings:  [Medium]


undefined4 * __fastcall FUN_004712e0(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a0c00;
  param_1[199] = &DAT_007cfb90;
  param_1[0xc9] = 3;
  param_1[0xca] = 0;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  param_1[0xcd] = 0x19c;
  FUN_00486f30(&PTR_DAT_005c32a4,0xffffffff);
  FUN_00486f30(s_Medium_005c6eb8,0xffffffff);
  FUN_00486f30(&DAT_005c32a8,0xffffffff);
  FUN_00486f30(&DAT_005c6eb0,0xffffffff);
  FUN_004670e0();
  return param_1;
}


