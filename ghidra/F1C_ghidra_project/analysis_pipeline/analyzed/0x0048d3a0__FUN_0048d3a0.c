// Function: FUN_0048d3a0 @ 0048d3a0
// Size (bytes): 61


undefined4 * __thiscall FUN_0048d3a0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00485e30();
  FUN_004883a0();
  param_1[0x3d] = param_2;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined1 *)((int)param_1 + 0xf1) = 0;
  *param_1 = &PTR_FUN_005ac118;
  param_1[0x3e] = param_3;
  return param_1;
}


