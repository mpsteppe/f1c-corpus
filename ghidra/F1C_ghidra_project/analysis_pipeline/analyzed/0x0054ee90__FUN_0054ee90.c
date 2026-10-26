// Function: FUN_0054ee90 @ 0054ee90
// Size (bytes): 49


float10 __fastcall FUN_0054ee90(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  return ((float10)*(float *)(param_1 + param_4 * 4) - (float10)*(float *)(param_2 + param_4 * 4)) *
         ((float10)*(float *)(param_3 + param_5 * 4) - (float10)*(float *)(param_2 + param_5 * 4)) -
         ((float10)*(float *)(param_3 + param_4 * 4) - (float10)*(float *)(param_2 + param_4 * 4)) *
         ((float10)*(float *)(param_1 + param_5 * 4) - (float10)*(float *)(param_2 + param_5 * 4));
}


