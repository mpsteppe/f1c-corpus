// Function: FUN_00443c07 @ 00443c07
// Size (bytes): 872


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00443c07(int param_1,int param_2)

{
  double dVar1;
  bool bVar2;
  bool bVar3;
  double dVar4;
  char cVar5;
  uint uVar6;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 fVar7;
  int iVar8;
  
  dVar1 = (double)in_ST0;
  dVar4 = *(double *)(unaff_ESI + 0x1e7c) - *(double *)(unaff_ESI + 0x68);
  bVar2 = dVar4 < _DAT_0059e430;
  bVar3 = dVar4 == _DAT_0059e430;
  *(double *)(unaff_ESI + 0x1e7c) = dVar4;
  if (bVar2 != bVar3) {
    *(int *)(unaff_ESI + 0x1ef0) = param_2;
  }
  cVar5 = (char)unaff_EBX;
  if (*(double *)(unaff_ESI + 0x1c5c) == dVar1) {
    *(int *)(unaff_ESI + 0x1ef0) = param_2;
    goto LAB_00443c48;
  }
  if (*(char *)(unaff_ESI + 0x1e78) != cVar5) {
    if (unaff_EBX < param_1) {
      if (dVar1 < *(double *)(unaff_ESI + 0x1c5c)) {
        *(int *)(unaff_ESI + 8) = unaff_EBX;
        *(int *)(unaff_ESI + 0xc) = unaff_EBX;
      }
      if (_DAT_0059e430 <= dVar4) goto LAB_00443c50;
      if (*(double *)(unaff_ESI + 0x1e8c) < dVar4) {
        *(double *)(unaff_ESI + 0x18) = _DAT_0059e420 - dVar4 / *(double *)(unaff_ESI + 0x1e8c);
        goto LAB_00443c50;
      }
    }
    else {
      if (*(double *)(unaff_ESI + 0x1c5c) < dVar1) {
        *(int *)(unaff_ESI + 8) = unaff_EBX;
        *(undefined4 *)(unaff_ESI + 0xc) = 0x3ff00000;
      }
      if (_DAT_0059e430 <= dVar4) goto LAB_00443c50;
      if (*(double *)(unaff_ESI + 0x1e9c) < dVar4) {
        *(double *)(unaff_ESI + 0x18) = _DAT_0059e420 - dVar4 / *(double *)(unaff_ESI + 0x1e9c);
        goto LAB_00443c50;
      }
    }
    if (*(double *)(unaff_ESI + 0x1e38) == dVar1) {
      *(int *)(unaff_ESI + 0x1ef8) = unaff_EBX;
    }
    goto LAB_00443c50;
  }
  if (*(int *)(unaff_EBP + 0xc) == unaff_EBX) goto LAB_00443c50;
  iVar8 = *(int *)(unaff_EBP + 8);
  if (unaff_EBX < param_1) {
    if ((((iVar8 == 1) || (iVar8 == 3)) || ((*(byte *)(unaff_ESI + 0x80) & 1) != 0)) &&
       (dVar1 < *(double *)(unaff_ESI + 0x1c5c))) {
      *(int *)(unaff_ESI + 8) = unaff_EBX;
      *(int *)(unaff_ESI + 0xc) = unaff_EBX;
    }
    if (_DAT_0059e430 <= dVar4) goto LAB_00443c50;
    if (dVar4 <= *(double *)(unaff_ESI + 0x1e8c)) {
LAB_00443c48:
      *(int *)(unaff_ESI + 0x1ef8) = unaff_EBX;
      goto LAB_00443c50;
    }
    dVar1 = *(double *)(unaff_ESI + 0x1e8c);
  }
  else {
    if ((((iVar8 == 2) || (iVar8 == 3)) || ((*(byte *)(unaff_ESI + 0x80) & 2) != 0)) &&
       (*(double *)(unaff_ESI + 0x1c5c) < dVar1)) {
      *(int *)(unaff_ESI + 8) = unaff_EBX;
      *(undefined4 *)(unaff_ESI + 0xc) = 0x3ff00000;
    }
    if (_DAT_0059e430 <= dVar4) goto LAB_00443c50;
    if (dVar4 <= *(double *)(unaff_ESI + 0x1e9c)) goto LAB_00443c48;
    dVar1 = *(double *)(unaff_ESI + 0x1e9c);
  }
  dVar1 = _DAT_0059e420 - dVar4 / dVar1;
  if (*(double *)(unaff_ESI + 0x20) < dVar1) {
    *(double *)(unaff_ESI + 0x20) = dVar1;
  }
LAB_00443c50:
  if (((*(int *)(unaff_ESI + 0x1ef8) < unaff_EBX) && (0 < param_2)) &&
     ((_DAT_0059e430 < *(double *)(unaff_ESI + 0x10) &&
      ((_DAT_0059e430 < *(double *)(unaff_ESI + 0x19c) &&
       (*(double *)(unaff_ESI + 0x1cdc) * _DAT_0059e880 < *(double *)(unaff_ESI + 0x1c5c))))))) {
    FUN_004ef4f0();
  }
  iVar8 = 1;
  if (*(double *)(unaff_ESI + 0x1c5c) <= *(double *)(unaff_ESI + 0x1ce4)) {
    iVar8 = unaff_EBX;
  }
  if (((double)iVar8 != _DAT_0059e430) || (*(char *)(unaff_ESI + 0x1c58) != cVar5)) {
    dVar1 = *(double *)(unaff_ESI + 8);
    if (((double)iVar8 != _DAT_0059e430) &&
       (dVar4 = (*(double *)(unaff_ESI + 0x1cec) - *(double *)(unaff_ESI + 0x1c5c)) /
                (*(double *)(unaff_ESI + 0x1cec) - *(double *)(unaff_ESI + 0x1ce4)),
       dVar4 < *(double *)(unaff_ESI + 8))) {
      if (dVar4 < _DAT_0059e430) {
        dVar4 = _DAT_0059e430;
      }
      *(double *)(unaff_ESI + 8) = dVar4;
    }
    if ((*(char *)(unaff_ESI + 0x1c58) != cVar5) && (*(int *)(unaff_ESI + 0x1ef0) != unaff_EBX)) {
      FUN_0059d806();
      return;
    }
    dVar1 = (dVar1 - *(double *)(unaff_ESI + 8)) * _DAT_0059edc0;
    if (*(double *)(unaff_ESI + 0x170) < dVar1) {
      *(double *)(unaff_ESI + 0x170) = dVar1;
    }
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
    if ((((*(double *)(unaff_ESI + 0x1c5c) <= *(double *)(unaff_ESI + 0x1c84) * _DAT_0059ed98) &&
         (*(double *)(unaff_ESI + 0x1d10) < _DAT_0059e430 !=
          (*(double *)(unaff_ESI + 0x1d10) == _DAT_0059e430))) && (DAT_007c56a8 != 2)) &&
       (((DAT_007ce254 == cVar5 && (DAT_007cc6e0 == unaff_EBX)) &&
        ((DAT_007cc6e4 == 0x59 && (cVar5 = FUN_00447160(), cVar5 != '\0')))))) {
      FUN_00447e00(unaff_EBX,4);
      FUN_004471f0(unaff_EBX);
    }
  }
  if (_DAT_0059e430 < *(double *)(unaff_ESI + 0x1d10)) {
    dVar1 = *(double *)(unaff_ESI + 0x1d10);
    dVar4 = *(double *)(unaff_ESI + 0x1d10) - *(double *)(unaff_ESI + 0x68);
    *(double *)(unaff_ESI + 0x1d10) = dVar4;
    if (((dVar4 < *(double *)(unaff_ESI + 0x1d28) != (dVar4 == *(double *)(unaff_ESI + 0x1d28))) &&
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
    uVar6 = __ftol();
    fVar7 = (extraout_ST0 - (float10)(int)uVar6) *
            ((float10)*(float *)(&DAT_008aae74 + (uVar6 + 1 & 0xff) * 4) -
            (float10)*(float *)(&DAT_008aae74 + (uVar6 & 0xff) * 4)) +
            (float10)*(float *)(&DAT_008aae74 + (uVar6 & 0xff) * 4);
    *(double *)(unaff_ESI + 8) =
         (double)(((float10)_DAT_0059e420 - fVar7 * (float10)*(double *)(unaff_ESI + 0x1dac) * fVar7
                  ) * (float10)*(double *)(unaff_ESI + 8));
  }
  fVar7 = (float10)FUN_00447b10();
  *(double *)(unaff_ESI + 8) = (double)(fVar7 * (float10)*(double *)(unaff_ESI + 8));
  return;
}


