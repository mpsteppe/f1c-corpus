// Function: FUN_004ed380 @ 004ed380
// Size (bytes): 157


float10 __thiscall FUN_004ed380(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = (param_3[2] * param_2[1] - param_3[1] * param_2[2]) * *(float *)(param_1 + 0x3528);
  fVar2 = ((float10)*param_3 * (float10)param_2[2] - (float10)*param_2 * (float10)param_3[2]) *
          (float10)*(float *)(param_1 + 0x352c);
  fVar3 = (float10)(*param_2 * param_3[1] - *param_3 * param_2[1]) *
          (float10)*(float *)(param_1 + 0x3530);
  return (float10)(float)(fVar2 * (float10)param_2[2] - fVar3 * (float10)param_2[1]) *
         (float10)*param_3 +
         (float10)(float)(fVar3 * (float10)*param_2 - (float10)fVar1 * (float10)param_2[2]) *
         (float10)param_3[1] +
         ((float10)fVar1 * (float10)param_2[1] - fVar2 * (float10)*param_2) * (float10)param_3[2] +
         (float10)*(float *)(param_1 + 0x3518);
}


