// Function: FUN_00489920 @ 00489920
// Size (bytes): 28


undefined1 * FUN_00489920(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_00489450();
  if (iVar1 == 0) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    puVar2 = *(undefined1 **)(iVar1 + 0xb0);
    if (puVar2 == (undefined1 *)0x0) {
      return &DAT_005ea438;
    }
  }
  return puVar2;
}


