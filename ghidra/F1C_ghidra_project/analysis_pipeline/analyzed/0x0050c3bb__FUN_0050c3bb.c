// Function: FUN_0050c3bb @ 0050c3bb
// Size (bytes): 209


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050c3bb(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = _DAT_0059e450;
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = (fVar1 * _DAT_0059e800 - fVar2) - param_6;
  fVar3 = (fVar2 * _DAT_0059e478 - fVar1 * _DAT_0059e7ec) + _DAT_0059e800;
  param_6 = (fVar1 * _DAT_0059e46c - fVar2 * _DAT_0059e478) + param_6;
  fVar2 = fVar2 - fVar1;
  *param_1 = (fVar2 * *param_5 + param_6 * *param_4 + fVar3 * *param_3 + fVar4 * *param_2) *
             _DAT_0059e450;
  param_1[1] = (fVar4 * param_2[1] + fVar3 * param_3[1] + param_6 * param_4[1] + fVar2 * param_5[1])
               * fVar5;
  param_1[2] = (fVar4 * param_2[2] + fVar3 * param_3[2] + param_6 * param_4[2] + fVar2 * param_5[2])
               * fVar5;
  return;
}


