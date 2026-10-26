// Function: FUN_00593e1b @ 00593e1b
// Size (bytes): 43


uint FUN_00593e1b(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_008d48fc;
  while( true ) {
    if (DAT_008d48fc + DAT_008d48f8 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


