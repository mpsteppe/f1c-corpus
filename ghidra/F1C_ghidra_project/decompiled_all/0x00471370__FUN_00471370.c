// Function: FUN_00471370 @ 00471370
// Strings:  [One Formation Lap, No Formation Lap]


undefined4 * __fastcall FUN_00471370(undefined4 *param_1)

{
  FUN_0048c070(1);
  *param_1 = &PTR_FUN_005a0cc0;
  param_1[199] = 0x19a;
  FUN_00486f30(s_No_Formation_Lap_005c6ee4,0xffffffff);
  FUN_00486f30(s_One_Formation_Lap_005c6ed0,0xffffffff);
  FUN_00471440();
  return param_1;
}


