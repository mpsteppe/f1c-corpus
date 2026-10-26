// Function: FUN_0053c9c0 @ 0053c9c0
// Size (bytes): 51


void FUN_0053c9c0(void)

{
  uint *puVar1;
  int iVar2;
  
  if (0 < DAT_008b8e30) {
    puVar1 = &DAT_008b5a38;
    iVar2 = DAT_008b8e30;
    do {
      if ((*puVar1 & 0x4000) != 0) {
        *puVar1 = *puVar1 & 0xffffbfff | 0x400;
      }
      puVar1 = puVar1 + 0x21;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_0053ca00();
  return;
}


