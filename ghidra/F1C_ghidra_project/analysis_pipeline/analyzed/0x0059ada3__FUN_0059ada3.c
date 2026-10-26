// Function: FUN_0059ada3 @ 0059ada3
// Size (bytes): 100


undefined4 * FUN_0059ada3(void)

{
  undefined1 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined1 **)(unaff_EBP + -0x10) = &DAT_005ea438;
  FUN_0059bf19(unaff_EBP + -0x10);
  puVar1 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 3) = *puVar1;
  FUN_005993af(0);
  FUN_0059a9ca(puVar1,0,DAT_005b9c38);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_005b9d7c;
  return extraout_ECX;
}


