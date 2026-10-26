// Function: FUN_00471a00 @ 00471a00
// Size (bytes): 129


undefined4 * __fastcall FUN_00471a00(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a1500;
  param_1[199] = &DAT_007ce6ac;
  param_1[0xc9] = 2;
  param_1[0xca] = 0;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  param_1[0xcd] = 0xf5;
  FUN_00486f30(&PTR_DAT_005be704,0xffffffff);
  FUN_00486f30(&PTR_DAT_005c32a4,0xffffffff);
  FUN_00486f30(&DAT_005c32a8,0xffffffff);
  FUN_004670e0();
  return param_1;
}


