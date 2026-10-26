// Function: FUN_00426430 @ 00426430
// Size (bytes): 2177


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00426430(int *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint in_EAX;
  uint uVar9;
  undefined2 uVar14;
  int iVar10;
  int *piVar11;
  float fVar12;
  ushort uVar15;
  float fVar13;
  int *piVar16;
  uint uVar17;
  int iVar18;
  float10 fVar19;
  float10 fVar20;
  float10 fVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  float local_3c;
  float local_34;
  
  uVar17 = param_1[0x10d5];
  pfVar1 = (float *)(param_1 + 0xd38);
  param_1[0x1110] =
       (int)SQRT((float)param_1[0xd40] * (float)param_1[0xd40] +
                 (float)param_1[0xd3f] * (float)param_1[0xd3f] +
                 (float)param_1[0xd3e] * (float)param_1[0xd3e]);
  if (uVar17 == 0) {
    uVar9 = FUN_004038e0(pfVar1,param_1[0x1154]);
    param_1[0x10d5] = uVar9;
    uVar17 = uVar9;
    if (uVar9 == 0) {
      return 0;
    }
LAB_00426558:
    *(undefined1 *)(param_1 + 0x1122) = 1;
  }
  else {
    fVar2 = *pfVar1 - *(float *)(uVar17 + 0x94);
    fVar13 = (float)param_1[0xd3a] - *(float *)(uVar17 + 0x9c);
    uVar9 = in_EAX & 0xffff0000;
    if (_DAT_0059e8e0 < fVar2 * fVar2 + fVar13 * fVar13) {
      uVar9 = FUN_004038e0(pfVar1,param_1[0x1154]);
      param_1[0x10d5] = uVar9;
      if (uVar9 == 0) {
        return 0;
      }
      *(undefined1 *)(param_1 + 0x1122) = 1;
      uVar17 = uVar9;
    }
    uVar4 = param_1[0x10d5];
    fVar2 = *(float *)(uVar4 + 0xc) * (*(float *)(uVar4 + 0x94) - *pfVar1) +
            *(float *)(uVar4 + 0x14) * (*(float *)(uVar4 + 0x9c) - (float)param_1[0xd3a]);
    uVar14 = (undefined2)(uVar9 >> 0x10);
    uVar9 = CONCAT22(uVar14,(ushort)(fVar2 < DAT_0059e440) << 8 |
                            (ushort)(NAN(fVar2) || NAN(DAT_0059e440)) << 10 |
                            (ushort)(fVar2 == DAT_0059e440) << 0xe);
    if (fVar2 < DAT_0059e440) {
      fVar2 = *(float *)(param_1[0x10d6] + 0x48);
      fVar13 = *(float *)(uVar4 + 0x48);
      uVar9 = CONCAT22(uVar14,(ushort)(fVar2 < fVar13) << 8 |
                              (ushort)(NAN(fVar2) || NAN(fVar13)) << 10 |
                              (ushort)(fVar2 == fVar13) << 0xe);
      uVar17 = uVar4;
      if (fVar2 < fVar13) {
        param_1[0x1116] = param_1[0x1116] + 1;
      }
      goto LAB_00426558;
    }
  }
  uVar22 = CONCAT31((int3)(uVar9 >> 8),(char)param_1[0x1122]);
  if ((char)param_1[0x1122] == '\0') {
    if ((char)param_1[0x1050] == '\0') goto LAB_00426ca7;
  }
  else {
    piVar16 = param_1 + 0x10d6;
    param_1[0x1114] = *(int *)(param_1[0x10d5] + 0x48);
    iVar10 = FUN_00403aa0(pfVar1,param_1[0x10d6],param_1[0x1154],1);
    param_1[0x10d5] = iVar10;
    local_34 = 2.66247e-44;
    piVar11 = piVar16;
    do {
      if (((param_1[0x1153] == 0) || (iVar10 = *(int *)(piVar11[-1] + 0x114), iVar10 == 0)) ||
         (param_1[0x1153] != *(int *)(iVar10 + 300))) {
        iVar10 = *(int *)(piVar11[-1] + 0x110);
      }
      *piVar11 = iVar10;
      piVar11 = piVar11 + 1;
      local_34 = (float)((int)local_34 + -1);
    } while (local_34 != 0.0);
    if ((param_1[0x1154] == 0) && (*(int *)(*piVar16 + 300) == 1)) {
      FUN_00424cd0(0xe,0);
      uVar23 = 1;
      uVar22 = 1;
LAB_0042662f:
      FUN_004a46f0(param_1,uVar22,uVar23);
    }
    else if ((param_1[0x1154] == 1) && (*(int *)(*piVar16 + 300) == 0)) {
      uVar23 = 0;
      uVar22 = 0;
      goto LAB_0042662f;
    }
    iVar10 = param_1[0x10d5];
    param_1[0x1154] = *(int *)(*piVar16 + 300);
    fVar19 = (float10)FUN_004e8ce0(*(undefined4 *)(iVar10 + 0x74),iVar10 + 0x78,
                                   *(undefined4 *)(iVar10 + 0x70),0x41800000);
    fVar19 = fVar19 * (float10)(float)param_1[0x1141] + (float10)(float)param_1[0x1140];
    if ((float10)_DAT_0059e8dc < fVar19) {
      fVar19 = (float10)_DAT_0059e8dc;
    }
    if (param_1[0x1154] == 1) {
      fVar19 = (float10)_DAT_008acfb4;
    }
    param_1[0x1111] = (int)(float)((float10)(float)param_1[0x1110] / fVar19);
    if ((float10)_DAT_0059e43c < (float10)(float)param_1[0x1110] / fVar19) {
      param_1[0x1111] = 0x3f800000;
    }
    param_1[0x1115] = (int)((float)param_1[0x1116] * DAT_005ea3fc + (float)param_1[0x1114]);
    if ((_DAT_0059e8d8 <= (float)param_1[0x1110]) || (param_1[0x1154] == 1)) {
      if (_DAT_0059e468 <= (float)param_1[0x1110]) {
        if (_DAT_0059e8d4 <= (float)param_1[0x1110]) {
          param_1[0x111a] = 3;
        }
        else {
          param_1[0x111a] = 2;
        }
      }
      else {
        param_1[0x111a] = 1;
      }
    }
    else {
      param_1[0x111a] = 0;
    }
    fVar2 = *(float *)(param_1[0x10d5] + 0x94) - (float)param_1[0xd38];
    fVar13 = *(float *)(param_1[0x10d5] + 0x9c) - (float)param_1[0xd3a];
    param_1[0x1126] = param_1[0xd38];
    param_1[0x1128] = param_1[0xd3a];
    param_1[0x10fd] = (int)SQRT(fVar2 * fVar2 + fVar13 * fVar13);
  }
  iVar10 = param_1[0x111a];
  uVar22 = 0;
  if (param_1[iVar10 + 0x10d5] != 0) {
    fVar2 = *(float *)(uVar17 + 0x94);
    iVar18 = param_1[0x10d6];
    fVar13 = *(float *)(uVar17 + 0x9c);
    iVar5 = param_1[0xf5b];
    fVar12 = *(float *)(uVar17 + 0x20);
    fVar3 = *(float *)(uVar17 + 0x28);
    piVar16 = param_1 + 0x10d6;
    param_1[0x114b] = 0x3f800000;
    param_1[0x114a] = 0x3f800000;
    param_1[0x110a] =
         (int)-(fVar12 * (fVar2 - (float)param_1[0xd38]) + fVar3 * (fVar13 - (float)param_1[0xd3a]))
    ;
    fVar19 = ((float10)_DAT_0059e43c - (float10)(float)param_1[0x1111]) * (float10)_DAT_0059e868 +
             (float10)*(float *)(iVar18 + 0xbc + iVar10 * 4);
    fVar2 = (float)fVar19;
    local_34 = (float)(fVar19 + (float10)(float)param_1[0xd3c]);
    fVar19 = (float10)(float)param_1[0xd3c] - fVar19;
    if ((iVar5 != 2) ||
       ((float)param_1[0xe61] < _DAT_0059e600 == ((float)param_1[0xe61] == _DAT_0059e600))) {
      fVar13 = *(float *)(iVar18 + 0xbc + iVar10 * 4);
      if (fVar13 < _DAT_0059e8d0 == (fVar13 == _DAT_0059e8d0)) {
        fVar13 = *(float *)(param_1[0x10d9] + 0xb8) - *(float *)(param_1[0x10d5] + 0xb8);
        if ((float)_DAT_0059e890 <= ABS(fVar13)) {
          if (DAT_0059e440 <= fVar13) {
            fVar13 = fVar13 - _DAT_0059e888;
          }
          else {
            fVar13 = fVar13 + _DAT_0059e888;
          }
        }
        fVar12 = (float)CONCAT22((short)((uint)param_1[0x10d5] >> 0x10),
                                 (ushort)(fVar13 < DAT_0059e440) << 8 |
                                 (ushort)(NAN(fVar13) || NAN(DAT_0059e440)) << 10 |
                                 (ushort)(fVar13 == DAT_0059e440) << 0xe);
        if (fVar13 < DAT_0059e440 == 0 && (fVar13 == DAT_0059e440) == 0) {
          param_1[0x114a] = -0x40800000;
          local_3c = *(float *)(iVar18 + 0xb8) + *(float *)(iVar18 + 0xbc + iVar10 * 4);
        }
        else {
          param_1[0x114b] = -0x40800000;
          local_3c = *(float *)(iVar18 + 0xb8) - *(float *)(iVar18 + 0xbc + iVar10 * 4);
        }
      }
      else {
        fVar12 = *(float *)(iVar18 + 0xb8);
        local_3c = fVar12;
      }
      if (*(int *)(*param_1 + 13000) != 1) {
        return CONCAT31((int3)((uint)fVar12 >> 8),1);
      }
      fVar13 = local_34 - local_3c;
      if ((float)_DAT_0059e890 <= ABS(fVar13)) {
        if (DAT_0059e440 <= fVar13) {
          fVar13 = fVar13 - _DAT_0059e888;
        }
        else {
          fVar13 = fVar13 + _DAT_0059e888;
        }
      }
      if (((fVar2 < fVar13) && (iVar5 != 2)) &&
         ((float)param_1[0xe61] < _DAT_0059e600 == ((float)param_1[0xe61] == _DAT_0059e600))) {
        fVar13 = (float)param_1[0xd3c] - local_3c;
        if ((float)_DAT_0059e890 <= ABS(fVar13)) {
          if (DAT_0059e440 <= fVar13) {
            fVar13 = fVar13 - _DAT_0059e888;
          }
          else {
            fVar13 = fVar13 + _DAT_0059e888;
          }
        }
        if (fVar13 <= fVar2) {
          local_34 = local_3c + fVar2;
        }
        else {
          local_34 = (float)param_1[0xd3c];
        }
      }
      fVar20 = fVar19 - (float10)local_3c;
      if ((float10)_DAT_0059e890 <= ABS(fVar20)) {
        if ((float10)DAT_0059e440 <= fVar20) {
          fVar20 = fVar20 - (float10)_DAT_0059e888;
        }
        else {
          fVar20 = fVar20 + (float10)_DAT_0059e888;
        }
      }
      if (((fVar20 < -(float10)fVar2) && (iVar5 != 2)) &&
         ((float)param_1[0xe61] < _DAT_0059e600 == ((float)param_1[0xe61] == _DAT_0059e600))) {
        fVar13 = local_3c - (float)param_1[0xd3c];
        if ((float)_DAT_0059e890 <= ABS(fVar13)) {
          if (DAT_0059e440 <= fVar13) {
            fVar13 = fVar13 - _DAT_0059e888;
          }
          else {
            fVar13 = fVar13 + _DAT_0059e888;
          }
        }
        if (fVar13 <= fVar2) {
          fVar19 = (float10)local_3c - (float10)fVar2;
        }
        else {
          fVar19 = (float10)(float)param_1[0xd3c];
        }
      }
    }
    iVar10 = param_1[iVar10 + 0x10d5];
    fVar20 = (float10)fsin((float10)local_34);
    fVar12 = *(float *)(iVar10 + 0x94);
    fVar3 = *(float *)(iVar10 + 0x9c);
    fVar6 = (float)param_1[0xd3a];
    fVar21 = (float10)fcos((float10)local_34);
    fVar2 = *(float *)(iVar10 + 0x20);
    fVar13 = *(float *)(iVar10 + 0x28);
    fVar7 = (float)param_1[0xd38];
    fVar8 = _DAT_0059e43c / SQRT(fVar2 * fVar2 + fVar13 * fVar13);
    fVar2 = fVar8 * fVar2;
    fVar8 = fVar8 * fVar13;
    uVar14 = (undefined2)((uint)fVar7 >> 0x10);
    if (-fVar20 == (float10)DAT_0059e440) {
      param_1[0x1105] = 0;
    }
    else {
      fVar20 = -fVar21 / -fVar20;
      param_1[0x1105] =
           (int)(float)(((((float10)fVar12 * fVar20 + (float10)fVar6) - (float10)fVar7 * fVar20) -
                        (float10)fVar3) / ((float10)fVar8 - (float10)fVar2 * fVar20));
    }
    fVar20 = (float10)fsin(fVar19);
    fVar19 = (float10)fcos(fVar19);
    if ((float)-fVar20 == DAT_0059e440) {
      param_1[0x1106] = 0;
    }
    else {
      fVar19 = -fVar19 / (float10)(float)-fVar20;
      param_1[0x1106] =
           (int)(float)(((((float10)fVar12 * fVar19 + (float10)fVar6) - (float10)fVar7 * fVar19) -
                        (float10)fVar3) / ((float10)fVar8 - (float10)fVar2 * fVar19));
    }
    fVar20 = (float10)fsin((float10)(float)param_1[0xd3c]);
    fVar20 = -fVar20;
    fVar21 = (float10)fcos((float10)(float)param_1[0xd3c]);
    fVar19 = (float10)DAT_0059e440;
    uVar22 = CONCAT22(uVar14,(ushort)(fVar20 < fVar19) << 8 |
                             (ushort)(NAN(fVar20) || NAN(fVar19)) << 10 |
                             (ushort)(fVar20 == fVar19) << 0xe);
    if (fVar20 == fVar19) {
      param_1[0x1107] = 0;
    }
    else {
      fVar20 = -fVar21 / fVar20;
      param_1[0x1107] =
           (int)(float)(((((float10)fVar12 * fVar20 + (float10)fVar6) - (float10)fVar7 * fVar20) -
                        (float10)fVar3) / ((float10)fVar8 - (float10)fVar2 * fVar20));
    }
    if (iVar5 != 2) {
      fVar2 = (float)param_1[0xe61];
      uVar22 = CONCAT22(uVar14,(ushort)(fVar2 < _DAT_0059e600) << 8 |
                               (ushort)(NAN(fVar2) || NAN(_DAT_0059e600)) << 10 |
                               (ushort)(fVar2 == _DAT_0059e600) << 0xe);
      if (fVar2 < _DAT_0059e600 == (fVar2 == _DAT_0059e600)) {
        iVar10 = param_1[0x10d5];
        local_3c = *(float *)(iVar10 + 0x54);
        fVar2 = *(float *)(iVar10 + 0x50);
        iVar18 = 5;
        do {
          iVar5 = *piVar16;
          uVar15 = (ushort)((uint)iVar10 >> 0x10);
          if (*(float *)(iVar5 + 0x54) <= local_3c) {
            local_3c = *(float *)(iVar5 + 0x54);
          }
          iVar10 = (uint)uVar15 << 0x10;
          if (*(float *)(iVar5 + 0x50) <= fVar2) {
            fVar2 = *(float *)(iVar5 + 0x50);
          }
          piVar16 = piVar16 + 1;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
        fVar13 = (float)((uint)uVar15 << 0x10);
        if (local_3c < (float)param_1[0x1105]) {
          fVar13 = (float)((uint)uVar15 << 0x10);
          if (local_3c <= (float)param_1[0x1106]) {
            param_1[0x1105] = param_1[0x1106];
          }
          else {
            param_1[0x1105] = (int)local_3c;
            fVar13 = local_3c;
          }
        }
        fVar2 = -fVar2;
        fVar12 = (float)param_1[0x1106];
        uVar14 = (undefined2)((uint)fVar13 >> 0x10);
        uVar22 = CONCAT22(uVar14,(ushort)(fVar2 < fVar12) << 8 |
                                 (ushort)(NAN(fVar2) || NAN(fVar12)) << 10 |
                                 (ushort)(fVar2 == fVar12) << 0xe);
        if (fVar2 < fVar12 == 0 && (fVar2 == fVar12) == 0) {
          fVar13 = (float)param_1[0x1105];
          uVar22 = CONCAT22(uVar14,(ushort)(fVar2 < fVar13) << 8 |
                                   (ushort)(NAN(fVar2) || NAN(fVar13)) << 10 |
                                   (ushort)(fVar2 == fVar13) << 0xe);
          if (fVar2 < fVar13) {
            param_1[0x1106] = (int)fVar2;
            *(undefined1 *)(param_1 + 0x1050) = 0;
            return CONCAT31((int3)((uint)uVar22 >> 8),1);
          }
          param_1[0x1106] = param_1[0x1105];
        }
      }
    }
    *(undefined1 *)(param_1 + 0x1050) = 0;
  }
LAB_00426ca7:
  return CONCAT31((int3)((uint)uVar22 >> 8),1);
}


