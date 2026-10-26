// Function: FUN_004e4f40 @ 004e4f40
// Size (bytes): 116


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e4f40(int param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x354c) = 0;
  *(undefined4 *)(param_1 + 0x3550) = 0;
  *(undefined4 *)(param_1 + 0x3554) = 0;
  *(undefined4 *)(param_1 + 0x3558) = 0;
  *(undefined4 *)(param_1 + 0x355c) = 0;
  *(undefined4 *)(param_1 + 0x3560) = 0;
  if (DAT_0059e440 < *(float *)(param_1 + 0x3a04)) {
    FUN_004e5080();
  }
  iVar4 = *(int *)(param_1 + 0x39f0);
  if (iVar4 != *(int *)(param_1 + 0x39f4)) {
    *(int *)(param_1 + 0x39f4) = iVar4;
    if (iVar4 != 0) {
      FUN_0059daef();
      return;
    }
    *(undefined4 *)(param_1 + 0x39c8) = 0;
    iVar4 = *(int *)(param_1 + 0x39b4);
    fVar1 = *(float *)(param_1 + 0x39c8) * *(float *)(param_1 + 0x3988) *
            *(float *)(param_1 + 0x39c8);
    if (iVar4 == 0) {
      fVar1 = fVar1 * _DAT_0059e450 + *(float *)(param_1 + 0x37d4);
      *(float *)(param_1 + 0x37d8) = fVar1;
      fVar2 = _DAT_0059e43c / fVar1;
      *(float *)(param_1 + 0x37dc) = fVar2;
      *(float *)(param_1 + 0x38d0) = fVar1;
      *(float *)(param_1 + 0x38d4) = fVar2;
      return;
    }
    if (iVar4 == 1) {
      fVar1 = fVar1 * _DAT_0059e7f8;
      iVar4 = 4;
      pfVar3 = (float *)(param_1 + 0x35e8);
      do {
        iVar4 = iVar4 + -1;
        fVar2 = fVar1 + pfVar3[-1];
        *pfVar3 = fVar2;
        pfVar3[1] = _DAT_0059e43c / fVar2;
        pfVar3 = pfVar3 + 0x3e;
      } while (iVar4 != 0);
    }
    else if (iVar4 == 2) {
      fVar1 = fVar1 * _DAT_0059e450 + *(float *)(param_1 + 0x35e4);
      *(float *)(param_1 + 0x35e8) = fVar1;
      fVar2 = _DAT_0059e43c / fVar1;
      *(float *)(param_1 + 0x35ec) = fVar2;
      *(float *)(param_1 + 0x36e0) = fVar1;
      *(float *)(param_1 + 0x36e4) = fVar2;
      return;
    }
  }
  return;
}


