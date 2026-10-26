// Function: FUN_004ea010 @ 004ea010
// Size (bytes): 35


undefined4 * FUN_004ea010(void)

{
  int iVar1;
  
  if (DAT_008adaf8 < 0x20) {
    iVar1 = DAT_008adaf8 * 0xe;
    DAT_008adaf8 = DAT_008adaf8 + 1;
    return &DAT_008ad3f8 + iVar1;
  }
  return (undefined4 *)&DAT_008adac0;
}


