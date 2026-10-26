// Function: FUN_00497e80 @ 00497e80
// Size (bytes): 56


undefined4 __thiscall FUN_00497e80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0) {
    for (iVar1 = *(int *)(param_1 + 0x10c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x54)) {
      iVar2 = FUN_00588410(iVar1,param_2);
      if (iVar2 == 0) {
        return *(undefined4 *)(iVar1 + 0x50);
      }
    }
  }
  return 0;
}


