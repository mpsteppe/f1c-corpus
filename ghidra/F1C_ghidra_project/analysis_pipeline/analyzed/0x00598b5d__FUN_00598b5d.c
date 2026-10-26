// Function: FUN_00598b5d @ 00598b5d
// Size (bytes): 95


int * FUN_00598b5d(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *extraout_ECX = (int)&DAT_005b9bc0;
    extraout_ECX[0xb] = 0;
    extraout_ECX[2] = (int)&PTR_FUN_005b9bb4;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_005b9ba4;
  FUN_0059a8fa();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}


