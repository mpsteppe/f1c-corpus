// Function: FUN_004b5460 @ 004b5460
// Size (bytes): 62


uint __fastcall FUN_004b5460(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x20);
  *(int **)(param_1 + 0x28) = piVar3;
  if (piVar3 != (int *)0x0) {
    iVar1 = *piVar3;
    while (iVar1 != 0) {
      uVar2 = FUN_005001d0();
      if ((char)uVar2 == '\0') {
        return uVar2 & 0xffffff00;
      }
      if (*(int *)(param_1 + 0x28) != 0) {
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(*(int *)(param_1 + 0x28) + 4);
      }
      piVar3 = *(int **)(param_1 + 0x28);
      if (piVar3 == (int *)0x0) break;
      iVar1 = *piVar3;
    }
  }
  return CONCAT31((int3)((uint)piVar3 >> 8),1);
}


