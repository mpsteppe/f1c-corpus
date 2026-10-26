// Function: FUN_0059d6ff @ 0059d6ff
// Size (bytes): 37


void FUN_0059d6ff(void)

{
  char in_AL;
  int unaff_EBX;
  
  *(char *)(unaff_EBX + 0x1065) = in_AL;
  if (in_AL == '\0') {
    *(undefined4 *)(unaff_EBX + 0x3584) = 0;
  }
  else {
    *(undefined4 *)(unaff_EBX + 0x3584) = 0x3f800000;
  }
  FUN_004c7774();
  return;
}


