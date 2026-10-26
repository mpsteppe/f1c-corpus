// Function: FUN_00438130 @ 00438130
// Size (bytes): 1373


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00438130(int param_1,double param_2)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  int iVar18;
  double *pdVar19;
  double *extraout_EDX;
  int iVar20;
  double *pdVar21;
  double local_70;
  double local_38 [3];
  double local_20 [3];
  
  fVar1 = _DAT_008afef4 + (float)_DAT_0059eac8;
  fVar2 = _DAT_008afef0 + (float)_DAT_0059eac8;
  dVar10 = _DAT_0059e430;
  if (_DAT_0059e430 < *(double *)(param_1 + 0x324)) {
    dVar10 = ABS(*(double *)(param_1 + 0xbc)) * *(double *)(param_1 + 0x3a4) *
             *(double *)(param_1 + 0x324);
  }
  if (*(double *)(param_1 + 0x31c) <= _DAT_0059e430) {
    local_70 = 0.0;
    dVar12 = _DAT_0059e430;
  }
  else {
    local_70 = (_DAT_0059e420 - *(double *)(param_1 + 0x14c)) * *(double *)(param_1 + 0x268) *
               *(double *)(param_1 + 0x31c);
    dVar12 = local_70 * *(double *)(param_1 + 0x3ac);
  }
  dVar15 = *(double *)(param_1 + 0x314) * _DAT_0059eb90;
  dVar16 = _DAT_0059e428;
  if ((dVar15 < _DAT_0059e428) || (dVar16 = _DAT_0059e420, _DAT_0059e420 < dVar15)) {
    dVar15 = dVar16;
  }
  dVar17 = *(double *)(param_1 + 0x344) * *(double *)(param_1 + 0x31c) +
           *(double *)(param_1 + 0x33c);
  dVar16 = (dVar17 - *(double *)(param_1 + 0x374)) * _DAT_0059eb88;
  dVar3 = _DAT_0059e428;
  if ((dVar16 < _DAT_0059e428) || (dVar3 = _DAT_0059e420, _DAT_0059e420 < dVar16)) {
    dVar16 = dVar3;
  }
  iVar20 = *(int *)(param_1 + 0x15c);
  pdVar19 = (double *)(param_1 + 0x34c);
  pdVar21 = local_20;
  for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
    *(undefined4 *)pdVar21 = *(undefined4 *)pdVar19;
    pdVar19 = (double *)((int)pdVar19 + 4);
    pdVar21 = (double *)((int)pdVar21 + 4);
  }
  local_38[0] = ((_DAT_0059e880 * dVar16 - dVar15) + _DAT_0059eb80) * _DAT_0059eb78;
  local_38[1] = (_DAT_0059eb80 - dVar16) * _DAT_0059eb78;
  local_38[2] = (_DAT_0059e880 * dVar16 + dVar15 + _DAT_0059eb80) * _DAT_0059eb78;
  dVar14 = (double)_DAT_008afee4 + *(double *)(param_1 + 0x270) + _DAT_0059e420;
  dVar3 = *(double *)(iVar20 + 0x74);
  dVar4 = *(double *)(iVar20 + 0x6c);
  dVar5 = *(double *)(iVar20 + 100);
  dVar6 = *(double *)(param_1 + 0x3c4);
  dVar7 = *(double *)(param_1 + 0x3bc);
  dVar8 = *(double *)(param_1 + 0x3b4);
  dVar9 = *(double *)(param_1 + 0x364);
  pdVar19 = (double *)(param_1 + 0x34c);
  iVar20 = 0;
  do {
    dVar13 = param_2 * *(double *)((int)local_38 + iVar20);
    dVar11 = dVar13 * dVar10 + dVar13 * dVar12 + *pdVar19;
    *pdVar19 = dVar11;
    if (_DAT_0059e430 < *(double *)(param_1 + 0x324)) {
      *pdVar19 = ((double)fVar1 - *(double *)((int)local_20 + iVar20)) * dVar13 * dVar14 * dVar8 +
                 dVar11;
    }
    iVar18 = iVar20 + 8;
    dVar11 = (dVar9 - *(double *)((int)local_20 + iVar20)) * param_2 * _DAT_0059eb70;
    *pdVar19 = ((double)fVar2 - *(double *)((int)local_20 + iVar20)) *
               (SQRT(dVar3 * dVar3 + dVar4 * dVar4 + dVar5 * dVar5) * dVar6 + dVar7) * dVar14 *
               param_2 + dVar11 + *pdVar19;
    *(double *)(param_1 + 0x364) = *(double *)(param_1 + 0x364) - dVar11;
    pdVar19 = pdVar19 + 1;
    iVar20 = iVar18;
  } while (iVar18 < 0x18);
  if (_DAT_0059eac8 <= *(double *)(param_1 + 0x364)) {
    if (*(double *)(param_1 + 0x364) <= _DAT_0059eb68) goto LAB_004383fe;
    *(undefined4 *)(param_1 + 0x368) = 0x4081128f;
  }
  else {
    *(undefined4 *)(param_1 + 0x368) = 0x4071128f;
  }
  *(undefined4 *)(param_1 + 0x364) = 0x5c28f5c3;
