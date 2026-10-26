// Function: FUN_004646c0 @ 004646c0
// Size (bytes): 44


void __thiscall FUN_004646c0(float *param_1,float param_2,float param_3)

{
  if (*param_1 < param_2) {
    *param_1 = param_2;
    return;
  }
  if (param_3 < *param_1) {
    *param_1 = param_3;
  }
  return;
}


