// Function: FUN_00443b70 @ 00443b70
// Size (bytes): 149


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00443b70(int param_1)

{
  double dVar1;
  undefined4 uVar2;
  double dVar3;
  char cVar4;
  uint uVar5;
  undefined4 unaff_EBX;
  float10 extraout_ST0;
  float10 fVar6;
  
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (*(int *)(param_1 + 0x1ef8) != 0) {
    FUN_0059d7ea();
    return;
  }
  dVar1 = (double)(*(double *)(param_1 + 0x1ce4) < *(double *)(param_1 + 0x1c5c));
  if ((dVar1 != _DAT_0059e430) || (*(char *)(param_1 + 0x1c58) != '\0')) {
    uVar2 = *(undefined4 *)(param_1 + 8);
    dVar3 = *(double *)(param_1 + 8);
    if ((dVar1 != _DAT_0059e430) &&
       (dVar1 = (*(double *)(param_1 + 0x1cec) - *(double *)(param_1 + 0x1c5c)) /
                (*(double *)(param_1 + 0x1cec) - *(double *)(param_1 + 0x1ce4)),
       dVar1 < *(double *)(param_1 + 8))) {
      if (dVar1 < _DAT_0059e430) {
        dVar1 = _DAT_0059e430;
      }
      *(double *)(param_1 + 8) = dVar1;
    }
    if ((*(char *)(param_1 + 0x1c58) != '\0') && (*(int *)(param_1 + 0x1ef0) != 0)) {
      FUN_0059d806(unaff_EBX,uVar2);
      return;
    }
    dVar1 = (dVar3 - *(double *)(param_1 + 8)) * _DAT_0059edc0;
    if (*(double *)(param_1 + 0x170) < dVar1) {
      *(double *)(param_1 + 0x170) = dVar1;
    }
  }
  if (*(double *)(param_1 + 0x1c5c) < *(double *)(param_1 + 0x1c8c)) {
    if (*(double *)(param_1 + 0x1c5c) <= *(double *)(param_1 + 0x1c84)) {
      dVar1 = *(double *)(param_1 + 0x1c7c);
    }
    else {
      dVar1 = ((*(double *)(param_1 + 0x1c8c) - *(double *)(param_1 + 0x1c5c)) *
              *(double *)(param_1 + 0x1c7c)) /
              (*(double *)(param_1 + 0x1c8c) - *(double *)(param_1 + 0x1c84));
    }
    if (*(double *)(param_1 + 8) < dVar1) {
      *(double *)(param_1 + 8) = dVar1;
    }
    if (((((*(double *)(param_1 + 0x1c5c) <= *(double *)(param_1 + 0x1c84) * _DAT_0059ed98) &&
          (*(double *)(param_1 + 0x1d10) < _DAT_0059e430 !=
           (*(double *)(param_1 + 0x1d10) == _DAT_0059e430))) && (DAT_007c56a8 != 2)) &&
        ((DAT_007ce254 == '\0' && (DAT_007cc6e0 == 0)))) &&
       ((DAT_007cc6e4 == 0x59 && (cVar4 = FUN_00447160(), cVar4 != '\0')))) {
      FUN_00447e00(0,4);
      FUN_004471f0(0);
    }
  }
  if (_DAT_0059e430 < *(double *)(param_1 + 0x1d10)) {
    dVar1 = *(double *)(param_1 + 0x1d10);
    dVar3 = *(double *)(param_1 + 0x1d10) - *(double *)(param_1 + 0x68);
    *(double *)(param_1 + 0x1d10) = dVar3;
    if (((dVar3 < *(double *)(param_1 + 0x1d28) != (dVar3 == *(double *)(param_1 + 0x1d28))) &&
        (*(double *)(param_1 + 0x1d28) < dVar1)) &&
       (*(double *)(param_1 + 0x1c5c) < *(double *)(param_1 + 0x1c84))) {
      FUN_004f87c0(0x27,2,0x3f800000,0x3f800000);
    }
    if ((*(double *)(param_1 + 0x1d10) < _DAT_0059e430 !=
         (*(double *)(param_1 + 0x1d10) == _DAT_0059e430)) &&
       (*(double *)(param_1 + 0x1c5c) < *(double *)(param_1 + 0x1c84))) {
      *(undefined4 *)(param_1 + 0x1c5c) = *(undefined4 *)(param_1 + 0x1c84);
      *(undefined4 *)(param_1 + 0x1c60) = *(undefined4 *)(param_1 + 0x1c88);
    }
  }
  if (_DAT_0059e430 < *(double *)(param_1 + 0x1dac)) {
    FUN_0058957a();
    uVar5 = __ftol();
    fVar6 = (extraout_ST0 - (float10)(int)uVar5) *
            ((float10)*(float *)(&DAT_008aae74 + (uVar5 + 1 & 0xff) * 4) -
            (float10)*(float *)(&DAT_008aae74 + (uVar5 & 0xff) * 4)) +
            (float10)*(float *)(&DAT_008aae74 + (uVar5 & 0xff) * 4);
    *(double *)(param_1 + 8) =
         (double)(((float10)_DAT_0059e420 - fVar6 * (float10)*(double *)(param_1 + 0x1dac) * fVar6)
                 * (float10)*(double *)(param_1 + 8));
  }
  fVar6 = (float10)FUN_00447b10();
  *(double *)(param_1 + 8) = (double)(fVar6 * (float10)*(double *)(param_1 + 8));
  return;
}


