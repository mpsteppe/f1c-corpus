// Function: FUN_0054fb90 @ 0054fb90
// Size (bytes): 125


undefined4 * __fastcall FUN_0054fb90(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_0053c2a0();
  puVar2 = param_1;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x11] = 1;
  param_1[0x12] = 1;
  param_1[0x10] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1b] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x1e] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  param_1[0x18] = 0x100000;
  param_1[0x19] = 4;
  param_1[0x1a] = 0xffffffff;
  return param_1;
}


