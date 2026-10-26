// Function: FUN_005410f0 @ 005410f0
// Size (bytes): 39


void __thiscall FUN_005410f0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_2 != 0) && (piVar1 = *(int **)(param_2 + 0x18), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1);
    *param_1 = iVar2;
    if (iVar2 == 0) {
      *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + -1;
    }
  }
  return;
}


