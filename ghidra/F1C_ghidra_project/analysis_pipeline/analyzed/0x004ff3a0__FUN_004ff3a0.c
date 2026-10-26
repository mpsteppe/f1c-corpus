// Function: FUN_004ff3a0 @ 004ff3a0
// Size (bytes): 710


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_004ff3a0(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
            float *param_6)

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
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  
  fVar13 = SQRT((*param_3 - *param_1) * (*param_3 - *param_1) +
                (param_3[1] - param_1[1]) * (param_3[1] - param_1[1]) +
                (param_3[2] - param_1[2]) * (param_3[2] - param_1[2]));
  if ((fVar13 < DAT_0059e440 == (fVar13 == DAT_0059e440)) && (param_5 != DAT_0059e440)) {
    if (param_5 != _DAT_0059e43c) {
      fVar1 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
      if (fVar1 < DAT_0059e440 == (fVar1 == DAT_0059e440)) {
        fVar1 = _DAT_0059e43c / SQRT(fVar1);
        *param_2 = fVar1 * *param_2;
        param_2[1] = fVar1 * param_2[1];
        param_2[2] = fVar1 * param_2[2];
      }
      fVar1 = param_4[2] * param_4[2] + param_4[1] * param_4[1] + *param_4 * *param_4;
      if (fVar1 < DAT_0059e440 == (fVar1 == DAT_0059e440)) {
        fVar1 = _DAT_0059e43c / SQRT(fVar1);
        *param_4 = fVar1 * *param_4;
        param_4[1] = fVar1 * param_4[1];
        param_4[2] = fVar1 * param_4[2];
      }
      fVar9 = param_1[1];
      fVar14 = param_5 * param_5;
      fVar15 = param_5 * fVar14;
      fVar1 = param_2[1];
      fVar2 = param_2[2];
      fVar3 = param_1[1];
      fVar4 = param_1[2];
      fVar10 = param_1[2];
      fVar11 = param_3[1];
      fVar12 = param_3[2];
      fVar5 = param_4[1];
      fVar6 = param_4[2];
      fVar7 = param_3[1];
      fVar8 = param_3[2];
      fVar18 = (_DAT_0059e478 * fVar15 - fVar14 * _DAT_0059e7ec) + param_5 * DAT_0059e440 +
               _DAT_0059e800;
      fVar17 = (fVar14 * _DAT_0059e46c - _DAT_0059e478 * fVar15) + param_5;
      fVar16 = ((fVar14 + fVar14) - fVar15) - param_5;
      fVar14 = (fVar15 - fVar14) + param_5 * DAT_0059e440;
      *param_6 = (fVar14 * (fVar13 * *param_4 + *param_3) +
                 fVar18 * *param_1 + fVar17 * *param_3 + fVar16 * (*param_1 - fVar13 * *param_2)) *
                 _DAT_0059e450;
      param_6[1] = (fVar16 * (fVar3 - fVar13 * fVar1) +
                   fVar14 * (fVar13 * fVar5 + fVar7) + fVar18 * fVar9 + fVar17 * fVar11) *
                   _DAT_0059e450;
      param_6[2] = (fVar16 * (fVar4 - fVar13 * fVar2) +
                   fVar14 * (fVar13 * fVar6 + fVar8) + fVar18 * fVar10 + fVar17 * fVar12) *
                   _DAT_0059e450;
      return;
    }
    *param_6 = *param_3;
    param_6[1] = param_3[1];
    param_6[2] = param_3[2];
    return;
  }
  *param_6 = *param_1;
  param_6[1] = param_1[1];
  param_6[2] = param_1[2];
  return;
}


