// Function: FUN_00486240 @ 00486240
// Size (bytes): 26


undefined1 * __fastcall FUN_00486240(int param_1)

{
  undefined1 *puVar1;
  
  if (*(int *)(param_1 + 200) == 0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = *(undefined1 **)(*(int *)(param_1 + 200) + 0x18);
    if (puVar1 == (undefined1 *)0x0) {
      return &DAT_005ea438;
    }
  }
  return puVar1;
}


