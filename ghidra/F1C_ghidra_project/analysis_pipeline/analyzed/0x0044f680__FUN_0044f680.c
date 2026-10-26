// Function: FUN_0044f680 @ 0044f680
// Size (bytes): 102


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044f680(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  
  param_1[3] = param_4;
  fVar1 = (float)(param_4 - param_2) * _DAT_0059e450;
  param_1[4] = param_2 + param_4 >> 1;
  fVar1 = _DAT_0059e43c / fVar1;
  param_1[1] = param_5;
  *param_1 = param_3;
  param_1[2] = param_2;
  param_1[5] = param_3 + param_5 >> 1;
  param_1[6] = (int)fVar1;
  param_1[7] = (int)(_DAT_0059e43c / ((float)(param_5 - param_3) * _DAT_0059e450));
  return;
}


