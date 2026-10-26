// Function: FUN_0049acc0 @ 0049acc0
// Size (bytes): 138


void __thiscall FUN_0049acc0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_3;
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = iVar3 + param_3;
  param_3 = iVar3;
  if (iVar4 <= iVar3) {
    param_3 = iVar4;
  }
  iVar4 = *(int *)(param_1 + 8);
  if (iVar4 <= iVar4 + iVar1) {
    iVar4 = iVar4 + iVar1;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if (iVar3 + param_2 <= iVar3) {
    iVar3 = iVar3 + param_2;
  }
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 <= iVar2 + param_2) {
    iVar2 = iVar2 + param_2;
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_00490920(param_3,iVar4,iVar3,iVar2);
    FUN_004918d0(param_3,iVar4,iVar3,iVar2);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_2;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_2;
  return;
}


