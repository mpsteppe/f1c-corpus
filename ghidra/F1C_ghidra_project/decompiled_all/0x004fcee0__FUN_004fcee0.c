// Function: FUN_004fcee0 @ 004fcee0
// Strings:  [NIGHTLIGHT, NIGHTLIGHT]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fcee0(float *param_1)

{
  float fVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  bool bVar11;
  float10 fVar12;
  undefined4 uVar13;
  float local_24;
  float fStack_20;
  float local_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float local_c [3];
  
  fVar1 = (float)_DAT_008afe98;
  fVar7 = param_1[1];
  param_1[1] = fVar7 - fVar1;
  if (((DAT_007c56a0 & 1) == 0) || (DAT_008ab6e4 == 2)) goto LAB_004fd0c7;
  if (fVar7 - fVar1 < DAT_0059e440) {
    if (*(char *)(param_1 + 0x10) != '\0') {
      *(undefined1 *)(param_1 + 0x10) = 0;
      FUN_004fc650();
      param_1[0x11] = -3.4028235e+38;
    }
    FUN_004fdeb0((_DAT_0059e43c - param_1[1]) * *param_1,(float)_DAT_008afea0 * *param_1,
                 DAT_005c329c);
    param_1[1] = 1.0;
    FUN_004fc870(local_c);
    iVar10 = DAT_008aae64;
    local_1c = (float)_DAT_008afea0;
    if (ABS(local_1c - param_1[0x11]) <= _DAT_0059e8e4) {
      iVar6 = 3;
      bVar11 = true;
      pfVar8 = param_1 + 0x12;
      pfVar9 = local_c;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar11 = *pfVar8 == *pfVar9;
        pfVar8 = pfVar8 + 1;
        pfVar9 = pfVar9 + 1;
      } while (bVar11);
      if (bVar11) goto LAB_004fd01b;
    }
    if (DAT_0083ee60 < 0x3ff) {
      DAT_0083ee60 = DAT_0083ee60 + 1;
      DAT_008aae64 = DAT_008aae64 + 0x1b0;
    }
    FUN_004b33b0(2,4,0xc,0xff,local_1c,0);
    *(float *)(iVar10 + 8) = local_c[0];
    *(float *)(iVar10 + 0xc) = local_c[1];
    *(float *)(iVar10 + 0x10) = local_c[2];
    fVar7 = (float)_DAT_008afea0;
    param_1[0x12] = local_c[0];
    param_1[0x13] = local_c[1];
    param_1[0x11] = fVar7;
    param_1[0x14] = local_c[2];
  }
LAB_004fd01b:
  iVar10 = DAT_008aae64;
  if ((((undefined4 *)param_1[0x17] != (undefined4 *)0x0) &&
      (pfVar8 = *(float **)param_1[0x17], pfVar8 != (float *)0x0)) &&
     (local_1c = (float)_DAT_008afea0, *pfVar8 < local_1c)) {
    if (DAT_0083ee60 < 0x3ff) {
      DAT_0083ee60 = DAT_0083ee60 + 1;
      DAT_008aae64 = DAT_008aae64 + 0x1b0;
    }
    if (pfVar8[1] == 1.4013e-45) {
      uVar13 = 2;
    }
    else {
      uVar13 = 3;
    }
    FUN_004b33b0(uVar13,6,1,0xff,local_1c,0);
    uVar2 = __ftol();
    *(undefined1 *)(iVar10 + 8) = uVar2;
    if (param_1[0x17] != 0.0) {
      param_1[0x17] = *(float *)((int)param_1[0x17] + 4);
    }
  }
