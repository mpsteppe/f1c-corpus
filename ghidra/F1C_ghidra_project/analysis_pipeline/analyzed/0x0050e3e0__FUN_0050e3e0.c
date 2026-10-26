
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050e3e0(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  
  fVar1 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  iVar2 = FUN_0050c042(fVar1,0x3f800000);
  if (iVar2 == 0) {
    if (fVar1 <= (float)PTR_DAT_005ade40) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      param_1[2] = 0.0;
      fVar1 = 0.0;
    }
    else {
      fVar1 = _DAT_0059e43c / SQRT(fVar1);
      *param_1 = fVar1 * *param_2;
      param_1[1] = fVar1 * param_2[1];
      param_1[2] = fVar1 * param_2[2];
      fVar1 = fVar1 * param_2[3];
    }
    param_1[3] = fVar1;
  }
  else if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return;
}

