// Function: FUN_00567120 @ 00567120
// Size (bytes): 543


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00567120(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  
  fVar18 = (float10)param_2[2] * (float10)param_2[2] +
           (float10)param_2[1] * (float10)param_2[1] + (float10)*param_2 * (float10)*param_2;
  if ((float10)DAT_0059e440 < fVar18) {
    fVar18 = SQRT(fVar18);
    fVar12 = (float10)_DAT_0059e670 / fVar18;
    fVar1 = (float)(fVar12 * (float10)*param_2);
    fVar2 = (float)(fVar12 * (float10)param_2[1]);
    fVar12 = fVar12 * (float10)param_2[2];
    fVar13 = (float10)fsin(fVar18);
    fVar18 = (float10)fcos(fVar18);
    fVar3 = (float)fVar18;
    fVar6 = _DAT_0059e43c - fVar3;
    fVar5 = fVar2 * fVar1 * fVar6;
    fVar4 = (float)((float10)fVar1 * fVar12 * (float10)fVar6);
    fVar18 = fVar12 * (float10)fVar2 * (float10)fVar6;
    fVar6 = _DAT_0059e43c - fVar1 * fVar1;
    fVar7 = _DAT_0059e43c - fVar2 * fVar2;
    fVar14 = (float10)_DAT_0059e43c;
    pfVar11 = param_1 + 2;
    pfVar10 = param_1 + 1;
    iVar8 = 0;
    do {
      fVar15 = (float10)param_1[iVar8];
      fVar16 = (float10)*pfVar10;
      fVar17 = (float10)*pfVar11;
      iVar9 = iVar8 + 3;
      pfVar10 = pfVar10 + 3;
      pfVar11 = pfVar11 + 3;
      param_1[iVar8] =
           (float)(fVar15 * (float10)(fVar6 * fVar3 + fVar1 * fVar1) +
                  fVar16 * (float10)(fVar5 - (float)(fVar13 * fVar12)) +
                  (float10)(fVar4 + (float)((float10)fVar2 * fVar13)) * fVar17);
      param_1[iVar8 + 1] =
           (float)(fVar15 * (float10)(fVar5 + (float)(fVar13 * fVar12)) +
                  fVar16 * (float10)(fVar7 * fVar3 + fVar2 * fVar2) +
                  fVar17 * (fVar18 - (float10)(float)((float10)fVar1 * fVar13)));
      param_1[iVar8 + 2] =
           (float)(fVar15 * (float10)(fVar4 - (float)((float10)fVar2 * fVar13)) +
                  fVar16 * (float10)(float)((float10)(float)((float10)fVar1 * fVar13) + fVar18) +
                  fVar17 * ((fVar14 - (float10)(float)(fVar12 * fVar12)) * (float10)fVar3 +
                           (float10)(float)(fVar12 * fVar12)));
      iVar8 = iVar9;
    } while (iVar9 < 9);
  }
  fVar18 = (float10)FUN_00588570();
  *param_3 = (float)-fVar18;
  if (ABS(param_1[5]) == (float)_DAT_0059e420) {
    fVar18 = (float10)fpatan(-(float10)param_1[6],(float10)*param_1);
    param_3[2] = 0.0;
    param_3[1] = (float)fVar18;
    return;
  }
  fVar18 = (float10)fpatan((float10)param_1[2],(float10)param_1[8]);
  param_3[1] = (float)fVar18;
  fVar18 = (float10)fpatan((float10)param_1[3],(float10)param_1[4]);
  param_3[2] = (float)fVar18;
  return;
}


