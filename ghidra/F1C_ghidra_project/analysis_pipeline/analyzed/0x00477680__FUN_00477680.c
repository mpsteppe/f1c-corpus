// Function: FUN_00477680 @ 00477680
// Size (bytes): 160


void FUN_00477680(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined1 local_200 [512];
  
  iVar1 = FUN_0048f590();
  if ((iVar1 != 0) && (puVar3 = *(undefined4 **)(iVar1 + 0x3c), puVar3 != (undefined4 *)0x0)) {
    FUN_004b1520(1,local_200,0x200);
    FUN_004c4d50(local_200);
    puVar2 = (undefined1 *)*puVar3;
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_004c4ff0(puVar2);
    DAT_008ac38c = FUN_004c5130();
    puVar3 = (undefined4 *)FUN_004c4080();
    puVar2 = (undefined1 *)*puVar3;
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_00566650(puVar2);
    FUN_00566650(puVar3 + 0x2f);
  }
  return;
}


