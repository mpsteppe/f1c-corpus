// Function: FUN_00567030 @ 00567030
// Size (bytes): 160


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00567030(float *param_1,float *param_2)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  fVar2 = (float10)fcos((float10)*param_1 * (float10)_DAT_0059e450);
  fVar3 = (float10)fsin((float10)*param_1 * (float10)_DAT_0059e450);
  fVar4 = (float10)fcos((float10)param_1[1] * (float10)_DAT_0059e450);
  fVar5 = (float10)fsin((float10)param_1[1] * (float10)_DAT_0059e450);
  fVar6 = (float10)fcos((float10)param_1[2] * (float10)_DAT_0059e450);
  fVar7 = (float10)fsin((float10)param_1[2] * (float10)_DAT_0059e450);
  fVar1 = (float)((float10)(float)fVar6 * fVar4);
  fVar8 = (float10)(float)fVar7 * fVar5;
  *param_2 = (float)((float10)fVar1 * fVar2 + fVar8 * fVar3);
  param_2[1] = (float)((float10)(float)fVar8 * fVar2 + (float10)fVar1 * fVar3);
  fVar1 = (float)((float10)(float)fVar6 * fVar5);
  fVar4 = fVar4 * (float10)(float)fVar7;
  param_2[2] = (float)((float10)fVar1 * fVar2 - fVar4 * fVar3);
  param_2[3] = (float)(fVar4 * fVar2 - (float10)fVar1 * fVar3);
  return;
}


