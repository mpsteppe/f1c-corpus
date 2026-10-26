// Function: FUN_0056c020 @ 0056c020
// Size (bytes): 673


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056c020(double *param_1,double *param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  
  dVar1 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  if (_DAT_0059e430 < dVar1) {
    dVar1 = SQRT(dVar1);
    dVar2 = _DAT_0059e420 / dVar1;
    fVar13 = (float10)dVar2 * (float10)*param_2;
    fVar14 = (float10)dVar2 * (float10)param_2[1];
    fVar15 = (float10)dVar2 * (float10)param_2[2];
    fVar16 = (float10)fsin((float10)dVar1);
    fVar17 = (float10)fcos((float10)dVar1);
    dVar1 = (double)fVar17;
    dVar2 = (double)((float10)(double)((float10)_DAT_0059e420 - fVar17) * fVar14 * fVar13);
    fVar17 = fVar15 * (float10)(double)((float10)_DAT_0059e420 - fVar17);
    dVar3 = (double)(fVar17 * fVar13);
    dVar4 = (double)(fVar17 * fVar14);
    dVar8 = (_DAT_0059e420 - (double)(fVar13 * fVar13)) * dVar1 + (double)(fVar13 * fVar13);
    dVar10 = dVar2 - (double)(fVar16 * fVar15);
    dVar9 = dVar3 + (double)(fVar16 * fVar14);
    dVar2 = dVar2 + (double)(fVar16 * fVar15);
    dVar11 = (_DAT_0059e420 - (double)(fVar14 * fVar14)) * dVar1 + (double)(fVar14 * fVar14);
    dVar7 = dVar4 - (double)(fVar16 * fVar13);
    dVar3 = dVar3 - (double)(fVar16 * fVar14);
    dVar4 = dVar4 + (double)(fVar16 * fVar13);
    dVar12 = (_DAT_0059e420 - (double)(fVar15 * fVar15)) * dVar1 + (double)(fVar15 * fVar15);
    dVar1 = *param_1;
    dVar5 = param_1[3];
    dVar6 = param_1[6];
    *param_1 = dVar1 * dVar8 + dVar5 * dVar10 + dVar6 * dVar9;
    param_1[3] = dVar1 * dVar2 + dVar5 * dVar11 + dVar7 * dVar6;
    param_1[6] = dVar1 * dVar3 + dVar5 * dVar4 + dVar6 * dVar12;
    dVar1 = param_1[1];
    dVar5 = param_1[4];
    dVar6 = param_1[7];
    param_1[1] = dVar1 * dVar8 + dVar5 * dVar10 + dVar6 * dVar9;
    param_1[4] = dVar1 * dVar2 + dVar5 * dVar11 + dVar7 * dVar6;
    param_1[7] = dVar1 * dVar3 + dVar5 * dVar4 + dVar6 * dVar12;
    dVar1 = param_1[2];
    dVar5 = param_1[5];
    dVar6 = param_1[8];
    param_1[2] = dVar1 * dVar8 + dVar5 * dVar10 + dVar6 * dVar9;
    param_1[5] = dVar1 * dVar2 + dVar5 * dVar11 + dVar6 * dVar7;
    param_1[8] = dVar1 * dVar3 + dVar5 * dVar4 + dVar6 * dVar12;
    return;
  }
  return;
}


