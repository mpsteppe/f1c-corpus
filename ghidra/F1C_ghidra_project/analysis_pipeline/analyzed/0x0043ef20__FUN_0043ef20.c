// Function: FUN_0043ef20 @ 0043ef20
// Size (bytes): 2247


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0043ef20(int param_1)

{
  float fVar1;
  double dVar2;
  double dVar3;
  bool bVar4;
  bool bVar5;
  double dVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  
  dVar3 = ABS(*(double *)(param_1 + 0x1c5c));
  dVar6 = _DAT_0059e430;
  if (_DAT_0059e430 < *(double *)(param_1 + 0x19c)) {
    dVar6 = *(double *)(param_1 + 0x1ac) * *(double *)(param_1 + 8) * dVar3;
    dVar2 = *(double *)(param_1 + 0x19c) - dVar6 * *(double *)(param_1 + 0x1b4);
    *(double *)(param_1 + 0x19c) = dVar2;
    if (dVar2 < _DAT_0059e430 != (dVar2 == _DAT_0059e430)) {
      *(undefined4 *)(param_1 + 0x19c) = 0;
      *(undefined4 *)(param_1 + 0x1a0) = 0;
      if (*(int *)(*(int *)(param_1 + 0x1f00) + 0x4068) == 0) {
        *(undefined4 *)(*(int *)(param_1 + 0x1f00) + 0x4068) = 9;
      }
    }
    iVar7 = *(int *)(param_1 + 0x1d4);
    dVar2 = *(double *)(param_1 + 0x19c) * _DAT_0059ea60 + _DAT_0059e420;
    *(double *)(iVar7 + 0xac) = dVar2;
    *(double *)(iVar7 + 0xb4) = _DAT_0059e420 / dVar2;
  }
  dVar2 = *(double *)(param_1 + 0x1d7c);
  if (*(double *)(param_1 + 0x1d54) - _DAT_0059eb48 < *(double *)(param_1 + 0x1d4c)) {
    dVar2 = dVar3 * *(double *)(param_1 + 0x1d84) + dVar2;
  }
  dVar2 = (*(double *)(param_1 + 0x1d4c) - *(double *)(param_1 + 0x1d8c)) * dVar2;
  dVar6 = (((((double)_DAT_008afef0 + _DAT_0059eac8) - *(double *)(param_1 + 0x1d4c)) *
            *(double *)(param_1 + 0x1d6c) +
           dVar3 * *(double *)(param_1 + 0x1d64) + dVar6 * *(double *)(param_1 + 0x1d5c)) - dVar2) *
          *(double *)(param_1 + 0x68) + *(double *)(param_1 + 0x1d4c);
  fVar10 = (float10)dVar3 * (float10)_DAT_0059ed00;
  *(double *)(param_1 + 0x1d4c) = dVar6;
  if (*(double *)(param_1 + 0x1d54) < dVar6) {
    fVar11 = (float10)fsin(((float10)*(double *)(param_1 + 0x1d54) * (float10)_DAT_0059e890) /
                           ((float10)dVar6 + (float10)dVar6));
    if (fVar11 < (float10)_DAT_0059e430) {
      fVar11 = (float10)_DAT_0059e430;
    }
    fVar10 = fVar11 * fVar10;
  }
  iVar7 = *(int *)(param_1 + 0x15f0);
  *(double *)(param_1 + 0x1d74) =
       (double)((fVar10 - (float10)*(double *)(param_1 + 0x1d74)) *
                (float10)*(double *)(param_1 + 0x68) * (float10)_DAT_0059e7d8 +
               (float10)*(double *)(param_1 + 0x1d74));
  dVar6 = *(double *)(iVar7 + 0x2c) * *(double *)(iVar7 + 100) +
          *(double *)(iVar7 + 0x6c) * *(double *)(iVar7 + 0x44) +
          *(double *)(iVar7 + 0x5c) * *(double *)(iVar7 + 0x74);
  if (_DAT_0059e430 <= dVar6) {
    dVar6 = dVar6 * _DAT_0059eb28;
  }
  else {
    dVar6 = -dVar6;
  }
  dVar6 = ((((double)_DAT_008afef0 + _DAT_0059eac8) - *(double *)(param_1 + 0x1d8c)) *
           (dVar6 * *(double *)(param_1 + 0x1d9c) + *(double *)(param_1 + 0x1d94)) + dVar2) *
          *(double *)(param_1 + 0x68) + *(double *)(param_1 + 0x1d8c);
  *(double *)(param_1 + 0x1d8c) = dVar6;
  fVar10 = (float10)dVar3 * (float10)_DAT_0059ecf8;
  if (_DAT_0059ecf0 < dVar6) {
    fVar11 = (float10)fsin((float10)_DAT_0059ece8 / ((float10)dVar6 + (float10)dVar6));
    if (fVar11 < (float10)_DAT_0059e430) {
      fVar11 = (float10)_DAT_0059e430;
    }
    fVar10 = fVar11 * fVar10;
  }
  *(double *)(param_1 + 0x1da4) =
       (double)((fVar10 - (float10)*(double *)(param_1 + 0x1da4)) *
                (float10)*(double *)(param_1 + 0x68) * (float10)_DAT_0059e7d8 +
               (float10)*(double *)(param_1 + 0x1da4));
  if (*(double *)(param_1 + 0x1db4) <= _DAT_0059e430) {
    if (*(double *)(param_1 + 0x1db4) < _DAT_0059ecb0) {
      if ((_DAT_0059e430 < *(double *)(param_1 + 0x1dac)) &&
         (dVar3 = *(double *)(param_1 + 0x68) * _DAT_0059ec98 + *(double *)(param_1 + 0x1dac),
         *(double *)(param_1 + 0x1dac) = dVar3, _DAT_0059eb30 < dVar3)) {
        *(undefined4 *)(param_1 + 0x1dac) = 0x33333333;
        *(undefined4 *)(param_1 + 0x1db0) = 0x3fe33333;
        return;
      }
    }
    else if (*(double *)(iVar7 + 0x74) * *(double *)(iVar7 + 0x74) +
             *(double *)(iVar7 + 0x6c) * *(double *)(iVar7 + 0x6c) +
             *(double *)(iVar7 + 100) * *(double *)(iVar7 + 100) < _DAT_0059eca8) {
      dVar3 = *(double *)(param_1 + 0x1db4);
      dVar6 = *(double *)(param_1 + 0x1db4) - *(double *)(param_1 + 0x68);
      bVar4 = _DAT_0059ecb0 <= dVar6;
      *(double *)(param_1 + 0x1db4) = dVar6;
      if (bVar4) {
        if ((dVar6 < _DAT_0059eca0) && (_DAT_0059eca0 <= dVar3)) {
          *(undefined4 *)(param_1 + 0x1df4) = 0;
          dVar3 = *(double *)(param_1 + 0x1de4) * _DAT_0059e880;
          *(undefined4 *)(param_1 + 0x1df8) = 0;
          *(double *)(param_1 + 0x1de4) = dVar3;
          *(double *)(param_1 + 0x1dec) = *(double *)(param_1 + 0x1dec) * _DAT_0059e880;
          return;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x1de4) = 0;
        *(undefined4 *)(param_1 + 0x1de8) = 0;
        *(undefined4 *)(param_1 + 0x1dec) = 0;
        *(undefined4 *)(param_1 + 0x1df0) = 0;
        *(undefined4 *)(param_1 + 0x1df4) = 0;
        *(undefined4 *)(param_1 + 0x1df8) = 0;
      }
    }
    return;
  }
  dVar3 = *(double *)(param_1 + 0x1db4);
  fVar10 = (float10)FUN_005881f0();
  fVar11 = (float10)FUN_005881f0();
  fVar12 = (float10)*(double *)(param_1 + 0x1db4) -
           ((fVar11 + (float10)(double)fVar10) * (float10)_DAT_0059e880 +
           (float10)*(double *)(param_1 + 0x1dac)) * (float10)*(double *)(param_1 + 0x68);
  *(double *)(param_1 + 0x1db4) = (double)fVar12;
  if (fVar12 < (float10)_DAT_0059e430 == (fVar12 == (float10)_DAT_0059e430)) {
    return;
  }
  *(undefined4 *)(param_1 + 0x1db4) = 0;
  *(undefined4 *)(param_1 + 0x1db8) = 0;
  if (*(int *)(*(int *)(param_1 + 0x1f00) + 0x4068) == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x1f00) + 0x4068) = 1;
  }
  if ((dVar3 != _DAT_0059ece0) ||
     (uVar9 = DAT_008aae70 & 0xff, DAT_008aae70 = DAT_008aae70 + 1,
     _DAT_0059e8b4 < *(float *)(&DAT_008ab274 + uVar9 * 4))) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (((*(double *)(param_1 + 0x1de4) == _DAT_0059e430) &&
      (*(double *)(param_1 + 0x1dec) == _DAT_0059e430)) &&
     (*(double *)(param_1 + 0x1df4) == _DAT_0059e430)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  uVar9 = DAT_008aae70 + 1;
  dVar3 = (double)*(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4);
  if (!bVar5) {
LAB_0043f4d1:
    DAT_008aae70 = uVar9;
    if (*(double *)(param_1 + 0x1de4) == _DAT_0059e430) {
      if (*(double *)(param_1 + 0x1dec) == _DAT_0059e430) {
        uVar9 = DAT_008aae70;
        if (*(double *)(param_1 + 0x1df4) != _DAT_0059e430) {
          uVar9 = DAT_008aae70 & 0xff;
          DAT_008aae70 = DAT_008aae70 + 1;
          *(double *)(param_1 + 0x1df4) =
               (double)((float)_DAT_0059e420 -
                       *(float *)(&DAT_008aae74 + uVar9 * 4) * (float)_DAT_0059ecd0);
          uVar9 = DAT_008aae70 & 0xff;
          DAT_008aae70 = DAT_008aae70 + 1;
          *(double *)(param_1 + 0x1dec) =
               (double)((float)_DAT_0059e420 -
                       *(float *)(&DAT_008aae74 + uVar9 * 4) * (float)_DAT_0059ecd0);
          uVar9 = DAT_008aae70;
        }
      }
      else {
        uVar9 = DAT_008aae70 & 0xff;
        DAT_008aae70 = DAT_008aae70 + 1;
        *(double *)(param_1 + 0x1dec) =
             (double)((float)_DAT_0059e420 -
                     *(float *)(&DAT_008aae74 + uVar9 * 4) * (float)_DAT_0059ecd0);
        fVar1 = *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4);
        uVar9 = DAT_008aae70 + 1;
        if ((float)_DAT_0059eb28 <= fVar1) {
          if (fVar1 < (float)_DAT_0059ec70) {
            DAT_008aae70 = DAT_008aae70 + 2;
            *(double *)(param_1 + 0x1df4) =
                 (double)((float)_DAT_0059e420 -
                         *(float *)(&DAT_008aae74 + (uVar9 & 0xff) * 4) * (float)_DAT_0059ecd0);
            uVar9 = DAT_008aae70;
          }
        }
        else {
          DAT_008aae70 = uVar9;
          *(double *)(param_1 + 0x1de4) = (double)(fVar1 + (float)_DAT_0059eba0);
          uVar9 = DAT_008aae70;
        }
      }
    }
    else {
      uVar9 = DAT_008aae70 & 0xff;
      DAT_008aae70 = DAT_008aae70 + 1;
      *(double *)(param_1 + 0x1de4) =
           (double)((float)_DAT_0059e420 -
                   *(float *)(&DAT_008aae74 + uVar9 * 4) * (float)_DAT_0059ecd0);
      uVar8 = DAT_008aae70 & 0xff;
      DAT_008aae70 = DAT_008aae70 + 1;
      uVar9 = DAT_008aae70;
      if (*(float *)(&DAT_008aae74 + uVar8 * 4) < (float)_DAT_0059eb28) {
        *(double *)(param_1 + 0x1dec) =
             (double)(*(float *)(&DAT_008aae74 + uVar8 * 4) + (float)_DAT_0059eba0);
        uVar9 = DAT_008aae70;
      }
    }
    DAT_008aae70 = uVar9;
    iVar7 = 0;
    *(undefined4 *)(param_1 + 0x1dac) = 0;
    *(undefined4 *)(param_1 + 0x1db0) = 0;
    if (0 < *(int *)(param_1 + 0x1d08)) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x1cfc) + 4 + iVar7 * 8) = 0;
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(param_1 + 0x1d08));
    }
    FUN_0041ac50(*(undefined4 *)(param_1 + 0x1f00),0);
    return;
  }
  if (_DAT_0059e880 <= dVar3) {
    if (bVar4) {
      fVar1 = *(float *)(&DAT_008aae74 + (uVar9 & 0xff) * 4);
      DAT_008aae70 = DAT_008aae70 + 2;
      if ((float)_DAT_0059ec80 <= fVar1) {
        if ((float)_DAT_0059ecb8 <= fVar1) {
          uVar9 = DAT_008aae70;
          if (fVar1 < (float)_DAT_0059eb38) {
            *(undefined4 *)(param_1 + 0x1df4) = 0;
            *(undefined4 *)(param_1 + 0x1df8) = 0x3ff00000;
            uVar9 = DAT_008aae70;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x1dec) = 0;
          *(undefined4 *)(param_1 + 0x1df0) = 0x3ff00000;
          uVar9 = DAT_008aae70;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x1de4) = 0;
        *(undefined4 *)(param_1 + 0x1de8) = 0x3ff00000;
        uVar9 = DAT_008aae70;
      }
    }
    goto LAB_0043f4d1;
  }
  if (!bVar4) goto LAB_0043f4d1;
  if ((double)fVar10 <= (double)fVar11) {
    dVar3 = dVar3 - _DAT_0059ea68;
  }
  else {
    dVar3 = dVar3 + _DAT_0059ea68;
  }
  dVar6 = _DAT_0059e430;
  if (_DAT_0059e430 <= dVar3) {
    dVar6 = _DAT_0059e880;
    if (dVar3 <= _DAT_0059e880) {
      dVar6 = dVar3;
      if (dVar3 < _DAT_0059ecd0) goto LAB_0043f3d9;
      if (dVar3 < _DAT_0059ec80) {
        DAT_008aae70 = DAT_008aae70 + 2;
        *(double *)(param_1 + 0x1dec) =
             (double)(*(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4) * (float)_DAT_0059ec80 -
                     (float)_DAT_0059eba0);
        dVar6 = (dVar3 - _DAT_0059ecd0) * _DAT_0059ecc0;
        goto LAB_0043f38d;
      }
    }
    DAT_008aae70 = DAT_008aae70 + 2;
    *(double *)(param_1 + 0x1df4) =
         (double)(*(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4) * (float)_DAT_0059ec80 -
                 (float)_DAT_0059eba0);
    dVar6 = (dVar6 - _DAT_0059ec80) * _DAT_0059ecd8;
  }
  else {
LAB_0043f3d9:
    DAT_008aae70 = DAT_008aae70 + 2;
    *(double *)(param_1 + 0x1de4) =
         (double)(*(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4) * (float)_DAT_0059ec80 -
                 (float)_DAT_0059eba0);
    dVar6 = dVar6 * _DAT_0059ecc8;
  }
LAB_0043f38d:
  *(double *)(param_1 + 0x1db4) = dVar6 + _DAT_0059e420;
  uVar9 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  *(double *)(param_1 + 0x1dac) =
       (double)(*(float *)(&DAT_008ab274 + uVar9 * 4) * (float)_DAT_0059eba0 + (float)_DAT_0059ec60)
  ;
  return;
}


