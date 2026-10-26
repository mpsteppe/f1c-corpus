// Function: FUN_0044af60 @ 0044af60
// Size (bytes): 212


void FUN_0044af60(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 == 1) {
    iVar1 = 0;
    iVar2 = 2;
    iVar3 = 1;
  }
  else if (param_3 == 2) {
    iVar1 = 1;
    iVar2 = 0;
    iVar3 = 2;
  }
  else {
    iVar1 = param_2;
    iVar2 = param_2;
    iVar3 = param_2;
    if (param_3 == 3) {
      iVar1 = 2;
      iVar2 = 1;
      iVar3 = 0;
    }
  }
  if (param_4 != 0) {
    *param_1 = *(undefined4 *)(*(int *)(param_2 + iVar3 * 4) + iVar1 * 8);
    param_1[1] = *(undefined4 *)(*(int *)(param_2 + iVar3 * 4) + 4 + iVar1 * 8);
    param_1[2] = *(undefined4 *)(*(int *)(param_2 + iVar3 * 4) + iVar3 * 8);
    param_1[3] = *(undefined4 *)(*(int *)(param_2 + iVar2 * 4) + iVar3 * 8);
    param_1[4] = *(undefined4 *)(*(int *)(param_2 + iVar2 * 4) + iVar2 * 8);
    param_1[5] = *(undefined4 *)(*(int *)(param_2 + iVar2 * 4) + 4 + iVar1 * 8);
    return;
  }
  *param_1 = *(undefined4 *)(*(int *)(param_2 + iVar1 * 4) + iVar1 * 8);
  param_1[1] = *(undefined4 *)(*(int *)(param_2 + iVar1 * 4) + 4 + iVar1 * 8);
  param_1[2] = *(undefined4 *)(*(int *)(param_2 + iVar1 * 4) + iVar3 * 8);
  param_1[3] = *(undefined4 *)(*(int *)(param_2 + iVar2 * 4) + 4 + iVar1 * 8);
  param_1[4] = *(undefined4 *)(*(int *)(param_2 + iVar2 * 4) + iVar2 * 8);
  param_1[5] = *(undefined4 *)(*(int *)(param_2 + iVar2 * 4) + iVar1 * 8);
  return;
}


