// Function: FUN_004bc2a0 @ 004bc2a0
// Size (bytes): 42


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004bc2a0(int param_1,int param_2)

{
  if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 8))) && (param_2 < *(int *)(param_1 + 0x88)))
  {
    return (float10)*(float *)(*(int *)(param_1 + 0x90) + param_2 * 4);
  }
  return (float10)_DAT_0059e670;
}


