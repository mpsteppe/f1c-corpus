// Function: FUN_00489c60 @ 00489c60
// Size (bytes): 78


undefined1 * __thiscall FUN_00489c60(int param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = &DAT_005ea438;
  if ((param_2 < *(int *)(param_1 + 0x94)) && (-1 < param_2)) {
    iVar2 = *(int *)(param_1 + 0x90);
    iVar3 = 0;
    if (iVar2 != 0) {
      while (iVar3 < param_2) {
        iVar2 = *(int *)(iVar2 + 0x8c);
        iVar3 = iVar3 + 1;
        if (iVar2 == 0) {
          return puVar1;
        }
      }
      if ((iVar2 != 0) && (puVar1 = *(undefined1 **)(iVar2 + 0xa0), puVar1 == (undefined1 *)0x0)) {
        puVar1 = &DAT_005ea438;
      }
    }
  }
  return puVar1;
}


