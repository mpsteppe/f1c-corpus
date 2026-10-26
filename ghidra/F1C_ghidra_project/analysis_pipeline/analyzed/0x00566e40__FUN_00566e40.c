// Function: FUN_00566e40 @ 00566e40
// Size (bytes): 153


void __fastcall FUN_00566e40(float *param_1,float *param_2)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar2 = (float10)fsin((float10)*param_1);
  fVar3 = (float10)fcos((float10)*param_1);
  fVar4 = (float10)fsin((float10)param_1[1]);
  fVar5 = (float10)fcos((float10)param_1[1]);
  fVar1 = (float)fVar5;
  fVar5 = (float10)fsin((float10)param_1[2]);
  fVar6 = (float10)fcos((float10)param_1[2]);
  *param_2 = (float)(fVar4 * fVar2 * fVar5 + (float10)(float)(fVar6 * (float10)fVar1));
  param_2[1] = (float)(fVar4 * fVar2 * fVar6 - (float10)(float)(fVar5 * (float10)fVar1));
  param_2[2] = (float)(fVar4 * fVar3);
  param_2[3] = (float)(fVar5 * fVar3);
  param_2[4] = (float)(fVar6 * fVar3);
  param_2[5] = (float)-fVar2;
  param_2[6] = (float)((float10)(float)(fVar5 * (float10)fVar1) * fVar2 - fVar6 * fVar4);
  param_2[7] = (float)((float10)(float)(fVar6 * (float10)fVar1) * fVar2 + fVar5 * fVar4);
  param_2[8] = (float)((float10)fVar1 * fVar3);
  return;
}


