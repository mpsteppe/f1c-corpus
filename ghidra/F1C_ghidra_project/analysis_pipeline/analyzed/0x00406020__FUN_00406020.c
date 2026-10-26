// Function: FUN_00406020 @ 00406020
// Size (bytes): 56


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00406020(int param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)*(float *)(param_1 + 0x1c) * (float10)param_2 +
          (float10)*(float *)(param_1 + 0x20);
  if (fVar1 < (float10)_DAT_0059e43c) {
    return (float10)*(float *)(param_1 + 0x40);
  }
  fVar1 = (float10)_DAT_0059e43c / fVar1;
  return ((fVar1 * fVar1 * fVar1 - fVar1) * (float10)*(float *)(param_1 + 0x24) + fVar1) *
         (float10)*(float *)(param_1 + 0x40);
}


