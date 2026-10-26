// Function: FUN_004893c0 @ 004893c0
// Size (bytes): 125


undefined4 * __fastcall FUN_004893c0(undefined4 *param_1)

{
  FUN_00485e30();
  *(undefined1 *)(param_1 + 0x51) = 0;
  *(undefined1 *)((int)param_1 + 0x145) = 0;
  *(undefined1 *)((int)param_1 + 0x146) = 0;
  param_1[0x52] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x56] = 0;
  param_1[0x5b] = 0;
  *param_1 = &PTR_FUN_005abd78;
  *(undefined1 *)((int)param_1 + 0x131) = 1;
  param_1[0x50] = 5;
  param_1[0x5a] = 0xffffffff;
  param_1[0x5c] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x38) = 1;
  return param_1;
}


