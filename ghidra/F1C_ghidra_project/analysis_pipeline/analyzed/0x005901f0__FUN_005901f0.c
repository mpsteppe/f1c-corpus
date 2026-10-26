// Function: FUN_005901f0 @ 005901f0
// Size (bytes): 86


void FUN_005901f0(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_008d3fa8);
  DAT_008d3fa4 = (uint)(sVar1 == 3);
  if (sVar1 == 3) {
    DAT_008d3fa0 = 2;
  }
  else {
    DAT_008d3fa0 = FUN_00590616(DAT_008d3fa8);
  }
  EnumSystemLocalesA(FUN_00590246,1);
  if ((DAT_008d3fb0 & 4) == 0) {
    DAT_008d3fb0 = 0;
  }
  return;
}


