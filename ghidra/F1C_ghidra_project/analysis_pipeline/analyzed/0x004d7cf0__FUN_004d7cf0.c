// Function: FUN_004d7cf0 @ 004d7cf0
// Size (bytes): 137


float10 __thiscall FUN_004d7cf0(int param_1,float param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  if (param_2 < DAT_0059e440) {
    do {
      param_2 = *(float *)(param_1 + 0x24) + param_2;
    } while (param_2 < DAT_0059e440);
  }
  for (; *(float *)(param_1 + 0x24) < param_2; param_2 = param_2 - *(float *)(param_1 + 0x24)) {
  }
  iVar4 = FUN_004d7c10(param_2);
  fVar1 = *(float *)(param_1 + 0x18 + iVar4 * 4);
  fVar2 = *(float *)(param_1 + 0x24 + iVar4 * 4);
  fVar3 = *(float *)(param_1 + 0x18 + iVar4 * 4);
  if (param_3 != (int *)0x0) {
    *param_3 = iVar4;
  }
  return ((float10)param_2 - (float10)fVar1) / ((float10)fVar2 - (float10)fVar3);
}


