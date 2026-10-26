// Function: FUN_00418a60 @ 00418a60
// Size (bytes): 89


void __fastcall FUN_00418a60(int param_1)

{
  int iVar1;
  int *extraout_ECX;
  int *piVar2;
  int extraout_EDX;
  
  if (*(int **)(param_1 + 0xaf4) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xaf4) + 8))();
    if (((iVar1 != 0) && (0 < *(int *)(param_1 + 0xaec))) && (*(int *)(param_1 + 0xaec) < 0x123)) {
      (**(code **)(**(int **)(param_1 + 0xaf4) + 0xc))();
    }
  }
  piVar2 = (int *)(param_1 + 0x864);
  iVar1 = 0x14;
  do {
    if ((0 < *piVar2) && (*piVar2 < 0x123)) {
      FUN_004144d0();
      piVar2 = extraout_ECX;
      iVar1 = extraout_EDX;
    }
    piVar2 = piVar2 + 8;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


