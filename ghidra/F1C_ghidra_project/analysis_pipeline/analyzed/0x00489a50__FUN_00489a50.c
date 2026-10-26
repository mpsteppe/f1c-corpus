// Function: FUN_00489a50 @ 00489a50
// Size (bytes): 89


undefined4 __thiscall FUN_00489a50(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x90);
  iVar4 = 0;
  if (param_2 != 0) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x8c)) {
      puVar2 = *(undefined1 **)(iVar1 + 0xb0);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(puVar2,param_2);
      if (iVar3 == 0) {
        if (param_3 != (int *)0x0) {
          *param_3 = iVar4;
        }
        return 1;
      }
      iVar4 = iVar4 + 1;
    }
  }
  return 0;
}


