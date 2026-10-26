// Function: FUN_004d1410 @ 004d1410
// Size (bytes): 64


undefined1 * __thiscall FUN_004d1410(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (*(int *)(param_1 + 0x1ac) == 0) {
    FUN_004d12c0();
  }
  if ((param_2 < 0) || (*(int *)(param_1 + 0x1a8) <= param_2)) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = *(undefined1 **)(*(int *)(param_1 + 0x1ac) + param_2 * 8);
    if (puVar1 == (undefined1 *)0x0) {
      return &DAT_005ea438;
    }
  }
  return puVar1;
}


