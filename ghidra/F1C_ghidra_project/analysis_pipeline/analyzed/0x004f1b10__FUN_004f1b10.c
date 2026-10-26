// Function: FUN_004f1b10 @ 004f1b10
// Size (bytes): 58


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004f1b10(int param_1)

{
  float10 fVar1;
  
  fVar1 = ABS((float10)*(float *)(param_1 + 0x3964) / (float10)*(float *)(param_1 + 0x3968));
  if (fVar1 < (float10)DAT_0059e440) {
    return (float10)DAT_0059e440;
  }
  if ((float10)_DAT_0059e43c < fVar1) {
    fVar1 = (float10)_DAT_0059e43c;
  }
  return fVar1;
}


