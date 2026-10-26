// Function: FUN_0056eb30 @ 0056eb30
// Size (bytes): 81


int __thiscall FUN_0056eb30(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(iVar2 + *(int *)(param_1 + 0x1c));
      if (iVar1 != 0) {
        iVar1 = FUN_00588410(param_2,iVar1);
        if (iVar1 == 0) {
          return *(int *)(param_1 + 0x1c) + iVar3 * 0x48;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x48;
    } while (iVar3 < *(int *)(param_1 + 0x18));
  }
  return 0;
}


