// Function: FUN_0058ff65 @ 0058ff65
// Size (bytes): 135


void FUN_0058ff65(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_008d3fa8);
  DAT_008d3fa4 = (uint)(sVar1 == 3);
  sVar1 = _strlen(DAT_008d3fac);
  DAT_008d3f9c = (uint)(sVar1 == 3);
  DAT_008d3f98 = 0;
  if (DAT_008d3fa4 == 0) {
    DAT_008d3fa0 = FUN_00590616(DAT_008d3fa8);
  }
  else {
    DAT_008d3fa0 = 2;
  }
  EnumSystemLocalesA(FUN_0058ffec,1);
  if ((((DAT_008d3fb0 & 0x100) == 0) || ((DAT_008d3fb0 & 0x200) == 0)) || ((DAT_008d3fb0 & 7) == 0))
  {
    DAT_008d3fb0 = 0;
  }
  return;
}


