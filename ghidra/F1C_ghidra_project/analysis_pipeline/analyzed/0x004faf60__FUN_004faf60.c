// Function: FUN_004faf60 @ 004faf60
// Size (bytes): 763


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004faf60(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  
  if (*(int *)(param_1 + 300) < DAT_005ea2cc) {
    iVar6 = *(int *)(param_1 + 0x110);
    if (iVar6 == 0) {
      iVar6 = *(int *)(param_1 + 0x10c);
      if (iVar6 != 0) {
        *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar6 + 0xa4);
        *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar6 + 0xa8);
        *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(iVar6 + 0xac);
      }
    }
    else {
      *(float *)(param_1 + 0xa4) = *(float *)(iVar6 + 0x94) - *(float *)(param_1 + 0x94);
      *(float *)(param_1 + 0xa8) = *(float *)(iVar6 + 0x98) - *(float *)(param_1 + 0x98);
      *(float *)(param_1 + 0xac) = *(float *)(iVar6 + 0x9c) - *(float *)(param_1 + 0x9c);
    }
    *(float *)(param_1 + 0x50) =
         (*(float *)(param_1 + 0x2c) - _DAT_0059e8a4) + *(float *)(param_1 + 0xa0);
    *(float *)(param_1 + 0x54) =
         (*(float *)(param_1 + 0x30) - _DAT_0059e8a4) - *(float *)(param_1 + 0xa0);
    *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x60) + *(float *)(param_1 + 0x2c);
    *(float *)(param_1 + 0x6c) = *(float *)(param_1 + 100) + *(float *)(param_1 + 0x30);
    *(float *)(param_1 + 0x3c) =
         SQRT(*(float *)(param_1 + 0xac) * *(float *)(param_1 + 0xac) +
              *(float *)(param_1 + 0xa8) * *(float *)(param_1 + 0xa8) +
              *(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4));
    if (((*(float *)(param_1 + 0xa4) != DAT_0059e440) ||
        (*(float *)(param_1 + 0xa8) != DAT_0059e440)) ||
       (*(float *)(param_1 + 0xac) != DAT_0059e440)) {
      fVar1 = _DAT_0059e43c /
              SQRT(*(float *)(param_1 + 0xac) * *(float *)(param_1 + 0xac) +
                   *(float *)(param_1 + 0xa8) * *(float *)(param_1 + 0xa8) +
                   *(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4));
      *(float *)(param_1 + 0xa4) = fVar1 * *(float *)(param_1 + 0xa4);
      *(float *)(param_1 + 0xa8) = fVar1 * *(float *)(param_1 + 0xa8);
      *(float *)(param_1 + 0xac) = fVar1 * *(float *)(param_1 + 0xac);
    }
    iVar6 = *(int *)(param_1 + 0x114);
    if (iVar6 != 0) {
      fVar1 = *(float *)(iVar6 + 0x94) - *(float *)(param_1 + 0x94);
      fVar3 = *(float *)(iVar6 + 0x98) - *(float *)(param_1 + 0x98);
      fVar2 = *(float *)(iVar6 + 0x9c) - *(float *)(param_1 + 0x9c);
      *(float *)(param_1 + 0x40) = SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2);
    }
    if (*(float *)(param_1 + 0xac) == DAT_0059e440) {
      *(undefined4 *)(param_1 + 0xb8) = 0x3fc90fdb;
    }
    else {
      fVar7 = (float10)fpatan((float10)*(float *)(param_1 + 0xa4) /
                              (float10)*(float *)(param_1 + 0xac),(float10)1);
      *(float *)(param_1 + 0xb8) = (float)fVar7;
      if (DAT_0059e440 < *(float *)(param_1 + 0xac)) {
        *(float *)(param_1 + 0xb8) = (float)(fVar7 + (float10)_DAT_0059e660);
      }
    }
    if ((*(int *)(param_1 + 0x110) != 0) &&
       (iVar6 = *(int *)(*(int *)(param_1 + 0x110) + 0x110), iVar6 != 0)) {
      iVar5 = 0;
      pfVar4 = (float *)(param_1 + 0xbc);
      do {
        fVar1 = *(float *)(iVar6 + 0x94) - *(float *)(param_1 + 0x94);
        fVar3 = *(float *)(iVar6 + 0x9c) - *(float *)(param_1 + 0x9c);
        fVar2 = SQRT(fVar1 * fVar1 + fVar3 * fVar3) *
                SQRT(*(float *)(param_1 + 0xac) * *(float *)(param_1 + 0xac) +
                     *(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4));
        if ((fVar2 == DAT_0059e440) ||
           (_DAT_0059e43c <=
            (fVar3 * *(float *)(param_1 + 0xac) + fVar1 * *(float *)(param_1 + 0xa4)) / fVar2)) {
LAB_004fb230:
          *pfVar4 = 0.02411;
        }
        else {
          fVar7 = (float10)FUN_005894a0();
          *pfVar4 = (float)fVar7;
          if (fVar7 < (float10)_DAT_005ad274) goto LAB_004fb230;
        }
        iVar6 = *(int *)(iVar6 + 0x110);
        if (iVar6 == 0) {
          return;
        }
        iVar5 = iVar5 + 1;
        pfVar4 = pfVar4 + 1;
      } while (iVar5 < 4);
    }
  }
  return;
}


