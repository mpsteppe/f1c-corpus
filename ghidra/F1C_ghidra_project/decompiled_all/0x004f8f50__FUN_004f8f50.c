// Function: FUN_004f8f50 @ 004f8f50
// Strings:  [Ovr: %d, Ins: %3.2f]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f8f50(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  float10 fVar6;
  
  if (*param_1 == 0) {
    return;
  }
  iVar3 = param_1[3];
  param_1[3] = iVar3 + 1U;
  switch(param_1[1]) {
  case 0:
    fVar6 = (float10)FUN_005565b0();
    if (fVar6 < (float10)_DAT_0059e420) {
      return;
    }
    fVar1 = (float)param_1[3];
    if (fVar1 < (float)param_1[4]) {
      param_1[4] = (int)fVar1;
    }
    if ((float)param_1[5] < fVar1) {
      param_1[5] = (int)fVar1;
      FUN_00556440();
      param_1[3] = 0;
      return;
    }
    FUN_00556440();
    param_1[3] = 0;
    return;
  case 1:
    uVar4 = iVar3 + 1U & 0x80000001;
    bVar5 = uVar4 == 0;
    if ((int)uVar4 < 0) {
      bVar5 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (!bVar5) goto switchD_004f8f73_default;
    fVar6 = (float10)FUN_00556510();
    if (*param_1 != 2) goto LAB_004f90cb;
    FUN_0058815f(param_1 + 0xb,s_Ins___3_2f_005d6da8,(double)((float10)_DAT_0059e800 / fVar6));
    break;
  case 2:
    fVar6 = (float10)FUN_005565b0();
    if ((float10)_DAT_0059e420 <= fVar6) {
      iVar3 = param_1[3];
      fVar1 = (float)iVar3;
      if (fVar1 < (float)param_1[4]) {
        param_1[4] = (int)fVar1;
      }
      if ((float)param_1[5] < fVar1) {
        param_1[5] = (int)fVar1;
      }
      if (*param_1 == 2) {
        FUN_0058815f(param_1 + 0xb,&DAT_005c3280,iVar3);
      }
      else {
        if (0x3e6 < iVar3) {
          iVar3 = 999;
        }
        param_1[2] = iVar3;
      }
      FUN_00556440();
      param_1[3] = 0;
    }
    param_1[7] = 0x3e0;
    goto switchD_004f8f73_default;
  case 3:
    if (*param_1 == 2) {
      uVar2 = __ftol();
      FUN_0058815f(param_1 + 0xb,s_Ovr___d_005d6da0,uVar2);
    }
    else {
LAB_004f90cb:
      iVar3 = __ftol();
      if (0x3e6 < iVar3) {
        iVar3 = 999;
      }
      param_1[2] = iVar3;
    }
    break;
  default:
    goto switchD_004f8f73_default;
  }
  param_1[7] = 900;
switchD_004f8f73_default:
  FUN_004f9f00();
  FUN_0053d2e0(s__FTFRAMERATE_005d6d77 + 1,param_1 + 0xb,param_1[7],param_1[8],DAT_008b8dc8);
  FUN_004f9f30();
  return;
}


