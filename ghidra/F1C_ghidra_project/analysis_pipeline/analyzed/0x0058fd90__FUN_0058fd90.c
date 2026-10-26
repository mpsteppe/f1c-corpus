// Function: FUN_0058fd90 @ 0058fd90
// Size (bytes): 381


undefined4 FUN_0058fd90(char *param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  BOOL BVar3;
  
  if (DAT_008d3fb8 == (code *)0x0) {
    iVar1 = FUN_005904c1();
    if (iVar1 == 0) {
      DAT_008d3fb8 = FUN_005904f7;
    }
    else {
      DAT_008d3fb8 = GetLocaleInfoA_exref;
    }
  }
  if (param_1 != (char *)0x0) {
    DAT_008d3fa8 = param_1;
    if (*param_1 != '\0') {
      FUN_0058ff0d(&PTR_s_american_005e72d0,0x40,&DAT_008d3fa8);
    }
    DAT_008d3fac = param_1 + 0x40;
    if ((DAT_008d3fac != (char *)0x0) && (*DAT_008d3fac != '\0')) {
      FUN_0058ff0d(&PTR_s_america_005e7218,0x16,&DAT_008d3fac);
    }
    DAT_008d3fb0 = 0;
    if ((DAT_008d3fa8 != (char *)0x0) && (*DAT_008d3fa8 != '\0')) {
      if ((DAT_008d3fac == (char *)0x0) || (*DAT_008d3fac == '\0')) {
        FUN_005901f0();
      }
      else {
        FUN_0058ff65();
      }
      goto LAB_0058fe4d;
    }
    if ((DAT_008d3fac != (char *)0x0) && (*DAT_008d3fac != '\0')) {
      FUN_00590303();
      goto LAB_0058fe4d;
    }
  }
  FUN_005903c0();
LAB_0058fe4d:
  if ((((DAT_008d3fb0 == 0) || (uVar2 = FUN_005903da(param_1 + 0x80), uVar2 == 0)) ||
      (BVar3 = IsValidCodePage(uVar2 & 0xffff), BVar3 == 0)) ||
     (BVar3 = IsValidLocale(DAT_008d3f98,1), BVar3 == 0)) {
    return 0;
  }
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = (undefined2)DAT_008d3f98;
    param_2[1] = (undefined2)DAT_008d3fb4;
    param_2[2] = (short)uVar2;
  }
  if (param_3 != 0) {
    iVar1 = (*DAT_008d3fb8)(DAT_008d3f98,0x1001,param_3,0x40);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (*DAT_008d3fb8)(DAT_008d3fb4,0x1002,param_3 + 0x40,0x40);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_00596bf3(uVar2,param_3 + 0x80,10);
  }
  return 1;
}


