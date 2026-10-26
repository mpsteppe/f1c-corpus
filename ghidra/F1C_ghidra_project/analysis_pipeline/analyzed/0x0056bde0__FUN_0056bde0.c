// Function: FUN_0056bde0 @ 0056bde0
// Size (bytes): 566


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056bde0(double *param_1,double *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  int iVar7;
  int iVar8;
  double *pdVar9;
  double *pdVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  
  dVar2 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  if (_DAT_0059e430 < dVar2) {
    dVar2 = SQRT(dVar2);
    dVar1 = _DAT_0059e428 / dVar2;
    fVar11 = (float10)dVar1 * (float10)*param_2;
    fVar12 = (float10)dVar1 * (float10)param_2[1];
    fVar13 = (float10)dVar1 * (float10)param_2[2];
    fVar14 = (float10)fsin((float10)dVar2);
    dVar1 = (double)fVar14;
    fVar14 = (float10)fcos((float10)dVar2);
    dVar2 = (double)fVar14;
    fVar14 = (float10)_DAT_0059e420 - fVar14;
    dVar3 = (double)(fVar12 * fVar11 * fVar14);
    dVar4 = (double)(fVar13 * fVar11 * fVar14);
    fVar14 = fVar13 * fVar12 * fVar14;
    dVar5 = _DAT_0059e420 - (double)(fVar11 * fVar11);
    dVar6 = _DAT_0059e420 - (double)(fVar12 * fVar12);
    pdVar10 = param_1 + 2;
    pdVar9 = param_1 + 1;
    fVar15 = (float10)_DAT_0059e420;
    iVar7 = 0;
    do {
      fVar16 = (float10)param_1[iVar7];
      fVar17 = (float10)*pdVar9;
      fVar18 = (float10)*pdVar10;
      iVar8 = iVar7 + 3;
      pdVar9 = pdVar9 + 3;
      pdVar10 = pdVar10 + 3;
      param_1[iVar7] =
           (double)(fVar16 * (float10)(dVar5 * dVar2 + (double)(fVar11 * fVar11)) +
                   fVar17 * (float10)(dVar3 - (double)((float10)dVar1 * fVar13)) +
                   (float10)(dVar4 + (double)((float10)dVar1 * fVar12)) * fVar18);
      param_1[iVar7 + 1] =
           (double)(fVar16 * (float10)(dVar3 + (double)((float10)dVar1 * fVar13)) +
                   fVar17 * (float10)(dVar6 * dVar2 + (double)(fVar12 * fVar12)) +
                   fVar18 * (fVar14 - (float10)(double)((float10)dVar1 * fVar11)));
      param_1[iVar7 + 2] =
           (double)(fVar16 * (float10)(dVar4 - (double)((float10)dVar1 * fVar12)) +
                   fVar17 * (float10)(double)((float10)(double)((float10)dVar1 * fVar11) + fVar14) +
                   fVar18 * ((fVar15 - (float10)(double)(fVar13 * fVar13)) * (float10)dVar2 +
                            (float10)(double)(fVar13 * fVar13)));
      iVar7 = iVar8;
    } while (iVar8 < 9);
  }
  if (param_3 != (double *)0x0) {
    fVar11 = (float10)FUN_00588570();
    *param_3 = (double)-fVar11;
    if (ABS(param_1[5]) != _DAT_0059e420) {
      fVar11 = (float10)fpatan((float10)param_1[2],(float10)param_1[8]);
      param_3[1] = (double)fVar11;
      fVar11 = (float10)fpatan((float10)param_1[3],(float10)param_1[4]);
      param_3[2] = (double)fVar11;
      return;
    }
    dVar2 = param_1[6];
    dVar1 = *param_1;
    *(undefined4 *)(param_3 + 2) = 0;
    fVar11 = (float10)fpatan(-(float10)dVar2,(float10)dVar1);
    *(undefined4 *)((int)param_3 + 0x14) = 0;
    param_3[1] = (double)fVar11;
  }
  return;
}


