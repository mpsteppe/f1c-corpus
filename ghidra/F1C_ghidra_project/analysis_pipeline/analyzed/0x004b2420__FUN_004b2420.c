// Function: FUN_004b2420 @ 004b2420
// Size (bytes): 89


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2420(undefined4 *param_1,undefined4 *param_2,float *param_3)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  *param_3 = (float)(int)*(short *)(param_1 + 3) * _DAT_0059e77c;
  param_3[1] = (float)(int)*(short *)((int)param_1 + 0xe) * _DAT_0059e77c;
  param_3[2] = (float)(int)*(short *)(param_1 + 4) * _DAT_0059e77c;
  return;
}


