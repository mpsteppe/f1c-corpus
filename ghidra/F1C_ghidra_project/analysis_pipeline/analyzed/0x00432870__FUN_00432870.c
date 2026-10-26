// Function: FUN_00432870 @ 00432870
// Size (bytes): 66


undefined1 * __fastcall FUN_00432870(int *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)*param_1;
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_00566650(puVar1);
  puVar1 = *(undefined1 **)(*param_1 + 8);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_005665b0(puVar1);
  puVar1 = *(undefined1 **)(*param_1 + 0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  return puVar1;
}


