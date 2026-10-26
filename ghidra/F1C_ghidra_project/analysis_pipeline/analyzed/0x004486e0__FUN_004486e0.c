// Function: FUN_004486e0 @ 004486e0
// Size (bytes): 72


void __thiscall FUN_004486e0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  *(int *)(param_1 + 0x48) = param_3;
  *(int *)(param_2 + param_3 * 4) = param_1;
  param_3 = param_3 + 1;
  piVar2 = (int *)(param_1 + 0x4c);
  iVar1 = 4;
  do {
    if (*piVar2 != 0) {
      param_3 = FUN_004486e0(param_2,param_3);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (*(int *)(param_1 + 0x5c) != 0) {
    FUN_004486e0(param_2,param_3);
  }
  return;
}


