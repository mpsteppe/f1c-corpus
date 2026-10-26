// Function: FUN_00566ee0 @ 00566ee0
// Size (bytes): 91


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00566ee0(float *param_1,float *param_2)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = SQRT((float10)param_1[4] * (float10)param_1[4] + (float10)param_1[3] * (float10)param_1[3]
              );
  fVar3 = (float10)_DAT_005b8968;
  fVar2 = (float10)fpatan(-(float10)param_1[5],fVar1);
  *param_2 = (float)fVar2;
  if (fVar3 < fVar1) {
    fVar3 = (float10)fpatan((float10)param_1[2],(float10)param_1[8]);
    param_2[1] = (float)fVar3;
    fVar3 = (float10)fpatan((float10)param_1[3],(float10)param_1[4]);
    param_2[2] = (float)fVar3;
    return;
  }
  fVar3 = (float10)fpatan(-(float10)param_1[6],(float10)*param_1);
  param_2[2] = 0.0;
  param_2[1] = (float)fVar3;
  return;
}


