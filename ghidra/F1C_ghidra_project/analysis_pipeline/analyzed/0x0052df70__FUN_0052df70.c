// Function: FUN_0052df70 @ 0052df70
// Size (bytes): 23


void FUN_0052df70(void)

{
  uint uVar1;
  
  uVar1 = FUN_0052df90();
  DAT_008b0108 = uVar1 & 0xff;
  if (DAT_008b0108 != 0) {
    FUN_005317c0();
    return;
  }
  return;
}


