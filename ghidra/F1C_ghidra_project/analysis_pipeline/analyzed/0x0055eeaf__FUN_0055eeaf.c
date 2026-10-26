// Function: FUN_0055eeaf @ 0055eeaf
// Size (bytes): 117


undefined8 __fastcall
FUN_0055eeaf(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4,float *param_5)

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
  float fVar12;
  float fVar13;
  float fVar14;
  undefined4 in_EAX;
  
  fVar1 = param_5[1];
  fVar2 = *param_3;
  fVar3 = param_5[2];
  fVar4 = *param_3;
  fVar5 = param_5[5];
  fVar6 = param_3[1];
  fVar7 = param_5[6];
  fVar8 = param_3[1];
  fVar9 = param_5[9];
  fVar10 = param_3[2];
  fVar11 = param_5[10];
  fVar12 = param_3[2];
  fVar13 = param_5[0xd];
  fVar14 = param_5[0xe];
  *param_4 = param_5[8] * param_3[2] + param_5[4] * param_3[1] + *param_5 * *param_3 + param_5[0xc];
  param_4[2] = fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4 + fVar14;
  param_4[1] = fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2 + fVar13;
  return CONCAT44(param_2,in_EAX);
}


