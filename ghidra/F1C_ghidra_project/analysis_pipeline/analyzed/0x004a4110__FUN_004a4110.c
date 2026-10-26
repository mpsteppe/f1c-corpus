// Function: FUN_004a4110 @ 004a4110
// Size (bytes): 1491


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __thiscall FUN_004a4110(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  float local_c;
  float local_4;
  
  piVar9 = param_2;
  fVar4 = _DAT_0059e43c;
  iVar12 = 0;
  iVar11 = DAT_005c329c;
  if (0 < DAT_005c329c) {
    do {
      iVar2 = *(int *)(param_1 + iVar12 * 4);
      if (iVar2 != 0) {
        if (*(int *)(iVar2 + 0x4550) == 0) {
          *(undefined4 *)(param_1 + iVar12 * 4) = 0;
          iVar11 = DAT_005c329c;
        }
        else {
          uVar10 = FUN_0042add0();
          fVar13 = (float10)FUN_00426cc0(uVar10);
          iVar11 = DAT_005c329c;
          if ((fVar13 < (float10)DAT_0059e440) && ((float10)_DAT_005acb48 < fVar13)) {
            iVar2 = *(int *)(param_1 + iVar12 * 4);
            iVar3 = *(int *)(iVar2 + 0x4510);
            if ((iVar3 != 4) && ((iVar3 != 5 && (_DAT_0059e800 < *(float *)(iVar2 + 0x4440))))) {
              return 0;
            }
          }
        }
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < iVar11);
  }
  if (DAT_007c56a4 == 7) {
    return 1;
  }
  piVar1 = param_2 + 0x1162;
  if (*piVar1 <= param_2[0x1178]) {
    return 0;
  }
  iVar12 = 0;
  param_2 = (int *)iVar11;
  if (0 < iVar11) {
    do {
      if (*(int *)(param_1 + iVar12 * 4) != 0) {
        param_2 = (int *)((int)param_2 + -1);
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < iVar11);
  }
  if (((DAT_007c56a4 == 3) || (DAT_007c56a4 == 4)) || (DAT_007c56a4 == 5)) {
    local_c = (float)(int)param_2 * _DAT_005acb40;
  }
  else {
    local_c = (float)(int)param_2 * _DAT_005acb44;
  }
  local_c = _DAT_0059e43c - local_c;
  if (local_c < _DAT_0059e444) {
    local_c = 0.01;
  }
  fVar6 = (float)_DAT_008afea0;
  fVar7 = _DAT_008acf90 + _DAT_0059e9b8;
  fVar5 = _DAT_008acf94;
  if (fVar7 < _DAT_008acf94) {
    fVar5 = fVar7;
  }
  fVar8 = _DAT_0059e43c;
  if (_DAT_0059e43c <= fVar5 - _DAT_008acf90) {
    if (_DAT_008acf94 <= fVar7) {
      fVar7 = _DAT_008acf94;
    }
    fVar8 = fVar7 - _DAT_008acf90;
  }
  fVar8 = (fVar6 - _DAT_008acf90) / fVar8;
  if (_DAT_0059e7f8 <= fVar8) {
    if (_DAT_0059e450 <= fVar8) {
      if (_DAT_0059e7fc <= fVar8) {
        if (*(float *)(param_1 + 0x1a0) < fVar6) goto LAB_004a45b2;
      }
      else {
        iVar11 = piVar9[0x100f];
        local_4 = (float)(piVar9[(*piVar1 + 0x458) * 4] - iVar11) * (float)piVar9[0x1027];
        if (local_4 < _DAT_005acb0c) {
          local_4 = _DAT_005acb0c;
        }
        fVar4 = _DAT_008acf90 + _DAT_005acb3c;
        fVar7 = _DAT_008acf94;
        if (fVar4 < _DAT_008acf94) {
          fVar7 = fVar4;
        }
        fVar5 = _DAT_0059e43c;
        if (_DAT_0059e43c <= fVar7 - fVar6) {
          fVar7 = _DAT_008acf94;
          if (fVar4 < _DAT_008acf94) {
            fVar7 = fVar4;
          }
          fVar5 = fVar7 - fVar6;
        }
        if (local_4 <= fVar5) {
          fVar7 = _DAT_008acf94;
          if (fVar4 < _DAT_008acf94) {
            fVar7 = fVar4;
          }
          fVar5 = _DAT_0059e43c;
          if (_DAT_0059e43c <= fVar7 - fVar6) {
            fVar7 = _DAT_008acf94;
            if (fVar4 < _DAT_008acf94) {
              fVar7 = fVar4;
            }
            fVar5 = fVar7 - fVar6;
          }
          local_4 = local_4 / fVar5;
        }
        else {
          local_4 = 1.0;
        }
        iVar12 = FUN_0042ae90();
        fVar4 = local_4;
        if ((float)iVar11 < (float)iVar12 * _DAT_0059e450) {
          fVar4 = _DAT_0059e43c;
        }
      }
    }
    else {
      iVar11 = piVar9[0x100f];
      iVar12 = FUN_0042ae90();
      fVar6 = _DAT_0059e7e8;
      if ((float)iVar12 * _DAT_0059e6e8 <= (float)iVar11) goto joined_r0x004a4405;
      fVar4 = _DAT_0059e974;
      if (*(int *)(*piVar9 + 0x48a4) < 4) {
        fVar4 = _DAT_0059e8c8;
      }
    }
  }
  else {
    iVar11 = piVar9[0x100f];
    iVar12 = FUN_0042ae90();
    fVar6 = _DAT_0059e84c;
    if ((float)iVar12 * _DAT_0059e458 <= (float)iVar11) {
joined_r0x004a4405:
      fVar4 = _DAT_0059e8cc;
      if ((local_c <= _DAT_0059e8cc) && (fVar4 = fVar6, local_c <= _DAT_0059e8c8)) {
        fVar4 = _DAT_0059e444;
      }
    }
    else {
      fVar4 = _DAT_0059e7f8;
      if ((3 < *(int *)(*piVar9 + 0x48a4)) &&
         (fVar4 = _DAT_0059e908, *(int *)(*piVar9 + 0x48a4) < 8)) {
        fVar4 = _DAT_0059e6e8;
      }
    }
  }
  fVar4 = fVar4 * local_c * _DAT_005acb38;
  if (fVar4 == DAT_0059e440) {
    fVar4 = _DAT_0059e600;
  }
  fVar6 = _DAT_008acf90 + _DAT_005acb34;
  fVar7 = _DAT_008acf94;
  if (fVar6 < _DAT_008acf94) {
    fVar7 = fVar6;
  }
  fVar5 = _DAT_0059e43c;
  if (_DAT_0059e43c <= fVar7 - _DAT_008acf90) {
    if (_DAT_008acf94 <= fVar6) {
      fVar6 = _DAT_008acf94;
    }
    fVar5 = fVar6 - _DAT_008acf90;
  }
  if (_DAT_0059e43c <= (_DAT_0059e7f8 / fVar4) * fVar5) {
    iVar11 = _rand();
    if (((DAT_007c56a4 != 7) && (iVar12 = __ftol(), iVar11 % iVar12 != 0)) ||
       (fVar6 = (float)_DAT_008afea0, fVar6 < *(float *)(param_1 + 0x1a0))) {
      return 0;
    }
  }
  else {
    fVar6 = (float)_DAT_008afea0;
    if (fVar6 <= *(float *)(param_1 + 0x1a0)) {
      return 0;
    }
  }
LAB_004a45b2:
  *(float *)(param_1 + 0x1a0) = fVar6 + _DAT_005acb38;
  return 1;
}


