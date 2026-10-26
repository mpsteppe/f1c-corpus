// Function: FUN_0049a360 @ 0049a360
// Size (bytes): 79


int __thiscall FUN_0049a360(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_00589901(param_2);
  iVar1 = FUN_0049a330(param_2);
  if (iVar1 != -1) {
    for (iVar1 = *(int *)(param_1 + iVar1 * 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
      uVar2 = FUN_0049a2b0(param_2);
      iVar3 = FUN_00588410(uVar2);
      if (iVar3 == 0) {
        return iVar1;
      }
    }
  }
  return 0;
}


