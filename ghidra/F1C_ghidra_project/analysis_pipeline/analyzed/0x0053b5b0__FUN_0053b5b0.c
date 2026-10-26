// Function: FUN_0053b5b0 @ 0053b5b0
// Size (bytes): 306


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0053b5b0(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float *pfVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  pfVar2 = param_2;
  fVar1 = param_3[1] * param_2[1] +
          *param_2 * *param_3 + param_3[2] * param_2[2] + param_3[3] * param_2[3];
  if (DAT_0059e440 <= fVar1) {
    local_10 = *param_3;
    local_c = param_3[1];
    local_8 = param_3[2];
    local_4 = param_3[3];
    param_3 = (float *)fVar1;
  }
  else {
    local_4 = -param_3[3];
    local_10 = -*param_3;
    local_c = -param_3[1];
    local_8 = -param_3[2];
    param_3 = (float *)-fVar1;
  }
  param_2 = (float *)(_DAT_0059e43c - param_4);
  if (_DAT_0059e6ec < _DAT_0059e43c - (float)param_3) {
    fVar3 = (float10)FUN_005894a0();
    fVar4 = (float10)fsin(fVar3);
    fVar5 = (float10)fsin(fVar3 * (float10)(float)param_2);
    param_2 = (float *)(float)(fVar5 * ((float10)_DAT_0059e43c / fVar4));
    fVar3 = (float10)fsin(fVar3 * (float10)param_4);
    param_4 = (float)(fVar3 * ((float10)_DAT_0059e43c / fVar4));
  }
  param_1[3] = local_4 * param_4 + (float)param_2 * pfVar2[3];
  *param_1 = local_10 * param_4 + (float)param_2 * *pfVar2;
  param_1[1] = local_c * param_4 + (float)param_2 * pfVar2[1];
  param_1[2] = (float)param_2 * pfVar2[2] + local_8 * param_4;
  return;
}


