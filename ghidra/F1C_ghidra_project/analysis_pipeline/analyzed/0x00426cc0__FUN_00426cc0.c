// Function: FUN_00426cc0 @ 00426cc0
// Size (bytes): 46


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00426cc0(int param_1,int param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)_DAT_0059e670;
  if (param_2 == 0) {
    return (float10)DAT_0059e440;
  }
  if (*(int *)(param_1 + 0x4354) != 0) {
    fVar1 = (float10)*(float *)(param_2 + 0x4c) -
            (float10)*(float *)(*(int *)(param_1 + 0x4354) + 0x4c);
  }
  return fVar1;
}


