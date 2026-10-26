// Function: FUN_0048c070 @ 0048c070
// Size (bytes): 95


undefined4 * __thiscall FUN_0048c070(undefined4 *param_1,undefined4 param_2)

{
  FUN_0048b420(0,0,0,0,0,0);
  param_1[0xc2] = param_2;
  *(undefined1 *)(param_1 + 0xc1) = 1;
  *(undefined1 *)((int)param_1 + 0x305) = 1;
  param_1[0xc5] = 1;
  *param_1 = &PTR_FUN_005abf88;
  param_1[0xc6] = 0;
  param_1[0xc3] = 0;
  param_1[0xc4] = 0;
  return param_1;
}


