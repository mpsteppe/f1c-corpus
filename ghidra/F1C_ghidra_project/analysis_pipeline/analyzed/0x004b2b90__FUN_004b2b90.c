// Function: FUN_004b2b90 @ 004b2b90
// Size (bytes): 95


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2b90(int param_1,float param_2)

{
  if (param_2 < _DAT_0059e7fc != (param_2 == _DAT_0059e7fc)) {
    *(uint *)(param_1 + 0xf) = *(uint *)(param_1 + 0xf) & 0xfffffffc;
    return;
  }
  if (param_2 < _DAT_0059e908) {
    *(uint *)(param_1 + 0xf) = *(uint *)(param_1 + 0xf) & 0xfffffffd | 1;
    return;
  }
  if (param_2 < _DAT_0059ee8c) {
    *(uint *)(param_1 + 0xf) = *(uint *)(param_1 + 0xf) & 0xfffffffe | 2;
    return;
  }
  *(uint *)(param_1 + 0xf) = *(uint *)(param_1 + 0xf) | 3;
  return;
}


