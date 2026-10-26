// Function: FUN_00599e71 @ 00599e71
// Size (bytes): 101


void FUN_00599e71(void)

{
  char cVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_005b9c68;
  cVar1 = *(char *)(extraout_ECX + 0x12);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (cVar1 != '\0') {
    FUN_0059a44c();
  }
  iVar2 = extraout_ECX[0x11];
  if (iVar2 != 0) {
    FUN_005993af(1);
    FUN_00587bcf(iVar2);
  }
  FUN_00598c70();
  *extraout_ECX = &PTR_FUN_005b9ca0;
  FUN_00598c70();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


