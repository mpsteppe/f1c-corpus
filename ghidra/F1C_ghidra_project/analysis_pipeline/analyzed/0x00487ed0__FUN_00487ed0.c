// Function: FUN_00487ed0 @ 00487ed0
// Size (bytes): 50


undefined4 * __thiscall FUN_00487ed0(undefined4 *param_1,undefined1 param_2,undefined1 param_3)

{
  FUN_00485e30();
  *(undefined1 *)(param_1 + 0x38) = param_2;
  *param_1 = &PTR_FUN_005abac8;
  *(undefined1 *)((int)param_1 + 0xe1) = param_3;
  param_1[0x21] = 0;
  return param_1;
}


