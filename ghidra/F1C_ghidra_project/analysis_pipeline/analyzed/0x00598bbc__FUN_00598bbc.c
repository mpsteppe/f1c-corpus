// Function: FUN_00598bbc @ 00598bbc
// Size (bytes): 96


undefined4 * FUN_00598bbc(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00598c1c();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_005b9c04;
  FUN_0059a4c9();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00598c1c();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_005b9bcc;
  FUN_005994bc(uVar1,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}


