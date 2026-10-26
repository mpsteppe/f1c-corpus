// Function: FUN_004b43e0 @ 004b43e0
// Size (bytes): 108


void FUN_004b43e0(void)

{
  uint local_1b0 [108];
  
  FUN_00566c00(local_1b0,4);
  if (((local_1b0[0] & 0xe0000000) == 0x20000000) && ((local_1b0[0] & 0xfc0000) == 0)) {
    FUN_00566df0((local_1b0[0] >> 8 & 0x3ff) + 1);
    return;
  }
  FUN_00566df0(local_1b0[0] >> 8 & 0x3ff);
  return;
}


