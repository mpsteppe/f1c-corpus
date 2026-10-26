// Function: FUN_004a09a0 @ 004a09a0
// Size (bytes): 73


undefined4 FUN_004a09a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  iVar1 = FUN_004c2850();
  if (iVar1 != 0) {
    uVar4 = 0;
    puVar2 = (undefined4 *)FUN_004c29d0();
    if (puVar2 != (undefined4 *)0x0) {
      puVar3 = (undefined1 *)*puVar2;
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      FUN_004c55b0(puVar3);
      FUN_004a09f0();
    }
  }
  return uVar4;
}


