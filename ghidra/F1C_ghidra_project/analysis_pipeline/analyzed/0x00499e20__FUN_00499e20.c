// Function: FUN_00499e20 @ 00499e20
// Size (bytes): 13


undefined1 * __fastcall FUN_00499e20(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  return puVar1;
}


