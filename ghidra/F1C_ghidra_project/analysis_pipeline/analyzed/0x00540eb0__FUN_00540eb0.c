// Function: FUN_00540eb0 @ 00540eb0
// Size (bytes): 77


void __thiscall FUN_00540eb0(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 != 0) && (*(int *)(param_2 + 0x20) != 0)) {
    iVar1 = *(int *)(param_2 + 0x14);
    while (0 < iVar1) {
      FUN_00540f90(param_2);
      iVar1 = *(int *)(param_2 + 0x14);
    }
    *(undefined4 *)(param_2 + 0x14) = 0;
    uVar2 = (**(code **)(**(int **)(param_2 + 0x20) + 8))(*(int **)(param_2 + 0x20));
    *param_1 = uVar2;
    *(undefined4 *)(param_2 + 0x20) = 0;
  }
  return;
}


