// Function: FUN_0056ead0 @ 0056ead0
// Size (bytes): 82


int __thiscall FUN_0056ead0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *param_1) {
    iVar3 = 0;
    do {
      iVar1 = FUN_00588410(param_2,*(undefined4 *)(iVar3 + param_1[1]));
      if (iVar1 == 0) {
        return iVar2 * 0x244 + param_1[1];
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x244;
    } while (iVar2 < *param_1);
  }
  return 0;
}


