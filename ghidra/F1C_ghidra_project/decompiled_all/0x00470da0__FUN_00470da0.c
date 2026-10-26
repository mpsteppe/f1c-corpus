// Function: FUN_00470da0 @ 00470da0
// Strings:  [Selected Season, Monsoon, Raining, Overcast, Changing Weather]


undefined4 * __fastcall FUN_00470da0(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a09c0;
  param_1[0xce] = &DAT_007cf080 + DAT_007d0410 * 9;
  param_1[0xc9] = 5;
  param_1[0xca] = 0;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  param_1[0xcd] = 0x19b;
  FUN_00486f30(s_Changing_Weather_005c6e9c,0xffffffff);
  FUN_00486f30(s_Selected_Season_005c6e58,0xffffffff);
  FUN_00486f30(&PTR_DAT_005c6e98,0xffffffff);
  FUN_00486f30(s_Overcast_005c6e8c,0xffffffff);
  FUN_00486f30(s_Raining_005c6e84,0xffffffff);
  FUN_00486f30(s_Monsoon_005c6e7c,0xffffffff);
  return param_1;
}


