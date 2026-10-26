// Function: FUN_00543920 @ 00543920
// Size (bytes): 57


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00543920(int param_1,float param_2)

{
  if (((float)_DAT_0059e430 <= param_2) &&
     (param_2 < (float)_DAT_0059e420 != (param_2 == (float)_DAT_0059e420))) {
    *(float *)(param_1 + 400) = param_2;
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10000;
  }
  return;
}


