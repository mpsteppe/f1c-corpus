// Function: FUN_004bc270 @ 004bc270
// Size (bytes): 47


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004bc270(int param_1,int param_2)

{
  param_2 = param_2 + -1;
  if ((((*(int *)(param_1 + 0x8c) != 0) && (-1 < param_2)) && (param_2 <= *(int *)(param_1 + 8))) &&
     (param_2 < *(int *)(param_1 + 0x88))) {
    return (float10)*(float *)(*(int *)(param_1 + 0x8c) + param_2 * 4);
  }
  return (float10)_DAT_0059e670;
}


