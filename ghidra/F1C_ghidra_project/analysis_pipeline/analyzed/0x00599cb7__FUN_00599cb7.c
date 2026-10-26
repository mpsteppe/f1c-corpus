// Function: FUN_00599cb7 @ 00599cb7
// Size (bytes): 96


undefined4 * FUN_00599cb7(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00598c1c();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_005b9ca0;
  FUN_0059a4c9();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00598c1c();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_005b9c68;
  FUN_0059a473(uVar1,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}


