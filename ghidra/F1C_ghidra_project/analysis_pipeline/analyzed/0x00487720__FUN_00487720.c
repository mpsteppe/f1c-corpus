// Function: FUN_00487720 @ 00487720
// Size (bytes): 19


uint FUN_00487720(void)

{
  int iVar1;
  
  iVar1 = FUN_00486720();
  if ((iVar1 != 1) && (iVar1 - 3U != 0)) {
    return iVar1 - 3U & 0xffffff00;
  }
  return 1;
}


