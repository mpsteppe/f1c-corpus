// Function: FUN_0053ced0 @ 0053ced0
// Size (bytes): 271


undefined4 FUN_0053ced0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_008b8f14 != 0) {
    iVar3 = *(int *)(DAT_008b8f14 + 0x130);
    iVar1 = DAT_008b8f14;
    while (iVar2 = iVar3, iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 300);
      if ((*(byte *)(iVar1 + 0x114) & 8) != 0) {
        if (*(int *)(iVar1 + 300) != 0) {
          *(undefined4 *)(*(int *)(iVar1 + 300) + 0x130) = *(undefined4 *)(iVar1 + 0x130);
        }
        if (*(int *)(iVar1 + 0x130) != 0) {
          *(undefined4 *)(*(int *)(iVar1 + 0x130) + 300) = *(undefined4 *)(iVar1 + 300);
        }
        if (*(int *)(iVar1 + 300) == 0) {
          DAT_008b8f14 = *(int *)(iVar1 + 0x130);
        }
        FUN_0055fe30();
        FUN_00557470();
        FUN_00587bcf(iVar1);
        DAT_008b6ac0 = DAT_008b6ac0 + -1;
      }
      iVar1 = iVar2;
      iVar3 = *(int *)(iVar2 + 0x130);
    }
    if ((*(byte *)(iVar1 + 0x114) & 8) != 0) {
      if (*(int *)(iVar1 + 300) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 300) + 0x130) = *(undefined4 *)(iVar1 + 0x130);
      }
      if (*(int *)(iVar1 + 0x130) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 0x130) + 300) = *(undefined4 *)(iVar1 + 300);
      }
      if (*(int *)(iVar1 + 300) == 0) {
        DAT_008b8f14 = *(int *)(iVar1 + 0x130);
      }
      FUN_0055fe30();
      FUN_00557470();
      FUN_00587bcf(iVar1);
      DAT_008b6ac0 = DAT_008b6ac0 + -1;
    }
  }
  return 0;
}


