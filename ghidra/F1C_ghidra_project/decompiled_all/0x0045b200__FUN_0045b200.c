// Function: FUN_0045b200 @ 0045b200
// Strings:  [ilya! _1011]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0045b200(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  _DAT_007c56b0 = 0x3f8353f8;
  _DAT_007c56b4 = s_ilya___1011_005c5b2c;
  DAT_007c56ad = 0;
  _DAT_007c56a0 = 3;
  DAT_007ce2a0 = param_1;
  FUN_00423070(param_3);
  FUN_00421cd0(0);
  FUN_004d7a00(param_3);
  FUN_004a0d50(param_3);
  FUN_004b17f0(param_3);
  FUN_00463160(param_3);
  iVar1 = FUN_0042d370();
  if ((iVar1 == 0) && (iVar1 = FUN_0042d5d0(), iVar1 == 0)) {
    while (iVar1 = FUN_0042d6b0(), iVar1 == 0) {
      do {
        iVar1 = FUN_0042d7a0();
        if (iVar1 != 0) goto LAB_0045b2da;
        iVar1 = FUN_0042d8a0();
      } while (iVar1 == 0);
      FUN_0042da30();
      iVar1 = FUN_0042d5d0();
      if (iVar1 != 0) break;
    }
  }
LAB_0045b2da:
  FUN_0042db20();
  return 0;
}


