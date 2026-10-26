// Function: FUN_004f6950 @ 004f6950
// Size (bytes): 134


void __thiscall FUN_004f6950(int param_1,float param_2,float *param_3,float *param_4)

{
  if (*(char *)(param_1 + 0x2f8) != '\0') {
    *param_4 = param_2 * (float)*(double *)(param_1 + 0x31c) +
               param_2 * (float)*(double *)(param_1 + 0x324) * param_2 +
               (float)*(double *)(param_1 + 0x314);
    *param_3 = ABS((float)*(double *)(param_1 + 0x34c));
    param_3[1] = ABS((float)*(double *)(param_1 + 900));
    param_3[2] = param_2 * (float)*(double *)(param_1 + 0x304) +
                 param_2 * (float)*(double *)(param_1 + 0x30c) * param_2 +
                 (float)*(double *)(param_1 + 0x2fc);
    return;
  }
  *param_4 = 0.0;
  *param_3 = 0.0;
  param_3[1] = 0.0;
  param_3[2] = 0.0;
  return;
}


