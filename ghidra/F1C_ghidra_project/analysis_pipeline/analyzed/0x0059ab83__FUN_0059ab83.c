// Function: FUN_0059ab83 @ 0059ab83
// Size (bytes): 74


void FUN_0059ab83(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_0058a5d8();
  FUN_0059a54d(extraout_ECX);
  iVar1 = DAT_008d4650;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_00598c88();
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0059a5e9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


