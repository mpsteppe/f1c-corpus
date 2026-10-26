// Function: FUN_00497980 @ 00497980
// Size (bytes): 35


undefined1 * __fastcall FUN_00497980(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x48) == 0)) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    puVar2 = *(undefined1 **)(*(int *)(iVar1 + 0x50) + 0x34);
    if (puVar2 == (undefined1 *)0x0) {
      return &DAT_005ea438;
    }
  }
  return puVar2;
}


