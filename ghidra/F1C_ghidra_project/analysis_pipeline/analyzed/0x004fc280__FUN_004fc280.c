// Function: FUN_004fc280 @ 004fc280
// Size (bytes): 102


void __fastcall FUN_004fc280(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  param_1[0x11] = 0xffffffff;
  *param_1 = 0;
  iVar2 = 3;
  puVar1 = param_1;
  do {
    puVar1 = puVar1 + 4;
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (param_1[0x13] != 0) {
    FUN_00587bcf(param_1[0x13]);
  }
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  param_1[0x1c] = 0;
  if (param_1[0x20] != 0) {
    FUN_00587bcf(param_1[0x20]);
  }
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  *(undefined1 *)(param_1 + 0x21) = 0;
  param_1[0x29] = 0;
  return;
}


