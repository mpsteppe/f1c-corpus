// Function: FUN_00486260 @ 00486260
// Size (bytes): 26


undefined1 * __fastcall FUN_00486260(int param_1)

{
  undefined1 *puVar1;
  
  if (*(int *)(param_1 + 200) == 0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = *(undefined1 **)(*(int *)(param_1 + 200) + 0x20);
    if (puVar1 == (undefined1 *)0x0) {
      return &DAT_005ea438;
    }
  }
  return puVar1;
}


