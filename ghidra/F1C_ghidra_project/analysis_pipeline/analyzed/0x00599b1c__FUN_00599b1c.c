// Function: FUN_00599b1c @ 00599b1c
// Size (bytes): 106


int * FUN_00599b1c(void)

{
  char cVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    *extraout_ECX = (int)&DAT_005b9c54;
    extraout_ECX[10] = 0;
    extraout_ECX[1] = (int)&PTR_FUN_005b9c50;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  cVar1 = *(char *)(unaff_EBP + 0x10);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_005b9c48;
  if (cVar1 != '\0') {
    FUN_0059a3a9(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}


