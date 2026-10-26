// Function: FUN_004fb260 @ 004fb260
// Size (bytes): 121


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fb260(float *param_1,float param_2)

{
  float fVar1;
  
  fVar1 = param_2 * param_1[6] + (_DAT_0059e43c - param_2) * param_1[7];
  param_1[0x28] = fVar1;
  param_1[0x25] = fVar1 * param_1[8] + *param_1;
  param_1[0x26] = fVar1 * param_1[9] + param_1[1];
  param_1[0x27] = fVar1 * param_1[10] + param_1[2];
  return;
}


