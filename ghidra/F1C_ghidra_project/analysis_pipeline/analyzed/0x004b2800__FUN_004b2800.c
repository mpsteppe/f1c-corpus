// Function: FUN_004b2800 @ 004b2800
// Size (bytes): 55


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2800(int param_1,float *param_2)

{
  param_2[1] = 0.0;
  *param_2 = (float)(int)*(short *)(param_1 + 0x28) * _DAT_0059e4d8;
  param_2[2] = (float)(int)*(short *)(param_1 + 0x2a) * _DAT_0059e4d8;
  return;
}


