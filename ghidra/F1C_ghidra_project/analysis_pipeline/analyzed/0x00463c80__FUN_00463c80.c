// Function: FUN_00463c80 @ 00463c80
// Size (bytes): 19


undefined1 * __fastcall FUN_00463c80(int *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(*param_1 + 0xb4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  return puVar1;
}


