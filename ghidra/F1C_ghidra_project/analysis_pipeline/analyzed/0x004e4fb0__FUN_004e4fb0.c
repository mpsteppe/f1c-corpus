// Function: FUN_004e4fb0 @ 004e4fb0
// Size (bytes): 198


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e4fb0(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + 0x39c8) = param_2;
  iVar3 = *(int *)(unaff_ESI + 0x39b4) - unaff_EDI;
  fVar1 = *(float *)(unaff_ESI + 0x39c8) * *(float *)(unaff_ESI + 0x3988) *
          *(float *)(unaff_ESI + 0x39c8);
  if (*(int *)(unaff_ESI + 0x39b4) == unaff_EDI) {
    fVar1 = fVar1 * _DAT_0059e450 + *(float *)(unaff_ESI + 0x37d4);
    *(float *)(unaff_ESI + 0x37d8) = fVar1;
    fVar2 = _DAT_0059e43c / fVar1;
    *(float *)(unaff_ESI + 0x37dc) = fVar2;
    *(float *)(unaff_ESI + 0x38d0) = fVar1;
    *(float *)(unaff_ESI + 0x38d4) = fVar2;
    return;
  }
  if (iVar3 == 1) {
    fVar1 = fVar1 * _DAT_0059e7f8;
    iVar3 = 4;
    pfVar4 = (float *)(unaff_ESI + 0x35e8);
    do {
      iVar3 = iVar3 + -1;
      fVar2 = fVar1 + pfVar4[-1];
      *pfVar4 = fVar2;
      pfVar4[1] = _DAT_0059e43c / fVar2;
      pfVar4 = pfVar4 + 0x3e;
    } while (iVar3 != 0);
  }
  else if (iVar3 == 2) {
    fVar1 = fVar1 * _DAT_0059e450 + *(float *)(unaff_ESI + 0x35e4);
    *(float *)(unaff_ESI + 0x35e8) = fVar1;
    fVar2 = _DAT_0059e43c / fVar1;
    *(float *)(unaff_ESI + 0x35ec) = fVar2;
    *(float *)(unaff_ESI + 0x36e0) = fVar1;
    *(float *)(unaff_ESI + 0x36e4) = fVar2;
    return;
  }
  return;
}


