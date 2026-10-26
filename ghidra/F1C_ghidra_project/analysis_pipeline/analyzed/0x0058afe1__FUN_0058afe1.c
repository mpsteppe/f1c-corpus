// Function: FUN_0058afe1 @ 0058afe1
// Size (bytes): 100


void FUN_0058afe1(int param_1)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  FUN_0058c1b1(param_1);
  FUN_0058a05a(param_1);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffcf;
  if (uVar1 == 0xffffffff) {
    puVar2 = &DAT_005e7898;
  }
  else {
    puVar2 = (undefined *)((&DAT_008d4920)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 0x24);
  }
  puVar2[4] = puVar2[4] & 0xfd;
  if ((*(uint *)(param_1 + 0xc) & 0x80) != 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffc;
  }
  FUN_0058c724(uVar1,0,0);
  FUN_0058c203(param_1);
  return;
}


