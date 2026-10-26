// Function: FUN_004e8780 @ 004e8780
// Size (bytes): 84


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004e8780(int param_1)

{
  float10 fVar1;
  
  if (*(float *)(param_1 + 0x39ac) == DAT_0059e440) {
    return (float10)DAT_0059e440;
  }
  fVar1 = -((float10)*(float *)(param_1 + 0x39a8) / (float10)*(float *)(param_1 + 0x39ac));
  if (fVar1 < (float10)DAT_0059e440) {
    return (float10)DAT_0059e440;
  }
  if ((float10)_DAT_0059e43c < fVar1) {
    fVar1 = (float10)_DAT_0059e43c;
  }
  return fVar1;
}


