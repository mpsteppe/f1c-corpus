// Function: FUN_00544d30 @ 00544d30
// Size (bytes): 117


undefined4 __thiscall FUN_00544d30(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_2 + 0x44) != 0) &&
     (iVar1 = FUN_00544d30(*(int *)(param_2 + 0x44),1), iVar1 != 0)) {
    return 0xffffffff;
  }
  if (((*(int *)(param_2 + 0x4c) == 0) || (param_3 == 0)) ||
     (iVar1 = FUN_00544d30(*(int *)(param_2 + 0x4c),1), iVar1 == 0)) {
    iVar1 = *(int *)(param_2 + 0x204);
    while( true ) {
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = FUN_0054c6c0(*(uint *)(param_1 + 0xec) & 4);
      if (iVar2 != 0) break;
      iVar1 = *(int *)(iVar1 + 0x10);
    }
  }
  return 0xffffffff;
}


