// Function: FUN_00586e50 @ 00586e50
// Size (bytes): 61


undefined4 * __thiscall FUN_00586e50(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  FUN_00587620(param_2 + 2);
  FUN_0059b3b0(param_2 + 5);
  param_1[0x13] = param_2[0x13];
  param_1[0x14] = param_2[0x14];
  return param_1;
}


