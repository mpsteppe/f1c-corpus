// Function: FUN_004c29f0 @ 004c29f0
// Size (bytes): 134


void FUN_004c29f0(void)

{
  int iVar1;
  char cVar2;
  
  cVar2 = FUN_0042bc10();
  if (((cVar2 != '\0') && (DAT_008ab6e4 != 2)) && (DAT_007c56a4 == 7)) {
    iVar1 = *(int *)(DAT_007c54e8 + 0x4058);
    FUN_004c2bf0();
    FUN_004c2c40(iVar1);
    if (0 < DAT_007d0990) {
      FUN_004c2dc0((float)DAT_007d01a0);
    }
    FUN_004c2d30(DAT_007d0798);
    if (((DAT_007d0410 == 4) || (DAT_007d0410 == 3)) && (iVar1 == 1)) {
      FUN_004c2c30();
      return;
    }
  }
  return;
}


