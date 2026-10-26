// Function: FUN_004d89d0 @ 004d89d0
// Size (bytes): 87


void __fastcall FUN_004d89d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffffffff;
  param_1[0x37] = DAT_005acf34;
  *(undefined1 *)(param_1 + 0x38) = 1;
  param_1[0x39] = 0x3f800000;
  param_1[0x3a] = 0x3f800000;
  param_1[3] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  puVar2 = param_1 + 4;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x36] = 0;
  return;
}


