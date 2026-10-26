// Function: FUN_00404f10 @ 00404f10
// Size (bytes): 29


uint FUN_00404f10(void)

{
  uint uVar1;
  int *extraout_ECX;
  
  uVar1 = FUN_00404f00();
  if ((((char)uVar1 != '\0') && (uVar1 = *(uint *)(*extraout_ECX + 0x20), 0 < (int)uVar1)) &&
     ((int)uVar1 < 3)) {
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}


