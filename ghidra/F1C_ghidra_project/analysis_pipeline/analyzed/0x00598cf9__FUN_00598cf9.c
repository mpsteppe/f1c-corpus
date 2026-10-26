// Function: FUN_00598cf9 @ 00598cf9
// Size (bytes): 116


int __thiscall FUN_00598cf9(int *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    while( true ) {
      if (param_3 < 1) {
        return local_8;
      }
      if ((*(int *)param_1[7] == 0) || (iVar1 = *(int *)param_1[0xb], iVar1 < 1)) break;
      if (param_3 < iVar1) {
        iVar1 = param_3;
      }
      FUN_0058cc00(param_2,*(int *)param_1[7],iVar1);
      local_8 = local_8 + iVar1;
      param_3 = param_3 - iVar1;
      *(int *)param_1[0xb] = *(int *)param_1[0xb] - iVar1;
      param_2 = param_2 + iVar1;
      *(int *)param_1[7] = *(int *)param_1[7] + iVar1;
    }
    iVar1 = (**(code **)(*param_1 + 0x14))();
    if (iVar1 == -1) break;
    *param_2 = (char)iVar1;
    param_2 = param_2 + 1;
    local_8 = local_8 + 1;
    param_3 = param_3 + -1;
  }
  return local_8;
}


