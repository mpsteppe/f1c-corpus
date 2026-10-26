// Function: FUN_004b8bd0 @ 004b8bd0
// Size (bytes): 98


char FUN_004b8bd0(void)

{
  char cVar1;
  
  cVar1 = FUN_0044f4a0(0xcb);
  if (cVar1 != '\0') {
    return '\0';
  }
  cVar1 = FUN_0044f4a0(200);
  if (cVar1 != '\0') {
    return '\x01';
  }
  cVar1 = FUN_0044f4a0(0xd0);
  if (cVar1 != '\0') {
    return '\x03';
  }
  cVar1 = FUN_0044f4a0(0xcd);
  return (-(cVar1 != '\0') & 2U) + 2;
}


