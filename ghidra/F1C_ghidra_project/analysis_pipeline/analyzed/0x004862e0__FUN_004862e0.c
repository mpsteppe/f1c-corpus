// Function: FUN_004862e0 @ 004862e0
// Size (bytes): 26


undefined1 * __fastcall FUN_004862e0(int param_1)

{
  undefined1 *puVar1;
  
  if (*(int *)(param_1 + 200) == 0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = *(undefined1 **)(*(int *)(param_1 + 200) + 0x48);
    if (puVar1 == (undefined1 *)0x0) {
      return &DAT_005ea438;
    }
  }
  return puVar1;
}


