// Function: FUN_004441f0 @ 004441f0
// Size (bytes): 9101


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004441f0(double *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  bool bVar11;
  char cVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  int iVar15;
  double *pdVar16;
  int iVar17;
  uint uVar18;
  int extraout_EDX;
  double *pdVar19;
  float *pfVar20;
  uint uVar21;
  double *pdVar22;
  int iVar23;
  bool bVar24;
  bool bVar25;
  float10 fVar26;
  float10 fVar27;
  undefined8 local_168;
  bool local_159;
  double local_158;
  float local_14c;
  float local_148;
  float local_144;
  double local_140;
  float local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined2 local_12c;
  char local_12a;
  float local_128;
  float local_124;
  float local_120;
  char local_11a;
  bool local_119;
  uint local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  undefined8 local_f0;
  double local_e8;
  double local_e0;
  double dStack_d8;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  double local_bc;
  double local_b4;
  double local_ac;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  int local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined1 local_50 [4];
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [4];
  float local_34;
  float local_30;
  float local_24;
  float local_18;
  float local_c;
  
  local_134 = *(uint *)((int)param_1 + 0x72);
  local_130 = *(uint *)((int)param_1 + 0x76);
  local_12c = *(undefined2 *)((int)param_1 + 0x7a);
  cVar12 = *(char *)((int)param_1 + 0x7c);
  if ((DAT_007ce910 == 0) || (bVar11 = true, *(char *)((int)param_1 + 0x75) != '\x03')) {
    bVar11 = false;
  }
  if (*(char *)(param_1 + 0xe) == '\0') {
    uVar21 = 0;
    local_118 = 0;
    local_138 = 0.0;
    local_114 = 0.0;
    local_cc = 1.0;
    local_70 = 0.0;
    local_6c = 0.0;
    local_80 = -2;
    local_159 = false;
    bVar24 = false;
    local_11a = '\0';
    local_12a = '\0';
    bVar11 = false;
LAB_0044438e:
    local_119 = false;
    *(undefined4 *)((int)param_1 + 0x1efc) = 0;
LAB_004443da:
    param_1[1] = (double)local_114;
    fVar2 = local_cc;
    cVar12 = local_134._3_1_;
  }
  else {
    local_12a = cVar12;
    FUN_00454da0((float)param_1[0xd],&local_138,&local_114,&local_cc,&local_70,&local_6c,&local_80);
    if (DAT_007cc184 == 0) {
      uVar21 = -(uint)(DAT_007cc1b0 != 0);
    }
    else {
      uVar21 = (uint)(DAT_007cc1b0 == 0);
    }
    local_159 = DAT_007cc1dc != 0;
    bVar24 = DAT_007cc368 != 0;
    local_11a = DAT_007cc33c != 0;
    local_118 = uVar21;
    if (cVar12 != '\0') {
      if (*(char *)(*(int *)(param_1 + 0x3e0) + 0x344c) == '\0') {
        FUN_00447c70(0,0);
        goto LAB_004443aa;
      }
      FUN_00447c70(1,0);
      uVar21 = 0;
      local_134._3_1_ = '\x03';
      bVar11 = false;
      local_118 = 0;
      local_114 = 1.0;
      local_134 = 0x3020202;
      local_130 = CONCAT31(local_130._1_3_,1);
      local_130 = CONCAT13(3,(undefined3)local_130);
      local_12c = 0x202;
      local_119 = false;
      *(undefined4 *)((int)param_1 + 0x1efc) = 0;
      goto LAB_004443da;
    }
LAB_004443aa:
    if (!bVar11) goto LAB_0044438e;
    local_119 = *(int *)(param_1 + 0x3de) == -1;
    if (!local_119) goto LAB_004443da;
    param_1[1] = (double)local_cc;
    fVar2 = local_114;
    cVar12 = local_134._3_1_;
  }
  param_1[2] = (double)fVar2;
  *param_1 = (double)local_138;
  param_1[4] = (double)local_6c;
  if (uVar21 != 0) {
    if ((((0 < (int)uVar21) && (*(int *)((int)param_1 + 0x34) == 6)) ||
        (((int)uVar21 < 0 && (*(int *)((int)param_1 + 0x34) == 5)))) &&
       ((float)param_1[0xc] < _DAT_007ce8ec + (float)param_1[7])) {
      uVar21 = 0;
      local_118 = 0;
    }
    if (*(char *)((int)param_1 + 0x71) == '\0') {
      if ((int)uVar21 < 1) {
        if (-1 < (int)uVar21) goto LAB_0044444f;
        bVar25 = cVar12 == '\x02';
      }
      else {
        bVar25 = cVar12 == '\x01';
      }
      if ((bVar25) || (cVar12 == '\x03')) {
        uVar21 = 0;
        local_118 = 0;
      }
    }
  }
LAB_0044444f:
  if (uVar21 == *(uint *)((int)param_1 + 0x2c)) {
    local_118 = 0;
  }
  else {
    *(uint *)((int)param_1 + 0x2c) = uVar21;
  }
  if ((bool)*(char *)(param_1 + 5) == local_159) {
    local_159 = false;
  }
  else {
    *(bool *)(param_1 + 5) = local_159;
  }
  param_1[8] = (double)local_138;
  *(undefined4 *)((int)param_1 + 0x4c) = *(undefined4 *)((int)param_1 + 0xc);
  param_1[0xb] = (double)local_6c;
  *(undefined4 *)((int)param_1 + 0x54) = *(undefined4 *)((int)param_1 + 0x14);
  dVar4 = param_1[0x38a] * *(double *)((int)param_1 + 0x1c5c);
  *(undefined4 *)(param_1 + 9) = *(undefined4 *)(param_1 + 1);
  *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_1 + 2);
  if (_DAT_0059e430 < dVar4) {
    param_1[1] = (dVar4 + param_1[1]) / (dVar4 + _DAT_0059e420);
  }
  iVar15 = *(int *)(param_1 + 0x3a6);
  if (iVar15 == 0) {
    if ((((bVar24) && (*(double *)((int)param_1 + 0x1d34) != _DAT_0059e430)) &&
        (*(int *)(param_1 + 0x3de) == 0)) &&
       ((*(int *)(param_1 + 0x1a) != 2 &&
        (iVar15 = *(int *)(param_1 + 0x2be),
        SQRT(*(double *)(iVar15 + 0x74) * *(double *)(iVar15 + 0x74) +
             *(double *)(iVar15 + 0x6c) * *(double *)(iVar15 + 0x6c) +
             *(double *)(iVar15 + 100) * *(double *)(iVar15 + 100)) < _DAT_0059e900)))) {
      *(undefined4 *)(param_1 + 0x1a) = 1;
      *(undefined4 *)(param_1 + 0x3a6) = 1;
      uVar18 = DAT_008aae70 & 0xff;
      uVar21 = DAT_008aae70 + 1;
      DAT_008aae70 = DAT_008aae70 + 2;
      FUN_004f87c0(0x29,2,_DAT_0059e43c -
                          *(float *)(&DAT_008aae74 + (uVar21 & 0xff) * 4) * _DAT_0059e868,
                   *(float *)(&DAT_008ab274 + uVar18 * 4) * _DAT_0059e84c + _DAT_0059e43c);
    }
  }
  else if (iVar15 == 1) {
    if (!bVar24) {
      *(undefined4 *)(param_1 + 0x3a6) = 2;
      uVar18 = DAT_008aae70 & 0xff;
      uVar21 = DAT_008aae70 + 1;
      DAT_008aae70 = DAT_008aae70 + 2;
      FUN_004f87c0(0x29,2,_DAT_0059e43c -
                          *(float *)(&DAT_008aae74 + (uVar21 & 0xff) * 4) * _DAT_0059e868,
                   *(float *)(&DAT_008ab274 + uVar18 * 4) * _DAT_0059e84c + _DAT_0059e43c);
    }
    local_118 = 0;
  }
  else if ((iVar15 == 2) && (param_1[1] < _DAT_0059ec70)) {
    *(undefined4 *)(param_1 + 0x3a6) = 0;
  }
  if (*(int *)(param_1 + 0x3a6) != 0) {
    if (cVar12 == '\0') {
      local_134 = CONCAT13(1,(undefined3)local_134);
    }
    else if (cVar12 == '\x02') {
      local_134 = CONCAT13(3,(undefined3)local_134);
    }
    local_134 = CONCAT31(local_134._1_3_,2);
  }
  local_158 = 1.0;
  if (_DAT_0059e430 < *(double *)((int)param_1 + 0x9c)) {
    iVar15 = *(int *)(param_1 + 0x2be);
    fVar26 = SQRT((float10)*(double *)(iVar15 + 0x74) * (float10)*(double *)(iVar15 + 0x74) +
                  (float10)*(double *)(iVar15 + 0x6c) * (float10)*(double *)(iVar15 + 0x6c) +
                  (float10)*(double *)(iVar15 + 100) * (float10)*(double *)(iVar15 + 100));
    if ((float10)_DAT_0059eeb8 <= fVar26) {
      fVar26 = (float10)_DAT_0059e420 - (float10)*(double *)((int)param_1 + 0x9c);
    }
    else {
      fVar26 = (float10)fcos(fVar26 * (float10)_DAT_0059eeb0);
      fVar26 = (float10)_DAT_0059e420 -
               ((float10)_DAT_0059e420 - fVar26) * (float10)*(double *)((int)param_1 + 0x9c) *
               (float10)_DAT_0059e880;
    }
    local_158 = (double)fVar26;
    *param_1 = local_158 * *param_1;
  }
  if (((local_130._2_1_ != '\0') &&
      (FUN_004388d0(*(int *)(param_1 + 0x2be) + 100,&local_bc),
      _DAT_0059eea8 < local_bc * local_bc + local_ac * local_ac)) && (local_ac < _DAT_0059e430)) {
    fVar26 = (float10)fpatan(-(float10)local_bc,-(float10)local_ac);
    fVar26 = fVar26 * (float10)*(double *)((int)param_1 + 0x8c);
    dVar4 = (double)fVar26;
    if ((((fVar26 < (float10)_DAT_0059e430) && (local_138 < (float)_DAT_0059e430)) ||
        ((_DAT_0059e430 < dVar4 && ((float)_DAT_0059e430 < local_138)))) &&
       (dVar4 = ABS(dVar4), local_158 < dVar4)) {
      if (dVar4 <= _DAT_0059e420) {
        *param_1 = (double)(local_138 * (float)dVar4);
        local_158 = dVar4;
      }
      else {
        local_158 = 1.0;
        *param_1 = (double)(local_138 * 1.0);
      }
    }
  }
  if ((DAT_007ce6d0 & 1) != 0) {
    puVar13 = (undefined4 *)((int)param_1 + 0x504);
    iVar15 = 4;
    do {
      *puVar13 = puVar13[0x75];
      puVar13[1] = puVar13[0x76];
      puVar13[4] = puVar13[0x77];
      puVar13[5] = puVar13[0x78];
      puVar13[0x2d] = puVar13[0x79];
      puVar13[0x2e] = puVar13[0x7a];
      puVar13 = puVar13 + 0x119;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  if (local_130._3_1_ == '\0') {
    if ((char)local_12c != '\0') {
LAB_004448ad:
      pdVar16 = param_1 + 0xd2;
      iVar15 = 4;
      do {
        if (_DAT_0059eea0 < *pdVar16) {
          *(undefined4 *)pdVar16 = 0xd70a3d71;
          *(undefined4 *)((int)pdVar16 + 4) = 0x4091f0a3;
        }
        pdVar16 = (double *)((int)pdVar16 + 0x464);
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      goto LAB_004448e1;
    }
  }
  else {
    if ((char)local_12c != '\0') goto LAB_004448ad;
LAB_004448e1:
    iVar15 = *(int *)(param_1 + 0x2be);
    local_c8 = (float)*(double *)(iVar15 + 4);
    local_c4 = (float)*(double *)(iVar15 + 0xc);
    pdVar16 = (double *)(iVar15 + 4);
    local_c0 = (float)*(double *)(iVar15 + 0x14);
    dVar4 = *pdVar16 - param_1[0x17];
    dVar6 = *(double *)(iVar15 + 0xc) - param_1[0x18];
    dVar5 = *(double *)(iVar15 + 0x14) - param_1[0x19];
    if ((*(int *)((int)param_1 + 0xb4) == 0) ||
       (_DAT_0059ee98 < dVar4 * dVar4 + dVar6 * dVar6 + dVar5 * dVar5)) {
      uVar14 = FUN_00403640(&local_c8,*(int *)((int)param_1 + 0xb4));
      iVar15 = *(int *)(param_1 + 0x2be);
      pdVar16 = (double *)(iVar15 + 4);
      *(undefined4 *)((int)param_1 + 0xb4) = uVar14;
      pdVar19 = pdVar16;
      pdVar22 = param_1 + 0x17;
      for (iVar17 = 6; iVar17 != 0; iVar17 = iVar17 + -1) {
        *(undefined4 *)pdVar22 = *(undefined4 *)pdVar19;
        pdVar19 = (double *)((int)pdVar19 + 4);
        pdVar22 = (double *)((int)pdVar22 + 4);
      }
    }
    iVar17 = *(int *)((int)param_1 + 0xb4);
    local_fc = *(float *)(iVar17 + 0xa4);
    local_f8 = *(float *)(iVar17 + 0xa8);
    local_f4 = *(float *)(iVar17 + 0xac);
    local_10c = local_fc * (*(float *)(iVar17 + 0x94) - local_c8) +
                local_f8 * (*(float *)(iVar17 + 0x98) - local_c4) +
                local_f4 * (*(float *)(iVar17 + 0x9c) - local_c0);
    fVar2 = *(float *)(iVar17 + 0x88);
    local_140 = (double)CONCAT44(local_140._4_4_,fVar2);
    local_100 = ((local_c8 - *(float *)(iVar17 + 0x94)) * *(float *)(iVar17 + 0x20) +
                (local_c4 - *(float *)(iVar17 + 0x98)) * *(float *)(iVar17 + 0x24) +
                (local_c0 - *(float *)(iVar17 + 0x9c)) * *(float *)(iVar17 + 0x28)) * _DAT_0059e450;
    local_108 = local_100 * *(float *)(iVar17 + 0x20);
    local_104 = local_100 * *(float *)(iVar17 + 0x24);
    local_100 = local_100 * *(float *)(iVar17 + 0x28);
    if (DAT_0059e440 <= local_10c) {
      iVar23 = *(int *)(iVar17 + 0x10c);
      fVar26 = (float10)local_10c / (float10)*(float *)(iVar23 + 0x3c);
    }
    else {
      iVar23 = *(int *)(iVar17 + 0x110);
      fVar26 = -(((float10)_DAT_0059e43c / (float10)*(float *)(iVar17 + 0x3c)) * (float10)local_10c)
      ;
    }
    if ((float10)DAT_0059e440 <= fVar26) {
      if ((float10)_DAT_0059e43c < fVar26) {
        fVar26 = (float10)_DAT_0059e43c;
      }
    }
    else {
      fVar26 = (float10)DAT_0059e440;
    }
    fVar27 = (((float10)local_c8 - (float10)*(float *)(iVar23 + 0x94)) *
              (float10)*(float *)(iVar23 + 0x20) +
             ((float10)local_c4 - (float10)*(float *)(iVar23 + 0x98)) *
             (float10)*(float *)(iVar23 + 0x24) +
             ((float10)local_c0 - (float10)*(float *)(iVar23 + 0x9c)) *
             (float10)*(float *)(iVar23 + 0x28)) * (float10)_DAT_0059e450;
    fVar3 = (float)(fVar27 * (float10)*(float *)(iVar23 + 0x28));
    local_e8 = (double)CONCAT44(local_e8._4_4_,fVar3);
    local_7c = (float)((fVar27 * (float10)*(float *)(iVar23 + 0x20) - (float10)local_108) * fVar26);
    local_f0 = (double)CONCAT44(local_f0._4_4_,local_7c);
    local_7c = local_7c + local_108;
    local_74 = (float)((float10)local_100 + ((float10)fVar3 - (float10)local_100) * fVar26);
    fVar26 = ((float10)*(float *)(iVar23 + 0x88) - (float10)fVar2) * fVar26 + (float10)fVar2;
    local_98 = (float)*(double *)(iVar15 + 100);
    local_94 = (float)*(double *)(iVar15 + 0x6c);
    local_90 = (float)*(double *)(iVar15 + 0x74);
    local_78 = local_104;
    if ((char)local_12c != '\0') {
      if ((DAT_0059e440 < (_DAT_008afee8 + _DAT_008afeec) * _DAT_0059e450) &&
         (fVar27 = ((float10)*(double *)((int)param_1 + 0xac) - (float10)_DAT_0059e420) *
                   ((float10)_DAT_008afee8 + (float10)_DAT_008afeec) * (float10)_DAT_0059e450 +
                   (float10)_DAT_0059e420, (float10)DAT_0059e440 < fVar27)) {
        fVar26 = (SQRT(fVar27) + fVar27) * (float10)_DAT_0059e450 * fVar26;
      }
      fVar27 = SQRT((float10)local_98 * (float10)local_98 +
                    (float10)local_94 * (float10)local_94 + (float10)local_90 * (float10)local_90);
      fVar2 = (float)fVar27;
      local_140 = (double)CONCAT44(local_140._4_4_,fVar2);
      if (fVar26 - (float10)_DAT_0059e7e0 < fVar27) {
        if ((float10)fVar2 < fVar26) {
          fVar26 = ((float10)fVar2 - fVar26) * (float10)_DAT_0059eb78 + (float10)_DAT_0059e420;
        }
        else {
          fVar26 = (float10)_DAT_0059e420;
        }
        if ((char)local_12c == '\x01') {
          if ((float10)param_1[2] < fVar26) {
            param_1[2] = (double)((fVar26 + (float10)param_1[2]) * (float10)_DAT_0059e880);
          }
          goto LAB_00445125;
        }
        if ((float10)param_1[2] < fVar26) {
          param_1[2] = (double)fVar26;
        }
        if ((float10)_DAT_0059e428 < fVar26) {
          if (fVar26 <= (float10)_DAT_0059e430) {
            fVar26 = -fVar26;
            if ((float10)param_1[1] < fVar26) {
              fVar26 = (float10)param_1[1];
            }
            param_1[1] = (double)fVar26;
          }
          else {
            *(undefined4 *)(param_1 + 1) = 0;
            *(undefined4 *)((int)param_1 + 0xc) = 0;
          }
        }
      }
      if (((char)local_12c == '\x02') &&
         (fVar26 = SQRT((float10)*(double *)(iVar15 + 0x74) * (float10)*(double *)(iVar15 + 0x74) +
                        (float10)*(double *)(iVar15 + 0x6c) * (float10)*(double *)(iVar15 + 0x6c) +
                        (float10)*(double *)(iVar15 + 100) * (float10)*(double *)(iVar15 + 100)),
         local_140 = (double)CONCAT44(local_140._4_4_,(float)fVar26),
         (float10)_DAT_0059ee94 < fVar26)) {
        local_a4 = (float)*pdVar16;
        pfVar20 = *(float **)(iVar17 + 0x110);
        local_110 = 500.0;
        local_9c = (float)*(double *)(iVar15 + 0x14);
        local_a0 = 0.0;
        iVar23 = 0x19;
        local_128 = -(float)*(double *)(iVar15 + 0x2c);
        local_124 = -(float)*(double *)(iVar15 + 0x44);
        local_120 = -(float)*(double *)(iVar15 + 0x5c);
        do {
          pfVar1 = pfVar20 + 8;
          local_5c = *pfVar1;
          local_58 = pfVar20[9];
          local_54 = pfVar20[10];
          local_68 = local_54 - local_58 * DAT_0059e440;
          local_64 = local_5c * DAT_0059e440 - local_54 * DAT_0059e440;
          local_60 = local_58 * DAT_0059e440 - local_5c;
          if (DAT_0059e440 <= local_128 * *pfVar1 + local_124 * pfVar20[9] + local_120 * pfVar20[10]
             ) {
            fVar2 = pfVar20[0xc];
            local_34 = fVar2 * pfVar20[9];
            local_30 = fVar2 * pfVar20[10];
            local_108 = fVar2 * *pfVar1 + *pfVar20;
            local_104 = local_34 + pfVar20[1];
            local_100 = local_30 + pfVar20[2];
            local_14c = local_108;
            local_148 = local_104;
            local_144 = local_100;
          }
          else {
            fVar2 = pfVar20[0xb];
            local_4c = fVar2 * pfVar20[9];
            local_48 = fVar2 * pfVar20[10];
            local_108 = *pfVar20 - fVar2 * *pfVar1;
            local_104 = pfVar20[1] - local_4c;
            local_100 = pfVar20[2] - local_48;
            local_8c = local_108;
            local_88 = local_104;
            local_84 = local_100;
          }
          local_44 = local_68;
          local_40 = local_64;
          local_3c = local_60;
          fVar26 = (float10)FUN_004352c0(&local_108,&local_68);
          fVar2 = (float)fVar26;
          if ((float10)DAT_0059e440 < fVar26) {
            local_bc = (double)CONCAT44(local_bc._4_4_,fVar2 * local_128);
            fVar3 = fVar2 * local_128 + local_a4;
            local_f0 = (double)CONCAT44(fVar2 * local_124,fVar3);
            fVar3 = local_108 - fVar3;
            fVar10 = local_104 - fVar2 * local_124;
            fVar9 = local_100 - (fVar2 * local_120 + local_9c);
            if ((fVar3 * fVar3 + fVar10 * fVar10 + fVar9 * fVar9 < _DAT_0059e920) &&
               (fVar2 < local_110)) {
              local_110 = fVar2;
            }
          }
          iVar23 = iVar23 + -1;
          pfVar20 = (float *)pfVar20[0x44];
        } while (iVar23 != 0);
        fVar3 = ABS((local_a4 - *(float *)(iVar17 + 0x94)) * *(float *)(iVar17 + 0x20) +
                    -*(float *)(iVar17 + 0x98) * *(float *)(iVar17 + 0x24) +
                    (local_9c - *(float *)(iVar17 + 0x9c)) * *(float *)(iVar17 + 0x28));
        fVar2 = _DAT_0059ee94;
        if (fVar3 < _DAT_0059e478) {
          fVar2 = (_DAT_0059e478 - fVar3) * _DAT_0059ee90 + _DAT_0059ee94;
        }
        fVar3 = ABS(local_128 * *(float *)(iVar17 + 0xa4) +
                    local_124 * *(float *)(iVar17 + 0xa8) + local_120 * *(float *)(iVar17 + 0xac));
        if (_DAT_0059ee8c < fVar3) {
          fVar2 = (fVar3 - _DAT_0059ee8c) * _DAT_0059ee88 + fVar2;
        }
        fVar2 = local_110 * _DAT_0059e8cc + fVar2;
        if (fVar2 - _DAT_0059ee84 < local_140._0_4_) {
          if (local_140._0_4_ <= fVar2) {
            fVar2 = (fVar2 - local_140._0_4_) * _DAT_0059ee80;
            if (fVar2 < (float)param_1[1]) {
              if ((float)_DAT_0059e420 < fVar2) {
                fVar2 = (float)_DAT_0059e420;
              }
              param_1[1] = (double)fVar2;
            }
          }
          else {
            *(undefined4 *)(param_1 + 1) = 0;
            *(undefined4 *)((int)param_1 + 0xc) = 0;
            fVar2 = (local_140._0_4_ - fVar2) * _DAT_0059ee80;
            if ((float)param_1[2] < fVar2) {
              if ((float)_DAT_0059e420 < fVar2) {
                fVar2 = (float)_DAT_0059e420;
              }
              param_1[2] = (double)fVar2;
            }
          }
        }
      }
    }
LAB_00445125:
    if ((local_12a != '\0') &&
       (iVar15 = *(int *)(param_1 + 0x3e0), *(char *)(iVar15 + 0x344c) != '\0')) {
      iVar23 = 0;
      if (*(int *)(param_1 + 0x3de) == -1) {
        FUN_00447e00(0,4);
      }
      iVar8 = *(int *)(iVar15 + 0x3450);
      if (((iVar8 == 2) || (iVar8 == 3)) || (iVar8 == 4)) {
        FUN_004d1100(*(undefined4 *)(param_1 + 0x3e0),&local_a4,&local_bc);
        FUN_004efb20(&local_f0,&local_8c);
        local_14c = local_a4 - (float)local_f0;
        local_148 = local_a0 - local_f0._4_4_;
        local_144 = local_9c - local_e8._0_4_;
        FUN_00566e40();
        bVar24 = true;
        fVar3 = local_148 * local_18 * _DAT_0059e670 +
                local_144 * local_c * _DAT_0059e670 + local_24 * _DAT_0059e670 * local_14c;
        fVar2 = local_24 * _DAT_0059e670 * local_98 +
                local_94 * local_18 * _DAT_0059e670 + local_90 * local_c * _DAT_0059e670;
        if (fVar2 < DAT_0059e440) {
          fVar2 = DAT_0059e440;
        }
        if (*(int *)(iVar15 + 0x3450) == 4) {
          bVar24 = fVar2 <= _DAT_008acfb4;
          iVar15 = *(int *)(*(int *)(param_1 + 0x3e0) + 0x32e0);
          if ((iVar15 != 0) &&
             ((*(int *)(iVar15 + 0x78) != 2 ||
              (*(float *)(iVar15 + 0x84) <= *(float *)(iVar15 + 0x7c) + _DAT_0059e84c)))) {
            FUN_004d1140(*(int *)(param_1 + 0x3e0),local_50,local_38);
            FUN_004ef6c0(local_50,local_38,&local_68);
            if ((local_60 - local_c0) * (local_60 - local_c0) +
                (local_64 - local_c4) * (local_64 - local_c4) +
                (local_68 - local_c8) * (local_68 - local_c8) < _DAT_0059e43c) {
              *(undefined4 *)(param_1 + 1) = 0;
              *(undefined4 *)((int)param_1 + 0xc) = 0;
              *(undefined4 *)(param_1 + 2) = 0;
              *(undefined4 *)((int)param_1 + 0x14) = 0x3ff00000;
            }
          }
          if (DAT_008acfd4 == 2) {
            iVar15 = *(int *)(param_1 + 0x2be);
            local_108 = (float)*(double *)(iVar15 + 4);
            local_104 = (float)*(double *)(iVar15 + 0xc);
            local_110 = 100.0;
            local_100 = (float)*(double *)(iVar15 + 0x14);
            if (DAT_008acfd8 != 0) {
              FUN_0054b950(&local_14c,&local_148,&local_144);
              fVar2 = local_14c - local_108;
              fVar10 = local_148 - local_104;
              fVar9 = local_144 - local_100;
              if (fVar2 * fVar2 + fVar10 * fVar10 + fVar9 * fVar9 < _DAT_0059ee68) {
                iVar15 = *(int *)((int)param_1 + 0xb4);
                local_110 = fVar2 * *(float *)(iVar15 + 0xa4) +
                            fVar10 * *(float *)(iVar15 + 0xa8) + fVar9 * *(float *)(iVar15 + 0xac);
              }
            }
            fVar2 = local_110;
            if (DAT_008ad078 != 0) {
              FUN_0054b950(&local_14c,&local_148,&local_144);
              fVar2 = local_14c - local_108;
              fVar10 = local_148 - local_104;
              fVar9 = local_144 - local_100;
              if (fVar2 * fVar2 + fVar10 * fVar10 + fVar9 * fVar9 < _DAT_0059ee68) {
                iVar15 = *(int *)((int)param_1 + 0xb4);
                fVar2 = fVar2 * *(float *)(iVar15 + 0xa4) +
                        fVar10 * *(float *)(iVar15 + 0xa8) + fVar9 * *(float *)(iVar15 + 0xac);
                if (fVar2 < local_110) goto LAB_00445569;
              }
              fVar2 = local_110;
            }
LAB_00445569:
            local_110 = fVar2;
            iVar15 = *(int *)(param_1 + 0x2be);
            fVar2 = (float)(((float10)local_110 + (float10)_DAT_0059eb48) * (float10)_DAT_0059eb28 -
                           SQRT((float10)*(double *)(iVar15 + 0x74) *
                                (float10)*(double *)(iVar15 + 0x74) +
                                (float10)*(double *)(iVar15 + 0x6c) *
                                (float10)*(double *)(iVar15 + 0x6c) +
                                (float10)*(double *)(iVar15 + 100) *
                                (float10)*(double *)(iVar15 + 100)));
            local_140 = (double)CONCAT44(local_140._4_4_,fVar2);
            if (fVar2 < (float)_DAT_0059eb08) {
              if ((local_110 < (float)_DAT_0059eb48) || (fVar2 < (float)_DAT_0059ee78)) {
                *(undefined4 *)(param_1 + 1) = 0;
                *(undefined4 *)((int)param_1 + 0xc) = 0;
                *(undefined4 *)(param_1 + 2) = 0;
                *(undefined4 *)((int)param_1 + 0x14) = 0x3ff00000;
              }
              else {
                if (fVar2 < DAT_0059e440) goto LAB_004452e2;
                param_1[1] = (double)(fVar2 * (float)_DAT_0059eb28);
              }
            }
          }
        }
        else {
          fVar2 = (fVar3 + (float)_DAT_0059e880) * (float)_DAT_0059e880 - fVar2;
          if (fVar2 < (float)_DAT_0059eb08) {
            if ((fVar3 < DAT_0059e440) || (fVar2 < (float)_DAT_0059ee78)) {
              fVar9 = (float)_DAT_0059ee70;
              *(undefined4 *)(param_1 + 1) = 0;
              *(undefined4 *)((int)param_1 + 0xc) = 0;
              *(undefined4 *)(param_1 + 2) = 0;
              *(undefined4 *)((int)param_1 + 0x14) = 0x3ff00000;
              if (fVar2 < fVar9) {
                bVar24 = false;
              }
            }
            else if (DAT_0059e440 <= fVar2) {
              param_1[1] = (double)(fVar2 * (float)_DAT_0059eb28);
            }
            else {
LAB_004452e2:
              *(undefined4 *)(param_1 + 1) = 0;
              fVar9 = (float)_DAT_0059eb28;
              *(undefined4 *)((int)param_1 + 0xc) = 0;
              if ((float)param_1[2] < -fVar2 * fVar9) {
                param_1[2] = (double)(-fVar2 * fVar9);
              }
            }
          }
        }
        if (param_1[0x27] == _DAT_0059e430) {
          iVar15 = FUN_00403640(&local_a4,0);
          param_1[0x27] =
               (double)((local_a4 - *(float *)(iVar15 + 0x94)) * *(float *)(iVar15 + 0x20) +
                       (local_a0 - *(float *)(iVar15 + 0x98)) * *(float *)(iVar15 + 0x24) +
                       (local_9c - *(float *)(iVar15 + 0x9c)) * *(float *)(iVar15 + 0x28));
        }
        local_140 = ABS(param_1[0x27]) + ABS(param_1[0x27]) + _DAT_0059edb8;
        if (((bVar24) && (fVar3 < (float)local_140)) && (_DAT_0059e7d0 - local_140 < (double)fVar3))
        {
          fVar26 = (float10)fVar3;
          if (fVar3 < DAT_0059e440 == (fVar3 == DAT_0059e440)) {
            if ((float10)_DAT_0059e7d0 <= fVar26) {
              fVar26 = (float10)fVar3 - (float10)_DAT_0059e7d0;
              goto LAB_00445706;
            }
            fVar26 = (float10)_DAT_0059e43c;
          }
          else {
LAB_00445706:
            fVar26 = (float10)fcos((fVar26 * (float10)_DAT_0059e890) /
                                   (((float10)local_140 - (float10)_DAT_0059e7d0) +
                                   ((float10)local_140 - (float10)_DAT_0059e7d0)));
          }
          fVar26 = fVar26 * (float10)param_1[0x27];
          local_14c = (float)(fVar26 * (float10)*(float *)(iVar17 + 0x20));
          local_148 = (float)(fVar26 * (float10)*(float *)(iVar17 + 0x24));
          local_144 = (float)(fVar26 * (float10)*(float *)(iVar17 + 0x28));
          local_7c = local_14c;
          local_78 = local_148;
          local_74 = local_144;
        }
      }
      if (0 < DAT_005c329c) {
        local_140 = (double)CONCAT44(local_140._4_4_,*(undefined4 *)(param_1 + 0x3e0));
        do {
          if (iVar23 != *(int *)((int)local_140._0_4_ + 0x4894)) {
            iVar15 = (&DAT_007c54f0)[iVar23];
            iVar8 = *(int *)(param_1 + 0x2be);
            local_14c = *(float *)(iVar15 + 0x34e0);
            local_148 = *(float *)(iVar15 + 0x34e4);
            local_144 = *(float *)(iVar15 + 0x34e8);
            local_bc = (double)local_14c;
            local_b4 = (double)local_148;
            local_ac = (double)local_144;
            FUN_004361d0(iVar8 + 4,&local_bc,&local_f0);
            if (((ABS(local_f0) < _DAT_0059e7e0) && (_DAT_0059ee60 < local_e0)) &&
               (local_e0 < _DAT_0059e430)) {
              local_8c = *(float *)(iVar15 + 0x34f8);
              local_88 = *(float *)(iVar15 + 0x34fc);
              local_84 = *(float *)(iVar15 + 0x3500);
              dVar4 = -((double)local_8c * *(double *)(iVar8 + 0x2c) +
                       (double)local_88 * *(double *)(iVar8 + 0x44) +
                       (double)local_84 * *(double *)(iVar8 + 0x5c)) -
                      SQRT(*(double *)(iVar8 + 0x74) * *(double *)(iVar8 + 0x74) +
                           *(double *)(iVar8 + 0x6c) * *(double *)(iVar8 + 0x6c) +
                           *(double *)(iVar8 + 100) * *(double *)(iVar8 + 100));
              if (DAT_008acfd4 != 2) {
                dVar4 = dVar4 + _DAT_0059eea8;
              }
              if (dVar4 < _DAT_0059eb08) {
                if (_DAT_0059ee78 <= dVar4) {
                  if ((double)DAT_0059e440 <= dVar4) {
                    if (dVar4 * _DAT_0059eb28 < param_1[1]) {
                      param_1[1] = dVar4 * _DAT_0059eb28;
                    }
                  }
                  else {
                    dVar4 = -dVar4 * _DAT_0059eb28;
                    *(undefined4 *)(param_1 + 1) = 0;
                    *(undefined4 *)((int)param_1 + 0xc) = 0;
                    if (param_1[2] < dVar4) {
                      param_1[2] = dVar4;
                    }
                  }
                }
                else {
                  *(undefined4 *)(param_1 + 1) = 0;
                  *(undefined4 *)((int)param_1 + 0xc) = 0;
                  *(undefined4 *)(param_1 + 2) = 0;
                  *(undefined4 *)((int)param_1 + 0x14) = 0x3ff00000;
                }
              }
            }
          }
          iVar23 = iVar23 + 1;
        } while (iVar23 < DAT_005c329c);
      }
    }
    if (local_130._3_1_ != '\0') {
      fVar2 = local_f8 * local_94 + local_f4 * local_90 + local_fc * local_98;
      if (fVar2 < DAT_0059e440) {
        fVar2 = DAT_0059e440;
      }
      local_128 = *(float *)(iVar17 + 0x94);
      local_124 = *(float *)(iVar17 + 0x98);
      fVar2 = fVar2 * (float)_DAT_0059ee58 + (float)_DAT_0059e7e0;
      local_140 = (double)CONCAT44(local_140._4_4_,fVar2);
      local_120 = *(float *)(iVar17 + 0x9c);
      if (local_10c < fVar2) {
        fVar3 = SQRT(local_fc * local_fc + local_f8 * local_f8 + local_f4 * local_f4);
        fVar9 = local_10c + fVar3;
        while ((fVar9 < fVar2 && (*(int *)(iVar17 + 0x110) != 0))) {
          fVar3 = *(float *)(iVar17 + 0x3c);
          local_10c = local_10c + fVar3;
          fVar9 = local_10c + fVar3;
          iVar17 = *(int *)(iVar17 + 0x110);
        }
        if ((*(int *)(iVar17 + 0x110) == 0) || (fVar3 == DAT_0059e440)) {
          local_128 = *(float *)(iVar17 + 0x94);
          local_124 = *(float *)(iVar17 + 0x98);
          local_120 = *(float *)(iVar17 + 0x9c);
        }
        else {
          fVar2 = fVar2 - local_10c;
          fVar9 = fVar2 * *(float *)(iVar17 + 0xa8);
          local_f0 = (double)CONCAT44(fVar9,(float)local_f0);
          fVar3 = fVar2 * *(float *)(iVar17 + 0xac);
          local_e8 = (double)CONCAT44(local_e8._4_4_,fVar3);
          local_14c = fVar2 * *(float *)(iVar17 + 0xa4) + *(float *)(iVar17 + 0x94);
          local_148 = fVar9 + *(float *)(iVar17 + 0x98);
          local_144 = fVar3 + *(float *)(iVar17 + 0x9c);
          local_128 = local_14c;
          local_124 = local_148;
          local_120 = local_144;
        }
      }
      iVar15 = *(int *)(param_1 + 0x2be);
      fVar2 = (local_128 + local_7c) - local_c8;
      local_bc = (double)CONCAT44(local_bc._4_4_,fVar2);
      fVar26 = (float10)fpatan(-(float10)*(double *)(iVar15 + 0x5c),
                               -(float10)*(double *)(iVar15 + 0x2c));
      fVar27 = (float10)fpatan(((float10)local_74 + (float10)local_120) - (float10)local_c0,
                               (float10)fVar2);
      fVar26 = fVar26 - fVar27;
      if (fVar26 <= (float10)_DAT_0059e660) {
        if (fVar26 < (float10)_DAT_0059ee50) {
          fVar26 = fVar26 + (float10)_DAT_0059e888;
        }
      }
      else {
        fVar26 = fVar26 - (float10)_DAT_0059e888;
      }
      fVar26 = fVar26 * (float10)*(double *)((int)param_1 + 0x8c);
      local_168 = (double)fVar26;
      if (fVar26 <= (float10)_DAT_0059e420) {
        if (local_168 < _DAT_0059e428) {
          local_168._4_4_ = 0xbff00000;
          goto LAB_00445ba6;
        }
      }
      else {
        local_168._4_4_ = 0x3ff00000;
LAB_00445ba6:
        local_168 = (double)((ulonglong)local_168._4_4_ << 0x20);
      }
      local_ac = *(double *)(iVar15 + 0x2c) * *(double *)(iVar15 + 100) +
                 *(double *)(iVar15 + 0x44) * *(double *)(iVar15 + 0x6c) +
                 *(double *)(iVar15 + 0x5c) * *(double *)(iVar15 + 0x74);
      if (_DAT_0059e428 < local_ac) {
        if (local_ac <= _DAT_0059e420) {
          local_168 = local_ac * local_168;
        }
        local_168 = -local_168;
      }
      if (local_130._3_1_ == '\x03') {
        *(undefined4 *)param_1 = (undefined4)local_168;
        *(uint *)((int)param_1 + 4) = local_168._4_4_;
      }
      else {
        if ((DAT_007ce6d0 & 1) != 0) {
          dVar4 = _DAT_0059ee40;
          if (local_130._3_1_ == '\x01') {
            dVar4 = _DAT_0059ee48;
          }
          iVar15 = 2;
          pdVar16 = (double *)((int)param_1 + 0x504);
          do {
            iVar15 = iVar15 + -1;
            *pdVar16 = dVar4 * *(double *)((int)pdVar16 + 0x1d4);
            pdVar16[2] = dVar4 * *(double *)((int)pdVar16 + 0x1dc);
            pdVar16 = (double *)((int)pdVar16 + 0x464);
          } while (iVar15 != 0);
          dVar4 = _DAT_0059ee30;
          if (local_130._3_1_ == '\x01') {
            dVar4 = _DAT_0059ee38;
          }
          iVar15 = 2;
          pdVar16 = (double *)((int)param_1 + 0xdcc);
          do {
            iVar15 = iVar15 + -1;
            *pdVar16 = dVar4 * *(double *)((int)pdVar16 + 0x1d4);
            pdVar16[2] = dVar4 * *(double *)((int)pdVar16 + 0x1dc);
            pdVar16 = (double *)((int)pdVar16 + 0x464);
          } while (iVar15 != 0);
          dVar4 = _DAT_0059ee20;
          if (local_130._3_1_ == '\x01') {
            dVar4 = _DAT_0059ee28;
          }
          iVar15 = 4;
          pdVar16 = param_1 + 0xb7;
          do {
            iVar15 = iVar15 + -1;
            *pdVar16 = dVar4 + pdVar16[0x26];
            pdVar16 = (double *)((int)pdVar16 + 0x464);
          } while (iVar15 != 0);
        }
        if ((int)DAT_007ce6d0 < 2) {
          dVar4 = _DAT_0059ee00;
          if (local_130._3_1_ == '\x01') {
            dVar4 = _DAT_0059ee08;
          }
          dVar4 = dVar4 * *(double *)((int)param_1 + 0x8c) * _DAT_0059eae8;
          if (local_158 < dVar4) {
            dVar4 = local_158;
          }
          if ((((local_138 < DAT_0059e440) && (local_168 < _DAT_0059e430)) ||
              ((DAT_0059e440 < local_138 && (_DAT_0059e430 < local_168)))) &&
             (local_158 = ABS(local_168), dVar4 <= local_158)) {
            dVar4 = local_158;
          }
          *param_1 = (double)local_138 * dVar4;
        }
        else if (local_130._3_1_ == '\x01') {
          dVar4 = ABS(*param_1 - *(double *)((int)param_1 + 0xa4)) * param_1[0xd];
          if (*(double *)((int)param_1 + 0xa4) <= *param_1) {
            if (local_168 <= *param_1) {
              if (*(double *)((int)param_1 + 0xa4) < local_168) {
                dVar4 = dVar4 * _DAT_0059eb48;
              }
            }
            else {
              dVar4 = dVar4 * _DAT_0059ee18;
            }
            dVar4 = dVar4 + *(double *)((int)param_1 + 0xa4);
            *(double *)((int)param_1 + 0xa4) = dVar4;
            if (*param_1 < dVar4) {
              *(undefined4 *)((int)param_1 + 0xa4) = *(undefined4 *)param_1;
              *(undefined4 *)(param_1 + 0x15) = *(undefined4 *)((int)param_1 + 4);
            }
          }
          else {
            if (*param_1 <= local_168) {
              if (local_168 < *(double *)((int)param_1 + 0xa4)) {
                dVar4 = dVar4 * _DAT_0059eb48;
              }
            }
            else {
              dVar4 = dVar4 * _DAT_0059ee18;
            }
            dVar4 = *(double *)((int)param_1 + 0xa4) - dVar4;
            *(double *)((int)param_1 + 0xa4) = dVar4;
            if (dVar4 < *param_1) {
              *(undefined4 *)((int)param_1 + 0xa4) = *(undefined4 *)param_1;
              *(undefined4 *)(param_1 + 0x15) = *(undefined4 *)((int)param_1 + 4);
            }
          }
          *(undefined4 *)param_1 = *(undefined4 *)((int)param_1 + 0xa4);
          *(undefined4 *)((int)param_1 + 4) = *(undefined4 *)(param_1 + 0x15);
        }
        else if ((float)_DAT_0059e430 <= local_138) {
          if (_DAT_0059eb28 <= local_168 + local_158) {
            dVar4 = (double)local_138 * local_158;
          }
          else {
            dVar4 = (_DAT_0059eb28 - local_168) * (double)local_138;
          }
          *param_1 = dVar4 + local_168;
          if (_DAT_0059e420 < *param_1) {
            *(undefined4 *)param_1 = 0;
            *(undefined4 *)((int)param_1 + 4) = 0x3ff00000;
          }
        }
        else {
          if (local_168 - local_158 <= _DAT_0059ee10) {
            dVar4 = (double)local_138 * local_158;
          }
          else {
            dVar4 = (local_168 + _DAT_0059eb28) * (double)local_138;
          }
          *param_1 = dVar4 + local_168;
          if (*param_1 < _DAT_0059e428) {
            *(undefined4 *)param_1 = 0;
            *(undefined4 *)((int)param_1 + 4) = 0xbff00000;
          }
        }
      }
    }
  }
  *(undefined4 *)((int)param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0x1e) = 0;
  *(undefined4 *)((int)param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0x1f) = 0;
  *(undefined4 *)((int)param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)((int)param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x21) = 0;
  *(undefined4 *)((int)param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x22) = 0;
  *(undefined4 *)((int)param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x23) = 0;
  if ((((local_12c._1_1_ != '\0') &&
       (iVar15 = *(int *)(param_1 + 0x2be),
       *(double *)(iVar15 + 0x74) * *(double *)(iVar15 + 0x74) +
       *(double *)(iVar15 + 0x6c) * *(double *)(iVar15 + 0x6c) +
       *(double *)(iVar15 + 100) * *(double *)(iVar15 + 100) < _DAT_0059e7d8)) &&
      (_DAT_0059e880 < *(double *)(iVar15 + 0x3c))) &&
     (*(int *)(*(int *)(param_1 + 0x3e0) + 0x4064) == 0)) {
    local_f4 = (float)*(double *)(iVar15 + 0x14);
    local_f8 = (float)*(double *)(iVar15 + 0xc);
    bVar24 = false;
    local_fc = (float)*(double *)(iVar15 + 4);
    FUN_004d1140(*(int *)(param_1 + 0x3e0),&local_f0,&local_bc);
    FUN_004ef6c0(&local_f0,&local_bc,&local_128);
    local_128 = local_128 - local_fc;
    local_124 = local_124 - local_f8;
    local_120 = local_120 - local_f4;
    if ((float)_DAT_0059eea8 <=
        local_124 * local_124 + local_120 * local_120 + local_128 * local_128) {
      iVar15 = *(int *)(param_1 + 0x2be);
      dVar4 = *(double *)(iVar15 + 4) - param_1[0x24];
      dVar5 = *(double *)(iVar15 + 0xc) - param_1[0x25];
      dVar6 = *(double *)(iVar15 + 0x14) - param_1[0x26];
      if ((*(int *)((int)param_1 + 0x11c) == 0) ||
         (_DAT_0059ee98 < dVar5 * dVar5 + dVar6 * dVar6 + dVar4 * dVar4)) {
        uVar14 = FUN_00403640(&local_fc,0);
        puVar13 = *(undefined4 **)(param_1 + 0x2be);
        *(undefined4 *)((int)param_1 + 0x11c) = uVar14;
        pdVar16 = param_1 + 0x24;
        for (iVar15 = 6; puVar13 = puVar13 + 1, iVar15 != 0; iVar15 = iVar15 + -1) {
          *(undefined4 *)pdVar16 = *puVar13;
          pdVar16 = (double *)((int)pdVar16 + 4);
        }
      }
    }
    else {
      bVar24 = true;
    }
    pfVar20 = *(float **)((int)param_1 + 0x11c);
    if (!bVar24) {
      bVar24 = false;
      fVar2 = (local_fc - *pfVar20) * pfVar20[8] +
              (local_f8 - pfVar20[1]) * pfVar20[9] + (local_f4 - pfVar20[2]) * pfVar20[10];
      if ((fVar2 < -pfVar20[0xb]) || (pfVar20[0xc] < fVar2)) {
        bVar24 = true;
        fVar26 = (float10)fpatan(-((float10)((float *)pfVar20[0x44])[2] - (float10)local_f4),
                                 (float10)*(float *)pfVar20[0x44] - (float10)local_fc);
      }
      else {
        local_14c = pfVar20[0x29];
        local_148 = pfVar20[0x2a];
        local_144 = pfVar20[0x2b];
        fVar26 = (float10)fpatan(-(float10)local_144,(float10)local_14c);
      }
      iVar15 = *(int *)(param_1 + 0x2be);
      fVar27 = (float10)fpatan(-((float10)*(double *)(iVar15 + 0x5c) * (float10)_DAT_0059e428),
                               (float10)*(double *)(iVar15 + 0x2c) * (float10)_DAT_0059e428);
      if (fVar26 - (float10)_DAT_0059e890 <= fVar27) {
        if (fVar26 + (float10)_DAT_0059e890 < fVar27) {
          fVar27 = fVar27 - (float10)_DAT_0059e888;
        }
      }
      else {
        fVar27 = fVar27 + (float10)_DAT_0059e888;
      }
      if (ABS((float)(fVar26 - fVar27)) <= (float)_DAT_0059edf8) {
        if (((bVar24) && (1 < local_12c._1_1_)) &&
           ((local_12a == '\0' || (*(char *)(*(int *)(param_1 + 0x3e0) + 0x344c) == '\0')))) {
          *(double *)((int)param_1 + 0xec) = *(double *)(iVar15 + 0x2c) * _DAT_0059ede0;
          *(double *)((int)param_1 + 0xf4) = *(double *)(iVar15 + 0x44) * _DAT_0059ede0;
          *(double *)((int)param_1 + 0xfc) = *(double *)(iVar15 + 0x5c) * _DAT_0059ede0;
        }
      }
      else {
        if ((local_12a != '\0') && (*(char *)(*(int *)(param_1 + 0x3e0) + 0x344c) != '\0')) {
          *(undefined4 *)(param_1 + 1) = 0;
          *(undefined4 *)((int)param_1 + 0xc) = 0;
          *(undefined4 *)(param_1 + 2) = 0;
          *(undefined4 *)((int)param_1 + 0x14) = 0x3ff00000;
        }
        dVar4 = (*(double *)(iVar15 + 0x24) * *(double *)(iVar15 + 0x7c) +
                *(double *)(iVar15 + 0x84) * *(double *)(iVar15 + 0x3c) +
                *(double *)(iVar15 + 0x8c) * *(double *)(iVar15 + 0x54)) * _DAT_0059edf0;
        if ((float)(fVar26 - fVar27) <= DAT_0059e440) {
          dVar4 = dVar4 - _DAT_0059ede8;
        }
        else {
          dVar4 = dVar4 + _DAT_0059ede8;
        }
        *(double *)((int)param_1 + 0x104) = dVar4 * *(double *)(iVar15 + 0x24);
        *(double *)((int)param_1 + 0x10c) = dVar4 * *(double *)(iVar15 + 0x3c);
        *(double *)((int)param_1 + 0x114) = dVar4 * *(double *)(iVar15 + 0x54);
      }
    }
  }
  uVar21 = local_118;
  if (((local_134._3_1_ != '\0') && (local_118 == 0)) &&
     ((3 < *(int *)((int)param_1 + 0x34) ||
      (_DAT_007ce8c8 + (float)param_1[7] < (float)param_1[0xc])))) {
    iVar15 = *(int *)(param_1 + 0x3de);
    if (iVar15 == -1) {
      if (local_119 != false) {
        fVar2 = *(float *)((int)param_1 + 0x1efc);
        *(undefined4 *)((int)param_1 + 0x1efc) = 0;
        if ((DAT_0059e440 < local_114) &&
           (fVar2 = local_114 * (float)param_1[0xd] + fVar2,
           *(float *)((int)param_1 + 0x1efc) = fVar2, (float)_DAT_0059e420 < fVar2)) {
          FUN_00447e00(0,4);
          *(undefined4 *)((int)param_1 + 0x1efc) = 0;
        }
      }
    }
    else if (iVar15 == 0) {
      fVar2 = *(float *)((int)param_1 + 0x1efc);
      *(undefined4 *)((int)param_1 + 0x1efc) = 0;
      if (bVar11) {
        if (*(int *)(param_1 + 0x3df) == 0) {
          if ((local_cc <= (float)_DAT_0059e430) ||
             (iVar15 = *(int *)(param_1 + 0x2be),
             _DAT_0059e420 <=
             *(double *)(iVar15 + 0x74) * *(double *)(iVar15 + 0x74) +
             *(double *)(iVar15 + 0x6c) * *(double *)(iVar15 + 0x6c) +
             *(double *)(iVar15 + 100) * *(double *)(iVar15 + 100))) goto LAB_0044647c;
          fVar2 = local_cc * (float)param_1[0xd] + fVar2;
          *(float *)((int)param_1 + 0x1efc) = fVar2;
          if ((float)_DAT_0059e420 < fVar2) {
            FUN_00447e00(0xffffffff,4);
            *(undefined4 *)((int)param_1 + 0x1efc) = 0;
          }
        }
      }
      else {
LAB_0044647c:
        if (((*(int *)(param_1 + 0x3df) == 0) &&
            (((float)_DAT_0059eb28 <= local_114 &&
             (*(double *)((int)param_1 + 0x1c8c) < *(double *)((int)param_1 + 0x1c5c))))) &&
           (local_134._3_1_ != '\x02')) {
          FUN_00447e00(1,4);
        }
      }
    }
    else if (*(int *)(param_1 + 0x3df) == 0) {
      if (*(double *)((int)param_1 + 0x1c5c) <= *(double *)((int)param_1 + 0x1c94)) {
        if (local_134._3_1_ != '\x01') {
          if (iVar15 != 1) {
            FUN_0059dab7();
            return;
          }
          if ((local_114 < (float)_DAT_0059eb28) &&
             (*(double *)((int)param_1 + 0x1c5c) < *(double *)((int)param_1 + 0x1c8c))) {
            FUN_00447e00(0,4);
          }
        }
      }
      else if ((((iVar15 < *(int *)((int)param_1 + 0x1eac)) && (*(int *)(param_1 + 0x3a6) != 1)) &&
               (local_134._3_1_ != '\x02')) &&
              (cVar12 = FUN_00443af0(*(undefined4 *)(param_1 + 0x28),
                                     *(undefined4 *)((int)param_1 + 0x144)), cVar12 != '\0')) {
        FUN_00447e00(extraout_EDX + 1,4);
      }
    }
  }
  if ((local_80 < -1) || (local_80 == *(int *)(param_1 + 6))) {
    if (uVar21 != 0) {
      if ((DAT_007cc1b8 == 0) && (DAT_007cc1bc == 0x59)) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      if (uVar21 == 1) {
        iVar15 = *(int *)((int)param_1 + 0x1ef4);
        if (((!bVar11) || (-1 < iVar15)) && (iVar15 < *(int *)((int)param_1 + 0x1eac))) {
          iVar15 = iVar15 + 1;
LAB_0044662b:
          FUN_00447e00(iVar15,0);
        }
      }
      else if (uVar21 == 0xffffffff) {
        iVar15 = *(int *)((int)param_1 + 0x1ef4);
        if (bVar11) {
          if ((-1 < iVar15) && (iVar15 != 1)) {
LAB_0044662a:
            iVar15 = iVar15 + -1;
            goto LAB_0044662b;
          }
        }
        else if (-1 < iVar15) goto LAB_0044662a;
      }
    }
  }
  else {
    FUN_00447e00(local_80,1);
    *(int *)(param_1 + 6) = local_80;
  }
  if (local_159 != false) {
    FUN_00447e00(0,1);
    *(undefined4 *)(param_1 + 6) = 0;
  }
  **(double **)(param_1 + 0x2c6) =
       *(double *)((int)param_1 + 0x163c) * *param_1 + *(double *)((int)param_1 + 0x1634);
  **(double **)((int)param_1 + 0x1644) = param_1[0x2ca] * *param_1 + param_1[0x2c9];
  *(undefined4 *)(param_1 + 0x2e) = 0;
  *(undefined4 *)((int)param_1 + 0x174) = 0;
  if (((char)local_134 != '\0') && (local_11a == '\0')) {
    iVar15 = *(int *)((int)param_1 + 0x1e14);
    if (iVar15 == 0) {
      local_158 = (*(double *)((int)param_1 + 0x10fc) + param_1[0x193]) * _DAT_0059e880;
    }
    else if (iVar15 == 1) {
      local_158 = (*(double *)((int)param_1 + 0x10fc) + param_1[0x193] +
                   *(double *)((int)param_1 + 0x834) + param_1[0x7a]) * _DAT_0059eb50;
    }
    else if (iVar15 == 2) {
      local_158 = (*(double *)((int)param_1 + 0x834) + param_1[0x7a]) * _DAT_0059e880;
    }
    dVar4 = local_158 * param_1[0x2a] + param_1[0x2b];
    dVar5 = _DAT_0059e430;
    if ((_DAT_0059e430 <= dVar4) && (dVar5 = dVar4, _DAT_0059e420 < dVar4)) {
      dVar5 = _DAT_0059e420;
    }
    local_158 = param_1[1];
    if ((char)local_134 == '\x01') {
      dVar4 = param_1[0x2c];
    }
    else {
      dVar4 = param_1[0x2d];
    }
    param_1[1] = ((dVar5 - _DAT_0059e420) * dVar4 + _DAT_0059e420) * param_1[1];
    param_1[0x2e] = local_158 - param_1[1];
  }
  if (*(int *)(param_1 + 0x3a6) == 0) {
    if ((char)local_130 != '\0') {
      if (*(double *)((int)param_1 + 0x1c84) <= *(double *)((int)param_1 + 0x1c5c)) {
        if (*(double *)((int)param_1 + 0x1c5c) < *(double *)((int)param_1 + 0x1c8c)) {
          fVar2 = _DAT_0059e43c - local_114;
          dVar4 = (*(double *)((int)param_1 + 0x1c8c) - *(double *)((int)param_1 + 0x1c5c)) /
                  (*(double *)((int)param_1 + 0x1c8c) - *(double *)((int)param_1 + 0x1c84));
          if (fVar2 <= (float)dVar4) {
            fVar2 = (float)dVar4;
          }
          param_1[4] = (double)fVar2;
          goto LAB_00446a0f;
        }
        *(undefined4 *)((int)param_1 + 0x24) = 0;
      }
      else {
        *(undefined4 *)((int)param_1 + 0x24) = 0x3ff00000;
      }
      *(undefined4 *)(param_1 + 4) = 0;
    }
LAB_00446a0f:
    if (_DAT_0059eba0 <= param_1[4]) {
      if (param_1[4] <= _DAT_0059eb38) {
        param_1[4] = (param_1[4] - _DAT_0059eba0) * _DAT_0059e930;
      }
      else {
        *(undefined4 *)(param_1 + 4) = 0;
        *(undefined4 *)((int)param_1 + 0x24) = 0x3ff00000;
      }
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)((int)param_1 + 0x24) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0;
    if (*(int *)(param_1 + 0x3a6) == 1) {
      *(undefined4 *)((int)param_1 + 0x24) = 0x3ff00000;
      if (*(double *)((int)param_1 + 0x1d3c) < *(double *)((int)param_1 + 0x1c5c)) {
        if (*(double *)((int)param_1 + 0x1d44) <= *(double *)((int)param_1 + 0x1c5c)) {
          *(undefined4 *)(param_1 + 1) = 0;
          *(undefined4 *)((int)param_1 + 0xc) = 0;
        }
        else {
          dVar4 = (*(double *)((int)param_1 + 0x1d44) - *(double *)((int)param_1 + 0x1c5c)) /
                  (*(double *)((int)param_1 + 0x1d44) - *(double *)((int)param_1 + 0x1d3c));
          if (dVar4 < param_1[1]) {
            param_1[1] = dVar4;
          }
        }
      }
    }
    else {
      *(undefined4 *)((int)param_1 + 0x24) = 0;
      if ((*(int *)(param_1 + 0x3de) == 1) && (param_1[0x3c7] < *(double *)((int)param_1 + 0x1c5c)))
      {
        iVar15 = *(int *)((int)param_1 + 0x1e14);
        if (iVar15 == 0) {
          local_158 = (param_1[0x1ac] - param_1[0x1cf]) * param_1[0x192] +
                      (*(double *)((int)param_1 + 0x11c4) - *(double *)((int)param_1 + 0x12dc)) *
                      *(double *)((int)param_1 + 0x10f4);
        }
        else if (iVar15 == 1) {
          local_158 = (param_1[0x93] - param_1[0xb6]) * param_1[0x79] +
                      (*(double *)((int)param_1 + 0x8fc) - *(double *)((int)param_1 + 0xa14)) *
                      *(double *)((int)param_1 + 0x82c) +
                      (param_1[0x1ac] - param_1[0x1cf]) * param_1[0x192] +
                      (*(double *)((int)param_1 + 0x11c4) - *(double *)((int)param_1 + 0x12dc)) *
                      *(double *)((int)param_1 + 0x10f4);
        }
        else if (iVar15 == 2) {
          local_158 = (param_1[0x93] - param_1[0xb6]) * param_1[0x79] +
                      (*(double *)((int)param_1 + 0x8fc) - *(double *)((int)param_1 + 0xa14)) *
                      *(double *)((int)param_1 + 0x82c);
        }
        param_1[4] = _DAT_0059e420 -
                     ((*(double *)((int)param_1 + 0x1d34) / param_1[0x3d7]) * local_158) /
                     param_1[0x3cb];
        if (_DAT_0059e430 <= param_1[4]) {
          if (_DAT_0059e420 < param_1[4]) {
            *(undefined4 *)((int)param_1 + 0x24) = 0x3ff00000;
            goto LAB_0044691a;
          }
        }
        else {
          *(undefined4 *)((int)param_1 + 0x24) = 0;
LAB_0044691a:
          *(undefined4 *)(param_1 + 4) = 0;
        }
        if (*(double *)((int)param_1 + 0x1d3c) < *(double *)((int)param_1 + 0x1c5c)) {
          if (*(double *)((int)param_1 + 0x1d44) <= *(double *)((int)param_1 + 0x1c5c)) {
            *(undefined4 *)(param_1 + 1) = 0;
            *(undefined4 *)((int)param_1 + 0xc) = 0;
          }
          else {
            dVar4 = (*(double *)((int)param_1 + 0x1d44) - *(double *)((int)param_1 + 0x1c5c)) /
                    (*(double *)((int)param_1 + 0x1d44) - *(double *)((int)param_1 + 0x1d3c));
            if (dVar4 < param_1[1]) {
              param_1[1] = dVar4;
            }
          }
        }
      }
      if (*(double *)((int)param_1 + 0x1c5c) < *(double *)((int)param_1 + 0x1c84)) {
        *(undefined4 *)(param_1 + 4) = 0;
        *(undefined4 *)((int)param_1 + 0x24) = 0x3ff00000;
      }
    }
  }
  if (*(int *)(param_1 + 0x1a) != 0) {
    if (*(int *)(param_1 + 0x1a) == 1) {
      if ((*(int *)(param_1 + 0x3de) != 0) && (*(int *)(param_1 + 0x3a6) != 1)) {
        *(undefined4 *)(param_1 + 0x1a) = 0;
        goto LAB_00446a89;
      }
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)((int)param_1 + 0x24) = 0x3ff00000;
    }
    *(undefined4 *)(param_1 + 2) = 0;
    *(undefined4 *)((int)param_1 + 0x14) = 0x3ff00000;
  }
LAB_00446a89:
  dStack_d8 = *(double *)((int)param_1 + 0x155c) * param_1[2];
  local_e8 = (_DAT_0059e420 - *(double *)((int)param_1 + 0x1564)) * dStack_d8;
  local_f0 = local_e8;
  dStack_d8 = dStack_d8 * *(double *)((int)param_1 + 0x1564);
  local_e0 = dStack_d8;
  if (local_134._2_1_ != '\0') {
    if (local_134._2_1_ == '\x01') {
      local_168 = 0.45;
      local_158 = 0.15;
      dVar4 = _DAT_0059edd8;
    }
    else {
      local_168 = 0.9;
      local_158 = 0.3;
      dVar4 = _DAT_0059ea68;
    }
    iVar15 = *(int *)(param_1 + 0x2be);
    local_bc = *(double *)(iVar15 + 0x1c) * *(double *)(iVar15 + 100) +
               *(double *)(iVar15 + 0x34) * *(double *)(iVar15 + 0x6c) +
               *(double *)(iVar15 + 0x4c) * *(double *)(iVar15 + 0x74);
    local_ac = *(double *)(iVar15 + 0x44) * *(double *)(iVar15 + 0x6c) +
               *(double *)(iVar15 + 0x5c) * *(double *)(iVar15 + 0x74) +
               *(double *)(iVar15 + 0x2c) * *(double *)(iVar15 + 100);
    if ((_DAT_0059eea8 < local_bc * local_bc + local_ac * local_ac) && (local_ac < _DAT_0059e430)) {
      fVar26 = (float10)fpatan(-(float10)local_bc,-(float10)local_ac);
      fVar26 = (fVar26 - (float10)*(double *)((int)param_1 + 0x94) * (float10)*param_1) -
               ((float10)*(double *)(iVar15 + 0x24) * (float10)*(double *)(iVar15 + 0x7c) +
               (float10)*(double *)(iVar15 + 0x3c) * (float10)*(double *)(iVar15 + 0x84) +
               (float10)*(double *)(iVar15 + 0x54) * (float10)*(double *)(iVar15 + 0x8c)) *
               (float10)_DAT_0059eba0;
      if (fVar26 <= (float10)_DAT_0059e430) {
        fVar26 = fVar26 + (float10)dVar4;
        if ((float10)_DAT_0059e430 < fVar26) goto LAB_00446c1f;
      }
      else {
        fVar26 = fVar26 - (float10)dVar4;
        if (fVar26 < (float10)_DAT_0059e430) goto LAB_00446c1f;
      }
      if (fVar26 != (float10)_DAT_0059e430) {
        fVar26 = fVar26 * (float10)local_168;
        if (fVar26 <= (float10)local_158) {
          if (fVar26 < (float10)-local_158) {
            fVar26 = (float10)-local_158;
          }
        }
        else {
          fVar26 = (float10)local_158;
        }
        iVar15 = 0;
        local_f0 = (double)((float10)local_e8 - fVar26);
        local_e8 = (double)((float10)local_e8 + fVar26);
        local_e0 = (double)((float10)dStack_d8 - fVar26);
        dStack_d8 = (double)((float10)dStack_d8 + fVar26);
        do {
          if (_DAT_0059e430 <= (double)(&local_f0)[iVar15]) {
            if (_DAT_0059e420 < (double)(&local_f0)[iVar15]) {
              *(undefined4 *)((int)&local_f0 + iVar15 * 8 + 4) = 0x3ff00000;
              goto LAB_00446d7e;
            }
          }
          else {
            *(undefined4 *)((int)&local_f0 + iVar15 * 8 + 4) = 0;
LAB_00446d7e:
            *(undefined4 *)(&local_f0 + iVar15) = 0;
          }
          iVar15 = iVar15 + 1;
        } while (iVar15 < 4);
        fVar26 = ABS(fVar26) * (float10)_DAT_0059edd0;
        if ((float10)_DAT_0059edc8 < fVar26) {
          fVar26 = (float10)_DAT_0059edc8;
        }
        if ((float10)param_1[1] < fVar26) {
          param_1[1] = (double)fVar26;
        }
      }
    }
  }
LAB_00446c1f:
  fVar2 = local_70 * (float)*(double *)((int)param_1 + 0x1554);
  local_e0 = (double)((float)local_e0 + fVar2);
  dStack_d8 = (double)((float)dStack_d8 + fVar2);
  if (local_134._1_1_ != '\0') {
    if (*(char *)(param_1 + 0x2f) == '\0') {
      pdVar16 = param_1 + 0x7a;
      iVar15 = 4;
      dVar4 = _DAT_0059e420;
      do {
        if (*pdVar16 < dVar4) {
          dVar4 = *pdVar16;
        }
        pdVar16 = (double *)((int)pdVar16 + 0x464);
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      dVar5 = *(double *)((int)param_1 + 0x17c);
      dVar6 = *(double *)((int)param_1 + 0x184);
      if (local_134._1_1_ == '\x01') {
        dVar7 = *(double *)((int)param_1 + 0x18c);
      }
      else {
        dVar7 = *(double *)((int)param_1 + 0x194);
      }
      iVar15 = 0;
      do {
        iVar15 = iVar15 + 1;
        *(double *)(&local_f8 + iVar15 * 2) =
             (((dVar4 * dVar5 + dVar6) - _DAT_0059e420) * dVar7 + _DAT_0059e420) *
             *(double *)(&local_f8 + iVar15 * 2);
      } while (iVar15 < 4);
    }
    else {
      iVar15 = 0;
      pdVar16 = param_1 + 0x7a;
      if (local_134._1_1_ == '\x01') {
        do {
          dVar4 = *pdVar16 * *(double *)((int)param_1 + 0x17c) + *(double *)((int)param_1 + 0x184);
          dVar5 = _DAT_0059e430;
          if ((_DAT_0059e430 <= dVar4) && (dVar5 = dVar4, _DAT_0059e420 < dVar4)) {
            dVar5 = _DAT_0059e420;
          }
          iVar15 = iVar15 + 1;
          pdVar16 = (double *)((int)pdVar16 + 0x464);
          *(double *)(&local_f8 + iVar15 * 2) =
               ((dVar5 - _DAT_0059e420) * *(double *)((int)param_1 + 0x18c) + _DAT_0059e420) *
               *(double *)(&local_f8 + iVar15 * 2);
        } while (iVar15 < 4);
      }
      else {
        do {
          dVar4 = *pdVar16 * *(double *)((int)param_1 + 0x17c) + *(double *)((int)param_1 + 0x184);
          dVar5 = _DAT_0059e430;
          if ((_DAT_0059e430 <= dVar4) && (dVar5 = dVar4, _DAT_0059e420 < dVar4)) {
            dVar5 = _DAT_0059e420;
          }
          iVar15 = iVar15 + 1;
          pdVar16 = (double *)((int)pdVar16 + 0x464);
          *(double *)(&local_f8 + iVar15 * 2) =
               ((dVar5 - _DAT_0059e420) * *(double *)((int)param_1 + 0x194) + _DAT_0059e420) *
               *(double *)(&local_f8 + iVar15 * 2);
        } while (iVar15 < 4);
      }
    }
  }
  iVar15 = *(int *)(param_1 + 0x3e0);
  if ((((*(int *)(iVar15 + 0x834) == 0) || (*(char *)(iVar15 + 0x874) == '\0')) ||
      (*(int *)(iVar15 + 0x95c) == 0)) || (*(char *)(iVar15 + 0x99c) == '\0')) {
    local_f0 = 0.0;
    local_e8 = 0.0;
  }
  if (((*(int *)(iVar15 + 0xa84) == 0) || (*(char *)(iVar15 + 0xac4) == '\0')) ||
     ((*(int *)(iVar15 + 0xbac) == 0 || (*(char *)(iVar15 + 0xbec) == '\0')))) {
    local_e0 = 0.0;
    dStack_d8 = 0.0;
  }
  iVar15 = 0;
  pdVar16 = param_1 + 0xcd;
  do {
    pdVar19 = (double *)(&local_f0 + iVar15);
    iVar15 = iVar15 + 1;
    pdVar16[-0x60] = *pdVar19 * pdVar16[1] + *pdVar16;
    pdVar16 = (double *)((int)pdVar16 + 0x464);
  } while (iVar15 < 4);
  FUN_00443b70(local_134 >> 0x18,local_130 & 0xff);
  return;
}


