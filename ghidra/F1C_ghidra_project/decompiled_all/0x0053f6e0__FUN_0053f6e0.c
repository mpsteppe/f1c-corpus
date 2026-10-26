// Function: FUN_0053f6e0 @ 0053f6e0
// Strings:  [Invalid parameters]


undefined4 __thiscall FUN_0053f6e0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_2 + 0xc);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = iVar2;
    if (iVar2 != 0) {
      FUN_0053c590(0xffffffff,s_Invalid_parameters_005dbcd0);
      return 0xffffffff;
    }
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  return 0;
}


