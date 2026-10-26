// Function: FUN_00566f40 @ 00566f40
// Size (bytes): 200


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00566f40(float *param_1,float *param_2)

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
  
  fVar10 = param_1[1] + param_1[1];
  fVar11 = fVar10 * param_1[1];
  fVar8 = param_1[2] + param_1[2];
  fVar1 = param_1[2];
  fVar9 = param_1[3] + param_1[3];
  fVar2 = param_1[3];
  fVar3 = param_1[1];
  fVar4 = param_1[1];
  fVar5 = *param_1;
  fVar10 = fVar10 * *param_1;
  fVar6 = *param_1;
  fVar7 = param_1[2];
  *param_2 = _DAT_0059e43c - (fVar9 * fVar2 + fVar8 * fVar1);
  param_2[1] = fVar8 * fVar4 - fVar9 * fVar6;
  param_2[2] = fVar8 * fVar5 + fVar9 * fVar3;
  param_2[3] = fVar9 * fVar6 + fVar8 * fVar4;
  param_2[4] = _DAT_0059e43c - (fVar9 * fVar2 + fVar11);
  param_2[5] = fVar9 * fVar7 - fVar10;
  param_2[6] = fVar9 * fVar3 - fVar8 * fVar5;
  param_2[7] = fVar9 * fVar7 + fVar10;
  param_2[8] = _DAT_0059e43c - (fVar8 * fVar1 + fVar11);
  return;
}


