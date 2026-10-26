// Function: FUN_004e87e0 @ 004e87e0
// Size (bytes): 193


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004e87e0(int param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar1 = *(float *)(param_1 + 0x3500) -
          (*(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x3a58) +
          *(float *)(param_1 + 0x3a5c) * *(float *)(param_1 + 0x34c4) +
          *(float *)(param_1 + 0x3a60) * *(float *)(param_1 + 0x34d0));
  if (*(float *)(param_1 + 0x39c8) == DAT_0059e440) {
    return (float10)DAT_0059e440;
  }
  if (*(float *)(param_1 + 0x39ac) == DAT_0059e440) {
    return (float10)DAT_0059e440;
  }
  fVar2 = (((float10)fVar1 * (float10)*(float *)(param_1 + 0x3d44) * (float10)fVar1 *
           (float10)*(float *)(param_1 + 0x3d40)) / (float10)*(float *)(param_1 + 0x39c8) -
          (float10)*(float *)(param_1 + 0x39a8)) / (float10)*(float *)(param_1 + 0x39ac);
  if (fVar2 < (float10)DAT_0059e440) {
    return (float10)DAT_0059e440;
  }
  if ((float10)_DAT_0059e43c < fVar2) {
    fVar2 = (float10)_DAT_0059e43c;
  }
  return fVar2;
}


