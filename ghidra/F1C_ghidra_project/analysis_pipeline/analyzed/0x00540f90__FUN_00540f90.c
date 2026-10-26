// Function: FUN_00540f90 @ 00540f90
// Size (bytes): 39


void __thiscall FUN_00540f90(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_2 != 0) && (piVar1 = *(int **)(param_2 + 0x20), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1);
    *param_1 = iVar2;
    if (iVar2 == 0) {
      *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + -1;
    }
  }
  return;
}