LAB_004383fe:
  FUN_00438100();
  dVar10 = (*(double *)(param_1 + 0x35c) + *(double *)(param_1 + 0x354) + *extraout_EDX) *
           _DAT_0059eb78;
  dVar12 = dVar10 / *(double *)(param_1 + 0x334);
  param_2 = (ABS(dVar15) + ABS(dVar16) + _DAT_0059e7d8) * _DAT_0059eb60 *
            *(double *)(param_1 + 0x3cc) * dVar12 * dVar12 * local_70 * param_2;
  if ((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) {
    fVar1 = (float)(((float10)*(double *)(param_1 + 0x394) - (float10)_DAT_0059ea60) *
                   (float10)_DAT_0059e7d8);
    fVar2 = (float)((((float10)*(double *)(param_1 + 0x394) - (float10)param_2) -
                    (float10)_DAT_0059ea60) * (float10)_DAT_0059e7d8);
    if (fVar1 == (float)_DAT_0059e420) {
      *(undefined4 *)(&DAT_005ec3bc + *(int *)(param_1 + 0x78) * 4) = 0;
    }
    else if ((fVar1 <= _DAT_0059e6e8) || (fVar2 < _DAT_0059e6e8 == (fVar2 == _DAT_0059e6e8))) {
      if ((_DAT_0059e8c8 < fVar1) && (fVar2 < _DAT_0059e8c8 != (fVar2 == _DAT_0059e8c8))) {
        FUN_0041ab30(*(undefined4 *)(param_1 + 0x78));
      }
    }
    else {
      FUN_0041aa10(*(undefined4 *)(param_1 + 0x78));
    }
  }
  if (_DAT_0059ea60 < *(double *)(param_1 + 0x394)) {
    param_2 = *(double *)(param_1 + 0x394) - param_2;
    *(double *)(param_1 + 0x394) = param_2;
    if (param_2 < _DAT_0059ea60 != (param_2 == _DAT_0059ea60)) {
      *(undefined4 *)(param_1 + 0x394) = 0;
      dVar12 = *(double *)(param_1 + 900) * _DAT_0059eb58;
      *(undefined4 *)(param_1 + 0x398) = 0x3fe80000;
      *(double *)(param_1 + 900) = dVar12;
      *(double *)(param_1 + 0x234) = *(double *)(param_1 + 0x234) * _DAT_0059e7d8;
      *(double *)(param_1 + 0x44c) = *(double *)(param_1 + 0x44c) * _DAT_0059e830;
      *(double *)(param_1 + 0x278) = *(double *)(param_1 + 0x278) * _DAT_0059e830;
      *(double *)(param_1 + 0x454) = *(double *)(param_1 + 0x454) * _DAT_0059e830;
      *(double *)(param_1 + 0x288) = *(double *)(param_1 + 0x288) * _DAT_0059e830;
      dVar12 = *(double *)(param_1 + 0x37c) * _DAT_0059eb50;
      if (_DAT_0059eb48 < dVar12) {
        dVar12 = _DAT_0059eb48;
      }
      *(double *)(param_1 + 0x36c) = dVar12 * _DAT_0059eb40;
    }
  }
  dVar10 = (ABS(*(double *)(param_1 + 0x374) - dVar17) / dVar17) * _DAT_0059eb30 +
           (ABS(dVar10 - *(double *)(param_1 + 0x334)) / *(double *)(param_1 + 0x334)) *
           _DAT_0059eb38;
  dVar12 = _DAT_0059e430;
  if ((_DAT_0059e430 <= dVar10) && (dVar12 = dVar10, _DAT_0059e420 < dVar10)) {
    dVar12 = _DAT_0059e420;
  }
  *(double *)(param_1 + 0x39c) =
       (_DAT_0059e420 - dVar12 * dVar12 * _DAT_0059e880) * *(double *)(param_1 + 0x394);
  return;
}


