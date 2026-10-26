// Function: FUN_004bccc0 @ 004bccc0
// Strings:  [Ignored Blue Flags, Ignored Blue Flags, Cut Track, Cut Track, Speeding In Pitlane, Speeding In Pitlane, Wrong Way, Wrong Way]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004bccc0(int *param_1,float param_2)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  float fVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  char cVar12;
  int iVar13;
  float10 fVar14;
  float10 fVar15;
  int iVar16;
  undefined4 uVar17;
  float local_2c;
  float local_20;
  int local_1c;
  float local_18;
  float *local_14;
  int local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar16 = *param_1;
  fVar14 = (float10)FUN_004f0050();
  fVar2 = (float)fVar14;
  pfVar4 = *(float **)(iVar16 + 0x3aa8);
  local_1c = -1;
  local_14 = pfVar4;
  if ((((param_1[5] != -0x40800000) &&
       (fVar14 = (float10)FUN_004d7cf0(fVar2,&local_1c), (float10)_DAT_005acda0 <= fVar14)) &&
      (fVar14 = (float10)FUN_004d7cf0(param_1[5],0), fVar14 < (float10)_DAT_005acda0)) &&
     (iVar13 = FUN_004d7c10(param_1[5]), local_1c == iVar13)) {
    FUN_004193a0(*param_1,local_1c);
  }
  param_1[5] = (int)fVar2;
  if (*(char *)(*param_1 + 0x344c) == '\0') {
    if ((((char)param_1[0x2a] != '\0') &&
        (*(undefined1 *)(param_1 + 0x2a) = 0, _DAT_0059e8f4 < (float)param_1[0x2b])) &&
       (DAT_007cef84 != 0)) {
      if (DAT_007c56a4 == 7) {
        FUN_004bbd60(s_Speeding_In_Pitlane_005c271c,10);
      }
      else {
        iVar13 = __ftol();
        FUN_004bba90(s_Speeding_In_Pitlane_005c271c,(float)iVar13 * _DAT_0059e91c + _DAT_005acd9c);
      }
    }
  }
  else {
    if ((char)param_1[0x2a] == '\0') {
      param_1[0x2b] = 0;
    }
    *(undefined1 *)(param_1 + 0x2a) = 1;
    fVar3 = SQRT(*(float *)(iVar16 + 0x34fc) * *(float *)(iVar16 + 0x34fc) +
                 *(float *)(iVar16 + 0x34f8) * *(float *)(iVar16 + 0x34f8) +
                 *(float *)(iVar16 + 0x3500) * *(float *)(iVar16 + 0x3500)) - _DAT_008acfb4;
    if (DAT_0059e440 < fVar3) {
      param_1[0x2b] = (int)(fVar3 * param_2 + (float)param_1[0x2b]);
    }
  }
  fVar3 = (*(float *)(iVar16 + 0x34e0) - *pfVar4) * pfVar4[8] +
          (*(float *)(iVar16 + 0x34e4) - pfVar4[1]) * pfVar4[9] +
          (*(float *)(iVar16 + 0x34e8) - pfVar4[2]) * pfVar4[10];
  if (DAT_0059e440 <= fVar3) {
    fVar3 = fVar3 - pfVar4[0x1b];
  }
  else {
    fVar3 = -(pfVar4[0x1a] + fVar3);
  }
  cVar12 = FUN_004bc340();
  if (cVar12 == '\0') {
    *(undefined1 *)(param_1 + 0x2d) = 0;
  }
  else if ((char)param_1[0x2d] == '\0') {
    if (_DAT_0059e8e4 < fVar3) {
      param_1[0x2f] = param_1[0xb];
      *(undefined1 *)(param_1 + 0x2d) = 1;
      param_1[0x2e] = param_1[2];
      param_1[0x30] = (int)pfVar4[0x4b];
      fVar14 = (float10)FUN_004f01b0();
      param_1[0x31] = (int)(float)fVar14;
      param_1[0x32] = 0;
      fVar14 = (float10)FUN_004eff00();
      param_1[0x33] = (int)(float)fVar14;
    }
  }
  else {
    fVar14 = (float10)FUN_004eff00();
    if (fVar14 < (float10)(float)param_1[0x33]) {
      param_1[0x33] = (int)(float)fVar14;
    }
    param_1[0x32] = (int)(param_2 + (float)param_1[0x32]);
    if (fVar3 < _DAT_0059e43c) {
      *(undefined1 *)(param_1 + 0x2d) = 0;
      local_2c = 0.0;
      if (DAT_007c56a4 == 7) {
        if (param_1[0xb] < param_1[0x2f]) {
          local_2c = (float)(param_1[0x2f] - param_1[0xb]) * _DAT_005acd98;
        }
      }
      if ((param_1[0x30] == 0) && (pfVar4[0x4b] == 0.0)) {
        fVar14 = (float10)FUN_004f01b0();
        fVar15 = (float10)(param_1[2] - param_1[0x2e]) * (float10)_DAT_005ea408 +
                 (fVar14 - (float10)(float)param_1[0x31]);
        fVar14 = fVar15 / (float10)(float)param_1[0x32] - (float10)_DAT_0059e824;
        if (fVar14 <= (float10)DAT_0059e440) {
          fVar14 = (float10)local_2c;
        }
        else {
          fVar14 = fVar14 * (float10)_DAT_005acd94 + (float10)local_2c;
        }
        local_2c = (float)((fVar15 - (float10)(float)param_1[0x32]) * (float10)_DAT_005acd90 +
                          fVar14);
      }
      local_c = *(float *)(iVar16 + 0x34f8);
      local_8 = *(float *)(iVar16 + 0x34fc);
      local_4 = *(float *)(iVar16 + 0x3500);
      if (((local_c != DAT_0059e440) || (local_8 != DAT_0059e440)) ||
         (fVar10 = local_4, fVar9 = local_8, fVar8 = local_c, local_4 != DAT_0059e440)) {
        fVar10 = _DAT_0059e43c / SQRT(local_8 * local_8 + local_4 * local_4 + local_c * local_c);
        fVar8 = fVar10 * local_c;
        fVar9 = local_8 * fVar10;
        fVar10 = fVar10 * local_4;
      }
      fVar10 = ((fVar8 * pfVar4[0x29] + fVar9 * pfVar4[0x2a] + fVar10 * pfVar4[0x2b]) -
               _DAT_0059e43c) + (float)param_1[0x33] + local_2c;
      if ((_DAT_0059e944 < fVar10) && (DAT_007cef84 != 0)) {
        if (((param_1[0x34] < 2) && (fVar10 <= _DAT_005acb30)) || (DAT_007c56a4 != 7)) {
          FUN_004bbc60(s_Cut_Track_005c2710);
        }
        else {
          FUN_004bbd60(s_Cut_Track_005c2710,10);
        }
        param_1[0x34] = param_1[0x34] + 1;
        if ((param_1[0x18] != 0) && (param_1[0x18] = 1, DAT_007c56a4 != 7)) {
          iVar13 = FUN_00423a00(s_Lap_Will_Not_Count_005d25bc,&DAT_005ec4cc);
          if (iVar13 != 0) {
            iVar13 = 0;
            do {
              pcVar1 = s_Lap_Will_Not_Count_005d25bc + iVar13;
              (&DAT_005ec4cc)[iVar13] = *pcVar1;
              iVar13 = iVar13 + 1;
            } while (*pcVar1 != '\0');
          }
          FUN_0045bd10(&DAT_005ec4cc,3,0x1020304);
        }
      }
    }
  }
  pfVar5 = (float *)pfVar4[0x44];
  fVar10 = *pfVar5 - *pfVar4;
  fVar11 = pfVar5[1] - pfVar4[1];
  fVar9 = pfVar5[2] - pfVar4[2];
  fVar8 = fVar10 * *(float *)(iVar16 + 0x34f8) +
          fVar11 * *(float *)(iVar16 + 0x34fc) + fVar9 * *(float *)(iVar16 + 0x3500);
  if (DAT_0059e440 <= fVar8) {
    param_1[0x2c] = 0;
  }
  else {
    fVar6 = (float)param_1[0x2c];
    fVar10 = (float)param_1[0x2c] -
             (fVar8 * param_2) / SQRT(fVar10 * fVar10 + fVar11 * fVar11 + fVar9 * fVar9);
    param_1[0x2c] = (int)fVar10;
    if ((fVar6 < (float)_DAT_0059eb48 != (fVar6 == (float)_DAT_0059eb48)) &&
       ((float)_DAT_0059eb48 < fVar10)) {
      iVar13 = FUN_00423a00(s_Wrong_Way_005d25b0,&DAT_005ec4cc);
      if (iVar13 != 0) {
        iVar13 = 0;
        do {
          pcVar1 = s_Wrong_Way_005d25b0 + iVar13;
          (&DAT_005ec4cc)[iVar13] = *pcVar1;
          iVar13 = iVar13 + 1;
        } while (*pcVar1 != '\0');
      }
      FUN_0045bd10(&DAT_005ec4cc,3,0x1020304);
      if ((*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) ==
           *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) &&
         (fVar14 = (float10)FUN_004eff00(), (float10)DAT_0059e440 < fVar14)) {
        FUN_0041a4a0();
      }
    }
    if (((DAT_007cef84 != 0) && (fVar6 < (float)_DAT_005acd88 != (fVar6 == (float)_DAT_005acd88)))
       && ((float)_DAT_005acd88 < (float)param_1[0x2c])) {
      FUN_004bc0e0(s_Wrong_Way_005d25b0);
    }
  }
  iVar13 = param_1[0x35];
  *(undefined1 *)(param_1 + 0x35) = 0;
  if (((*(char *)(*param_1 + 0x344c) != '\0') || (DAT_007c56a8 != 5)) ||
     ((_DAT_0059e4dc <= fVar3 ||
      (*(float *)(iVar16 + 0x3500) * *(float *)(iVar16 + 0x3500) +
       *(float *)(iVar16 + 0x34fc) * *(float *)(iVar16 + 0x34fc) +
       *(float *)(iVar16 + 0x34f8) * *(float *)(iVar16 + 0x34f8) <= _DAT_0059e43c)))) {
LAB_004bd745:
    param_1[0x37] = 0;
    return;
  }
  fVar3 = _DAT_005acd80;
  if (DAT_007c56a4 == 5) {
    fVar3 = _DAT_005acd84;
  }
  fVar10 = DAT_0059e440;
  if ((char)iVar13 != '\0') {
    fVar10 = _DAT_0059e478;
  }
  fVar10 = fVar10 + fVar3;
  fVar3 = _DAT_0059e8cc;
  if (DAT_007c56a4 == 5) {
    fVar3 = _DAT_005acd7c;
  }
  local_18 = DAT_0059e440;
  if ((char)iVar13 != '\0') {
    local_18 = _DAT_0059e7e8;
  }
  local_10 = param_1[0x36];
  local_18 = local_18 + fVar3;
  local_c = *(float *)(iVar16 + 0x34e0);
  local_4 = *(float *)(iVar16 + 0x34e8);
  local_8 = *(float *)(iVar16 + 0x34e4);
  iVar13 = 0;
  local_20 = fVar10;
  if (0 < DAT_005c329c) {
    do {
      if ((iVar13 != param_1[1]) &&
         (iVar7 = (&DAT_007c54f0)[iVar13], fVar3 = local_c - *(float *)(iVar7 + 0x34e0),
         fVar9 = local_8 - *(float *)(iVar7 + 0x34e4), fVar8 = local_4 - *(float *)(iVar7 + 0x34e8),
         fVar3 = fVar3 * fVar3 + fVar9 * fVar9 + fVar8 * fVar8,
         fVar10 * fVar10 < fVar3 == (fVar10 * fVar10 == fVar3))) {
        fVar14 = (float10)FUN_004f0050();
        if ((float10)fVar2 < fVar14) {
          fVar14 = fVar14 - (float10)DAT_005ea3fc;
        }
        fVar3 = (float)((float10)fVar2 - fVar14);
        if ((((fVar3 < fVar10) && (*(char *)(iVar7 + 0x344c) == '\0')) &&
            (fVar8 = SQRT(*(float *)(iVar7 + 0x3500) * *(float *)(iVar7 + 0x3500) +
                          *(float *)(iVar7 + 0x34fc) * *(float *)(iVar7 + 0x34fc) +
                          *(float *)(iVar7 + 0x34f8) * *(float *)(iVar7 + 0x34f8)),
            _DAT_0059e7ec <= fVar8)) && (fVar3 / fVar8 < local_18)) {
          iVar7 = (&DAT_007c54f0)[iVar13];
          if (DAT_007c56a4 == 7) {
            if (((*(int *)(iVar7 + 0x4060) < param_1[0xb]) &&
                ((param_1[2] < *(int *)(iVar7 + 0x403c) || (*(int *)(iVar7 + 0x4040) != param_1[3]))
                )) && (*(undefined1 *)(param_1 + 0x35) = 1, fVar3 < local_20)) {
              param_1[0x36] = iVar13;
              local_20 = fVar3;
            }
          }
          else if (((param_1[0x18] != 2) && (*(int *)(iVar7 + 0x4094) == 2)) &&
                  ((local_14[0x23] * _DAT_0059e450 * local_14[0x23] * _DAT_0059e450 <
                    *(float *)(iVar16 + 0x3500) * *(float *)(iVar16 + 0x3500) +
                    *(float *)(iVar16 + 0x34fc) * *(float *)(iVar16 + 0x34fc) +
                    *(float *)(iVar16 + 0x34f8) * *(float *)(iVar16 + 0x34f8) &&
                   (*(undefined1 *)(param_1 + 0x35) = 1, fVar3 < local_20)))) {
            param_1[0x36] = iVar13;
            local_20 = fVar3;
          }
        }
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < DAT_005c329c);
  }
  if ((((char)param_1[0x35] == '\0') || (param_1[0x36] != local_10)) || (DAT_007c56a4 != 7)) {
    if ((float)param_1[0x37] == DAT_0059e440) {
      return;
    }
    FUN_0041b910(5,*param_1);
    goto LAB_004bd745;
  }
  if ((float)param_1[0x37] == DAT_0059e440) {
    iVar16 = *param_1;
    iVar13 = param_1[5];
    uVar17 = 1;
  }
  else if ((_DAT_0059e5fc <= (float)param_1[0x37]) ||
          (param_2 + (float)param_1[0x37] < _DAT_0059e5fc)) {
    if ((_DAT_0059e8ec <= (float)param_1[0x37]) || (param_2 + (float)param_1[0x37] < _DAT_0059e8ec))
    goto LAB_004bd6c9;
    iVar16 = *param_1;
    iVar13 = param_1[5];
    uVar17 = 3;
  }
  else {
    iVar16 = *param_1;
    iVar13 = param_1[5];
    uVar17 = 2;
  }
  FUN_0041b3c0(5,0xffffffff,iVar13,iVar16,uVar17);
LAB_004bd6c9:
  fVar2 = (float)param_1[0x37];
  param_1[0x37] = (int)(param_2 + fVar2);
  if (param_2 + fVar2 <= _DAT_0059e468) {
    return;
  }
  if (DAT_007cef84 == 0) {
    return;
  }
  FUN_004bbd60(s_Ignored_Blue_Flags_005c26ec,10);
  FUN_0041a720(*param_1,s_Ignored_Blue_Flags_005c26ec);
  param_1[0x37] = 0;
  return;
}


