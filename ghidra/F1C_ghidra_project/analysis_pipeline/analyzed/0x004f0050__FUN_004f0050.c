// Function: FUN_004f0050 @ 004f0050
// Size (bytes): 351


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004f0050(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float10 fVar7;
  
  pfVar6 = (float *)FUN_004e9630();
  pfVar1 = (float *)pfVar6[0x44];
  pfVar2 = (float *)pfVar6[0x43];
  fVar3 = *pfVar1 - *pfVar2;
  fVar4 = pfVar1[1] - pfVar2[1];
  fVar5 = pfVar1[2] - pfVar2[2];
  if (((fVar3 == DAT_0059e440) && (fVar4 == DAT_0059e440)) && (fVar5 == DAT_0059e440)) {
    return (float10)pfVar6[0x12];
  }
  fVar7 = (float10)_DAT_0059e43c /
          SQRT((float10)fVar3 * (float10)fVar3 +
               (float10)fVar4 * (float10)fVar4 + (float10)fVar5 * (float10)fVar5);
  fVar7 = (float10)(float)((float10)fVar3 * fVar7) *
          ((float10)*(float *)(param_1 + 0x34d4) - (float10)*pfVar6) +
          (float10)(float)((float10)fVar4 * fVar7) *
          ((float10)*(float *)(param_1 + 0x34d8) - (float10)pfVar6[1]) +
          fVar7 * (float10)fVar5 * ((float10)*(float *)(param_1 + 0x34dc) - (float10)pfVar6[2]) +
          (float10)pfVar6[0x12];
  if ((float10)DAT_0059e440 <= fVar7) {
    if (((float10)DAT_005ea3fc < fVar7) &&
       (fVar7 = fVar7 - (float10)DAT_005ea3fc, (float10)DAT_005ea3fc < fVar7)) {
      fVar7 = (float10)DAT_005ea3fc;
    }
  }
  else {
    fVar7 = fVar7 + (float10)DAT_005ea3fc;
    if (fVar7 < (float10)DAT_0059e440) {
      return (float10)DAT_0059e440;
    }
  }
  return fVar7;
}


