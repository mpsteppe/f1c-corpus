// Function: FUN_004fd6f0 @ 004fd6f0
// Size (bytes): 229


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fd6f0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_1 + 0x28);
  fVar3 = *(float *)(param_1 + 0x2c) - *(float *)(param_1 + 0x28);
  *(float *)(param_1 + 100) = _DAT_0059e448 * fVar3 + fVar1;
  *(float *)(param_1 + 0x68) = _DAT_005acd48 * fVar3 + fVar1;
  fVar2 = _DAT_0059e444 * fVar3 + fVar1;
  *(float *)(param_1 + 0x6c) = fVar2;
  *(float *)(param_1 + 0x70) = fVar3 * DAT_0059e440 + fVar1;
  *(float *)(param_1 + 0x74) = fVar2;
  *(float *)(param_1 + 0x78) = _DAT_0059e454 * fVar3 + fVar1;
  *(float *)(param_1 + 0x7c) = _DAT_005ad150 * fVar3 + fVar1;
  *(float *)(param_1 + 0x80) = _DAT_0059e7f8 * fVar3 + fVar1;
  *(float *)(param_1 + 0x84) = _DAT_005ad2cc * fVar3 + fVar1;
  *(float *)(param_1 + 0x88) = _DAT_0059e450 * fVar3 + fVar1;
  *(float *)(param_1 + 0x8c) = _DAT_005ad2c8 * fVar3 + fVar1;
  *(float *)(param_1 + 0x90) = _DAT_0059e7fc * fVar3 + fVar1;
  *(float *)(param_1 + 0x94) = _DAT_005ad2c4 * fVar3 + fVar1;
  *(float *)(param_1 + 0x98) = _DAT_005acdc0 * fVar3 + fVar1;
  *(float *)(param_1 + 0x9c) = _DAT_005ad2c0 * fVar3 + fVar1;
  *(float *)(param_1 + 0xa0) = fVar3 + fVar1;
  return;
}


