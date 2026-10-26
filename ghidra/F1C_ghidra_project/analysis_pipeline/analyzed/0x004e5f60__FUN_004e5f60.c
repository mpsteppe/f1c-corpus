// Function: FUN_004e5f60 @ 004e5f60
// Size (bytes): 3593


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e5f60(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float *pfVar12;
  int iVar13;
  undefined4 uVar14;
  void *pvVar15;
  int iVar16;
  double *pdVar17;
  float *pfVar18;
  undefined4 *puVar19;
  int iVar20;
  uint uVar21;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 *puVar22;
  float10 fVar23;
  float10 fVar24;
  float10 fVar25;
  int *local_30c;
  int local_308;
  float local_304;
  float local_300;
  float local_2fc;
  double *local_2f8;
  double *local_2f0;
  int local_2ec;
  float local_2e8;
  float fStack_2e4;
  float fStack_2d8;
  float fStack_2d0;
  float local_2c0;
  float afStack_2bc [4];
  float local_2ac;
  float local_2a8;
  float local_2a4;
  float fStack_2a0;
  float fStack_29c;
  float fStack_298;
  float local_294;
  float local_290;
  float local_28c;
  float fStack_288;
  float fStack_280;
  float local_27c;
  float fStack_278;
  float fStack_274;
  float fStack_270;
  float afStack_26c [4];
  float local_25c;
  float local_258;
  float local_254;
  float afStack_250 [4];
  float local_240 [2];
  float local_238;
  float local_234;
  float local_22c;
  float local_228;
  float local_220;
  float local_21c;
  float local_214;
  float local_210;
  float fStack_20c;
  float afStack_208 [5];
  float afStack_1f4 [4];
  float fStack_1e4;
  float fStack_1e0;
  float fStack_1dc;
  int local_1d8;
  float fStack_1d4;
  double local_1d0;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b4;
  double local_1b0;
  float afStack_1a8 [105];
  
  fVar6 = *(float *)(param_1 + 0x75c);
  fVar7 = *(float *)(param_1 + 0x760);
  fVar8 = *(float *)(param_1 + 0x764);
  local_294 = *(float *)(param_1 + 0x768);
  local_290 = (float)*(undefined4 *)(param_1 + 0x76c);
  *(undefined4 *)(param_1 + 0x3bf4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3bf8) = 0xff7fffff;
  local_28c = *(float *)(param_1 + 0x770);
  pfVar12 = local_240;
  pfVar18 = (float *)(param_1 + 0x8b8);
  local_30c = (int *)0x4;
  do {
    *pfVar12 = *pfVar18;
    fVar9 = pfVar18[2];
    pfVar12[1] = pfVar18[1];
    pfVar12[2] = fVar9;
    pfVar18 = pfVar18 + 0x4a;
    pfVar12 = pfVar12 + 3;
    local_30c = (int *)((int)local_30c + -1);
  } while (local_30c != (int *)0x0);
  if (*(char *)(param_3 + 0x54a) != '\0') {
    local_238 = (local_22c + local_238) * _DAT_0059e450;
    local_22c = local_238;
    local_240[0] = (local_240[0] - local_234) * _DAT_0059e450;
    local_234 = -local_240[0];
    local_220 = (local_214 + local_220) * _DAT_0059e450;
    local_214 = local_220;
    local_228 = (local_228 - local_21c) * _DAT_0059e450;
    local_21c = -local_228;
  }
  if (*(double *)(param_3 + 0x54c) != _DAT_0059e430) {
    fVar9 = ((float)*(double *)(param_3 + 0x54c) - (local_240[0] - local_234)) *
            (float)_DAT_0059e880;
    local_240[0] = local_240[0] + fVar9;
    local_234 = local_234 - fVar9;
  }
  if (*(double *)(param_3 + 0x554) != _DAT_0059e430) {
    fVar9 = ((float)*(double *)(param_3 + 0x554) - (local_228 - local_21c)) * (float)_DAT_0059e880;
    local_228 = local_228 + fVar9;
    local_21c = local_21c - fVar9;
  }
  if (*(double *)(param_3 + 0x55c) != _DAT_0059e430) {
    fVar9 = ((float)*(double *)(param_3 + 0x55c) - (local_220 - local_238)) * (float)_DAT_0059e880;
    local_238 = local_238 - fVar9;
    local_220 = fVar9 + local_220;
  }
  if (*(double *)(param_3 + 0x564) != _DAT_0059e430) {
    fVar9 = ((float)*(double *)(param_3 + 0x564) - (local_214 - local_22c)) * (float)_DAT_0059e880;
    local_22c = local_22c - fVar9;
    local_214 = fVar9 + local_214;
  }
  local_2f8 = (double *)(param_1 + 0x358c);
  pfVar12 = local_240;
  pfVar18 = (float *)(param_1 + 0x8b8);
  local_30c = (int *)0x4;
  do {
    *pfVar18 = *pfVar12;
    fVar9 = pfVar12[2];
    pfVar18[1] = pfVar12[1];
    pfVar18[2] = fVar9;
    *(float *)local_2f8 = *pfVar12;
    fVar9 = pfVar12[2];
    *(float *)((int)local_2f8 + 4) = pfVar12[1];
    *(float *)((int)local_2f8 + 8) = fVar9;
    local_2f8 = (double *)((int)local_2f8 + 0xf8);
    pfVar18 = pfVar18 + 0x4a;
    pfVar12 = pfVar12 + 3;
    local_30c = (int *)((int)local_30c + -1);
  } while (local_30c != (int *)0x0);
  puVar19 = (undefined4 *)(param_1 + 0x3674);
  fVar1 = (float)*(int *)(param_2 + 0xc04) * (float)*(double *)(param_2 + 0xbf8) +
          (float)*(double *)(param_2 + 0xbf0);
  local_27c = (*(float *)(param_1 + 0x358c) + *(float *)(param_1 + 0x377c)) * _DAT_0059e450;
  local_27c = ((*(float *)(param_1 + 0x3874) + *(float *)(param_1 + 0x3684)) * _DAT_0059e450 -
              local_27c) * fVar1 + local_27c;
  local_2c0 = (float)((float10)*(double *)(param_3 + 0x40) * (float10)_DAT_0059ea58);
  fVar9 = (float)*(int *)(param_2 + 0xc44) * (float)*(double *)(param_2 + 0xc38) +
          (float)*(double *)(param_2 + 0xc30);
  fVar3 = _DAT_0059e43c - fVar9;
  afStack_208[1] = fVar3 * (_DAT_0059e43c - fVar1);
  afStack_208[2] = fVar3 * fVar1;
  afStack_208[3] = (_DAT_0059e43c - fVar1) * fVar9;
  afStack_208[4] = fVar9 * fVar1;
  iVar20 = 0;
  do {
    fVar1 = *(float *)((int)afStack_208 + iVar20 + 4U);
    *puVar19 = *(undefined4 *)((int)afStack_208 + iVar20 + 4U);
    iVar13 = iVar20 + 4;
    puVar19 = puVar19 + 0x3e;
    *(float *)((int)afStack_250 + iVar20) = local_2c0 * fVar1;
    iVar20 = iVar13;
  } while (iVar13 < 0x10);
  iVar20 = 0;
  *(float *)(param_1 + 0x4024) = (float)*(double *)(param_3 + 0x60);
  pdVar17 = (double *)(param_2 + 0x138);
  do {
    iVar20 = iVar20 + 1;
    *(float *)(param_1 + 0x4024) =
         afStack_208[iVar20] * _DAT_0059e7fc *
         ((float)*(int *)((int)pdVar17 + 0xc) * (float)*pdVar17 + (float)pdVar17[-1]) +
         *(float *)(param_1 + 0x4024);
    pdVar17 = pdVar17 + 0x58;
  } while (iVar20 < 4);
  local_304 = (float)*(double *)(param_3 + 0x70) +
              -((fVar6 + local_294) * _DAT_0059e450 + local_27c);
  local_2fc = (float)*(double *)(param_3 + 0x80) +
              -((*(float *)(param_1 + 0x387c) + *(float *)(param_1 + 0x3784)) * fVar9 *
                _DAT_0059e450 +
               (*(float *)(param_1 + 0x368c) + *(float *)(param_1 + 0x3594)) * fVar3 * _DAT_0059e450
               );
  local_210 = fVar7 - (float)*(double *)(param_3 + 0x78);
  local_300 = -((float)*(double *)(param_3 + 0x60) + local_210);
  if (*(int *)(param_1 + 0x32bc) == 0) {
    local_2ac = *(float *)(param_1 + 0x72c);
    local_2a8 = *(float *)(param_1 + 0x730);
    local_2a4 = *(float *)(param_1 + 0x734);
    local_304 = local_2ac - (float)_DAT_007c8a24;
    local_300 = local_2a8 - (float)_DAT_007c8a2c;
    local_2fc = local_2a4 - (float)_DAT_007c8a34;
  }
  *(float *)(param_1 + 0x72c) = local_304;
  *(float *)(param_1 + 0x730) = local_300;
  *(float *)(param_1 + 0x734) = local_2fc;
  uVar14 = FUN_004d7880();
  *(undefined4 *)(param_1 + 0x396c) = uVar14;
  FUN_004f1a60(*(undefined4 *)(param_2 + 0xbc4),0);
  iVar20 = FUN_004d7570();
  local_254 = (float)(iVar20 + 0x18);
  local_1d8 = iVar20 + 0x160;
  pdVar17 = (double *)(param_2 + 0x1b8);
  iVar20 = 0;
  fVar9 = DAT_0059e440;
  fVar1 = DAT_0059e440;
  fVar3 = DAT_0059e440;
  do {
    iVar13 = iVar20 + 4;
    fVar2 = (float)*(int *)((int)pdVar17 + 0xc) * (float)*pdVar17 + (float)pdVar17[-1];
    *(float *)((int)afStack_2bc + iVar20) = fVar2;
    fVar9 = fVar2 + fVar9;
    fVar2 = ((float)*(int *)((int)pdVar17 + 0x4c) * (float)pdVar17[8] + (float)pdVar17[7] +
            (float)*(int *)((int)pdVar17 + 0xcc) * (float)pdVar17[0x18] + (float)pdVar17[0x17]) *
            (float)_DAT_0059e880;
    *(float *)((int)afStack_26c + iVar20) = fVar2;
    fVar1 = fVar2 + fVar1;
    fVar2 = ((float)*(int *)((int)pdVar17 + 0x8c) * (float)pdVar17[0x10] + (float)pdVar17[0xf] +
            (float)*(int *)((int)pdVar17 + 0x10c) * (float)pdVar17[0x20] + (float)pdVar17[0x1f]) *
            (float)_DAT_0059e880;
    *(float *)((int)afStack_1f4 + iVar20) = fVar2;
    fVar3 = fVar2 + fVar3;
    pdVar17 = pdVar17 + 0x58;
    iVar20 = iVar13;
  } while (iVar13 < 0x10);
  local_2f8 = (double *)(param_3 + 0x1400);
  local_2f0 = (double *)(param_2 + 0xf8);
  local_25c = fVar9 * _DAT_0059e7f8;
  local_2ec = 0;
  puVar19 = (undefined4 *)(param_1 + 0x35ac);
  local_258 = fVar1 * _DAT_0059e7f8;
  fVar3 = fVar3 * _DAT_0059e7f8;
  do {
    puVar19[-2] = 0;
    puVar19[-1] = 0;
    *puVar19 = 0;
    puVar19[1] = 0;
    puVar19[6] = 0;
    puVar19[3] = 0;
    puVar19[4] = 0x3f800000;
    puVar19[5] = 0;
    puVar19[10] = 0;
    puVar19[0xb] = 0;
    puVar19[0xc] = _DAT_008afef0 + _DAT_005acafc;
    fVar23 = (float10)local_2f8[0xc] + (float10)local_2f8[0xc];
    puVar19[0xe] = (float)fVar23;
    puVar19[0xf] = (float)fVar23;
    puVar19[0x10] = (float)((float10)_DAT_0059e43c / fVar23);
    puVar19[0x11] = *(undefined4 *)(param_1 + 0x34a8);
    puVar19[0x25] = 0;
    puVar19[0x24] = 0x3f800000;
    puVar19[0x26] = 0x7cf0bdc2;
    puVar19[0x27] = 0x7cf0bdc2;
    puVar19[0x2b] = 0;
    puVar19[0x2c] = 0;
    puVar19[0x2d] = 0;
    puVar19[0x2e] = 0;
    puVar19[0x2f] = 0;
    fVar10 = (local_25c - afStack_2bc[local_2ec]) * (float)*(double *)(param_3 + 0xfc) +
             afStack_2bc[local_2ec];
    fVar11 = local_258 - afStack_26c[local_2ec];
    dVar4 = *(double *)(param_3 + 0xfc);
    fVar9 = afStack_26c[local_2ec];
    fVar1 = afStack_1f4[local_2ec];
    dVar5 = *(double *)(param_3 + 0xfc);
    fVar2 = afStack_1f4[local_2ec];
    fVar23 = (float10)FUN_004d6ae0((double)*(int *)((int)local_2f0 + 0xc) * *local_2f0 +
                                   local_2f0[-1]);
    fVar24 = (float10)_DAT_0059e43c / ((float10)fVar10 + fVar23);
    fVar25 = fVar23 * (float10)fVar10 * fVar24;
    puVar19[0x30] = (float)(fVar25 * (float10)*(double *)(param_3 + 0x104));
    puVar19[0x31] =
         (fVar11 * (float)dVar4 + fVar9) * (float)*(double *)(param_3 + 0x10c) +
         ((fVar3 - fVar1) * (float)dVar5 + fVar2) * (float)*(double *)(param_3 + 0x114);
    puVar19[0x13] = (float)(fVar24 * fVar23);
    puVar19[0x14] =
         (float)(ABS((float10)*local_2f8 - (float10)local_2f8[1]) + (float10)_DAT_0059e450);
    pfVar18 = (float *)(puVar19 + -8);
    puVar19[-7] = ((local_210 -
                   ((float)*(int *)((int)local_2f0 + 0x4c) * (float)local_2f0[8] +
                   (float)local_2f0[7])) + (float)puVar19[0x19]) -
                  afStack_250[local_2ec] / (float)fVar25;
    *pfVar18 = local_304 + *pfVar18;
    puVar19[-7] = local_300 + (float)puVar19[-7];
    puVar19[-6] = local_2fc + (float)puVar19[-6];
    puVar19[0xd] = puVar19[-7];
    if ((local_2ec == 0) || (local_2ec == 1)) {
      local_2e8 = (float)*(int *)(param_2 + 0xd84) * (float)*(double *)(param_2 + 0xd78) +
                  (float)*(double *)(param_2 + 0xd70);
    }
    else {
      local_2e8 = (float)*(int *)(param_2 + 0xdc4) * (float)*(double *)(param_2 + 0xdb8) +
                  (float)*(double *)(param_2 + 0xdb0);
    }
    if ((local_2ec == 0) || (local_2ec == 2)) {
      fVar9 = -((float)*(int *)((int)local_2f0 + -0x34) * (float)local_2f0[-8] +
               (float)local_2f0[-9]);
    }
    else {
      local_2e8 = -local_2e8;
      fVar9 = (float)*(int *)((int)local_2f0 + -0x34) * (float)local_2f0[-8] + (float)local_2f0[-9];
    }
    FUN_004e2540(local_2ec,pfVar18,0,local_2e8,fVar9);
    local_2ec = local_2ec + 1;
    local_2f8 = local_2f8 + 0x21;
    local_2f0 = local_2f0 + 0x58;
    puVar19 = puVar19 + 0x3e;
  } while (local_2ec < 4);
  iVar20 = 0;
  pfVar18 = (float *)(param_1 + 0x3604);
  do {
    pfVar18[-1] = 0.0;
    if ((iVar20 == 0) || (iVar20 == 1)) {
      fVar9 = *(float *)(param_1 + 0x3784);
    }
    else {
      fVar9 = *(float *)(param_1 + 0x3594);
    }
    iVar20 = iVar20 + 1;
    *pfVar18 = (float)(ABS((float10)fVar9 /
                           ((float10)*(float *)(param_1 + 0x3594) -
                           (float10)*(float *)(param_1 + 0x3784))) *
                       ((float10)_DAT_0059e420 - (float10)*(double *)(param_3 + 0x104)) *
                      (float10)_DAT_0059e99c);
    pfVar18[1] = (float)((((float10)_DAT_0059e420 - (float10)*(double *)(param_3 + 0x104)) *
                         (float10)_DAT_0059eb50) / (float10)pfVar18[-0x1c]);
    pfVar18[2] = (float)((((float10)_DAT_0059e420 - (float10)*(double *)(param_3 + 0x104)) *
                         (float10)_DAT_0059ed10) / (float10)pfVar18[-0x1e]);
    pfVar18 = pfVar18 + 0x3e;
  } while (iVar20 < 4);
  *(float *)(param_1 + 0x3978) =
       (float)*(int *)(param_2 + 0xcc4) * (float)*(double *)(param_2 + 0xcb8) +
       (float)*(double *)(param_2 + 0xcb0);
  fVar9 = (float)(*(int *)(param_2 + 0xcc0) + -1) * (float)*(double *)(param_2 + 0xcb8) +
          (float)*(double *)(param_2 + 0xcb0);
  *(float *)(param_1 + 0x397c) = fVar9;
  *(float *)(param_1 + 0x3980) = _DAT_0059e43c / fVar9;
  *(float *)(param_1 + 0x3984) =
       (float)DAT_007d0b64 * (float)*(double *)(param_3 + 0x674) * _DAT_007d01e8;
  FUN_004a5330();
  dVar4 = *(double *)(param_3 + 0x40);
  *(float *)(param_1 + 0x3510) = (float)dVar4;
  fVar9 = *(float *)(param_1 + 0x3978) * _DAT_0059e7fc + (float)dVar4;
  *(float *)(param_1 + 0x3514) = fVar9;
  *(float *)(param_1 + 0x3518) = _DAT_0059e43c / fVar9;
  *(float *)(param_1 + 0x351c) = (float)*(double *)(param_3 + 0x48);
  *(float *)(param_1 + 0x3520) = (float)*(double *)(param_3 + 0x50);
  *(float *)(param_1 + 0x3524) = (float)*(double *)(param_3 + 0x58);
  *(float *)(param_1 + 0x3528) = _DAT_0059e43c / *(float *)(param_1 + 0x351c);
  *(float *)(param_1 + 0x352c) = _DAT_0059e43c / *(float *)(param_1 + 0x3520);
  *(float *)(param_1 + 0x3530) = _DAT_0059e43c / *(float *)(param_1 + 0x3524);
  *(float *)(param_1 + 0x3564) = (float)*(double *)(param_3 + 300);
  *(float *)(param_1 + 0x3568) = (float)*(double *)(param_3 + 0x134);
  *(float *)(param_1 + 0x356c) = (float)*(double *)(param_3 + 0x13c);
  fVar9 = (float)(*(int *)(param_2 + 0x1440) + -1) * (float)*(double *)(param_2 + 0x1438) +
          (float)*(double *)(param_2 + 0x1430);
  *(float *)(param_1 + 0x3960) = fVar9;
  *(float *)(param_1 + 0x1038) = fVar9;
  fVar23 = (float10)FUN_004f6850((double)*(int *)(param_2 + 0xd04) * *(double *)(param_2 + 0xcf8) +
                                 *(double *)(param_2 + 0xcf0));
  fVar24 = (float10)FUN_004f6880((double)*(int *)(param_2 + 0xd44) * *(double *)(param_2 + 0xd38) +
                                 *(double *)(param_2 + 0xd30));
  *(float *)(param_1 + 0x3974) =
       (float)((fVar24 + (float10)(float)fVar23) * (float10)*(double *)(param_3 + 0x104) *
              (float10)_DAT_0059eb50);
  fVar23 = (float10)*(double *)(param_3 + 0x1374) + (float10)*(double *)(param_3 + 0x684);
  *(undefined4 *)(param_1 + 0x3994) = 0;
  *(float *)(param_1 + 0x3988) = (float)fVar23;
  *(float *)(param_1 + 0x398c) = (float)((float10)_DAT_0059e43c / fVar23);
  *(float *)(param_1 + 0x3998) =
       (float)*(int *)(param_2 + 0x1584) * (float)*(double *)(param_2 + 0x1578) +
       (float)*(double *)(param_2 + 0x1570);
  *(float *)(param_1 + 0x399c) =
       (float)(((float10)*(double *)(param_3 + 0x694) + (float10)*(double *)(param_3 + 0x68c)) *
              (float10)_DAT_0059e880);
  *(undefined4 *)(param_1 + 0x39b4) = *(undefined4 *)(param_3 + 0x13c0);
  *(undefined1 *)(param_1 + 0x39ec) = 0;
  *(bool *)(param_1 + 0x39ed) = _DAT_0059e430 < *(double *)(param_3 + 0x6a4);
  uVar21 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  *(float *)(param_1 + 0x3990) =
       *(float *)(&DAT_008aae74 + uVar21 * 4) * (float)_DAT_0059e430 +
       (float)*(double *)(param_3 + 0x6ac);
  if (*(float *)(param_1 + 0x399c) <= *(float *)(param_1 + 0x3990)) {
    if (*(float *)(param_1 + 0x3998) < *(float *)(param_1 + 0x3990)) {
      *(float *)(param_1 + 0x3990) = *(float *)(param_1 + 0x3998);
    }
  }
  else {
    *(float *)(param_1 + 0x3990) = *(float *)(param_1 + 0x399c);
  }
  *(undefined4 *)(param_1 + 0x39b8) = 0;
  *(float *)(param_1 + 0x39bc) = (float)*(double *)(param_3 + 0x135c);
  *(float *)(param_1 + 0x39c0) = (float)*(double *)(param_3 + 0x1364);
  *(float *)(param_1 + 0x39c4) = (float)*(double *)(param_3 + 0x136c);
  fVar9 = (float)*(double *)(param_3 + 0x68c) * _DAT_005acdc0;
  *(float *)(param_1 + 0x88) = *(float *)(param_1 + 0x3998) * _DAT_005acee0;
  FUN_004f8330();
  *(float *)(param_1 + 0x8c) = fVar9;
  FUN_004f8330();
  *(undefined4 *)(param_1 + 0x39a8) = 0;
  *(undefined4 *)(param_1 + 0x39ac) = 0;
  iVar20 = __ftol();
  *(int *)(param_1 + 0x39b0) = 2 - iVar20;
  pvVar15 = operator_new((2 - iVar20) * 8);
  *(void **)(param_1 + 0x39a4) = pvVar15;
  local_2ec = 0;
  if (0 < *(int *)(param_1 + 0x39b0)) {
    do {
      FUN_004f6720((double)((float)local_2ec * _DAT_0059ec20),&local_1d0,&local_1b0);
      local_2ec = local_2ec + 1;
      *(float *)(*(int *)(param_1 + 0x39a4) + -8 + local_2ec * 8) =
           (float)((float10)local_1d0 - (float10)*(double *)(param_3 + 0x138c));
      *(float *)(*(int *)(param_1 + 0x39a4) + -4 + local_2ec * 8) =
           (float)((float10)local_1b0 - (float10)local_1d0);
    } while (local_2ec < *(int *)(param_1 + 0x39b0));
  }
  iVar13 = 0;
  *(undefined4 *)(param_1 + 0x39c8) = 0;
  *(undefined1 *)(param_1 + 0x39ee) = 0;
  *(undefined4 *)(param_1 + 0x39f0) = 0;
  *(undefined4 *)(param_1 + 0x39f4) = 0xfffffffe;
  iVar20 = *(int *)(param_3 + 0x13c4);
  *(int *)(param_1 + 0x39f8) = iVar20;
  if (-1 < iVar20) {
    pfVar18 = (float *)(param_1 + 0x39cc);
    do {
      fVar23 = (float10)FUN_0042ed00();
      *pfVar18 = (float)fVar23;
      if (iVar13 == 7) {
        pfVar18 = pfVar18 + 0x396;
      }
      else {
        pfVar18 = pfVar18 + 1;
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 <= *(int *)(param_1 + 0x39f8));
  }
  *(float *)(param_1 + 0x39fc) =
       (float)((float10)*(double *)(param_3 + 0x13a8) * (float10)_DAT_005ad1a8 +
              (float10)*(double *)(param_3 + 0x13a0));
  *(float *)(param_1 + 0x3a00) =
       (float)((float10)*(double *)(param_3 + 0x13b8) * (float10)_DAT_005ad1a8 +
              (float10)*(double *)(param_3 + 0x13b0));
  *(undefined4 *)(param_1 + 0x3a04) = 0;
  *(undefined4 *)(param_1 + 0x3a08) = 0;
  *(float *)(param_1 + 0x3a0c) = *(float *)(param_1 + 0x3998) * _DAT_005ad1a0;
  *(float *)(param_1 + 0x3a10) = *(float *)(param_1 + 0x399c) * _DAT_005ad19c;
  pfVar18 = (float *)(param_1 + 0x3a10);
  pfVar12 = (float *)(param_1 + 0x3a14);
  for (iVar20 = 7; iVar20 != 0; iVar20 = iVar20 + -1) {
    *pfVar12 = *pfVar18;
    pfVar18 = pfVar18 + 1;
    pfVar12 = pfVar12 + 1;
  }
  if (1 < *(int *)(param_1 + 0x39f8)) {
    FUN_0059d9d7();
    return;
  }
  iVar20 = 0;
  fVar9 = (float)*(int *)(param_2 + 0x1344) * (float)*(double *)(param_2 + 0x1338) +
          (float)*(double *)(param_2 + 0x1330);
  do {
    if (iVar20 == 0) {
      iVar13 = param_3 + 0x13d0;
      iVar16 = param_3 + 0x14d8;
      pfVar18 = (float *)(param_1 + 0x3a30);
    }
    else {
      iVar13 = param_3 + 0x15e0;
      iVar16 = param_3 + 0x16e8;
      pfVar18 = (float *)(param_1 + 0x3a44);
    }
    iVar20 = iVar20 + 1;
    *pfVar18 = (float)(((float10)*(double *)(iVar16 + 0xb0) + (float10)*(double *)(iVar13 + 0xb0)) *
                      (float10)_DAT_0059e880);
    pfVar18[1] = (float)(((float10)*(double *)(iVar16 + 0xa8) + (float10)*(double *)(iVar13 + 0xa8))
                        * (float10)_DAT_0059e880);
    pfVar18[2] = (float)(((float10)*(double *)(iVar16 + 200) + (float10)*(double *)(iVar13 + 200)) *
                        (float10)_DAT_005ad190);
    pfVar18[3] = (float)(((float10)*(double *)(iVar16 + 0xd0) + (float10)*(double *)(iVar13 + 0xd0))
                        * (float10)_DAT_005ad190);
    pfVar18[4] = (fVar9 * (float)*(double *)(iVar13 + 0xe0) + (float)*(double *)(iVar13 + 0xd8) +
                 fVar9 * (float)*(double *)(iVar16 + 0xe0) + (float)*(double *)(iVar16 + 0xd8)) *
                 (float)_DAT_005ad190;
  } while (iVar20 < 2);
  fVar1 = (float)*(int *)(param_2 + 0x1384) * (float)*(double *)(param_2 + 0x1378) +
          (float)*(double *)(param_2 + 0x1370);
  fVar9 = (_DAT_0059e43c - fVar1) * *(float *)(param_1 + 0x3a30);
  *(float *)(param_1 + 0x3a30) = fVar9;
  fVar1 = fVar1 * *(float *)(param_1 + 0x3a44);
  *(float *)(param_1 + 0x3a44) = fVar1;
  if (fVar9 == DAT_0059e440) {
    *(undefined4 *)(param_1 + 0x3618) = 0;
    *(undefined4 *)(param_1 + 0x3710) = 0;
  }
  else {
    fVar9 = _DAT_0059e43c / fVar9;
    *(float *)(param_1 + 0x3618) = fVar9;
    *(float *)(param_1 + 0x3710) = fVar9;
  }
  if (fVar1 == DAT_0059e440) {
    *(undefined4 *)(param_1 + 0x3808) = 0;
    *(undefined4 *)(param_1 + 0x3900) = 0;
  }
  else {
    fVar1 = _DAT_0059e43c / fVar1;
    *(float *)(param_1 + 0x3808) = fVar1;
    *(float *)(param_1 + 0x3900) = fVar1;
  }
  iVar20 = 4;
  pdVar17 = (double *)(param_2 + 0x138);
  fVar9 = DAT_0059e440;
  do {
    iVar20 = iVar20 + -1;
    fVar9 = (float)*(int *)((int)pdVar17 + 0xc) * (float)*pdVar17 + (float)pdVar17[-1] + fVar9;
    pdVar17 = pdVar17 + 0x58;
  } while (iVar20 != 0);
  fVar9 = fVar9 * _DAT_0059e84c;
  afStack_26c[2] = (*(float *)(param_1 + 0x3594) + *(float *)(param_1 + 0x368c)) * _DAT_0059e450;
  afStack_2bc[2] = (*(float *)(param_1 + 0x3784) + *(float *)(param_1 + 0x387c)) * _DAT_0059e450;
  FUN_004f3190();
  FUN_004f3190();
  local_258 = afStack_26c[2] + (float)*(double *)(param_3 + 0x2f0);
  FUN_004f68b0((float)*(int *)(param_2 + 0x1284) * (float)*(double *)(param_2 + 0x1278) +
               (float)*(double *)(param_2 + 0x1270),fVar9,&fStack_1c8,&fStack_20c);
  fVar1 = afStack_2bc[2] + (float)*(double *)(param_3 + 0x3ec);
  FUN_004f6950();
  local_254 = afStack_2bc[2] + (float)*(double *)(param_3 + 0x424);
  FUN_004f69e0((float)*(int *)(param_2 + 0x1344) * (float)*(double *)(param_2 + 0x1338) +
               (float)*(double *)(param_2 + 0x1330),
               (float)*(int *)(param_2 + 0x1304) * (float)*(double *)(param_2 + 0x12f8) +
               (float)*(double *)(param_2 + 0x12f0),fVar9,afStack_208 + 1,&local_2c0);
  local_25c = afStack_2bc[2] + (float)*(double *)(param_3 + 0x510);
  FUN_004f6a50(fVar9,&local_27c);
  fStack_1e0 = fStack_1e0 + fStack_1d4;
  *(undefined4 *)(param_1 + 0x3a58) = 0;
  *(undefined4 *)(param_1 + 0x3a5c) = 0;
  *(undefined4 *)(param_1 + 0x3a60) = 0;
  afStack_2bc[1] = fStack_1c4 + fStack_1e0;
  afStack_2bc[2] = fStack_1b4 + fStack_1c0 + fStack_1e0;
  local_2ac = afStack_208[1] + fStack_1bc + fStack_1c8 + fStack_1e0;
  *(float *)(param_1 + 0x3a64) = local_2ac;
  local_2a8 = afStack_208[2] + fStack_1b8 + afStack_2bc[1];
  *(float *)(param_1 + 0x3a68) = local_2a8;
  local_2a4 = afStack_208[3] + afStack_2bc[2];
  *(float *)(param_1 + 0x3a6c) = local_2a4;
  *(undefined4 *)(param_1 + 0x3a74) = 0;
  *(undefined4 *)(param_1 + 0x3a78) = *(undefined4 *)(param_1 + 0x3a6c);
  fVar9 = -(afStack_208[0] + local_27c + local_2c0 + fStack_20c + fStack_1dc + fStack_1e4);
  *(float *)(param_1 + 0x3a70) = fVar9;
  *(float *)(param_1 + 0x3a7c) = fVar9;
  *(float *)(param_1 + 0x3a80) = -(local_27c + local_2c0);
  if (fVar9 != DAT_0059e440) {
    *(float *)(param_1 + 0x3a74) =
         -((local_2c0 * local_254 +
           local_27c * local_25c + fStack_20c * local_258 + afStack_208[0] * fVar1) / fVar9);
  }
  *(float *)(param_1 + 0x3a74) =
       ((float)*(double *)(param_3 + 0x11c) - *(float *)(param_1 + 0x3a74)) *
       (float)*(double *)(param_3 + 0x124) + *(float *)(param_1 + 0x3a74);
  puVar19 = (undefined4 *)(param_3 + 0x17f0);
  puVar22 = (undefined4 *)(param_1 + 0x3d78);
  for (iVar20 = 0x9e; iVar20 != 0; iVar20 = iVar20 + -1) {
    *puVar22 = *puVar19;
    puVar19 = puVar19 + 1;
    puVar22 = puVar22 + 1;
  }
  if ((((*(int *)(param_1 + 0xcc8) != 0) && (*(float *)(param_1 + 0x3d9c) == DAT_0059e440)) &&
      (*(float *)(param_1 + 0x3da0) == DAT_0059e440)) &&
     (*(float *)(param_1 + 0x3da4) == DAT_0059e440)) {
    FUN_0054b420();
  }
  *(float *)(param_1 + 0x3d9c) = local_304 + *(float *)(param_1 + 0x3d9c);
  *(float *)(param_1 + 0x3da0) = local_300 + *(float *)(param_1 + 0x3da0);
  *(float *)(param_1 + 0x3da4) = local_2fc + *(float *)(param_1 + 0x3da4);
  if (((*(int *)(param_1 + 0xd0c) != 0) && (*(float *)(param_1 + 0x3dcc) == DAT_0059e440)) &&
     ((*(float *)(param_1 + 0x3dd0) == DAT_0059e440 &&
      (*(float *)(param_1 + 0x3dd4) == DAT_0059e440)))) {
    FUN_0054b420();
  }
  local_30c = (int *)(param_1 + 0xd50);
  local_308 = 8;
  *(float *)(param_1 + 0x3dcc) = local_304 + *(float *)(param_1 + 0x3dcc);
  *(float *)(param_1 + 0x3dd0) = local_300 + *(float *)(param_1 + 0x3dd0);
  *(float *)(param_1 + 0x3dd4) = local_2fc + *(float *)(param_1 + 0x3dd4);
  pfVar18 = (float *)(param_1 + 0x3eb8);
  do {
    if (((*local_30c != 0) && (pfVar18[-2] == DAT_0059e440)) &&
       ((pfVar18[-1] == DAT_0059e440 && (*pfVar18 == DAT_0059e440)))) {
      FUN_0054b420();
    }
    local_30c = local_30c + 0x11;
    pfVar18[-2] = local_304 + pfVar18[-2];
    local_308 = local_308 + -1;
    pfVar18[-1] = local_300 + pfVar18[-1];
    *pfVar18 = local_2fc + *pfVar18;
    pfVar18 = pfVar18 + 3;
  } while (local_308 != 0);
  *(undefined4 *)(param_1 + 0x3a9c) = 0;
  *(undefined4 *)(param_1 + 0x3b54) = 0;
  *(undefined4 *)(param_1 + 0x3b58) = 0;
  *(undefined4 *)(param_1 + 0x3b5c) = 0;
  FUN_004e9bd0();
  *(undefined4 *)(param_1 + 0x3be8) = 0;
  *(undefined4 *)(param_1 + 0x3bec) = 0;
  *(undefined4 *)(param_1 + 0x3bf0) = 0;
  iVar20 = 4;
  pfVar18 = (float *)(param_1 + 0x3594);
  do {
    iVar20 = iVar20 + -1;
    *(float *)(param_1 + 0x3be8) = pfVar18[-2] + *(float *)(param_1 + 0x3be8);
    *(float *)(param_1 + 0x3bec) = pfVar18[-1] + *(float *)(param_1 + 0x3bec);
    *(float *)(param_1 + 0x3bf0) = *(float *)(param_1 + 0x3bf0) + *pfVar18;
    pfVar18 = pfVar18 + 0x3e;
  } while (iVar20 != 0);
  iVar20 = 0;
  *(float *)(param_1 + 0x3be8) = *(float *)(param_1 + 0x3be8) * _DAT_0059e7f8;
  *(float *)(param_1 + 0x3bec) = *(float *)(param_1 + 0x3bec) * _DAT_0059e7f8;
  *(float *)(param_1 + 0x3bf0) = *(float *)(param_1 + 0x3bf0) * _DAT_0059e7f8;
  *(undefined4 *)(param_1 + 0x3b6c) = 0;
  *(undefined1 *)(param_1 + 0x3b74) = 0;
  *(undefined1 *)(param_1 + 0x3b75) = 0;
  do {
    if (iVar20 < 4) {
      afStack_1f4[2] = _DAT_0059e670;
      if ((iVar20 != 0) && (iVar20 != 1)) {
        afStack_1f4[2] = _DAT_0059e43c;
      }
      afStack_1f4[0] = _DAT_0059e43c;
      if ((iVar20 != 0) && (iVar20 != 2)) {
        afStack_1f4[0] = _DAT_0059e670;
      }
      afStack_1f4[1] = 0.0;
      FUN_004dd7c0();
      fStack_2d0 = fStack_280;
      fStack_2d8 = fStack_288;
      iVar13 = iVar20 * 0x128 + param_1;
      if (*(int *)(iVar13 + 0x828) != 0) {
        FUN_004dd7c0();
        fStack_2d8 = fStack_2d8 + *(float *)(iVar13 + 0x82c);
        fStack_2d0 = fStack_2d0 + *(float *)(iVar13 + 0x834);
      }
      fVar9 = fStack_280;
      fStack_2e4 = fStack_288;
      if (((iVar20 == 0) || (iVar20 == 1)) && (*(int *)(param_1 + 0xcc8) != 0)) {
        FUN_004dd7c0();
        fStack_2e4 = fStack_2e4 + *(float *)(param_1 + 0xccc);
        fStack_280 = fVar9 + *(float *)(param_1 + 0xcd4);
      }
      fVar9 = fStack_288;
      if ((iVar20 == 0) || (iVar20 == 2)) {
        fVar1 = fStack_2e4;
        if (fStack_2e4 < fStack_2d8) {
          fVar1 = fStack_2d8;
        }
        if (fStack_288 <= fVar1) {
          if (fStack_2d8 <= fStack_2e4) {
            iVar13 = param_1 + iVar20 * 0xc;
            fVar9 = fStack_2e4;
          }
          else {
            iVar13 = param_1 + iVar20 * 0xc;
            fVar9 = fStack_2d8;
          }
        }
        else {
          iVar13 = param_1 + iVar20 * 0xc;
        }
      }
      else {
        fVar1 = fStack_2e4;
        if (fStack_2d8 < fStack_2e4) {
          fVar1 = fStack_2d8;
        }
        if ((fVar1 <= fStack_288) && (fVar9 = fStack_2e4, fStack_2d8 < fStack_2e4)) {
          fVar9 = fStack_2d8;
        }
        iVar13 = param_1 + iVar20 * 0xc;
      }
      puVar19 = (undefined4 *)(param_1 + (iVar20 * 3 + 0xeaf) * 4);
      *(float *)(iVar13 + 0x3ab8) = fVar9 + local_304;
      *puVar19 = 0;
      fVar9 = fStack_280;
      if ((iVar20 == 0) || (iVar20 == 1)) {
        fVar1 = fStack_280;
        if (fStack_2d0 < fStack_280) {
          fVar1 = fStack_2d0;
        }
        if ((fVar1 <= fStack_280) && (fVar9 = fStack_2d0, fStack_280 <= fStack_2d0))
        goto LAB_004e778e;
      }
      else {
        fVar1 = fStack_280;
        if (fStack_280 < fStack_2d0) {
          fVar1 = fStack_2d0;
        }
        if ((fStack_280 <= fVar1) && (fVar9 = fStack_2d0, fStack_2d0 <= fStack_280)) {
LAB_004e778e:
          fVar9 = fStack_280;
        }
      }
      *(float *)(iVar13 + 0x3ac0) = fVar9 + local_2fc;
      if ((*(byte *)(param_3 + 0x3c) & 1) != 0) {
        fVar9 = fVar8;
        if (iVar20 == 0) {
          local_2ac = local_304 + local_294;
LAB_004e7803:
          local_2a4 = fVar9 + local_2fc;
        }
        else {
          if (iVar20 == 1) {
            local_2ac = local_304 + fVar6;
            goto LAB_004e7803;
          }
          fVar9 = local_294;
          if ((iVar20 == 2) || (fVar9 = fVar6, iVar20 == 3)) {
            local_2ac = local_304 + fVar9;
            fVar9 = local_28c;
            goto LAB_004e7803;
          }
        }
        *(float *)(iVar13 + 0x3ab8) =
             *(float *)(iVar13 + 0x3ab8) * _DAT_005ace00 + local_2ac * _DAT_005ad18c;
        *(float *)(iVar13 + 0x3ac0) =
             *(float *)(iVar13 + 0x3ac0) * _DAT_005ace00 + local_2a4 * _DAT_005ad18c;
      }
      if ((*(byte *)(param_3 + 0x3c) & 2) != 0) {
        *puVar19 = 0xbc75c28f;
      }
      if ((*(byte *)(param_3 + 0x3c) & 4) != 0) {
        if ((iVar20 == 0) || (iVar20 == 2)) {
          fVar9 = *(float *)(iVar13 + 0x3ab8) + _DAT_0059e454;
        }
        else {
          fVar9 = *(float *)(iVar13 + 0x3ab8) - _DAT_0059e454;
        }
        *(float *)(iVar13 + 0x3ab8) = fVar9;
      }
    }
    else if (iVar20 < 8) {
      if (iVar20 == 4) {
        pfVar18 = (float *)(param_1 + 0x3ae8);
        *pfVar18 = 0.0;
        *(float *)(param_1 + 0x3af0) = fVar8 + local_2fc;
LAB_004e7950:
        pfVar18[1] = 0.0;
      }
      else {
        if (iVar20 == 5) {
          pfVar18 = (float *)(param_1 + 0x3af4);
          *pfVar18 = 0.0;
          *(float *)(param_1 + 0x3afc) = local_28c + local_2fc;
          goto LAB_004e7950;
        }
        if (iVar20 == 6) {
          pfVar18 = (float *)(param_1 + 0x3b00);
          fVar9 = fVar6;
LAB_004e794b:
          *pfVar18 = local_304 + fVar9;
          pfVar18[2] = 0.0;
          goto LAB_004e7950;
        }
        if (iVar20 == 7) {
          pfVar18 = (float *)(param_1 + 0x3b0c);
          fVar9 = local_294;
          goto LAB_004e794b;
        }
      }
      if ((*(byte *)(param_3 + 0x3c) & 2) != 0) {
        iVar13 = iVar20 * 3 + 0xeaf;
        *(float *)(param_1 + iVar13 * 4) = *(float *)(param_1 + iVar13 * 4) - _DAT_005acd44;
      }
      if ((*(byte *)(param_3 + 0x3c) & 4) != 0) {
        if (iVar20 == 6) {
          *(float *)(param_1 + 0x3b00) = *(float *)(param_1 + 0x3b00) - _DAT_005ad188;
        }
        else if (iVar20 == 7) {
          *(float *)(param_1 + 0x3b0c) = *(float *)(param_1 + 0x3b0c) + _DAT_005ad188;
        }
      }
    }
    else if (iVar20 < 0xc) {
      fStack_2a0 = _DAT_0059e450;
      if ((iVar20 == 8) || (iVar20 == 9)) {
        if ((*(byte *)(param_3 + 0x3c) & 8) == 0) {
          fStack_2a0 = _DAT_0059e84c;
          if (iVar20 == 8) {
            fStack_2a0 = _DAT_005ad184;
          }
          fStack_298 = 0.0;
        }
        else if (iVar20 == 8) {
          fStack_298 = -0.1;
          fStack_2a0 = _DAT_0059e99c;
        }
        else {
          fStack_298 = -0.1;
        }
        fStack_29c = 1.0;
        FUN_004dd7c0();
        afStack_26c[0] = fStack_278 + local_304;
        pfVar18 = (float *)(param_1 + 0x3ab8 + iVar20 * 0xc);
        *pfVar18 = afStack_26c[0];
        afStack_26c[1] = fStack_274 + local_300;
        pfVar18[1] = afStack_26c[1];
        afStack_26c[2] = fStack_270 + local_2fc;
        pfVar18[2] = afStack_26c[2];
      }
      else {
        if ((*(byte *)(param_3 + 0x3c) & 8) == 0) {
          fStack_2a0 = _DAT_0059e84c;
          if (iVar20 == 10) {
            fStack_2a0 = _DAT_005ad184;
          }
        }
        else if (iVar20 == 10) {
          fStack_2a0 = _DAT_0059e99c;
        }
        fStack_29c = 1.0;
        fStack_298 = 0.8;
        FUN_004dd7c0();
        if (*(int *)(param_1 + 0xd0c) != 0) {
          FUN_004dd7c0();
          afStack_250[0] = afStack_250[0] + *(float *)(param_1 + 0xd10);
          afStack_250[1] = afStack_250[1] + *(float *)(param_1 + 0xd14);
          afStack_250[2] = afStack_250[2] + *(float *)(param_1 + 0xd18);
          if (fStack_278 * fStack_2a0 + fStack_274 * fStack_29c + fStack_270 * fStack_298 <
              afStack_250[0] * fStack_2a0 +
              afStack_250[1] * fStack_29c + afStack_250[2] * fStack_298) {
            *(undefined1 *)(param_1 + 0x3b74) = 1;
            fStack_278 = afStack_250[0];
            fStack_274 = afStack_250[1];
            fStack_270 = afStack_250[2];
          }
        }
      }
      afStack_2bc[0] = fStack_278 + local_304;
      iVar13 = param_1 + iVar20 * 0xc;
      *(float *)(iVar13 + 0x3ab8) = afStack_2bc[0];
      afStack_2bc[1] = fStack_274 + local_300;
      *(float *)(iVar13 + 0x3abc) = afStack_2bc[1];
      afStack_2bc[2] = fStack_270 + local_2fc;
      *(float *)(iVar13 + 0x3ac0) = afStack_2bc[2];
      if ((*(byte *)(param_3 + 0x3c) & 4) != 0) {
        if (iVar20 + -8 < 2) {
          *(float *)(iVar13 + 0x3ac0) = *(float *)(iVar13 + 0x3ac0) - _DAT_0059e7f8;
          pfVar18 = (float *)(param_1 + (iVar20 * 3 + 0xeaf) * 4);
          *pfVar18 = *pfVar18 + _DAT_0059e7e8;
        }
        else {
          iVar13 = iVar20 * 3 + 0xeaf;
          *(float *)(param_1 + iVar13 * 4) = *(float *)(param_1 + iVar13 * 4) + _DAT_0059e8c8;
        }
      }
    }
    else {
      puVar19 = (undefined4 *)(param_1 + 0x3ab8 + iVar20 * 0xc);
      *puVar19 = 0;
      puVar19[2] = 0;
      puVar19[1] = (local_300 + fVar7) * _DAT_0059e450;
    }
    fVar9 = *(float *)(param_1 + 0x3ac0 + iVar20 * 0xc);
    pfVar18 = (float *)(param_1 + 0x3ab8 + iVar20 * 0xc);
    fVar1 = pfVar18[1];
    fVar3 = *pfVar18;
    fVar9 = SQRT(fVar9 * fVar9 + fVar1 * fVar1 + fVar3 * fVar3);
    if (*(float *)(param_1 + 0x3b6c) < fVar9) {
      *(float *)(param_1 + 0x3b6c) = fVar9;
    }
    iVar20 = iVar20 + 1;
    if (0xc < iVar20) {
      iVar20 = 0xd;
      *(float *)(param_1 + 0x3b70) = *(float *)(param_1 + 0x3b6c) + _DAT_0059e84c;
      pfVar18 = afStack_1a8 + 1;
      pfVar12 = (float *)(param_1 + 0x3abc);
      do {
        pfVar18[-1] = -local_304;
        iVar20 = iVar20 + -1;
        *pfVar18 = -local_300;
        pfVar18[1] = -local_2fc;
        pfVar18[2] = pfVar12[-1] - local_304;
        pfVar18[3] = *pfVar12 - local_300;
        pfVar18[4] = pfVar12[1] - local_2fc;
        pfVar18 = pfVar18 + 8;
        pfVar12 = pfVar12 + 3;
      } while (iVar20 != 0);
      FUN_0054f830(afStack_1a8,0xd);
      *(undefined1 *)(param_1 + 0x3ff0) = 0;
      *(undefined4 *)(param_1 + 0x3ff4) = 0;
      *(undefined4 *)(param_1 + 0x3ff8) = 0;
      *(undefined4 *)(param_1 + 0x3ffc) = 0;
      *(undefined4 *)(param_1 + 0x4000) = 0;
      *(undefined4 *)(param_1 + 0x4004) = 0;
      *(undefined4 *)(param_1 + 0x4008) = 0;
      *(undefined4 *)(param_1 + 0x400c) = 0;
      *(undefined4 *)(param_1 + 0x4010) = 0;
      afStack_26c[0] = (*(float *)(param_1 + 0x358c) + *(float *)(param_1 + 0x3684)) * _DAT_0059e450
      ;
      afStack_26c[2] = (*(float *)(param_1 + 0x3594) + *(float *)(param_1 + 0x368c)) * _DAT_0059e450
      ;
      local_290 = -(float)*(double *)(param_3 + 0x60);
      afStack_1f4[2] = *(float *)(param_1 + 0x3784) + *(float *)(param_1 + 0x387c);
      *(undefined4 *)(param_1 + 0x3d48) = 0;
      *(undefined4 *)(param_1 + 0x3d4c) = 0;
      *(undefined4 *)(param_1 + 0x3d50) = 0;
      afStack_2bc[0] = (*(float *)(param_1 + 0x377c) + *(float *)(param_1 + 0x3874)) * _DAT_0059e450
      ;
      afStack_2bc[1] = (*(float *)(param_1 + 0x3780) + *(float *)(param_1 + 0x3878)) * _DAT_0059e450
      ;
      afStack_2bc[2] = afStack_1f4[2] * _DAT_0059e450;
      dVar4 = *(double *)(param_3 + 0x1350);
      dVar5 = *(double *)(param_3 + 0x1348);
      *(float *)(param_1 + 0x3d54) = afStack_2bc[0] + (float)*(double *)(param_3 + 0x1340);
      *(float *)(param_1 + 0x3d58) = local_290 + (float)dVar5;
      *(float *)(param_1 + 0x3d5c) = afStack_2bc[2] + (float)dVar4;
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x3d54);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x3d58);
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x3d5c);
      *(undefined4 *)(param_1 + 0x3d60) = 0;
      local_294 = afStack_2bc[0];
      local_28c = afStack_2bc[2];
      afStack_26c[1] = local_290;
      FUN_004ee150();
      *(undefined4 *)(param_1 + 0x4014) = 0;
      *(undefined1 *)(param_1 + 0x4018) = 0;
      *(undefined4 *)(param_1 + 0x401c) = 0;
      iVar20 = _rand();
      *(int *)(param_1 + 0x4020) = iVar20;
      FUN_0059da3a(unaff_ESI,unaff_EBX);
      return;
    }
  } while( true );
}


