// Function: FUN_00465160 @ 00465160
// Size (bytes): 85


void __thiscall FUN_00465160(int *param_1,int param_2,int param_3)

{
  if (DAT_0059e440 < (float)param_2) {
    *(int *)(*param_1 + 0x50) = (int)(param_2 * 1000 + (param_2 * 1000 >> 0x1f & 7U)) >> 3;
  }
  if (DAT_0059e440 < (float)param_3) {
    *(int *)(*param_1 + 0x54) = (int)(param_3 * 1000 + (param_3 * 1000 >> 0x1f & 7U)) >> 3;
  }
  return;
}


