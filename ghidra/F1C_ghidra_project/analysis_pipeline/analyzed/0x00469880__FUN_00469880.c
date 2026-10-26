// Function: FUN_00469880 @ 00469880
// Size (bytes): 60


undefined4 * __fastcall FUN_00469880(undefined4 *param_1)

{
  FUN_004893c0();
  param_1[0x60] = 0;
  param_1[0x61] = 0xffffffff;
  *param_1 = &PTR_FUN_0059f7c8;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  *(undefined1 *)(param_1 + 0x5f) = 1;
  FUN_00566650(0);
  return param_1;
}


