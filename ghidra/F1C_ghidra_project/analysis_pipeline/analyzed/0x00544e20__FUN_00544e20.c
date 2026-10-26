// Function: FUN_00544e20 @ 00544e20
// Size (bytes): 107


undefined4 FUN_00544e20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x44) != 0) &&
     (iVar1 = FUN_00544e20(*(int *)(param_1 + 0x44),1), iVar1 != 0)) {
    return 0xffffffff;
  }
  if (((*(int *)(param_1 + 0x4c) == 0) || (param_2 == 0)) ||
     (iVar1 = FUN_00544e20(*(int *)(param_1 + 0x4c),1), iVar1 == 0)) {
    iVar1 = *(int *)(param_1 + 0x204);
    while( true ) {
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = FUN_0054d030();
      if (iVar2 != 0) break;
      iVar1 = *(int *)(iVar1 + 0x10);
    }
  }
  return 0xffffffff;
}


