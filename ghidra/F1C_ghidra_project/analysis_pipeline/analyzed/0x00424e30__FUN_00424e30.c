// Function: FUN_00424e30 @ 00424e30
// Size (bytes): 50


undefined4 __thiscall FUN_00424e30(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (-1 < *(int *)(param_1 + 0x44b0)) {
    piVar2 = *(int **)(param_1 + 0x44a8);
    do {
      if (*piVar2 == param_2) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar1 <= *(int *)(param_1 + 0x44b0));
  }
  return 0;
}


