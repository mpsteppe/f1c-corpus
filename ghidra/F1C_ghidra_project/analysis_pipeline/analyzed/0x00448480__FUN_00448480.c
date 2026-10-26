// Function: FUN_00448480 @ 00448480
// Size (bytes): 53


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00448480(float *param_1,float *param_2,float *param_3)

{
  *param_1 = (*param_2 + *param_3) * _DAT_0059e450;
  *(double *)(param_1 + 1) = (*(double *)(param_2 + 1) + *(double *)(param_3 + 1)) * _DAT_0059e880;
  param_1[3] = (param_2[3] + param_3[3]) * _DAT_0059e450;
  return;
}


