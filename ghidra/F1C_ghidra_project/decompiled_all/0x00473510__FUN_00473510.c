// Function: FUN_00473510 @ 00473510
// Strings:  [Selected Season, Random]


undefined4 * __fastcall FUN_00473510(undefined4 *param_1)

{
  FUN_0048c070(1);
  *param_1 = &PTR_FUN_005a2a00;
  param_1[199] = 0xffffffff;
  FUN_00486f30(s_Random_005c7064,0xffffffff);
  FUN_00486f30(s_Selected_Season_005c6e58,0xffffffff);
  return param_1;
}


