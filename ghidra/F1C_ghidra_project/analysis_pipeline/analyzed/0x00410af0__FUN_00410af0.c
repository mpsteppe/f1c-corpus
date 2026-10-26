// Function: FUN_00410af0 @ 00410af0
// Size (bytes): 43


void __thiscall FUN_00410af0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *param_2;
  *param_1 = iVar1 + -1;
  *(undefined4 *)(param_1[2] + iVar2 * 4) = *(undefined4 *)(param_1[2] + (iVar1 + -1) * 4);
  **(int **)(param_1[2] + iVar2 * 4) = iVar2;
  *param_2 = -1;
  return;
}


