// Function: FUN_00590303 @ 00590303
// Size (bytes): 55


void FUN_00590303(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_008d3fac);
  DAT_008d3f9c = (uint)(sVar1 == 3);
  EnumSystemLocalesA(FUN_0059033a,1);
  if ((DAT_008d3fb0 & 4) == 0) {
    DAT_008d3fb0 = 0;
  }
  return;
}


