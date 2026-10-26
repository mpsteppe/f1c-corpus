// Function: FUN_004f68b0 @ 004f68b0
// Size (bytes): 152


void __thiscall FUN_004f68b0(int param_1,float param_2,float param_3,float *param_4,float *param_5)

{
  if (*(char *)(param_1 + 0x1ec) != '\0') {
    *param_5 = param_2 * (float)*(double *)(param_1 + 0x218) +
               param_2 * (float)*(double *)(param_1 + 0x220) * param_2 +
               (param_3 + (float)*(double *)(param_1 + 0x2e8)) * (float)*(double *)(param_1 + 0x228)
               + (float)*(double *)(param_1 + 0x210);
    *param_4 = ABS((float)*(double *)(param_1 + 0x250));
    param_4[1] = ABS((float)*(double *)(param_1 + 0x288));
    param_4[2] = param_2 * (float)*(double *)(param_1 + 0x200) +
                 param_2 * (float)*(double *)(param_1 + 0x208) * param_2 +
                 (float)*(double *)(param_1 + 0x1f8);
    return;
  }
  *param_5 = 0.0;
  *param_4 = 0.0;
  param_4[1] = 0.0;
  param_4[2] = 0.0;
  return;
}


