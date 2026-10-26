// Function: FUN_004f6880 @ 004f6880
// Size (bytes): 44


float10 __thiscall FUN_004f6880(int param_1,double param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)param_2;
  if (*(char *)(param_1 + 0x56c) == '\0') {
    fVar1 = (float10)FUN_005881f0();
    fVar1 = fVar1 * (float10)*(double *)(param_1 + 0x590);
  }
  return fVar1 + (float10)*(double *)(param_1 + 0x588);
}


