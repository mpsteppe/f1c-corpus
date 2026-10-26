// Function: FUN_004f6a50 @ 004f6a50
// Size (bytes): 76


void __thiscall FUN_004f6a50(int param_1,float param_2,float *param_3)

{
  if (*(char *)(param_1 + 0x4d4) != '\0') {
    *param_3 = param_2 * (float)*(double *)(param_1 + 0x4e0) +
               param_2 * (float)*(double *)(param_1 + 0x4f0) +
               param_2 * (float)*(double *)(param_1 + 0x4e8) * param_2 +
               (float)*(double *)(param_1 + 0x4d8);
    return;
  }
  *param_3 = 0.0;
  return;
}


