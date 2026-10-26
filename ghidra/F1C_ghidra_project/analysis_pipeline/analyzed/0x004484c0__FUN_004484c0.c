// Function: FUN_004484c0 @ 004484c0
// Size (bytes): 35


void __thiscall FUN_004484c0(float *param_1,float *param_2,float *param_3)

{
  *param_1 = *param_2 - *param_3;
  *(double *)(param_1 + 1) = *(double *)(param_2 + 1) - *(double *)(param_3 + 1);
  param_1[3] = param_2[3] - param_3[3];
  return;
}


