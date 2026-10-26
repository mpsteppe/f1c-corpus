// Function: FUN_0049f790 @ 0049f790
// Size (bytes): 213


void __fastcall FUN_0049f790(int *param_1)

{
  byte bVar1;
  int *extraout_ECX;
  int iVar2;
  
  if (DAT_007cc234 != 0) {
    if ((DAT_005ea518 == DAT_005ea528) &&
       ((*(int *)(DAT_005ea528 + 0x34) == 1 ||
        ((DAT_005ea518 == DAT_005ea528 && (*(int *)(DAT_005ea528 + 0x34) == 2)))))) {
      iVar2 = *param_1;
      do {
        while( true ) {
          iVar2 = iVar2 + 1;
          if (4 < iVar2) {
            iVar2 = 0;
            goto LAB_0049f7fc;
          }
          if (iVar2 != 2) break;
          bVar1 = DAT_007cf7ac & 1;
joined_r0x0049f7f5:
          if (bVar1 != 0) goto LAB_0049f7fc;
        }
        if (iVar2 != 3) {
          if (iVar2 == 4) {
            bVar1 = DAT_007cf7ac & 4;
            goto joined_r0x0049f7f5;
          }
          break;
        }
      } while ((DAT_007cf7ac & 2) == 0);
    }
    else if (*param_1 == 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
LAB_0049f7fc:
    FUN_0049f150(iVar2);
    param_1 = extraout_ECX;
  }
  if (*param_1 == 1) {
    if (DAT_007cc28c != 0) {
      FUN_0049f170(1);
      return;
    }
    if (DAT_007cc2b8 != 0) {
      FUN_0049f170(0);
      return;
    }
    if (DAT_007cc2e4 != 0) {
      FUN_004a5750(param_1[1]);
      return;
    }
    if (DAT_007cc310 != 0) {
      FUN_004a57a0(param_1[1]);
    }
  }
  return;
}


