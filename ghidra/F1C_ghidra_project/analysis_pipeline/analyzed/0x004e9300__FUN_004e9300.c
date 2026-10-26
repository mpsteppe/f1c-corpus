// Function: FUN_004e9300 @ 004e9300
// Size (bytes): 419


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
FUN_004e9300(int param_1,float param_2,float param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  int iVar6;
  float10 fVar7;
  float local_28;
  int local_1c;
  int local_14;
  
  fVar3 = param_2 * param_2;
  fVar4 = fVar3 * *(float *)(param_1 + 0x3a70) -
          (fVar3 * param_3 + param_4[1]) * *(float *)(param_1 + 0x3514);
  fVar5 = ABS(fVar3 * param_5 - *param_4) * *(float *)(param_1 + 0x3514);
  if (DAT_0059e440 <= fVar5) {
    local_28 = fVar4 * *(float *)(param_1 + 0x3c7c);
    fVar7 = (float10)FUN_005895a2((double)local_28);
    local_1c = (int)ROUND((float)fVar7);
    if (local_1c < 0) {
      local_28 = *(float *)(param_1 + 0x3c80);
      goto LAB_004e9423;
    }
    if (0xd < local_1c) {
      local_1c = 0xd;
    }
    fVar1 = *(float *)(param_1 + 0x3c80 + local_1c * 4);
    fVar2 = *(float *)(param_1 + 0x3c84 + local_1c * 4);
  }
  else {
    local_28 = fVar4 * *(float *)(param_1 + 0x3c3c);
    fVar7 = (float10)FUN_005895a2((double)local_28);
    local_1c = (int)ROUND((float)fVar7);
    if (local_1c < 0) {
      local_28 = *(float *)(param_1 + 0x3c40);
      goto LAB_004e9423;
    }
    if (0xd < local_1c) {
      local_1c = 0xd;
    }
    fVar1 = *(float *)(param_1 + 0x3c40 + local_1c * 4);
    fVar2 = *(float *)(param_1 + 0x3c44 + local_1c * 4);
  }
  local_28 = (local_28 - (float)local_1c) * (fVar2 - fVar1) + fVar1;
LAB_004e9423:
  fVar1 = DAT_0059e440;
  fVar5 = local_28 * local_28 - fVar5 * fVar5;
  fVar7 = (float10)DAT_0059e440;
  if (fVar7 < (float10)fVar5) {
    if (0 < *(int *)(param_1 + 0x39f8)) {
      iVar6 = param_1 + 0x3580;
      if (*(int *)(param_1 + 0x39b4) != 2) {
        iVar6 = param_1 + 0x3770;
      }
      fVar3 = (param_2 / *(float *)(iVar6 + 0x90)) * *(float *)(param_1 + 0x39d0);
      if (*(float *)(param_1 + 0x3998) <= fVar3) {
        fVar7 = (float10)FUN_0059d99e();
        return fVar7;
      }
      fVar3 = fVar3 * _DAT_0059ed18;
      FUN_005895a2((double)fVar3);
      FUN_005895a2((double)fVar3);
      fVar7 = (float10)FUN_0059d984(unaff_ESI,unaff_EBX);
      return fVar7;
    }
    fVar4 = fVar4 * *(float *)(param_1 + 0x3cbc);
    fVar7 = (float10)FUN_005895a2((double)fVar4);
    local_14 = (int)ROUND((float)fVar7);
    if (local_14 < 0) {
      fVar7 = (float10)*(float *)(param_1 + 0x3cc0);
    }
    else {
      if (0xd < local_14) {
        local_14 = 0xd;
      }
      fVar7 = (float10)*(float *)(param_1 + 0x3cc0 + local_14 * 4);
      fVar7 = ((float10)fVar4 - (float10)local_14) *
              ((float10)*(float *)(param_1 + 0x3cc4 + local_14 * 4) - fVar7) + fVar7;
    }
    fVar7 = fVar7 * (float10)*(float *)(param_1 + 0x3518) * (float10)(SQRT(fVar5) / local_28);
    if ((float10)fVar1 < fVar7) {
      fVar7 = (float10)fVar1;
    }
  }
  return (fVar7 - (float10)*(float *)(param_1 + 0x3d44) * (float10)*(float *)(param_1 + 0x3518) *
                  (float10)fVar3) - (float10)param_4[2];
}


