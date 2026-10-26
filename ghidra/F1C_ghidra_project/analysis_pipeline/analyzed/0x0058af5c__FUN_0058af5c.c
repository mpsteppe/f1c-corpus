// Function: FUN_0058af5c @ 0058af5c
// Size (bytes): 115


void FUN_0058af5c(uint param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (uint *)FUN_0058afd8();
  iVar3 = 0;
  *puVar1 = param_1;
  puVar1 = &DAT_005e65c0;
  do {
    if (param_1 == *puVar1) {
      puVar2 = (undefined4 *)FUN_0058afcf();
      *puVar2 = *(undefined4 *)(iVar3 * 8 + 0x5e65c4);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar1 < 0x5e6728);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    puVar2 = (undefined4 *)FUN_0058afcf();
    *puVar2 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    puVar2 = (undefined4 *)FUN_0058afcf();
    *puVar2 = 8;
    return;
  }
  puVar2 = (undefined4 *)FUN_0058afcf();
  *puVar2 = 0x16;
  return;
}


