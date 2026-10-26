// Function: FUN_004bd8c0 @ 004bd8c0
// Size (bytes): 55


void __thiscall FUN_004bd8c0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = 0;
  if (0 < iVar1) {
    piVar2 = *(int **)(param_1 + 8);
    piVar4 = piVar2;
    while (*piVar4 != param_2) {
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
      if (iVar1 <= iVar3) {
        return;
      }
    }
    *(int *)(param_1 + 4) = iVar1 + -1;
    piVar2[iVar3] = piVar2[iVar1 + -1];
  }
  return;
}


