// Function: FUN_00558990 @ 00558990
// Size (bytes): 150


undefined4 __fastcall FUN_00558990(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x1c);
  if (iVar2 != 0) {
    FUN_00540eb0(iVar2);
    iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x1c);
    if (iVar2 != 0) {
      FUN_00587bcf(iVar2);
    }
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x1c) = 0;
    FUN_00541040(*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x24));
    iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x24);
    if (iVar2 != 0) {
      FUN_00587bcf(iVar2);
    }
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x24) = 0;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffeff;
  }
  puVar1 = *(uint **)(param_1 + 0x34);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x2c)) {
    do {
      puVar1[0x1e] = 0;
      puVar1[0x1f] = 0;
      *puVar1 = *puVar1 & 0xffffffbf;
      puVar1 = puVar1 + 0x20;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x2c));
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  return 0;
}


