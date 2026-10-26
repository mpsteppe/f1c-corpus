// Function: FUN_004d7ff0 @ 004d7ff0
// Size (bytes): 315


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d7ff0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 extraout_ST0;
  float10 fVar4;
  undefined4 uVar5;
  
  *(float *)(param_1 + 0xc) = (float)_DAT_008afe98 + *(float *)(param_1 + 0xc);
  iVar3 = __ftol();
  fVar4 = extraout_ST0 - (float10)iVar3 * (float10)_DAT_0059f118;
  if (fVar4 < (float10)_DAT_0059e7e8) {
    return;
  }
  fVar4 = fVar4 - (float10)_DAT_0059e7e8;
  fVar1 = (float)fVar4;
  if (fVar4 < (float10)_DAT_0059e450) {
    FUN_004d8130(_DAT_0059e43c - ((_DAT_0059e450 - fVar1) + (_DAT_0059e450 - fVar1)),1);
    return;
  }
  if (fVar1 < _DAT_0059e8a4) {
    FUN_004d8130(0x3f800000,1);
    return;
  }
  if (_DAT_0059e800 <= fVar1) {
    if (fVar1 < _DAT_0059e8e4) {
      FUN_004d8130(_DAT_0059e43c - ((_DAT_0059e8e4 - fVar1) + (_DAT_0059e8e4 - fVar1)),0);
      return;
    }
    if (fVar1 < _DAT_005acce8) {
      FUN_004d8130(0x3f800000,0);
      return;
    }
    if (_DAT_0059e46c <= fVar1) {
      return;
    }
    uVar5 = 0;
    fVar2 = _DAT_0059e46c;
  }
  else {
    uVar5 = 1;
    fVar2 = _DAT_0059e800;
  }
  FUN_004d8130((fVar2 - fVar1) + (fVar2 - fVar1),uVar5);
  return;
}