LAB_004fd0c7:
  if (param_1[1] < DAT_0059e440 == (param_1[1] == DAT_0059e440)) {
    fVar7 = (float)_DAT_008afe98 / ((float)_DAT_008afe98 + param_1[1]);
    param_1[2] = fVar7 * param_1[8] + (_DAT_0059e43c - fVar7) * param_1[2];
  }
  else {
    param_1[2] = param_1[8];
  }
  if (_DAT_0059e43c <= param_1[2]) {
    local_24 = (_DAT_0059e43c - param_1[0x3f]) - (param_1[0x40] - param_1[0x3f]) * param_1[9];
  }
  else {
    local_24 = _DAT_0059e43c - param_1[0x3f] * param_1[2];
  }
  if (DAT_007cfec4 < _DAT_0059e43c) {
    local_10 = (float)_DAT_008afea0;
    fVar12 = (float10)FUN_0058957a();
    fStack_20 = (float)fVar12;
    if ((float10)_DAT_005ad2b4 <= fVar12) {
      if (_DAT_005ad2b0 <= fStack_20) {
        if (_DAT_005ad2a8 <= fStack_20) {
          if (_DAT_005ad2a4 <= fStack_20) {
            local_1c = DAT_007cfec4;
          }
          else {
            local_1c = (_DAT_005ad2a4 - fStack_20) * _DAT_005ad2ac;
          }
        }
        else {
          local_1c = 1.0;
        }
      }
      else {
        local_1c = (fStack_20 - _DAT_005ad2b4) * _DAT_005ad2ac;
      }
    }
    else {
      local_1c = DAT_007cfec4;
    }
    local_24 = local_1c * local_24;
    FUN_004fc170(local_1c);
    fVar7 = 0.0;
    if ((fStack_20 < _DAT_005ad2a0) || (_DAT_005ad29c < fStack_20)) {
      fVar7 = 1.4013e-45;
    }
    if (param_1[4] != fVar7) {
      param_1[4] = fVar7;
      FUN_00545670(&local_10,&local_1c,&fStack_20);
      iVar10 = 0;
      if (0 < (int)local_1c) {
        do {
          iVar6 = FUN_005457f0(iVar10);
          iVar6 = _strncmp((char *)(iVar6 + 0x58),s_NIGHTLIGHT_005d6f78,10);
          if (iVar6 == 0) {
            FUN_0055d2f0(param_1[4]);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)local_1c);
      }
      iVar10 = 0;
      if (0 < (int)fStack_20) {
        do {
          iVar6 = FUN_00545820(iVar10);
          iVar6 = _strncmp((char *)(iVar6 + 0x58),s_NIGHTLIGHT_005d6f78,10);
          if (iVar6 == 0) {
            FUN_0055d2f0(param_1[4]);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)fStack_20);
      }
    }
  }
  if (param_1[7] != DAT_0059e440) {
    if (1 < DAT_007cf8a8) {
      local_24 = (_DAT_0059e43c - local_24) * param_1[7] + local_24;
    }
    param_1[7] = 0.0;
  }
  if (_DAT_005ad298 < ABS(param_1[3] - local_24)) {
    FUN_005457c0(0);
    if (DAT_0059e440 <= local_24) {
      if (_DAT_0059e43c < local_24) {
        local_24 = 1.0;
      }
    }
    else {
      local_24 = 0.0;
    }
    param_1[3] = local_24;
    FUN_0055d410(2,local_24);
  }
  fStack_20 = (param_1[0xb] - param_1[10]) * _DAT_0059e46c;
  if (DAT_0059e440 <= fStack_20) {
    if (_DAT_0059e43c < fStack_20) {
      fStack_20 = 1.0;
    }
  }
  else {
    fStack_20 = 0.0;
  }
  if (_DAT_0059e97c < ABS(param_1[0x29] - fStack_20)) {
    param_1[0x29] = fStack_20;
    FUN_004cefe0(10,fStack_20);
  }
  fVar7 = param_1[2] * _DAT_0059ef78 +
          param_1[9] * _DAT_005ad294 + (param_1[0xb] + param_1[10]) * _DAT_0059e450 * _DAT_0059e8fc;
  fVar1 = DAT_0059e440;
  if ((DAT_0059e440 <= fVar7) && (fVar1 = fVar7, _DAT_0059e43c < fVar7)) {
    fVar1 = _DAT_0059e43c;
  }
  if (param_1[0x2a] <= fVar1) {
    fVar7 = (fVar1 - param_1[0x2a]) * param_1[0x2c];
    fStack_20 = (param_1[0x3c] - param_1[0x39]) * fVar7 + param_1[0x39];
    local_1c = (param_1[0x3d] - param_1[0x3a]) * fVar7 + param_1[0x3a];
    local_24 = (param_1[0x3e] - param_1[0x3b]) * fVar7 + param_1[0x3b];
    local_10 = (param_1[0x33] - param_1[0x30]) * fVar7 + param_1[0x30];
    fStack_14 = (param_1[0x34] - param_1[0x31]) * fVar7 + param_1[0x31];
    fStack_18 = (param_1[0x35] - param_1[0x32]) * fVar7 + param_1[0x32];
  }
  else {
    fVar1 = fVar1 * param_1[0x2b];
    fStack_20 = (param_1[0x39] - param_1[0x36]) * fVar1 + param_1[0x36];
    local_1c = (param_1[0x3a] - param_1[0x37]) * fVar1 + param_1[0x37];
    local_24 = (param_1[0x3b] - param_1[0x38]) * fVar1 + param_1[0x38];
    local_10 = (param_1[0x30] - param_1[0x2d]) * fVar1 + param_1[0x2d];
    fStack_14 = (param_1[0x31] - param_1[0x2e]) * fVar1 + param_1[0x2e];
    fStack_18 = (param_1[0x32] - param_1[0x2f]) * fVar1 + param_1[0x2f];
  }
  FUN_005438b0(fStack_20,local_1c);
  FUN_00543920(local_24);
  uVar13 = __ftol();
  uVar3 = __ftol(uVar13);
  uVar4 = __ftol(uVar3);
  FUN_00543870(uVar4,uVar3,uVar13);
  if (DAT_0059e440 < param_1[0xb]) {
    param_1[5] = 1.4013e-45;
  }
  iVar10 = DAT_008acea8;
  if (_DAT_0059e444 < ABS(param_1[10] - param_1[6])) {
    param_1[6] = param_1[10];
    if (param_1[10] <= _DAT_005acd48) {
      if (0 < iVar10) {
        iVar6 = 0;
        do {
          iVar5 = DAT_008aceac + iVar6;
          if (*(int *)(iVar5 + 0x30) == 7) {
            *(undefined4 *)(iVar5 + 0x30) = 6;
          }
          if (*(int *)(iVar5 + 0x34) == 0x16) {
            *(undefined4 *)(iVar5 + 0x34) = 0x15;
          }
          iVar6 = iVar6 + 0x6c;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
    else if (0 < iVar10) {
      iVar6 = 0;
      do {
        iVar5 = DAT_008aceac + iVar6;
        if (*(int *)(iVar5 + 0x30) == 6) {
          *(undefined4 *)(iVar5 + 0x30) = 7;
        }
        if (*(int *)(iVar5 + 0x34) == 0x15) {
          *(undefined4 *)(iVar5 + 0x34) = 0x16;
        }
        iVar6 = iVar6 + 0x6c;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      return;
    }
  }
  return;
}


