// Function: FUN_004ed810 @ 004ed810
// Size (bytes): 322


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ed810(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  
  pfVar4 = (float *)(param_1 + 0x35dc);
  fVar1 = _DAT_008afef0 + _DAT_005acafc;
  pfVar3 = (float *)(param_1 + 0x8cc);
  iVar5 = 4;
  fVar2 = ((fVar1 - *pfVar4) *
           (ABS(*(float *)(param_1 + 0x3500)) * *(float *)(param_1 + 0x3a40) +
           *(float *)(param_1 + 0x3a3c)) +
          (ABS(*(float *)(param_1 + 0x35b0)) * *(float *)(param_1 + 0x35d8) +
          ABS(*(float *)(param_1 + 0x36a8)) * *(float *)(param_1 + 0x36d0)) *
          *(float *)(param_1 + 0x3a38) * _DAT_0059e450) * param_2 + *pfVar4;
  *pfVar4 = fVar2;
  *(float *)(param_1 + 0x36d4) = fVar2;
  fVar1 = ((fVar1 - *(float *)(param_1 + 0x37cc)) *
           (ABS(*(float *)(param_1 + 0x3500)) * *(float *)(param_1 + 0x3a54) +
           *(float *)(param_1 + 0x3a50)) +
          (ABS(*(float *)(param_1 + 0x37a0)) * *(float *)(param_1 + 0x37c8) +
          ABS(*(float *)(param_1 + 0x3898)) * *(float *)(param_1 + 0x38c0)) *
          *(float *)(param_1 + 0x3a4c) * _DAT_0059e450) * param_2 + *(float *)(param_1 + 0x37cc);
  *(float *)(param_1 + 0x37cc) = fVar1;
  *(float *)(param_1 + 0x38c4) = fVar1;
  do {
    fVar1 = (*pfVar4 - (float)_DAT_0059eec8) * (float)_DAT_0059eec0;
    fVar2 = DAT_0059e440;
    if ((DAT_0059e440 <= fVar1) && (fVar2 = fVar1, _DAT_0059e43c < fVar1)) {
      fVar2 = _DAT_0059e43c;
    }
    *pfVar3 = fVar2;
    pfVar4 = pfVar4 + 0x3e;
    pfVar3 = pfVar3 + 0x4a;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}


