// Function: FUN_00598e39 @ 00598e39
// Size (bytes): 101


void FUN_00598e39(void)

{
  char cVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_005b9bcc;
  cVar1 = *(char *)(extraout_ECX + 0x12);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (cVar1 != '\0') {
    FUN_00599495();
  }
  iVar2 = extraout_ECX[0x11];
  if (iVar2 != 0) {
    FUN_005993af(1);
    FUN_00587bcf(iVar2);
  }
  FUN_00598c70();
  *extraout_ECX = &PTR_FUN_005b9c04;
  FUN_00598c70();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


