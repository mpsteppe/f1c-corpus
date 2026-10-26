// Function: FUN_00488b00 @ 00488b00
// Size (bytes): 47


undefined4 * __thiscall FUN_00488b00(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00485e30();
  param_1[0x38] = param_2;
  *param_1 = &PTR_LAB_005abc28;
  *(undefined1 *)(param_1 + 0x3a) = 1;
  param_1[0x39] = param_3;
  return param_1;
}


