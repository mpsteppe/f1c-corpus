// Function: FUN_004722a0 @ 004722a0
// Strings:  [Sawtooth down, Sawtooth up, Triangle, Square]


undefined4 * __fastcall FUN_004722a0(undefined4 *param_1)

{
  FUN_00466d60(1);
  *param_1 = &PTR_FUN_005a1d40;
  param_1[199] = &DAT_007d22f0;
  param_1[0xc9] = 4;
  param_1[0xca] = 0;
  param_1[0xcb] = 1;
  param_1[0xcc] = 1;
  FUN_00486f30(&DAT_005c6f28,0xffffffff);
  FUN_00486f30(s_Square_005c6f20,0xffffffff);
  FUN_00486f30(s_Triangle_005c6f14,0xffffffff);
  FUN_00486f30(s_Sawtooth_up_005c6f08,0xffffffff);
  FUN_00486f30(s_Sawtooth_down_005c6ef8,0xffffffff);
  param_1[0xcd] = 0x100;
  return param_1;
}


