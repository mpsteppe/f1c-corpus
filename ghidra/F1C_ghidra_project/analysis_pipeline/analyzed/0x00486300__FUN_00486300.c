// Function: FUN_00486300 @ 00486300
// Size (bytes): 26


undefined1 * __fastcall FUN_00486300(int param_1)

{
  undefined1 *puVar1;
  
  if (*(int *)(param_1 + 200) == 0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = *(undefined1 **)(*(int *)(param_1 + 200) + 0x50);
    if (puVar1 == (undefined1 *)0x0) {
      return &DAT_005ea438;
    }
  }
  return puVar1;
}


