// Function: FUN_004f01b0 @ 004f01b0
// Size (bytes): 548


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004f01b0(int *param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *pfVar9;
  float10 fVar10;
  float local_2c;
  float local_28;
  
  pfVar9 = (float *)FUN_004e9630();
  local_2c = pfVar9[0x24];
  pfVar1 = (float *)pfVar9[0x43];
  pfVar2 = (float *)pfVar9[0x44];
  fVar10 = (float10)pfVar1[0x24];
  local_28 = pfVar2[0x24];
  if (*(int *)(*param_1 + 0x4040) == 0) {
    if (pfVar9[0x11] == 2.8026e-45) {
      local_2c = local_2c - _DAT_005ea408;
    }
    if (pfVar1[0x11] == 2.8026e-45) {
      fVar10 = fVar10 - (float10)_DAT_005ea408;
    }
    if (pfVar2[0x11] == 2.8026e-45) {
      local_28 = local_28 - _DAT_005ea408;
    }
  }
  else if (*(int *)(*param_1 + 0x4040) == 2) {
    if (pfVar9[0x11] == 0.0) {
      local_2c = _DAT_005ea408 + local_2c;
    }
    if (pfVar1[0x11] == 0.0) {
      fVar10 = fVar10 + (float10)_DAT_005ea408;
    }
    if (pfVar2[0x11] == 0.0) {
      local_28 = _DAT_005ea408 + local_28;
    }
  }
  fVar3 = *pfVar2 - *pfVar1;
  fVar4 = pfVar2[1] - pfVar1[1];
  fVar5 = pfVar2[2] - pfVar1[2];
  fVar6 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5);
  if (fVar6 == DAT_0059e440) {
    return (float10)local_2c;
  }
  fVar7 = _DAT_0059e43c / fVar6;
  fVar8 = (*pfVar9 - *pfVar1) * fVar3 * fVar7 +
          fVar4 * fVar7 * (pfVar9[1] - pfVar1[1]) + fVar5 * fVar7 * (pfVar9[2] - pfVar1[2]);
  fVar3 = ((float)param_1[0xd35] - *pfVar1) * fVar3 * fVar7 +
          fVar4 * fVar7 * ((float)param_1[0xd36] - pfVar1[1]) +
          fVar5 * fVar7 * ((float)param_1[0xd37] - pfVar1[2]);
  if (fVar3 < DAT_0059e440 == (fVar3 == DAT_0059e440)) {
    if (fVar3 < fVar8) {
      return ((float10)local_2c - fVar10) * ((float10)fVar3 / (float10)fVar8) + fVar10;
    }
    if (fVar3 < fVar6) {
      return ((float10)local_28 - (float10)local_2c) *
             (((float10)fVar3 - (float10)fVar8) / ((float10)fVar6 - (float10)fVar8)) +
             (float10)local_2c;
    }
    fVar10 = (float10)local_28;
  }
  return fVar10;
}


