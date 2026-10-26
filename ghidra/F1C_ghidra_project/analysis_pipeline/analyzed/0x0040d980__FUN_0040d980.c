// Function: FUN_0040d980 @ 0040d980
// Size (bytes): 121


undefined4 * __fastcall FUN_0040d980(undefined4 *param_1)

{
  FUN_00434860();
  FUN_00567a00();
  param_1[1] = &DAT_005ea510;
  param_1[2] = &DAT_005ea618;
  param_1[3] = &DAT_005eb978;
  param_1[4] = &DAT_005ec6d0;
  *param_1 = 0;
  FUN_00567f10();
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0x7c;
  param_1[0x25] = 0xffffffff;
  return param_1;
}


