// Function: FUN_0059ac7f @ 0059ac7f
// Size (bytes): 136


void FUN_0059ac7f(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  
  FUN_0058a5d8();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_005b9d4c;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0059a54d();
  iVar2 = extraout_ECX[3];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    if (*(int *)(extraout_ECX[2] + iVar2 * 4) != 0) {
      puVar1 = (undefined4 *)FUN_00598c88();
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
    }
  }
  FUN_0058aa6f(extraout_ECX[2]);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0059a5e9();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005993af(1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_005b9d54;
  return;
}


