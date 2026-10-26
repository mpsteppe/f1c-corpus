// Function: FUN_004e5470 @ 004e5470
// Size (bytes): 1107


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e5470(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  int local_1c;
  
  pfVar11 = (float *)(param_1 + 0x34b0);
  iVar12 = 4;
  pfVar10 = (float *)(param_1 + 0x3588);
  do {
    fVar1 = pfVar10[1];
    fVar2 = pfVar10[0x16];
    fVar3 = pfVar10[3];
    pfVar10[-2] = fVar1 * *pfVar11 +
                  fVar3 * *(float *)(param_1 + 0x34b8) + fVar2 * *(float *)(param_1 + 0x34b4);
    pfVar10[-1] = fVar2 * *(float *)(param_1 + 0x34c0) +
                  fVar3 * *(float *)(param_1 + 0x34c4) + fVar1 * *(float *)(param_1 + 0x34bc);
    *pfVar10 = fVar3 * *(float *)(param_1 + 0x34d0) +
               fVar2 * *(float *)(param_1 + 0x34cc) + fVar1 * *(float *)(param_1 + 0x34c8);
    pfVar10[-2] = *(float *)(param_1 + 0x34d4) + pfVar10[-2];
    pfVar10[-1] = pfVar10[-1] + *(float *)(param_1 + 0x34d8);
    *pfVar10 = *(float *)(param_1 + 0x34dc) + *pfVar10;
    fVar4 = *(float *)(param_1 + 0x350c);
    fVar5 = *(float *)(param_1 + 0x3504);
    fVar6 = *(float *)(param_1 + 0x3504);
    fVar7 = *(float *)(param_1 + 0x3508);
    fVar8 = *(float *)(param_1 + 0x34fc);
    fVar9 = *(float *)(param_1 + 0x3500);
    pfVar10[4] = (fVar3 * *(float *)(param_1 + 0x3508) - fVar2 * *(float *)(param_1 + 0x350c)) +
                 *(float *)(param_1 + 0x34f8);
    pfVar10[5] = (fVar1 * fVar4 - fVar3 * fVar5) + fVar8;
    iVar12 = iVar12 + -1;
    pfVar10[6] = (fVar2 * fVar6 - fVar1 * fVar7) + fVar9;
    pfVar10 = pfVar10 + 0x3e;
  } while (iVar12 != 0);
  fVar13 = (float10)*(float *)(param_1 + 0x3960) * (float10)*(float *)(param_1 + 0x3574);
  *(float *)(param_1 + 0x35a8) = (float)fVar13;
  fVar14 = (float10)fcos(fVar13);
  *(float *)(param_1 + 0x363c) = (float)fVar14;
  fVar15 = (float10)fsin(fVar13);
  *(float *)(param_1 + 0x3640) = (float)fVar15;
  *(float *)(param_1 + 0x36a0) = (float)fVar13;
  *(float *)(param_1 + 0x3738) = (float)fVar15;
  *(float *)(param_1 + 0x3734) = (float)fVar14;
  FUN_0053ac70(2,0);
  local_1c = 4;
  do {
    FUN_004e3aa0(pfVar11,(float *)(param_1 + 0x34d4));
    local_1c = local_1c + -1;
  } while (local_1c != 0);
  FUN_0053ac70(1,0);
  if (_DAT_0059e6e8 < *(float *)(param_1 + 0x34c0)) {
    fVar1 = (((*(float *)(param_1 + 0x35b4) - *(float *)(param_1 + 0x36ac)) +
             *(float *)(param_1 + 0x37a4)) - *(float *)(param_1 + 0x389c)) *
            *(float *)(param_1 + 0x3974);
    *(float *)(param_1 + 0x35c4) = fVar1 + *(float *)(param_1 + 0x35c4);
    *(float *)(param_1 + 0x36bc) = *(float *)(param_1 + 0x36bc) - fVar1;
    *(float *)(param_1 + 0x37b4) = fVar1 + *(float *)(param_1 + 0x37b4);
    *(float *)(param_1 + 0x38ac) = *(float *)(param_1 + 0x38ac) - fVar1;
  }
  pfVar10 = (float *)(param_1 + 0x35c4);
  iVar12 = 4;
  do {
    if (pfVar10[0xc] < DAT_0059e440) {
      if (_DAT_0059e664 < pfVar10[0xc]) {
        fVar1 = (pfVar10[0xc] + _DAT_0059e448) * _DAT_0059e8ec * pfVar10[-2];
        goto LAB_004e56ab;
      }
    }
    else {
      fVar1 = pfVar10[-2];
LAB_004e56ab:
      *pfVar10 = fVar1 * pfVar10[0xf] + *pfVar10;
    }
    if (*pfVar10 < DAT_0059e440) {
      *pfVar10 = *pfVar10 * _DAT_0059e450;
    }
    pfVar10 = pfVar10 + 0x3e;
    iVar12 = iVar12 + -1;
    if (iVar12 == 0) {
      iVar12 = 4;
      pfVar10 = (float *)(param_1 + 0x3660);
      do {
        FUN_004e3d00(pfVar11);
        iVar12 = iVar12 + -1;
        *(float *)(param_1 + 0x354c) = *(float *)(param_1 + 0x354c) + pfVar10[-2];
        *(float *)(param_1 + 0x3550) = *(float *)(param_1 + 0x3550) + pfVar10[-1];
        *(float *)(param_1 + 0x3554) = *(float *)(param_1 + 0x3554) + *pfVar10;
        fVar1 = pfVar10[-2];
        fVar2 = pfVar10[-3];
        fVar3 = *pfVar10;
        fVar4 = pfVar10[-5];
        fVar5 = pfVar10[-5];
        fVar6 = pfVar10[-1];
        fVar7 = pfVar10[-2];
        fVar8 = pfVar10[-4];
        *(float *)(param_1 + 0x3558) =
             (*pfVar10 * pfVar10[-4] - pfVar10[-1] * pfVar10[-3]) + *(float *)(param_1 + 0x3558);
        *(float *)(param_1 + 0x355c) =
             (fVar1 * fVar2 - fVar3 * fVar4) + *(float *)(param_1 + 0x355c);
        *(float *)(param_1 + 0x3560) =
             (fVar5 * fVar6 - fVar7 * fVar8) + *(float *)(param_1 + 0x3560);
        pfVar10 = pfVar10 + 0x3e;
      } while (iVar12 != 0);
      fVar1 = *(float *)(param_1 + 0x3550);
      fVar2 = *(float *)(param_1 + 0x3558);
      iVar12 = 4;
      fVar3 = *(float *)(param_1 + 0x3560);
      pfVar11 = (float *)(param_1 + 0x3608);
      do {
        iVar12 = iVar12 + -1;
        pfVar11[-2] = fVar2 * *pfVar11 + fVar1 * pfVar11[-1] + fVar3 * pfVar11[1];
        pfVar11 = pfVar11 + 0x3e;
      } while (iVar12 != 0);
      iVar12 = 4;
      pfVar11 = (float *)(param_1 + 0x3594);
      do {
        fVar1 = pfVar11[0xc];
        iVar12 = iVar12 + -1;
        fVar7 = fVar1 * pfVar11[9];
        fVar6 = fVar1 * pfVar11[10];
        fVar1 = fVar1 * pfVar11[0xb];
        *(float *)(param_1 + 0x354c) = fVar7 + *(float *)(param_1 + 0x354c);
        *(float *)(param_1 + 0x3550) = fVar6 + *(float *)(param_1 + 0x3550);
        *(float *)(param_1 + 0x3554) = fVar1 + *(float *)(param_1 + 0x3554);
        fVar2 = *pfVar11;
        fVar3 = pfVar11[-2];
        fVar4 = pfVar11[-2];
        fVar5 = pfVar11[-1];
        *(float *)(param_1 + 0x3558) =
             (fVar1 * pfVar11[-1] - fVar6 * *pfVar11) + *(float *)(param_1 + 0x3558);
        *(float *)(param_1 + 0x355c) =
             (fVar7 * fVar2 - fVar1 * fVar3) + *(float *)(param_1 + 0x355c);
        *(float *)(param_1 + 0x3560) =
             (fVar6 * fVar4 - fVar7 * fVar5) + *(float *)(param_1 + 0x3560);
        pfVar11 = pfVar11 + 0x3e;
      } while (iVar12 != 0);
      return;
    }
  } while( true );
}


