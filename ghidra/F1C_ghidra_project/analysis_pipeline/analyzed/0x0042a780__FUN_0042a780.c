// Function: FUN_0042a780 @ 0042a780
// Size (bytes): 68


float10 __thiscall FUN_0042a780(int param_1,int param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004e8ce0(*(undefined4 *)(param_2 + 0x74),param_2 + 0x78,
                                *(undefined4 *)(param_2 + 0x70),0x41800000);
  return (fVar1 * (float10)*(float *)(param_1 + 0x4504) + (float10)*(float *)(param_1 + 0x4500)) *
         (float10)*(float *)(param_1 + 0x4580) * (float10)*(float *)(param_1 + 0x453c) *
         (float10)*(float *)(param_2 + 0x84);
}


