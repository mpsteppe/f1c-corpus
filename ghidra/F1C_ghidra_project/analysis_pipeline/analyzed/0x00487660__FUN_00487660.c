// Function: FUN_00487660 @ 00487660
// Size (bytes): 40


undefined4 * __thiscall FUN_00487660(undefined4 *param_1,undefined1 param_2,undefined1 param_3)

{
  FUN_00485e30();
  *(undefined1 *)(param_1 + 0x38) = param_2;
  *param_1 = &PTR_FUN_005aba18;
  *(undefined1 *)((int)param_1 + 0xe1) = param_3;
  return param_1;
}


