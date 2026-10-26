// Function: FUN_004e9100 @ 004e9100
// Size (bytes): 497


float10 __thiscall
FUN_004e9100(int param_1,float param_2,float param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float10 fVar6;
  
  pfVar5 = param_4;
  param_2 = param_2 * param_2;
  fVar3 = param_2 * *(float *)(param_1 + 0x3a70) -
          (param_2 * param_3 + param_4[1]) * *(float *)(param_1 + 0x3514);
  fVar4 = ABS(param_2 * param_5 - *param_4) * *(float *)(param_1 + 0x3514);
  if (DAT_0059e440 <= fVar4) {
    param_5 = fVar3 * *(float *)(param_1 + 0x3c7c);
    fVar6 = (float10)FUN_005895a2((double)param_5);
    param_4 = (float *)(int)ROUND((float)fVar6);
    if ((int)param_4 < 0) {
      fVar1 = *(float *)(param_1 + 0x3c80);
      goto LAB_004e9210;
    }
    if (0xd < (int)param_4) {
      param_4 = (float *)0xd;
    }
    fVar1 = *(float *)(param_1 + 0x3c80 + (int)param_4 * 4);
    fVar2 = *(float *)(param_1 + 0x3c84 + (int)param_4 * 4);
  }
  else {
    param_5 = fVar3 * *(float *)(param_1 + 0x3c3c);
    fVar6 = (float10)FUN_005895a2((double)param_5);
    param_4 = (float *)(int)ROUND((float)fVar6);
    if ((int)param_4 < 0) {
      fVar1 = *(float *)(param_1 + 0x3c40);
      goto LAB_004e9210;
    }
    if (0xd < (int)param_4) {
      param_4 = (float *)0xd;
    }
    fVar1 = *(float *)(param_1 + 0x3c40 + (int)param_4 * 4);
    fVar2 = *(float *)(param_1 + 0x3c44 + (int)param_4 * 4);
  }
  fVar1 = (param_5 - (float)(int)param_4) * (fVar2 - fVar1) + fVar1;
LAB_004e9210:
  fVar4 = fVar1 * fVar1 - fVar4 * fVar4;
  if (fVar4 <= DAT_0059e440) {
    fVar6 = (float10)DAT_0059e440;
  }
  else {
    fVar1 = SQRT(fVar4) / fVar1;
    fVar3 = fVar3 * *(float *)(param_1 + 0x3bfc);
    fVar6 = (float10)FUN_005895a2((double)fVar3);
    param_3 = (float)(int)ROUND((float)fVar6);
    if ((int)param_3 < 0) {
      fVar6 = (float10)*(float *)(param_1 + 0x3c00) * (float10)*(float *)(param_1 + 0x3518) *
              (float10)fVar1;
    }
    else {
      if (0xd < (int)param_3) {
        param_3 = 1.82169e-44;
      }
      fVar6 = (float10)*(float *)(param_1 + 0x3c00 + (int)param_3 * 4);
      fVar6 = (((float10)fVar3 - (float10)(int)param_3) *
               ((float10)*(float *)(param_1 + 0x3c04 + (int)param_3 * 4) - fVar6) + fVar6) *
              (float10)*(float *)(param_1 + 0x3518) * (float10)fVar1;
    }
  }
  if ((float10)*(float *)(param_1 + 0x3d3c) < fVar6) {
    fVar6 = (float10)*(float *)(param_1 + 0x3d3c);
  }
  return (float10)*(float *)(param_1 + 0x3d44) * (float10)*(float *)(param_1 + 0x3518) *
         (float10)param_2 + fVar6 + (float10)pfVar5[2];
}


