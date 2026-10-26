// Function: FUN_0053b4c0 @ 0053b4c0
// Size (bytes): 205


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0053b4c0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  fVar10 = *param_1 + *param_1;
  fVar11 = fVar10 * *param_1;
  fVar8 = param_1[1] + param_1[1];
  fVar1 = param_1[1];
  fVar9 = param_1[2] + param_1[2];
  fVar2 = param_1[2];
  fVar3 = *param_1;
  fVar4 = *param_1;
  fVar5 = param_1[3];
  fVar10 = fVar10 * param_1[3];
  fVar6 = param_1[3];
  fVar7 = param_1[1];
  *param_2 = _DAT_0059e43c - (fVar9 * fVar2 + fVar8 * fVar1);
  param_2[1] = fVar8 * fVar4 - fVar9 * fVar6;
  param_2[2] = fVar8 * fVar5 + fVar9 * fVar3;
  param_2[4] = fVar9 * fVar6 + fVar8 * fVar4;
  param_2[5] = _DAT_0059e43c - (fVar9 * fVar2 + fVar11);
  param_2[6] = fVar9 * fVar7 - fVar10;
  param_2[8] = fVar9 * fVar3 - fVar8 * fVar5;
  param_2[9] = fVar9 * fVar7 + fVar10;
  param_2[10] = _DAT_0059e43c - (fVar8 * fVar1 + fVar11);
  return;
}


