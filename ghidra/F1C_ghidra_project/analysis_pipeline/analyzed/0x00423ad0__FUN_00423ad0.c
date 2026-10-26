// Function: FUN_00423ad0 @ 00423ad0
// Size (bytes): 56


float10 __fastcall FUN_00423ad0(float *param_1,float *param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)param_1[2] * (float10)param_1[2] + (float10)*param_1 * (float10)*param_1;
  if (fVar1 != (float10)DAT_0059e440) {
    return ((float10)*param_1 * (float10)*param_2 + (float10)param_2[2] * (float10)param_1[2]) /
           fVar1;
  }
  return (float10)DAT_0059e440;
}


