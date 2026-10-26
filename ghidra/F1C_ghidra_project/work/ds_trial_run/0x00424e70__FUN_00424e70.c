// Function: FUN_00424e70 @ 00424e70
// Size (bytes): 2024


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_00424e70(int *param_1)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  float fVar5;
  double dVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  float10 fVar13;
  undefined4 uVar14;
  float afStack_18 [2];
  float fStack_10;
  undefined1 auStack_c [12];
  
  uVar7 = param_1[0xcb2];
  if ((uVar7 != 1) && (uVar7 != 0)) {
    return uVar7;
  }
  param_1[0x1120] = (int)(float)_DAT_008afea0;
  if (((char)param_1[0x117d] != '\0') || (*(int *)(*param_1 + 13000) != 1)) {
    fVar13 = (float10)fsin((float10)(float)param_1[0xd3c]);
    param_1[0x1123] = (int)(float)-fVar13;
    fVar13 = (float10)fcos((float10)(float)param_1[0xd3c]);
    param_1[0x1125] = (int)(float)-fVar13;
    uVar7 = FUN_00426430();
    if ((char)uVar7 == '\0') {
      return uVar7;
    }
    if (*(int *)(*param_1 + 13000) != 1) {
      return uVar7;
    }
    if ((double)(float)param_1[0x104f] < _DAT_008afea0) {
      param_1[0x104f] = 0x7f7fffff;
      if (DAT_007c56a8 == 8) {
        FUN_0042ac70(1);
      }
      else {
        FUN_0042a180();
      }
      piVar12 = param_1 + 0x1052;
      iVar11 = 5;
      do {
        if ((param_1[0x100f] == piVar12[-1]) && (*piVar12 < 4)) {
          param_1[0x105b] = param_1[0x1027];
          if ((float)param_1[0x1027] < _DAT_0059e86c) {
            param_1[0x105b] = 0x42200000;
          }
          iVar8 = _rand();
          iVar9 = __ftol();
          param_1[0x105b] = (int)(float)(iVar8 % iVar9);
          param_1[*piVar12 + 0xf5c] = (int)(float)(iVar8 % iVar9);
        }
        piVar12 = piVar12 + 2;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    if ((float)param_1[0x1101] < (float)param_1[0x1120]) {
      param_1[0x1101] = (int)((float)param_1[0x1120] + _DAT_0059e46c);
      FUN_00429470();
    }
    if ((float)param_1[0x105c] < (float)param_1[0x1120]) {
      param_1[0x110f] = 0;
      param_1[0x10fe] = 0;
      FUN_0042ae00();
      if (DAT_007c56a4 == 7) {
        param_1[0x1144] = 4;
      }
      else {
        param_1[0x1144] = 5;
      }
      param_1[0x1149] = 0;
      param_1[0x110e] = 0x3f800000;
      param_1[0x110d] = 0;
      param_1[0x1153] = 0;
      param_1[0x1154] = 1;
      param_1[0x1109] = 0;
      FUN_00426430();
      param_1[0x105c] = 0x7f7fffff;
      param_1[0x111f] = (int)((float)_DAT_008afea0 + _DAT_0059e46c);
      FUN_004efa40(0);
    }
    iVar11 = param_1[0x1144];
    if ((iVar11 == 4) || (iVar11 == 5)) {
      dVar6 = (double)(float)param_1[0x114d];
      uVar7 = (uint)(ushort)((ushort)(_DAT_008afea0 < dVar6) << 8 |
                             (ushort)(NAN(_DAT_008afea0) || NAN(dVar6)) << 10 |
                            (ushort)(_DAT_008afea0 == dVar6) << 0xe);
      if ((_DAT_008afea0 >= dVar6 && (_DAT_008afea0 == dVar6) == 0) || (iVar11 == 4)) {
        if ((param_1[0x1162] <= param_1[0x1178]) && (DAT_007c56a4 != 7)) {
          *(undefined1 *)(param_1 + 0x117d) = 0;
        }
        if (param_1[0x1019] == 2) {
          *(undefined1 *)(param_1 + 0x117d) = 0;
        }
        uVar7 = FUN_004a4110(param_1);
        if (((char)uVar7 == '\0') || ((char)param_1[0x117d] == '\0')) {
          param_1[0x114d] = (int)((float)_DAT_008afea0 + _DAT_0059e46c);
        }
        else if (param_1[0x1144] == 5) {
          uVar14 = 1;
          uVar10 = FUN_00429fd0(1);
          FUN_004f1a60(uVar10,uVar14);
          uVar7 = FUN_004efa40(0);
          param_1[0x1144] = 3;
        }
        else {
          param_1[0x1144] = 0;
        }
      }
      param_1[0xd60] = 0;
      param_1[0xd61] = 0x3f800000;
      param_1[0xd5f] = 0;
      return uVar7;
    }
    if ((param_1[0x117f] == 0) &&
       ((param_1[0xf5b] != 2 &&
        ((float)param_1[0xe61] < _DAT_0059e600 == ((float)param_1[0xe61] == _DAT_0059e600))))) {
      param_1[0x1108] = 0;
    }
    FUN_0042a7d0();
    param_1[0x1121] = 0x497423f0;
    FUN_00425920();
    if (param_1[0x1154] < DAT_005ea2cc) {
      FUN_004270a0();
    }
    FUN_00426100();
    FUN_00426cf0();
    FUN_00426330();
    uVar7 = param_1[0x1144];
    if ((uVar7 == 0) || (uVar7 == 6)) {
      uVar7 = FUN_00425670();
    }
    else if (uVar7 == 1) {
      uVar7 = FUN_004258c0();
    }
    else if (uVar7 == 3) {
      FUN_00403f70(*(undefined4 *)(*param_1 + 0x48a4),afStack_18,auStack_c);
      fVar5 = (afStack_18[0] - (float)param_1[0xd38]) * (afStack_18[0] - (float)param_1[0xd38]) +
              (fStack_10 - (float)param_1[0xd3a]) * (fStack_10 - (float)param_1[0xd3a]);
      fVar1 = (float)param_1[0x1187];
      uVar7 = (uint)(ushort)((ushort)(fVar5 < fVar1) << 8 | (ushort)(NAN(fVar5) || NAN(fVar1)) << 10
                            | (ushort)(fVar5 == fVar1) << 0xe);
      if (fVar5 < fVar1 == (fVar5 == fVar1)) {
        param_1[0x1144] = 0;
      }
      else {
        param_1[0x1187] = (int)fVar5;
      }
    }
    else {
      if (uVar7 == 2) {
        uVar7 = FUN_00425660();
        return uVar7;
      }
      if (uVar7 == 7) {
        fVar1 = (float)param_1[0x1110];
        param_1[0x110b] = 0;
        bVar2 = NAN(_DAT_0059e7e8);
        bVar3 = fVar1 < _DAT_0059e7e8;
        bVar4 = fVar1 == _DAT_0059e7e8;
        param_1[0x110e] = 0x3f800000;
        param_1[0x110d] = 0;
        uVar7 = (uint)(ushort)((ushort)bVar3 << 8 | (ushort)(NAN(fVar1) || bVar2) << 10 |
                              (ushort)bVar4 << 0xe);
        if (bVar3) {
          param_1[0x1144] = 0;
        }
      }
    }
    goto LAB_004254f5;
  }
  uVar7 = param_1[0x1113];
  param_1[0x100a] = 0;
  param_1[0x110d] = 0;
  if (DAT_007c56a8 != uVar7) {
    fVar1 = (float)param_1[0x1112] - _DAT_0059e87c;
    param_1[0x1112] = (int)fVar1;
    uVar7 = (uint)(ushort)((ushort)(fVar1 < DAT_0059e440) << 8 |
                           (ushort)(NAN(fVar1) || NAN(DAT_0059e440)) << 10 |
                          (ushort)(fVar1 == DAT_0059e440) << 0xe);
    if (fVar1 < DAT_0059e440) {
      FUN_00424c80();
      if ((DAT_007c56a8 == 5) || (DAT_007c56a8 == 1)) {
        FUN_0042adb0();
      }
      uVar7 = DAT_007c56a8;
      param_1[0x1113] = DAT_007c56a8;
      if (((char)param_1[0x117d] == '\x01') && (DAT_005c3160 == '\x01')) {
        piVar12 = param_1 + 0x1051;
        iVar11 = 5;
        param_1[0x104f] = (int)((float)_DAT_008afea0 + _DAT_0059e800);
        do {
          uVar7 = piVar12[1];
          if ((uVar7 == 4) && (*piVar12 == 0)) {
            FUN_004efac0();
            uVar7 = _rand();
            uVar7 = uVar7 & 0x14;
            param_1[0x105c] = (int)((float)uVar7 + (float)_DAT_008afea0 + _DAT_0059e5fc);
          }
          else if ((uVar7 == 5) && (*piVar12 == 0)) {
            FUN_004efac0();
            uVar7 = _rand();
            uVar7 = uVar7 & 0x80000003;
            if ((int)uVar7 < 0) {
              uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
            }
            if (uVar7 == 0) {
              uVar7 = 7;
            }
            else {
              uVar7 = (-(uint)(uVar7 != 1) & 5) + 3;
            }
            if (param_1[0x101a] == 0) {
              param_1[0x101a] = uVar7;
            }
          }
          piVar12 = piVar12 + 2;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
  }
  if (param_1[0x1113] == 4) {
    DAT_005c3160 = '\x01';
    FUN_004ef930(0);
    fVar1 = (float)_DAT_008afea0;
    if (fVar1 - _DAT_008acfb8 <= _DAT_0059e7e8) {
      if (fVar1 < (float)param_1[0x1159]) {
        if (param_1[0x115a] == 0) {
          iVar11 = __ftol();
          uVar7 = iVar11 * -4;
          param_1[0x110d] = *(int *)(&DAT_005c3144 + iVar11 * 4);
          param_1[0x110e] = 0x3f800000;
          param_1[0x110b] = 0;
        }
        else {
          iVar11 = __ftol();
          uVar7 = *(uint *)(&DAT_005c30e0 + iVar11 * -4);
          param_1[0x110d] = uVar7;
          param_1[0x110e] = 0x3f800000;
          param_1[0x110b] = 0;
        }
        goto LAB_004254f5;
      }
      iVar11 = param_1[0x115a];
      param_1[0x1158] = (int)fVar1;
      param_1[0x115a] = (uint)(iVar11 == 0);
      if ((iVar11 == 0) == 0) {
        iVar11 = _rand();
        fVar1 = (float)(iVar11 % 100) * _DAT_0059e6ec + (float)_DAT_008afea0 + _DAT_0059e43c;
      }
      else {
        iVar11 = _rand();
        fVar1 = (float)(iVar11 % 100) * _DAT_0059e444 + (float)_DAT_008afea0;
      }
      uVar7 = iVar11 / 100;
      param_1[0x1159] = (int)fVar1;
    }
    else {
      fVar1 = ((fVar1 - _DAT_008acfb8) - _DAT_0059e7e8) * _DAT_0059e878;
      fVar5 = _DAT_0059e6a8;
      if (fVar1 <= _DAT_0059e43c) {
        fVar5 = _DAT_0059e820 - fVar1 * _DAT_0059e874;
      }
      param_1[0x110d] =
           (int)(((float)param_1[0xe67] - (float)param_1[0xe68]) / fVar5 + _DAT_0059e450);
      fVar1 = (float)param_1[0x110d];
      uVar7 = (uint)(ushort)((ushort)(fVar1 < DAT_0059e440) << 8 |
                             (ushort)(NAN(fVar1) || NAN(DAT_0059e440)) << 10 |
                            (ushort)(fVar1 == DAT_0059e440) << 0xe);
      if (fVar1 < DAT_0059e440) {
        param_1[0x110d] = 0;
        param_1[0x110e] = 0x3f800000;
        param_1[0x110b] = 0;
        goto LAB_004254f5;
      }
      fVar1 = (float)param_1[0x110d];
      uVar7 = (uint)(ushort)((ushort)(fVar1 < _DAT_0059e43c) << 8 |
                             (ushort)(NAN(fVar1) || NAN(_DAT_0059e43c)) << 10 |
                            (ushort)(fVar1 == _DAT_0059e43c) << 0xe);
      if (fVar1 >= _DAT_0059e43c && (fVar1 == _DAT_0059e43c) == 0) {
        param_1[0x110d] = 0x3f800000;
        param_1[0x110e] = 0x3f800000;
        param_1[0x110b] = 0;
        goto LAB_004254f5;
      }
    }
  }
  param_1[0x110e] = 0x3f800000;
  param_1[0x110b] = 0;
LAB_004254f5:
  if (param_1[0xf5b] == 2) {
    param_1[0x110d] = 0;
    fVar1 = ABS((float)param_1[0x110a]);
    uVar7 = (uint)(ushort)((ushort)(fVar1 < _DAT_0059e864) << 8 |
                           (ushort)(NAN(fVar1) || NAN(_DAT_0059e864)) << 10 |
                          (ushort)(fVar1 == _DAT_0059e864) << 0xe);
    if (fVar1 < _DAT_0059e864 || (fVar1 == _DAT_0059e864) != 0) {
      uVar7 = (uint)(ushort)((ushort)(fVar1 < _DAT_0059e7ec) << 8 |
                             (ushort)(NAN(fVar1) || NAN(_DAT_0059e7ec)) << 10 |
                            (ushort)(fVar1 == _DAT_0059e7ec) << 0xe);
      if (fVar1 < _DAT_0059e7ec) {
        param_1[0x110e] = 0x3c23d70a;
      }
      else {
        param_1[0x110e] = (int)((fVar1 - _DAT_0059e7ec) * _DAT_0059e84c + _DAT_0059e444);
      }
    }
    else {
      param_1[0x110e] = 0x3e570a3d;
    }
  }
  param_1[0xd60] = param_1[0x110b];
  param_1[0x117f] = 0;
  param_1[0xd61] = param_1[0x110e];
  param_1[0xd5f] = param_1[0x110d];
  return uVar7;
}


