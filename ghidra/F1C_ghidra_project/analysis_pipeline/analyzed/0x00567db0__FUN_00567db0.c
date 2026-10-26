// Function: FUN_00567db0 @ 00567db0
// Size (bytes): 82


int __thiscall FUN_00567db0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if ((param_3 != -1) || (param_3 = FUN_00567d00(param_2), param_3 != -1)) {
    for (iVar1 = *(int *)(param_1 + param_3 * 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      puVar2 = *(undefined1 **)(iVar1 + 0x10);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(puVar2,param_2);
      if (iVar3 == 0) {
        return iVar1;
      }
    }
  }
  return 0;
}


