// Function: FUN_0051249f @ 0051249f
// Size (bytes): 54


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051249f(int param_1,double param_2,double param_3)

{
  if (_DAT_005af428 < ABS(param_2 * param_3 - _DAT_0059e420)) {
    *(byte *)(param_1 + 0x61) = *(byte *)(param_1 + 0x61) | 0x20;
  }
  *(float *)(param_1 + 0x130) = (float)param_3;
  *(float *)(param_1 + 0x134) = (float)param_2;
  return;
}


