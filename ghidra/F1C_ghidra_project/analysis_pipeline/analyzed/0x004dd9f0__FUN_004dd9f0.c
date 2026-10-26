// Function: FUN_004dd9f0 @ 004dd9f0
// Size (bytes): 215


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004dd9f0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  fVar2 = (param_3[2] - param_2[2]) * (param_1[1] - param_2[1]) -
          (param_3[1] - param_2[1]) * (param_1[2] - param_2[2]);
  fVar1 = (*param_3 - *param_2) * (param_1[2] - param_2[2]) -
          (param_3[2] - param_2[2]) * (*param_1 - *param_2);
  fVar4 = (param_3[1] - param_2[1]) * (*param_1 - *param_2) -
          (*param_3 - *param_2) * (param_1[1] - param_2[1]);
  fVar3 = fVar2 * fVar2 + fVar1 * fVar1 + fVar4 * fVar4;
  if (fVar3 <= (float)_DAT_0059e430) {
    uVar5 = 0xffffffff;
    fVar3 = (float)_DAT_0059e420;
  }
  else {
    fVar3 = (float)_DAT_0059e420 / SQRT(fVar3);
  }
  *param_4 = fVar3 * fVar2;
  param_4[1] = fVar1 * fVar3;
  param_4[2] = fVar3 * fVar4;
  return uVar5;
}


