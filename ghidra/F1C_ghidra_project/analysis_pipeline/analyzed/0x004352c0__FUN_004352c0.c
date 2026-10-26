// Function: FUN_004352c0 @ 004352c0
// Size (bytes): 196


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004352c0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar1 = *param_4;
  fVar2 = param_4[2];
  if (fVar1 == DAT_0059e440) {
    if (fVar2 == DAT_0059e440) {
      return (float10)_DAT_0059eae0;
    }
    fVar4 = ((float10)*param_3 - (float10)*param_1) -
            (float10)(fVar1 / fVar2) * (float10)(param_3[2] - param_1[2]);
    fVar3 = (float10)*param_2 - (float10)(fVar1 / fVar2) * (float10)param_2[2];
  }
  else {
    fVar4 = (float10)(param_3[2] - param_1[2]) -
            ((float10)*param_3 - (float10)*param_1) * (float10)(fVar2 / fVar1);
    fVar3 = (float10)param_2[2] - (float10)(fVar2 / fVar1) * (float10)*param_2;
  }
  if (fVar3 == (float10)DAT_0059e440) {
    return (float10)_DAT_0059eae0;
  }
  return fVar4 / fVar3;
}


