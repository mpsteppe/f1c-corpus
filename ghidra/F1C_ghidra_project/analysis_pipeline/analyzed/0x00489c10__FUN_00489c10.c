// Function: FUN_00489c10 @ 00489c10
// Size (bytes): 79


undefined4 __thiscall FUN_00489c10(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  if ((param_2 < *(int *)(param_1 + 0x94)) && (-1 < param_2)) {
    iVar1 = *(int *)(param_1 + 0x90);
    for (iVar3 = 0; (iVar1 != 0 && (iVar3 < param_2)); iVar3 = iVar3 + 1) {
      iVar1 = *(int *)(iVar1 + 0x8c);
    }
    if (param_3 == (undefined1 *)0x0) {
      param_3 = &DAT_005ea438;
    }
    FUN_00566650(param_3);
    uVar2 = 1;
  }
  return uVar2;
}


