// Function: FUN_00465c30 @ 00465c30
// Size (bytes): 59


undefined4 __thiscall FUN_00465c30(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(int **)(*param_1 + 0xe5c8) != (int *)0x0) &&
     (iVar1 = **(int **)(*param_1 + 0xe5c8), iVar1 != 0)) {
    *param_2 = iVar1;
    iVar1 = *param_1;
    if (*(int *)(iVar1 + 0xe5c8) != 0) {
      *(undefined4 *)(iVar1 + 0xe5c8) = *(undefined4 *)(*(int *)(iVar1 + 0xe5c8) + 4);
    }
    return CONCAT31((int3)((uint)(iVar1 + 0xe5c0) >> 8),1);
  }
  return 0;
}


