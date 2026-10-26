// Function: FUN_004f69e0 @ 004f69e0
// Size (bytes): 105


void __thiscall
FUN_004f69e0(int param_1,float param_2,float param_3,float param_4,float *param_5,float *param_6)

{
  *param_6 = param_3 * (float)*(double *)(param_1 + 0x520) +
             param_2 * (float)*(double *)(param_1 + 0x530) + (float)*(double *)(param_1 + 0x4ac);
  *param_5 = ABS((float)*(double *)(param_1 + 0x444));
  param_5[1] = ABS((float)*(double *)(param_1 + 0x47c));
  param_5[2] = param_4 * (float)*(double *)(param_1 + 0x3fc) +
               param_3 * (float)*(double *)(param_1 + 0x518) +
               param_2 * (float)*(double *)(param_1 + 0x528) + (float)*(double *)(param_1 + 0x3f4);
  return;
}


