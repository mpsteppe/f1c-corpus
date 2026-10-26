// Function: FUN_004731d0 @ 004731d0
// Strings:  [Custom, Veteran, Professional, Intermediate, Novice, Beginner]


undefined4 * __fastcall FUN_004731d0(undefined4 *param_1)

{
  FUN_0048c070(1);
  *param_1 = &PTR_FUN_005a2640;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[199] = 0x10c;
  FUN_00486f30(s_Custom_005c670c,0xffffffff);
  FUN_00486f30(s_Beginner_005c7058,0xffffffff);
  FUN_00486f30(s_Novice_005c7050,0xffffffff);
  FUN_00486f30(s_Intermediate_005c7040,0xffffffff);
  FUN_00486f30(s_Professional_005c7030,0xffffffff);
  FUN_00486f30(s_Veteran_005c7028,0xffffffff);
  FUN_004732d0();
  return param_1;
}


