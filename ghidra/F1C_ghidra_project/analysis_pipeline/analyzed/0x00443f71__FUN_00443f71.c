// Function: FUN_00443f71 @ 00443f71
// Size (bytes): 637


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00443f71(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  double dVar1;
  double dVar2;
  char cVar3;
  uint uVar4;
  int unaff_EBX;
  int unaff_ESI;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 in_ST1;
  float10 fVar5;
  float10 in_ST2;
  
  fVar5 = in_ST1 - ABS(in_ST0 * in_ST2);
  fVar5 = fVar5 + fVar5;
  if (fVar5 < (float10)*(double *)(unaff_ESI + 8)) {
    if (fVar5 < (float10)_DAT_0059e430) {
      fVar5 = (float10)_DAT_0059e430;
    }
    *(double *)(unaff_ESI + 8) = (double)fVar5;
  }
  dVar1 = ((double)CONCAT44(param_3,param_2) - *(double *)(unaff_ESI + 8)) * _DAT_0059edc0;
  if (*(double *)(unaff_ESI + 0x170) < dVar1) {
    *(double *)(unaff_ESI + 0x170) = dVar1;
  }
  if (*(double *)(unaff_ESI + 0x1c5c) < *(double *)(unaff_ESI + 0x1c8c)) {
    if (*(double *)(unaff_ESI + 0x1c5c) <= *(double *)(unaff_ESI + 0x1c84)) {
      dVar1 = *(double *)(unaff_ESI + 0x1c7c);
    }
    else {
      dVar1 = ((*(double *)(unaff_ESI + 0x1c8c) - *(double *)(unaff_ESI + 0x1c5c)) *
              *(double *)(unaff_ESI + 0x1c7c)) /
              (*(double *)(unaff_ESI + 0x1c8c) - *(double *)(unaff_ESI + 0x1c84));
    }
    if (*(double *)(unaff_ESI + 8) < dVar1) {
      *(double *)(unaff_ESI + 8) = dVar1;
    }
    if (((((*(double *)(unaff_ESI + 0x1c5c) <= *(double *)(unaff_ESI + 0x1c84) * _DAT_0059ed98) &&
          (*(double *)(unaff_ESI + 0x1d10) < _DAT_0059e430 !=
           (*(double *)(unaff_ESI + 0x1d10) == _DAT_0059e430))) && (DAT_007c56a8 != 2)) &&
        ((DAT_007ce254 == (char)unaff_EBX && (DAT_007cc6e0 == unaff_EBX)))) &&
       ((DAT_007cc6e4 == 0x59 && (cVar3 = FUN_00447160(), cVar3 != '\0')))) {
      FUN_00447e00(unaff_EBX,4);
      FUN_004471f0(unaff_EBX);
    }
  }
  if (_DAT_0059e430 < *(double *)(unaff_ESI + 0x1d10)) {
    dVar1 = *(double *)(unaff_ESI + 0x1d10);
    dVar2 = *(double *)(unaff_ESI + 0x1d10) - *(double *)(unaff_ESI + 0x68);
    *(double *)(unaff_ESI + 0x1d10) = dVar2;
    if (((dVar2 < *(double *)(unaff_ESI + 0x1d28) != (dVar2 == *(double *)(unaff_ESI + 0x1d28))) &&
        (*(double *)(unaff_ESI + 0x1d28) < dVar1)) &&
       (*(double *)(unaff_ESI + 0x1c5c) < *(double *)(unaff_ESI + 0x1c84))) {
      FUN_004f87c0(0x27,2,0x3f800000,0x3f800000);
    }
    if ((*(double *)(unaff_ESI + 0x1d10) < _DAT_0059e430 !=
         (*(double *)(unaff_ESI + 0x1d10) == _DAT_0059e430)) &&
       (*(double *)(unaff_ESI + 0x1c5c) < *(double *)(unaff_ESI + 0x1c84))) {
      *(undefined4 *)(unaff_ESI + 0x1c5c) = *(undefined4 *)(unaff_ESI + 0x1c84);
      *(undefined4 *)(unaff_ESI + 0x1c60) = *(undefined4 *)(unaff_ESI + 0x1c88);
    }
  }
  if (_DAT_0059e430 < *(double *)(unaff_ESI + 0x1dac)) {
    FUN_0058957a();
    uVar4 = __ftol();
    fVar5 = (extraout_ST0 - (float10)(int)uVar4) *
            ((float10)*(float *)(&DAT_008aae74 + (uVar4 + 1 & 0xff) * 4) -
            (float10)*(float *)(&DAT_008aae74 + (uVar4 & 0xff) * 4)) +
            (float10)*(float *)(&DAT_008aae74 + (uVar4 & 0xff) * 4);
    *(double *)(unaff_ESI + 8) =
         (double)(((float10)_DAT_0059e420 - fVar5 * (float10)*(double *)(unaff_ESI + 0x1dac) * fVar5
                  ) * (float10)*(double *)(unaff_ESI + 8));
  }
  fVar5 = (float10)FUN_00447b10();
  *(double *)(unaff_ESI + 8) = (double)(fVar5 * (float10)*(double *)(unaff_ESI + 8));
  return;
}


