// Function: FUN_00477640 @ 00477640
// Size (bytes): 58


void FUN_00477640(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = FUN_0048f590();
  if ((iVar2 != 0) && (puVar1 = *(undefined4 **)(iVar2 + 0x3c), puVar1 != (undefined4 *)0x0)) {
    puVar3 = (undefined1 *)*puVar1;
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    FUN_00566650(puVar1 + 0x2f);
  }
  return;
}


