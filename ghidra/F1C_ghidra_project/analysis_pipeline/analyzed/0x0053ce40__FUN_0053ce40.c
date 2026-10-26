// Function: FUN_0053ce40 @ 0053ce40
// Size (bytes): 140


undefined4 FUN_0053ce40(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = DAT_008b8f14;
  if (DAT_008b8f14 != 0) {
    while (param_1 != iVar2) {
      piVar1 = (int *)(iVar2 + 0x130);
      iVar2 = *piVar1;
      if (*piVar1 == 0) {
        return 0;
      }
    }
    if (*(int *)(iVar2 + 300) != 0) {
      *(undefined4 *)(*(int *)(iVar2 + 300) + 0x130) = *(undefined4 *)(iVar2 + 0x130);
    }
    if (*(int *)(iVar2 + 0x130) != 0) {
      *(undefined4 *)(*(int *)(iVar2 + 0x130) + 300) = *(undefined4 *)(iVar2 + 300);
    }
    if (*(int *)(param_1 + 300) == 0) {
      DAT_008b8f14 = *(int *)(param_1 + 0x130);
    }
    FUN_0055fe30();
    FUN_00557470();
    FUN_00587bcf(param_1);
    DAT_008b6ac0 = DAT_008b6ac0 + -1;
  }
  return 0;
}


