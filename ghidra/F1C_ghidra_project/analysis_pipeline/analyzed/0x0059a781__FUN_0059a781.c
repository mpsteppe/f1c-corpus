// Function: FUN_0059a781 @ 0059a781
// Size (bytes): 93


undefined4 * FUN_0059a781(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0059bf56(iVar2);
  uVar1 = *(undefined1 *)(iVar2 + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 3) = uVar1;
  FUN_005993af(0);
  FUN_0059a9ca(iVar2 + 0xc,0,DAT_005b9c38);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_005b9d28;
  return extraout_ECX;
}


