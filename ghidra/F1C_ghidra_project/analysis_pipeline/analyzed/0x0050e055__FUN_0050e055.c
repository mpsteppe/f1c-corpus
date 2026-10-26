
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050e055(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  if (param_2[3] < _DAT_0059e43c) {
    fVar3 = (float10)FUN_005894a0();
    fVar4 = (float10)fsin(fVar3);
    iVar2 = FUN_0050c042((float)fVar4,0);
    if (iVar2 == 0) {
      fVar1 = (float)fVar3 / (float)fVar4;
      *param_1 = fVar1 * *param_2;
      param_1[1] = fVar1 * param_2[1];
      param_1[2] = fVar1 * param_2[2];
      goto LAB_0050e0c9;
    }
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
LAB_0050e0c9:
  param_1[3] = 0.0;
  return;
}

