// Function: FUN_0055d460 @ 0055d460
// Size (bytes): 134


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0055d460(int param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  
  *(float *)(param_1 + 0x44) = param_2;
  *(float *)(param_1 + 0x4c) = param_4;
  *(float *)(param_1 + 0x48) = param_3;
  fVar1 = SQRT(param_4 * param_4 + param_3 * param_3 + param_2 * param_2);
  if (fVar1 != (float)_DAT_0059e430) {
    fVar1 = _DAT_0059e43c / fVar1;
    *(float *)(param_1 + 0x44) = param_2 * fVar1;
    *(float *)(param_1 + 0x48) = param_3 * fVar1;
    *(float *)(param_1 + 0x4c) = fVar1 * param_4;
  }
  FUN_005416a0(param_1,*(undefined4 *)(param_1 + 4),5);
  *(uint *)(DAT_008b8f28 + 0xec) = *(uint *)(DAT_008b8f28 + 0xec) | 0x800;
  return;
}


