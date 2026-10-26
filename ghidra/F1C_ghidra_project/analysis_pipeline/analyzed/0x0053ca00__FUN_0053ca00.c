// Function: FUN_0053ca00 @ 0053ca00
// Size (bytes): 191


void FUN_0053ca00(void)

{
  int extraout_ECX;
  int extraout_EDX;
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  
  FUN_005881c0();
  do {
    FUN_0053c6a0();
  } while (extraout_EDX != 1);
  iVar2 = 0;
  if (0 < DAT_008b8e30) {
    puVar3 = &DAT_008b5a38;
    iVar1 = 0;
    do {
      if ((*puVar3 & 0x400) == 0) {
        FUN_0053c6b0(puVar3);
        iVar2 = iVar2 + 1;
      }
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 0x21;
    } while (iVar1 < DAT_008b8e30);
  }
  DAT_008b8e30 = iVar2;
  if (0 < iVar2) {
    iVar4 = 0;
    iVar1 = iVar2;
    do {
      FUN_0053c6b0(&stack0x00000000 + iVar4);
      iVar4 = iVar4 + 0x84;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if (iVar2 < 0x20) {
    do {
      FUN_0053c6b0(0);
    } while (extraout_ECX + 0x84 < 0x8b6ab8);
  }
  return;
}


