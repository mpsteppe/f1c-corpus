// Function: FUN_004e8b80 @ 004e8b80
// Size (bytes): 345


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004e8b80(int param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  undefined4 local_10;
  
  fVar2 = param_2 * param_2;
  fVar3 = (fVar2 * *(float *)(param_1 + 0x3a70) -
          (fVar2 * DAT_0059e440 - _DAT_005aceb8) * *(float *)(param_1 + 0x3514)) *
          *(float *)(param_1 + 0x3bfc);
  fVar4 = (float10)FUN_005895a2((double)fVar3);
  local_10 = (int)ROUND((float)fVar4);
  if (local_10 < 0) {
    fVar1 = *(float *)(param_1 + 0x3c00);
  }
  else {
    if (0xd < local_10) {
      local_10 = 0xd;
    }
    fVar1 = *(float *)(param_1 + 0x3c00 + local_10 * 4);
    fVar1 = (fVar3 - (float)local_10) * (*(float *)(param_1 + 0x3c04 + local_10 * 4) - fVar1) +
            fVar1;
  }
  fVar1 = fVar1 * *(float *)(param_1 + 0x3518);
  if (*(float *)(param_1 + 0x3d3c) < fVar1) {
    fVar1 = *(float *)(param_1 + 0x3d3c);
  }
  fVar1 = *(float *)(param_1 + 0x3d44) * *(float *)(param_1 + 0x3518) * fVar2 + fVar1;
  if (fVar1 < DAT_0059e440 != (fVar1 == DAT_0059e440)) {
    if (param_2 < _DAT_0059e43c) {
      return (float10)DAT_0059e440;
    }
    return (float10)param_2;
  }
  fVar4 = (float10)fVar1 * (float10)_DAT_0059e99c;
  fVar5 = (float10)fVar2 - -(float10)param_3 * fVar4 * (float10)_DAT_0059e46c;
  if (fVar5 < (float10)DAT_0059e440 != (fVar5 == (float10)DAT_0059e440)) {
    return (float10)DAT_0059e440;
  }
  return (float10)param_2 -
         ((SQRT(fVar5) - (float10)param_2) / (fVar4 + fVar4)) * (float10)fVar1 * (float10)param_4;
}


