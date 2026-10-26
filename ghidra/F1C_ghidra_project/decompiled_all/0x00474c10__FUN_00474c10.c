// Function: FUN_00474c10 @ 00474c10
// Strings:  [Disallowed, Allowed]


undefined4 * __thiscall FUN_00474c10(undefined4 *param_1,undefined4 param_2)

{
  FUN_0048c070(1);
  *param_1 = &PTR_FUN_005a4080;
  param_1[199] = param_2;
  FUN_00486f30(s_Allowed_005c70e0,0xffffffff);
  FUN_00486f30(s_Disallowed_005c32cc,0xffffffff);
  return param_1;
}


