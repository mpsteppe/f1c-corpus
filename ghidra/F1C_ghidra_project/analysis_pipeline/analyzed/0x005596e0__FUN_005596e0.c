// Function: FUN_005596e0 @ 005596e0
// Size (bytes): 120


void FUN_005596e0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (param_1[2] != 0) {
    for (piVar2 = *(int **)(param_1[2] + 0x224); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
      iVar3 = *piVar2;
      if ((*(int *)(iVar3 + 0x14) == *(int *)(iVar1 + 0x220)) &&
         (*(int *)(*(int *)(iVar3 + 0x18) + 0x14) != 0)) {
        param_1[8] = *(int *)(*(int *)(iVar3 + 0x18) + 0x18);
        (**(code **)(*(int *)(iVar3 + 0x18) + 0x14))();
      }
    }
  }
  if (((iVar1 != 0) && (iVar3 = *(int *)(iVar1 + 0x220), iVar3 != 0)) &&
     (*(int *)(iVar3 + 0x14) != 0)) {
    param_1[8] = *(int *)(iVar3 + 0x18);
    (**(code **)(*(int *)(iVar1 + 0x220) + 0x14))();
  }
  return;
}


