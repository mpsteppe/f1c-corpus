// Function: FUN_0044c550 @ 0044c550
// Size (bytes): 121


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044c550(double *param_1,float *param_2)

{
  double *pdVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  pdVar1 = (double *)FUN_0044c4c0(param_1);
  if (pdVar1 != (double *)0x0) {
    fVar2 = (float10)*param_1 * (float10)*pdVar1;
    fVar2 = (float10)(float)param_1[2] * (float10)pdVar1[2] + fVar2 + fVar2 + (float10)pdVar1[3];
    fVar3 = (float10)(float)param_1[2] * (float10)pdVar1[1];
    fVar3 = (float10)(float)*param_1 * (float10)pdVar1[2] + fVar3 + fVar3 + (float10)pdVar1[4];
    fVar4 = (float10)_DAT_0059e420 / SQRT(fVar2 * fVar2 + fVar3 * fVar3 + (float10)_DAT_0059e420);
    *param_2 = (float)-(fVar4 * fVar2);
    param_2[1] = (float)fVar4;
    param_2[2] = (float)-(fVar4 * fVar3);
  }
  return;
}


