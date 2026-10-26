// Function: FUN_004d5ea0 @ 004d5ea0
// Size (bytes): 51


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004d5ea0(float *param_1,float param_2,float param_3)

{
  float fVar1;
  
  fVar1 = _DAT_0059eae0;
  if (DAT_0059e440 < param_3) {
    fVar1 = param_3;
  }
  param_1[1] = fVar1;
  *param_1 = (param_2 - _DAT_0059e43c) / fVar1;
  return;
}


