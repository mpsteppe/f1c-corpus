// Function: FUN_0059aab9 @ 0059aab9
// Size (bytes): 202


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0059aab9(void)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  int unaff_EBP;
  
  FUN_0058a5d8();
  FUN_0059a54d();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (DAT_008d4650 == 0) {
    pvVar2 = operator_new(0x28);
    *(void **)(unaff_EBP + -0x14) = pvVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar2 == (void *)0x0) {
      DAT_008d4650 = 0;
    }
    else {
      DAT_008d4650 = FUN_0059abcd(0);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_00587b3e(FUN_0059ab83);
    *(undefined4 *)(DAT_008d4650 + 0x10) = 0x3f;
    sVar3 = _strlen("C");
    FUN_00599615(&DAT_005b9d44,sVar3);
    DAT_008d464c = DAT_008d4650;
    FUN_00598c4a();
    _DAT_008d4648 = DAT_008d464c;
  }
  iVar1 = DAT_008d4650;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0059a5e9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}


