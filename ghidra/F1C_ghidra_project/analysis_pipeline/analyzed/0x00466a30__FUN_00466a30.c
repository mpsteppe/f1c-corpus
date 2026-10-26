// Function: FUN_00466a30 @ 00466a30
// Size (bytes): 59


undefined4 * __thiscall
FUN_00466a30(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_004668e0(param_3,param_4);
  *param_1 = &PTR_FUN_0059f380;
  param_1[0x41] = 0x3f000000;
  *(undefined1 *)(param_1 + 0x40) = 0;
  param_1[0x42] = param_2;
  return param_1;
}


