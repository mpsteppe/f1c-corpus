// Function: FUN_00567400 @ 00567400
// Size (bytes): 190


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00567400(float *param_1,float param_2,float *param_3)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar2 = (float10)fsin((float10)param_2);
  fVar3 = (float10)fcos((float10)param_2);
  fVar1 = *param_1;
  *param_1 = (float)((float10)fVar1 * fVar3 - (float10)param_1[2] * fVar2);
  param_1[2] = (float)((float10)fVar1 * fVar2 + (float10)param_1[2] * fVar3);
  fVar1 = param_1[3];
  param_1[3] = (float)((float10)fVar1 * fVar3 - (float10)param_1[5] * fVar2);
  param_1[5] = (float)((float10)fVar1 * fVar2 + (float10)param_1[5] * fVar3);
  fVar1 = param_1[6];
  param_1[6] = (float)((float10)fVar1 * fVar3 - (float10)param_1[8] * fVar2);
  param_1[8] = (float)((float10)fVar1 * fVar2 + (float10)param_1[8] * fVar3);
  fVar2 = (float10)FUN_00588570();
  *param_3 = (float)-fVar2;
  if (ABS(param_1[5]) != (float)_DAT_0059e420) {
    fVar2 = (float10)fpatan((float10)param_1[2],(float10)param_1[8]);
    param_3[1] = (float)fVar2;
    fVar2 = (float10)fpatan((float10)param_1[3],(float10)param_1[4]);
    param_3[2] = (float)fVar2;
    return;
  }
  fVar2 = (float10)fpatan(-(float10)param_1[6],(float10)*param_1);
  param_3[2] = 0.0;
  param_3[1] = (float)fVar2;
  return;
}


