// Function: FUN_004b72a0 @ 004b72a0
// Size (bytes): 81


undefined4 __thiscall FUN_004b72a0(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  undefined4 extraout_ECX;
  undefined4 uVar5;
  int extraout_EDX;
  
  piVar1 = (int *)((param_2 + 4) * 0x10 + param_1);
  piVar2 = (int *)*piVar1;
  piVar1[2] = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    iVar3 = *piVar2;
    while( true ) {
      uVar5 = 0;
      if ((iVar3 == 0) || (cVar4 = FUN_004b50c0(param_3), uVar5 = extraout_ECX, cVar4 != '\0')) {
        return uVar5;
      }
      if (*(int *)(extraout_EDX + 8) != 0) {
        *(undefined4 *)(extraout_EDX + 8) = *(undefined4 *)(*(int *)(extraout_EDX + 8) + 4);
      }
      if (*(int **)(extraout_EDX + 8) == (int *)0x0) break;
      iVar3 = **(int **)(extraout_EDX + 8);
    }
  }
  return 0;
}


