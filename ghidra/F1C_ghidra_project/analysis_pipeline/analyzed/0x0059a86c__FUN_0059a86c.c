// Function: FUN_0059a86c @ 0059a86c
// Size (bytes): 80


void FUN_0059a86c(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_005b9d3c;
  iVar1 = extraout_ECX[9];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((iVar1 == 0) ||
     ((&DAT_008d463c)[iVar1] = (&DAT_008d463c)[iVar1] + -1,
     (char)(&DAT_008d463c)[extraout_ECX[9]] < '\x01')) {
    FUN_0059a980();
  }
  FUN_00598c70();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


