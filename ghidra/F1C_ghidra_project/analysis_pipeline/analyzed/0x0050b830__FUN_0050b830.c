// Function: FUN_0050b830 @ 0050b830
// Size (bytes): 73


void FUN_0050b830(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_005adbb8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0050a92d();
  if (extraout_ECX[0x41b] != 0) {
    FUN_00587bcf(extraout_ECX[0x41b]);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00506ccc();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


