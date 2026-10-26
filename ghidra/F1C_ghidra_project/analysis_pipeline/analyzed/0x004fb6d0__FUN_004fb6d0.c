// Function: FUN_004fb6d0 @ 004fb6d0
// Size (bytes): 498


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004fb6d0(float *param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float10 fVar10;
  
  fVar3 = *param_2 - *param_1;
  fVar4 = param_2[1] - param_1[1];
  fVar1 = (float)((float10)param_2[2] - (float10)param_1[2]);
  fVar10 = (float10)fVar3 * (float10)param_1[8] +
           (float10)fVar4 * (float10)param_1[9] +
           ((float10)param_2[2] - (float10)param_1[2]) * (float10)param_1[10];
  if ((float10)DAT_0059e440 <= fVar10) {
    fVar10 = fVar10 - (float10)param_1[0x17];
  }
  else {
    fVar10 = -(fVar10 + (float10)param_1[0x16]);
  }
  pfVar2 = (float *)param_1[0x44];
  fVar5 = *pfVar2 - *param_1;
  fVar6 = pfVar2[1] - param_1[1];
  fVar7 = pfVar2[2] - param_1[2];
  fVar8 = SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7);
  if (fVar8 == DAT_0059e440) {
    return (float10)_DAT_0059e5fc;
  }
  fVar9 = _DAT_0059e43c / fVar8;
  fVar8 = (fVar5 * fVar9 * fVar3 + fVar6 * fVar9 * fVar4 + fVar7 * fVar9 * fVar1) - fVar8;
  if (fVar10 < (float10)fVar8) {
    fVar10 = (float10)fVar8;
  }
  pfVar2 = (float *)param_1[0x43];
  fVar5 = *pfVar2 - *param_1;
  fVar6 = pfVar2[1] - param_1[1];
  fVar7 = pfVar2[2] - param_1[2];
  fVar8 = SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7);
  if (fVar8 == DAT_0059e440) {
    return (float10)_DAT_0059e5fc;
  }
  fVar9 = _DAT_0059e43c / fVar8;
  fVar8 = (fVar5 * fVar9 * fVar3 + fVar6 * fVar9 * fVar4 + fVar7 * fVar9 * fVar1) - fVar8;
  if (fVar10 < (float10)fVar8) {
    fVar10 = (float10)fVar8;
  }
  if (fVar10 < (float10)(ABS(fVar4) - _DAT_0059e478)) {
    fVar10 = (float10)(ABS(fVar4) - _DAT_0059e478);
  }
  return fVar10;
}


