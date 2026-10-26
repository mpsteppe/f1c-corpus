// Function: FUN_00406060 @ 00406060
// Size (bytes): 81


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00406060(int param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x54);
  return (((float10)*(float *)(iVar1 + 0x70) * (float10)*param_2 +
          (float10)*(float *)(iVar1 + 0x74) * (float10)param_2[1] +
          (float10)*(float *)(iVar1 + 0x78) * (float10)param_2[2]) * (float10)_DAT_0059e4e8 +
         (float10)_DAT_0059e43c) * (float10)_DAT_0059e450;
}


