// Function: FUN_0053fb80 @ 0053fb80
// Strings:  [Invalid parameters]


undefined4 FUN_0053fb80(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (((*(byte *)(param_1 + 0x18) & 4) != 0) &&
     (piVar1 = *(int **)(param_1 + 0x10), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 8))(piVar1);
    if (iVar2 != 0) goto LAB_0053fc0a;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffb;
  }
  if (((*(uint *)(param_1 + 0x18) & 8) != 0) && (*(int *)(param_1 + 0x14) != 0)) {
    if (((*(uint *)(param_1 + 0x18) & 0x40000) != 0) && (*(int *)(param_1 + 4) != 0)) {
      FUN_0053f6e0(*(int *)(param_1 + 4));
    }
    iVar2 = (**(code **)(**(int **)(param_1 + 0x14) + 8))(*(int **)(param_1 + 0x14));
    if (iVar2 != 0) goto LAB_0053fc0a;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffff7;
  }
  if (((*(byte *)(param_1 + 0x18) & 1) != 0) &&
     (piVar1 = *(int **)(param_1 + 8), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 8))(piVar1);
    if (iVar2 != 0) goto LAB_0053fc0a;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffe;
  }
  if (((*(byte *)(param_1 + 0x18) & 2) != 0) &&
     (piVar1 = *(int **)(param_1 + 0xc), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 8))(piVar1);
    if (iVar2 != 0) {
LAB_0053fc0a:
      FUN_0053c590(0xffffffff,s_Invalid_parameters_005dbcd0);
      return 0xffffffff;
    }
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffd;
  }
  return 0;
}


