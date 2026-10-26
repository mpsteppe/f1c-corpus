// Function: FUN_004f3190 @ 004f3190
// Size (bytes): 89


void __thiscall FUN_004f3190(char *param_1,float param_2,float *param_3,float *param_4)

{
  if (*param_1 != '\0') {
    *param_3 = param_2 * (float)*(double *)(param_1 + 0xc) +
               param_2 * (float)*(double *)(param_1 + 0x14) * param_2 +
               (float)*(double *)(param_1 + 4);
    *param_4 = param_2 * (float)*(double *)(param_1 + 0x24) +
               param_2 * (float)*(double *)(param_1 + 0x2c) * param_2 +
               (float)*(double *)(param_1 + 0x1c);
    return;
  }
  *param_3 = 0.0;
  *param_4 = 0.0;
  return;
}


