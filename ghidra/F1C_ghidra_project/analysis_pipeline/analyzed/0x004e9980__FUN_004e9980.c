// Function: FUN_004e9980 @ 004e9980
// Size (bytes): 188


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004e9980(int param_1)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar3 = (float10)*(float *)(param_1 + 0x3b60) - (float10)*(float *)(param_1 + 0x34d4);
  fVar4 = (float10)*(float *)(param_1 + 0x3b64) - (float10)*(float *)(param_1 + 0x34d8);
  fVar5 = (float10)*(float *)(param_1 + 0x3b68) - (float10)*(float *)(param_1 + 0x34dc);
  fVar1 = (float)(fVar3 * (float10)*(float *)(param_1 + 0x34b0) +
                 fVar4 * (float10)*(float *)(param_1 + 0x34bc) +
                 fVar5 * (float10)*(float *)(param_1 + 0x34c8));
  fVar2 = (float)(fVar3 * (float10)*(float *)(param_1 + 0x34b4) +
                 fVar4 * (float10)*(float *)(param_1 + 0x34c0) +
                 fVar5 * (float10)*(float *)(param_1 + 0x34cc));
  fVar3 = fVar3 * (float10)*(float *)(param_1 + 0x34b8) +
          fVar4 * (float10)*(float *)(param_1 + 0x34c4) +
          fVar5 * (float10)*(float *)(param_1 + 0x34d0);
  fVar3 = SQRT((float10)fVar1 * (float10)fVar1 + (float10)fVar2 * (float10)fVar2 + fVar3 * fVar3) +
          (float10)_DAT_005ad1d8;
  if (fVar3 < (float10)*(float *)(param_1 + 0x3b6c)) {
    fVar3 = (float10)*(float *)(param_1 + 0x3b6c);
  }
  return fVar3;
}


