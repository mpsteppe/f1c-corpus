// Function: FUN_00435e00 @ 00435e00
// Size (bytes): 81


void __thiscall FUN_00435e00(double *param_1,double *param_2,double *param_3)

{
  *param_3 = *param_2 * *param_1 + param_1[1] * param_2[1] + param_1[2] * param_2[2];
  param_3[1] = param_1[4] * param_2[1] + param_1[5] * param_2[2] + param_1[3] * *param_2;
  param_3[2] = param_1[7] * param_2[1] + param_1[8] * param_2[2] + param_1[6] * *param_2;
  return;
}


