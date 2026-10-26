// Function: FUN_0044f010 @ 0044f010
// Size (bytes): 59


void __thiscall FUN_0044f010(int param_1,float param_2,float param_3)

{
  if (param_2 < DAT_0059e440) {
    param_2 = -param_2;
  }
  if (param_3 < DAT_0059e440) {
    param_3 = -param_3;
  }
  *(float *)(param_1 + 0xc7c) = -param_2;
  *(float *)(param_1 + 0xc80) = -param_3;
  return;
}


