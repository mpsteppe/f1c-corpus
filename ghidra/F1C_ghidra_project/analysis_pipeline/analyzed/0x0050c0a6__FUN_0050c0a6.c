// Function: FUN_0050c0a6 @ 0050c0a6
// Size (bytes): 142


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050c0a6(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = ((fVar2 + fVar2) - fVar1 * _DAT_0059e478) + _DAT_0059e43c;
  param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
  fVar3 = fVar1 * _DAT_0059e478 - (fVar2 + fVar2);
  *param_1 = (fVar2 - fVar1) * *param_5 + fVar3 * *param_4 + param_6 * *param_3 + fVar4 * *param_2;
  param_1[1] = fVar4 * param_2[1] +
               param_6 * param_3[1] + fVar3 * param_4[1] + (fVar2 - fVar1) * param_5[1];
  return;
}


