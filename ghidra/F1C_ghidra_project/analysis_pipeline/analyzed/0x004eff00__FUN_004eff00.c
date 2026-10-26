// Function: FUN_004eff00 @ 004eff00
// Size (bytes): 196


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004eff00(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  
  if (((*(float *)(param_1 + 0x34ec) == DAT_0059e440) &&
      (*(float *)(param_1 + 0x34f0) == DAT_0059e440)) &&
     (*(float *)(param_1 + 0x34f4) == DAT_0059e440)) {
    return (float10)DAT_0059e440;
  }
  fVar1 = *(float *)(param_1 + 0x34ec);
  fVar2 = *(float *)(param_1 + 0x34f0);
  fVar3 = *(float *)(param_1 + 0x34f4);
  fVar4 = (float10)_DAT_0059e43c /
          SQRT((float10)fVar1 * (float10)fVar1 +
               (float10)fVar2 * (float10)fVar2 + (float10)fVar3 * (float10)fVar3);
  return -((float10)(float)((float10)fVar1 * fVar4) * (float10)*(float *)(param_1 + 0x34b8) +
          (float10)(float)((float10)fVar2 * fVar4) * (float10)*(float *)(param_1 + 0x34c4) +
          fVar4 * (float10)fVar3 * (float10)*(float *)(param_1 + 0x34d0));
}


