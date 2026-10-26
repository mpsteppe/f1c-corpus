// Function: FUN_004962c0 @ 004962c0
// Size (bytes): 191


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004962c0(int param_1,undefined4 param_2,float param_3)

{
  bool bVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  
  bVar1 = DAT_0059e440 <= param_3;
  iVar3 = __ftol();
  fVar4 = (float10)FUN_0058957a();
  if ((-1 < iVar3) && (iVar3 < 0x10)) {
    param_2 = *(float *)(param_1 + 0x162c + iVar3 * 4);
    fVar2 = _DAT_0059e43c;
    if (iVar3 != 0xf) {
      fVar2 = *(float *)(param_1 + 0x1630 + iVar3 * 4);
    }
    fVar5 = (float10)fVar2;
    if (bVar1) {
      fVar5 = (float10)FUN_005881f0();
      param_2 = (float)fVar5;
      fVar5 = (float10)FUN_005881f0();
    }
    return (float10)(float)fVar4 * (float10)_DAT_0059eed0 * (fVar5 - (float10)param_2) +
           (float10)param_2;
  }
  return (float10)_DAT_0059e43c;
}


