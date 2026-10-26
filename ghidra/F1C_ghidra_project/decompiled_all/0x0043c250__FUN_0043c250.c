// Function: FUN_0043c250 @ 0043c250
// Strings:  [D:\dev\F1_1999_2002\Source\hdvehicle.cpp, *.hdv file references unknown tire compound "%s"]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043c250(int param_1,int param_2,int param_3)

{
  double dVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  undefined1 uVar6;
  double *pdVar7;
  void *pvVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  char extraout_DL;
  int extraout_EDX;
  double *pdVar12;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 *puVar13;
  double *pdVar14;
  float10 fVar15;
  undefined8 local_d0;
  int local_c8;
  undefined8 local_c0;
  double *local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  undefined8 local_98;
  undefined8 local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  undefined4 local_38 [6];
  undefined8 local_20;
  double local_18;
  double local_10;
  
  pdVar7 = (double *)(param_2 + 0x138);
  pdVar12 = (double *)(param_3 + 0x1468);
  local_98 = (double)CONCAT44(local_98._4_4_,pdVar7);
  local_90 = (double)CONCAT44(local_90._4_4_,pdVar12);
  local_b8 = (double *)0x4;
  puVar9 = (undefined4 *)(param_1 + 0x340);
  do {
    puVar9[-2] = 0;
    puVar9[-1] = 0;
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[2] = 0;
    puVar9[3] = 0;
    puVar9[4] = 0;
    puVar9[5] = 0;
    puVar9[10] = 0;
    puVar9[0xb] = 0;
    puVar9[0x24] = 0;
    puVar9[0x26] = 0;
    puVar9[0x25] = 0x3ff00000;
    puVar9[0x27] = 0x3ff00000;
    puVar9[0x12] = 0xffffffff;
    puVar9[0x13] = 0xffefffff;
    puVar9[0x1a] = 0xffffffff;
    puVar9[0x1b] = 0xffefffff;
    puVar9[6] = *(undefined4 *)(pdVar12 + -1);
    puVar9[7] = *(undefined4 *)((int)pdVar12 + -4);
    if (*(char *)(param_3 + 0x549) == '\0') {
      local_c0 = 1.0;
    }
    else {
      local_c0 = _DAT_0059e420 / *pdVar12;
    }
    local_88 = local_c0 * *(double *)(param_3 + 0x538);
    dVar1 = *(double *)(param_3 + 0x540);
    *(undefined1 *)(puVar9 + 0x44) = 0;
    *(undefined1 *)(puVar9 + 0x53) = 0;
    FUN_004364a0((undefined4)local_c0,local_c0._4_4_,local_88,local_c0 * dVar1,pdVar12 + -0x13,
                 (double)*(int *)((int)pdVar7 + 0x8c) * pdVar7[0x10] + pdVar7[0xf],
                 (double)*(int *)((int)pdVar7 + 0x4c) * pdVar7[8] + pdVar7[7],
                 (double)*(int *)((int)pdVar7 + 0x10c) * pdVar7[0x20] + pdVar7[0x1f],
                 (double)*(int *)((int)pdVar7 + 0xcc) * pdVar7[0x18] + pdVar7[0x17],
                 (double)*(int *)((int)pdVar7 + 0x18c) * pdVar7[0x30] + pdVar7[0x2f],
                 (double)*(int *)((int)pdVar7 + 0x14c) * pdVar7[0x28] + pdVar7[0x27],
                 (double)*(int *)((int)pdVar7 + 0xc) * *pdVar7 + pdVar7[-1],
                 *(undefined4 *)(pdVar12 + 1),*(undefined4 *)((int)pdVar12 + 0xc));
    puVar9[0xca] = *(undefined4 *)(pdVar12 + 2);
    puVar9[0xcb] = *(undefined4 *)((int)pdVar12 + 0x14);
    puVar9[0xcc] = *(undefined4 *)(pdVar12 + 3);
    puVar9[0xcd] = *(undefined4 *)((int)pdVar12 + 0x1c);
    puVar9[0xce] = *(undefined4 *)(pdVar12 + 3);
    puVar9[0xcf] = *(undefined4 *)((int)pdVar12 + 0x1c);
    dVar1 = pdVar12[5];
    *(double *)(puVar9 + 0xd0) = dVar1;
    *(double *)(puVar9 + 0xd2) = _DAT_0059e890 / dVar1;
    dVar1 = (double)(*(int *)(extraout_EDX + 0x1c8) + -1) * *(double *)(extraout_EDX + 0x1c0) +
            *(double *)(extraout_EDX + 0x1b8);
    *(double *)(puVar9 + 0xd4) = (double)(_DAT_008afef0 + (float)_DAT_0059eac8);
    puVar9[0xd6] = *(undefined4 *)(pdVar12 + 4);
    puVar9[0xd7] = *(undefined4 *)((int)pdVar12 + 0x24);
    *(double *)(puVar9 + 0xd8) = dVar1 * pdVar12[6];
    *(double *)(puVar9 + 0xda) = dVar1 * pdVar12[7];
    *(double *)(puVar9 + 0xdc) =
         (((double)*(int *)(param_2 + 0x1344) * *(double *)(param_2 + 0x1338) +
          *(double *)(param_2 + 0x1330)) * pdVar12[9] + pdVar12[8]) * dVar1;
    *(double *)(puVar9 + 0xde) =
         (double)*(int *)(extraout_EDX + 0x1cc) * *(double *)(extraout_EDX + 0x1c0) +
         *(double *)(extraout_EDX + 0x1b8);
    *(double *)(puVar9 + 0xe2) =
         pdVar12[0xb] /
         (*(double *)(puVar9 + 0xd6) * *(double *)(puVar9 + 0xd6) * *(double *)(puVar9 + 0xd6));
    fVar15 = (float10)FUN_004b3ce0();
    *(double *)(puVar9 + 0xe4) = (double)(fVar15 * (float10)pdVar12[0xd] + (float10)pdVar12[0xc]);
    if (*(double *)(puVar9 + 0xde) * _DAT_0059eb20 <= *(double *)(puVar9 + 0xe4)) {
      if (*(double *)(puVar9 + 0xde) * _DAT_0059ec40 < *(double *)(puVar9 + 0xe4)) {
        *(double *)(puVar9 + 0xe4) = *(double *)(puVar9 + 0xde) * _DAT_0059ec40;
      }
    }
    else {
      *(double *)(puVar9 + 0xe4) = *(double *)(puVar9 + 0xde) * _DAT_0059eb20;
    }
    dVar1 = pdVar12[10];
    *(double *)(puVar9 + 0xe0) = dVar1;
    puVar13 = (undefined4 *)(puVar9[0x2a] + 0xbc);
    pdVar7 = &local_b0;
    for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
      *(undefined4 *)pdVar7 = *puVar13;
      puVar13 = puVar13 + 1;
      pdVar7 = (double *)((int)pdVar7 + 4);
    }
    local_b0 = dVar1 * *(double *)(puVar9 + 0xde) + *(double *)(puVar9 + 6);
    FUN_005697a0();
    puVar9[0x6c] = 0;
    puVar9[0x6d] = 0;
    puVar9[0x6f] = 0;
    dVar1 = _DAT_0059e420 /
            (*(double *)(puVar9 + 0xe0) * *(double *)(puVar9 + 0xde) + *(double *)(puVar9 + 6));
    puVar9[0x70] = 0;
    iVar10 = (int)(double *)local_98;
    puVar9[0x6e] = 0x3ff00000;
    pdVar7 = (double *)((int)(double *)local_98 + 0x2c0);
    local_98 = (double)CONCAT44(local_98._4_4_,pdVar7);
    pdVar12 = (double *)((int)(undefined4 *)local_90 + 0x108);
    local_90 = (double)CONCAT44(local_90._4_4_,pdVar12);
    *(double *)(puVar9 + 8) = dVar1;
    local_b8 = (double *)((int)local_b8 + -1);
    *(double *)(puVar9 + 0xb2) =
         (double)*(int *)(iVar10 + -0x34) * *(double *)(iVar10 + -0x40) +
         *(double *)(iVar10 + -0x48);
    puVar9 = puVar9 + 0x119;
  } while (local_b8 != (double *)0x0);
  iVar10 = FUN_004d7880();
  *(int *)(param_1 + 0x1458) = iVar10;
  if (((iVar10 == 0) && (DAT_007c569c != 5)) && (cVar5 = FUN_004d7a50(), cVar5 != '\0')) {
    FUN_004d7aa0();
  }
  *(undefined4 *)(param_1 + 0x145c) = *(undefined4 *)(param_2 + 0xbc4);
  local_c8 = 0;
  do {
    FUN_0043da10();
    local_c8 = local_c8 + 1;
  } while (local_c8 < 4);
  if (*(char *)(param_3 + 0x549) == '\0') {
    local_c0 = 1.0;
  }
  else {
    local_c0 = _DAT_0059e880 / *(double *)(param_3 + 0x1468) +
               _DAT_0059e880 / *(double *)(param_3 + 0x1570);
  }
  dVar2 = local_c0 * *(double *)(param_3 + 0x538);
  dVar1 = *(double *)(param_3 + 0x540);
  fVar15 = (float10)FUN_004f6850((double)*(int *)(param_2 + 0xd04) * *(double *)(param_2 + 0xcf8) +
                                 *(double *)(param_2 + 0xcf0));
  *(double *)(param_1 + 0x1438) = (double)(fVar15 * (float10)dVar2 * (float10)_DAT_0059e880);
  if (*(char *)(param_3 + 0x549) == '\0') {
    local_d0 = 1.0;
  }
  else {
    local_d0 = _DAT_0059e880 / *(double *)(param_3 + 0x1678) +
               _DAT_0059e880 / *(double *)(param_3 + 0x1780);
  }
  local_98 = local_d0 * *(double *)(param_3 + 0x538);
  local_20 = local_d0 * *(double *)(param_3 + 0x540);
  fVar15 = (float10)FUN_004f6880((double)*(int *)(param_2 + 0xd44) * *(double *)(param_2 + 0xd38) +
                                 *(double *)(param_2 + 0xd30));
  *(double *)(param_1 + 0x1440) = (double)(fVar15 * (float10)local_98 * (float10)_DAT_0059e880);
  local_90 = ((double)*(int *)(param_2 + 0x404) * *(double *)(param_2 + 0x3f8) +
              *(double *)(param_2 + 0x3f0) +
             (double)*(int *)(param_2 + 0x144) * *(double *)(param_2 + 0x138) +
             *(double *)(param_2 + 0x130)) * _DAT_0059e880;
  local_88 = (*(double *)(param_3 + 0x1578) + *(double *)(param_3 + 0x1470)) * _DAT_0059e880;
  FUN_004364a0((undefined4)local_c0,local_c0._4_4_,dVar2,local_c0 * dVar1,param_3 + 0x5a0,
               (double)*(int *)(param_2 + 0xfc4) * *(double *)(param_2 + 0xfb8) +
               *(double *)(param_2 + 0xfb0),
               (double)*(int *)(param_2 + 0xf84) * *(double *)(param_2 + 0xf78) +
               *(double *)(param_2 + 0xf70),
               (double)*(int *)(param_2 + 0x1044) * *(double *)(param_2 + 0x1038) +
               *(double *)(param_2 + 0x1030),
               (double)*(int *)(param_2 + 0x1004) * *(double *)(param_2 + 0xff8) +
               *(double *)(param_2 + 0xff0),
               (double)*(int *)(param_2 + 0x10c4) * *(double *)(param_2 + 0x10b8) +
               *(double *)(param_2 + 0x10b0),
               (double)*(int *)(param_2 + 0x1084) * *(double *)(param_2 + 0x1078) +
               *(double *)(param_2 + 0x1070),local_90,local_88);
  local_88 = (*(double *)(param_3 + 0x1788) + *(double *)(param_3 + 0x1680)) * _DAT_0059e880;
  cVar5 = FUN_004364a0((undefined4)local_d0,local_d0._4_4_,(double *)local_98,local_98._4_4_,
                       (undefined4)local_20,local_20._4_4_,param_3 + 0x5e0,
                       (double)*(int *)(param_2 + 0x1144) * *(double *)(param_2 + 0x1138) +
                       *(double *)(param_2 + 0x1130),
                       (double)*(int *)(param_2 + 0x1104) * *(double *)(param_2 + 0x10f8) +
                       *(double *)(param_2 + 0x10f0),
                       (double)*(int *)(param_2 + 0x11c4) * *(double *)(param_2 + 0x11b8) +
                       *(double *)(param_2 + 0x11b0),
                       (double)*(int *)(param_2 + 0x1184) * *(double *)(param_2 + 0x1178) +
                       *(double *)(param_2 + 0x1170),
                       (double)*(int *)(param_2 + 0x1244) * *(double *)(param_2 + 0x1238) +
                       *(double *)(param_2 + 0x1230),
                       (double)*(int *)(param_2 + 0x1204) * *(double *)(param_2 + 0x11f8) +
                       *(double *)(param_2 + 0x11f0),
                       ((double)*(int *)(param_2 + 0x6c4) * *(double *)(param_2 + 0x6b8) +
                        *(double *)(param_2 + 0x6b0) +
                       (double)*(int *)(param_2 + 0x984) * *(double *)(param_2 + 0x978) +
                       *(double *)(param_2 + 0x970)) * _DAT_0059e880,local_88);
  if ((extraout_DL == '\0') && (cVar5 == '\0')) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
  }
  *(undefined1 *)(param_1 + 0x1460) = uVar6;
  *(bool *)(param_1 + 0x70) = DAT_007ce254 == '\0';
  iVar10 = *(int *)(param_1 + 1000);
  *(double *)(param_1 + 0x1554) =
       (double)*(int *)(param_2 + 0x1404) * *(double *)(param_2 + 0x13f8) +
       *(double *)(param_2 + 0x13f0);
  *(double *)(param_1 + 0x155c) =
       (double)*(int *)(param_2 + 0x13c4) * *(double *)(param_2 + 0x13b8) +
       *(double *)(param_2 + 0x13b0);
  puVar9 = (undefined4 *)(param_2 + 0x1370);
  pdVar7 = (double *)(param_1 + 0x156c);
  for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
    *(undefined4 *)pdVar7 = *puVar9;
    puVar9 = puVar9 + 1;
    pdVar7 = (double *)((int)pdVar7 + 4);
  }
  iVar11 = *(int *)(param_1 + 0x84c);
  *(undefined4 *)(param_1 + 0xd0) = 1;
  *(undefined4 *)(param_1 + 0x1658) = 0;
  *(undefined4 *)(param_1 + 0x165c) = 0;
  *(double *)(param_1 + 0x1564) =
       (double)*(int *)(param_1 + 0x1580) * *(double *)(param_1 + 0x1574) +
       *(double *)(param_1 + 0x156c);
  local_a0 = *(double *)(iVar10 + 0x14) + *(double *)(iVar11 + 0x14);
  local_68 = (*(double *)(iVar11 + 4) + *(double *)(iVar10 + 4)) * _DAT_0059e880;
  local_60 = (*(double *)(iVar10 + 0xc) + *(double *)(iVar11 + 0xc)) * _DAT_0059e880;
  local_58 = local_a0 * _DAT_0059e880;
  dVar1 = *(double *)(param_3 + 0x60);
  pdVar7 = &local_68;
  pdVar12 = &local_50;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined4 *)pdVar12 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    pdVar12 = (double *)((int)pdVar12 + 4);
  }
  dVar1 = -dVar1;
  local_48 = dVar1;
  iVar10 = *(int *)(param_1 + 0x1114);
  iVar11 = *(int *)(param_1 + 0xcb0);
  local_a0 = *(double *)(iVar11 + 0x14) + *(double *)(iVar10 + 0x14);
  local_68 = (*(double *)(iVar10 + 4) + *(double *)(iVar11 + 4)) * _DAT_0059e880;
  local_60 = (*(double *)(iVar11 + 0xc) + *(double *)(iVar10 + 0xc)) * _DAT_0059e880;
  local_58 = local_a0 * _DAT_0059e880;
  pdVar7 = &local_68;
  pdVar12 = &local_80;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined4 *)pdVar12 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    pdVar12 = (double *)((int)pdVar12 + 4);
  }
  local_78 = dVar1;
  local_90._0_4_ = (undefined4 *)(param_1 + 0x1668);
  iVar10 = 0;
  local_98._0_4_ = (double *)(param_3 + 0x1458);
  pdVar7 = (double *)(param_1 + 0x16f0);
  local_b8 = (double *)(param_2 + 0x138);
  do {
    if ((iVar10 == 0) || (pdVar12 = &local_80, iVar10 == 1)) {
      pdVar12 = &local_50;
    }
    pdVar14 = &local_68;
    for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
      *(undefined4 *)pdVar14 = *(undefined4 *)pdVar12;
      pdVar12 = (double *)((int)pdVar12 + 4);
      pdVar14 = (double *)((int)pdVar14 + 4);
    }
    local_b0 = local_68 + ((double *)local_98)[-2];
    local_a8 = local_60 + ((double *)local_98)[-1];
    local_a0 = local_58 + *(double *)local_98;
    pdVar12 = &local_b0;
    puVar9 = (undefined4 *)local_90 + -2;
    for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar9 = *(undefined4 *)pdVar12;
      pdVar12 = (double *)((int)pdVar12 + 4);
      puVar9 = puVar9 + 1;
    }
    *(undefined4 *)(pdVar7 + -6) = *(undefined4 *)local_90;
    *(undefined4 *)((int)pdVar7 + -0x2c) = ((undefined4 *)local_90)[1];
    iVar10 = iVar10 + 1;
    dVar2 = (double)*(int *)((int)local_b8 + 0xc) * *local_b8 + local_b8[-1];
    *pdVar7 = dVar2;
    pdVar7[7] = dVar2;
    local_98._0_4_ = (double *)local_98 + 0x21;
    local_90._0_4_ = (undefined4 *)local_90 + 6;
    pdVar7 = pdVar7 + 1;
    local_b8 = local_b8 + 0x58;
  } while (iVar10 < 4);
  *(undefined1 *)(param_1 + 0x1718) = 0;
  *(undefined4 *)(param_1 + 0x171c) = 0;
  *(undefined4 *)(param_1 + 0x1720) = 0;
  *(double *)(param_1 + 0x1710) = ABS(*(double *)(param_1 + 0x1670) - *(double *)(param_1 + 0x16a0))
  ;
  *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_3 + 0x620);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_3 + 0x624);
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_3 + 0x628);
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_3 + 0x62c);
  *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_3 + 0x630);
  *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_3 + 0x634);
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_3 + 0x638);
  *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_3 + 0x63c);
  *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_3 + 0x640);
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_3 + 0x644);
  if (_DAT_0059e430 <= *(double *)(param_1 + 0x160)) {
    if (_DAT_0059e420 < *(double *)(param_1 + 0x160)) {
      *(undefined4 *)(param_1 + 0x160) = 0;
      *(undefined4 *)(param_1 + 0x164) = 0x3ff00000;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x160) = 0;
    *(undefined4 *)(param_1 + 0x164) = 0;
  }
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_3 + 0x648);
  *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(param_3 + 0x64c);
  if (_DAT_0059e430 <= *(double *)(param_1 + 0x168)) {
    if (_DAT_0059e420 < *(double *)(param_1 + 0x168)) {
      *(undefined4 *)(param_1 + 0x16c) = 0x3ff00000;
      goto LAB_0043cd9d;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x16c) = 0;
LAB_0043cd9d:
    *(undefined4 *)(param_1 + 0x168) = 0;
  }
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined1 *)(param_1 + 0x178) = *(undefined1 *)(param_3 + 0x650);
  *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_3 + 0x654);
  *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_3 + 0x658);
  *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_3 + 0x65c);
  *(undefined4 *)(param_1 + 0x188) = *(undefined4 *)(param_3 + 0x660);
  *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(param_3 + 0x664);
  *(undefined4 *)(param_1 + 400) = *(undefined4 *)(param_3 + 0x668);
  if (_DAT_0059e430 <= *(double *)(param_1 + 0x18c)) {
    if (_DAT_0059e420 < *(double *)(param_1 + 0x18c)) {
      *(undefined4 *)(param_1 + 400) = 0x3ff00000;
      goto LAB_0043ce37;
    }
  }
  else {
    *(undefined4 *)(param_1 + 400) = 0;
LAB_0043ce37:
    *(undefined4 *)(param_1 + 0x18c) = 0;
  }
  *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(param_3 + 0x66c);
  *(undefined4 *)(param_1 + 0x198) = *(undefined4 *)(param_3 + 0x670);
  if (_DAT_0059e430 <= *(double *)(param_1 + 0x194)) {
    if (*(double *)(param_1 + 0x194) <= _DAT_0059e420) goto LAB_0043ce8f;
    *(undefined4 *)(param_1 + 0x198) = 0x3ff00000;
  }
  else {
    *(undefined4 *)(param_1 + 0x198) = 0;
  }
  *(undefined4 *)(param_1 + 0x194) = 0;
LAB_0043ce8f:
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  *(double *)(param_1 + 0x19c) =
       (double)*(int *)(param_2 + 0xcc4) * *(double *)(param_2 + 0xcb8) +
       *(double *)(param_2 + 0xcb0);
  *(double *)(param_1 + 0x1a4) =
       (double)(*(int *)(param_2 + 0xcc0) + -1) * *(double *)(param_2 + 0xcb8) +
       *(double *)(param_2 + 0xcb0);
  *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)(param_3 + 0x674);
  *(undefined4 *)(param_1 + 0x1b0) = *(undefined4 *)(param_3 + 0x678);
  iVar10 = *(int *)(param_1 + 0x1d4);
  *(double *)(param_1 + 0x1b4) = (double)DAT_007d0b64 * *(double *)(param_1 + 0x68);
  local_b0 = local_80 + *(double *)(param_3 + 200);
  local_a8 = dVar1 + *(double *)(param_3 + 0xd0);
  local_a0 = local_70 + *(double *)(param_3 + 0xd8);
  dVar1 = *(double *)(param_1 + 0x19c);
  pdVar7 = &local_b0;
  puVar9 = (undefined4 *)(param_1 + 0x1bc);
  for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar9 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    puVar9 = puVar9 + 1;
  }
  dVar1 = dVar1 * _DAT_0059ea60 + _DAT_0059e420;
  *(double *)(iVar10 + 0xac) = dVar1;
  *(double *)(iVar10 + 0xb4) = _DAT_0059e420 / dVar1;
  puVar9 = *(undefined4 **)(param_1 + 0x1d4);
  puVar13 = local_38;
  for (iVar10 = 6; puVar9 = puVar9 + 1, iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar9 = *puVar13;
    puVar13 = puVar13 + 1;
  }
  FUN_005691d0();
  puVar9 = local_38;
  puVar13 = (undefined4 *)(*(int *)(param_1 + 0x1d4) + 100);
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar13 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar13 = puVar13 + 1;
  }
  FUN_00569280();
  *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_3 + 0xe0);
  *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_3 + 0xe4);
  *(double *)(param_1 + 0x1e0) = *(double *)(param_3 + 0xe8) + *(double *)(param_3 + 0xe8);
  *(undefined1 *)(param_1 + 0x1724) = 0;
  FUN_0043bc20(param_2,param_3);
  local_b0 = local_50 + *(double *)(param_3 + 0x180);
  local_a8 = local_48 + *(double *)(param_3 + 0x188);
  local_a0 = local_40 + *(double *)(param_3 + 400);
  pdVar7 = &local_b0;
  puVar9 = (undefined4 *)(param_1 + 0x1884);
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar9 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    puVar9 = puVar9 + 1;
  }
  local_b0 = local_50 + *(double *)(param_3 + 0x1d4);
  local_a8 = local_48 + *(double *)(param_3 + 0x1dc);
  local_a0 = local_40 + *(double *)(param_3 + 0x1e4);
  pdVar7 = &local_b0;
  puVar9 = (undefined4 *)(param_1 + 0x18e8);
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar9 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    puVar9 = puVar9 + 1;
  }
  local_b0 = local_50 + *(double *)(param_3 + 0x2e0);
  local_a8 = local_48 + *(double *)(param_3 + 0x2e8);
  local_a0 = local_40 + *(double *)(param_3 + 0x2f0);
  pdVar7 = &local_b0;
  puVar9 = (undefined4 *)(param_1 + 0x1948);
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar9 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    puVar9 = puVar9 + 1;
  }
  local_b0 = local_80 + *(double *)(param_3 + 0x3dc);
  local_a8 = local_78 + *(double *)(param_3 + 0x3e4);
  local_a0 = local_70 + *(double *)(param_3 + 0x3ec);
  pdVar7 = &local_b0;
  puVar9 = (undefined4 *)(param_1 + 0x1a1c);
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar9 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    puVar9 = puVar9 + 1;
  }
  local_b0 = local_80 + *(double *)(param_3 + 0x414);
  local_a8 = local_78 + *(double *)(param_3 + 0x41c);
  local_a0 = local_70 + *(double *)(param_3 + 0x424);
  pdVar7 = &local_b0;
  puVar9 = (undefined4 *)(param_1 + 0x1afc);
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar9 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    puVar9 = puVar9 + 1;
  }
  local_b0 = local_80 + *(double *)(param_3 + 0x500);
  local_a8 = local_78 + *(double *)(param_3 + 0x508);
  local_a0 = local_70 + *(double *)(param_3 + 0x510);
  pdVar7 = &local_b0;
  puVar9 = (undefined4 *)(param_1 + 0x1be8);
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar9 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    puVar9 = puVar9 + 1;
  }
  iVar10 = *(int *)(param_2 + 0x1604);
  dVar1 = *(double *)(param_2 + 0x15f8);
  dVar2 = *(double *)(param_2 + 0x15f0);
  *(undefined1 *)(param_1 + 0x1c58) = 0;
  *(undefined1 *)(param_1 + 0x1c59) = 0;
  *(undefined4 *)(param_1 + 0x1d10) = 0;
  *(undefined4 *)(param_1 + 0x1d14) = 0;
  *(undefined4 *)(param_1 + 0x1c5c) = 0;
  *(undefined4 *)(param_1 + 0x1c60) = 0;
  *(undefined4 *)(param_1 + 0x1c64) = 0;
  *(undefined4 *)(param_1 + 0x1c68) = 0;
  *(double *)(param_1 + 0x1c50) = ((double)iVar10 * dVar1 + dVar2) * _DAT_0059ec38;
  dVar1 = *(double *)(param_3 + 0x684);
  *(double *)(param_1 + 0x1c6c) = dVar1;
  *(double *)(param_1 + 0x1c74) = _DAT_0059e420 / dVar1;
  *(undefined4 *)(param_1 + 0x1c7c) = *(undefined4 *)(param_3 + 0x69c);
  *(undefined4 *)(param_1 + 0x1c80) = *(undefined4 *)(param_3 + 0x6a0);
  *(undefined4 *)(param_1 + 0x1c84) = *(undefined4 *)(param_3 + 0x68c);
  *(undefined4 *)(param_1 + 0x1c88) = *(undefined4 *)(param_3 + 0x690);
  *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_3 + 0x694);
  *(undefined4 *)(param_1 + 0x1c90) = *(undefined4 *)(param_3 + 0x698);
  dVar1 = (double)*(int *)(param_2 + 0x1584) * *(double *)(param_2 + 0x1578) +
          *(double *)(param_2 + 0x1570);
  *(double *)(param_1 + 0x1cdc) = dVar1;
  dVar2 = *(double *)(param_3 + 0x6bc) * _DAT_0059e880;
  *(double *)(param_1 + 0x1cec) = dVar2 + dVar1;
  *(double *)(param_1 + 0x1ce4) = *(double *)(param_1 + 0x1cdc) - dVar2;
  *(double *)(param_1 + 0x1c94) = *(double *)(param_1 + 0x1cdc) * _DAT_0059ec30;
  dVar1 = _DAT_0059e430;
  if (0 < *(int *)(param_3 + 0x6c4)) {
    dVar1 = *(double *)(param_3 + 0x6b0 + *(int *)(param_3 + 0x6c4) * 0x18);
  }
  *(double *)(param_1 + 0x1cf4) = dVar1 + dVar1;
  iVar10 = __ftol();
  *(int *)(param_1 + 0x1d08) = 2 - iVar10;
  pvVar8 = operator_new((2 - iVar10) * 8);
  *(void **)(param_1 + 0x1cfc) = pvVar8;
  local_c8 = 0;
  if (0 < *(int *)(param_1 + 0x1d08)) {
    do {
      FUN_004f6720((double)((float)local_c8 * _DAT_0059ec20),&local_18,&local_10);
      *(float *)(*(int *)(param_1 + 0x1cfc) + local_c8 * 8) = (float)local_18;
      local_c8 = local_c8 + 1;
      *(float *)(*(int *)(param_1 + 0x1cfc) + -4 + local_c8 * 8) =
           (float)((float10)local_10 - (float10)local_18);
    } while (local_c8 < *(int *)(param_1 + 0x1d08));
  }
  *(undefined4 *)(param_1 + 0x1d54) = *(undefined4 *)(param_3 + 0x12c8);
  *(undefined4 *)(param_1 + 0x1d58) = *(undefined4 *)(param_3 + 0x12cc);
  *(undefined4 *)(param_1 + 0x1d5c) = *(undefined4 *)(param_3 + 0x12d0);
  *(undefined4 *)(param_1 + 0x1d60) = *(undefined4 *)(param_3 + 0x12d4);
  *(undefined4 *)(param_1 + 0x1d64) = *(undefined4 *)(param_3 + 0x12d8);
  *(undefined4 *)(param_1 + 0x1d68) = *(undefined4 *)(param_3 + 0x12dc);
  *(undefined4 *)(param_1 + 0x1d6c) = *(undefined4 *)(param_3 + 0x12e0);
  *(undefined4 *)(param_1 + 0x1d70) = *(undefined4 *)(param_3 + 0x12e4);
  *(undefined4 *)(param_1 + 0x1d7c) = *(undefined4 *)(param_3 + 0x12e8);
  *(undefined4 *)(param_1 + 0x1d80) = *(undefined4 *)(param_3 + 0x12ec);
  *(undefined4 *)(param_1 + 0x1d84) = *(undefined4 *)(param_3 + 0x12f0);
  *(undefined4 *)(param_1 + 0x1d88) = *(undefined4 *)(param_3 + 0x12f4);
  *(undefined4 *)(param_1 + 0x1d94) = *(undefined4 *)(param_3 + 0x12f8);
  *(undefined4 *)(param_1 + 0x1d98) = *(undefined4 *)(param_3 + 0x12fc);
  fVar3 = _DAT_008afef0 + (float)_DAT_0059eac8;
  *(undefined4 *)(param_1 + 0x1d74) = 0;
  *(undefined4 *)(param_1 + 0x1d78) = 0;
  *(double *)(param_1 + 0x1d4c) =
       (double)((fVar3 + (float)*(double *)(param_1 + 0x1d54)) * (float)_DAT_0059e880);
  fVar4 = _DAT_008afef0;
  *(undefined4 *)(param_1 + 0x1da4) = 0;
  fVar3 = (float)_DAT_0059eac8;
  *(undefined4 *)(param_1 + 0x1da8) = 0;
  *(double *)(param_1 + 0x1d8c) = (double)(fVar4 + fVar3);
  fVar15 = (float10)FUN_004b3ce0();
  fVar15 = fVar15 * (float10)*(double *)(param_3 + 0x1338) + (float10)*(double *)(param_3 + 0x1330);
  *(double *)(param_1 + 0x1db4) = (double)fVar15;
  if (fVar15 < (float10)_DAT_0059e430 != (fVar15 == (float10)_DAT_0059e430)) {
    *(undefined4 *)(param_1 + 0x1db4) = *(undefined4 *)(param_3 + 0x1330);
    *(undefined4 *)(param_1 + 0x1db8) = *(undefined4 *)(param_3 + 0x1334);
  }
  if (DAT_007cea5c == 0) {
    *(undefined4 *)(param_1 + 0x1db4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1db8) = 0x7fefffff;
    puVar9 = (undefined4 *)(param_1 + 0x6c8);
    iVar10 = 4;
    do {
      *puVar9 = 0;
      puVar9[1] = 0;
      puVar9 = puVar9 + 0x119;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  else if ((1 < DAT_007cea5c) && (DAT_007cea5c < 4)) {
    if (DAT_007c56a4 == 7) {
      *(double *)(param_1 + 0x1db4) = (double)((float)*(double *)(param_1 + 0x1db4) / _DAT_008acf9c)
      ;
    }
    iVar10 = 4;
    pdVar7 = (double *)(param_1 + 0x6c8);
    do {
      iVar10 = iVar10 + -1;
      *pdVar7 = (double)(_DAT_008acf9c * (float)*pdVar7);
      pdVar7 = (double *)((int)pdVar7 + 0x464);
    } while (iVar10 != 0);
  }
  dVar1 = _DAT_0059e420;
  *(undefined4 *)(param_1 + 0x1dac) = 0;
  *(undefined4 *)(param_1 + 0x1db0) = 0;
  *(undefined4 *)(param_1 + 0x1dbc) = *(undefined4 *)(param_3 + 0x1310);
  *(undefined4 *)(param_1 + 0x1dc0) = *(undefined4 *)(param_3 + 0x1314);
  *(double *)(param_1 + 0x1dc4) = dVar1 / *(double *)(param_3 + 0x1318);
  dVar1 = _DAT_0059e420;
  *(undefined4 *)(param_1 + 0x1dcc) = *(undefined4 *)(param_3 + 0x1320);
  *(undefined4 *)(param_1 + 0x1dd0) = *(undefined4 *)(param_3 + 0x1324);
  dVar1 = dVar1 / *(double *)(param_3 + 0x1328);
  *(undefined4 *)(param_1 + 0x1de4) = 0;
  *(undefined4 *)(param_1 + 0x1de8) = 0;
  *(undefined4 *)(param_1 + 0x1dec) = 0;
  *(undefined4 *)(param_1 + 0x1df0) = 0;
  *(undefined4 *)(param_1 + 0x1df4) = 0;
  *(undefined4 *)(param_1 + 0x1df8) = 0;
  *(double *)(param_1 + 0x1dd4) = dVar1;
  *(double *)(param_1 + 0x1ddc) = _DAT_0059e7e0 / dVar1 + *(double *)(param_1 + 0x1dcc);
  *(undefined1 *)(param_1 + 0x1d0c) = *(undefined1 *)(param_3 + 0x1358);
  *(undefined4 *)(param_1 + 0x1d18) = *(undefined4 *)(param_3 + 0x135c);
  *(undefined4 *)(param_1 + 0x1d1c) = *(undefined4 *)(param_3 + 0x1360);
  *(undefined4 *)(param_1 + 0x1d20) = *(undefined4 *)(param_3 + 0x1364);
  *(undefined4 *)(param_1 + 0x1d24) = *(undefined4 *)(param_3 + 0x1368);
  *(undefined4 *)(param_1 + 0x1d28) = *(undefined4 *)(param_3 + 0x136c);
  *(undefined4 *)(param_1 + 0x1d2c) = *(undefined4 *)(param_3 + 0x1370);
  *(undefined4 *)(param_1 + 0x1d30) = 0;
  dVar1 = *(double *)(param_3 + 0x6a4);
  *(double *)(param_1 + 0x1d34) = dVar1;
  if (DAT_007ce97c != '\0') {
    if (dVar1 <= _DAT_0059ea60) {
      dVar1 = _DAT_0059ea60;
    }
    *(double *)(param_1 + 0x1d34) = dVar1;
  }
  *(undefined4 *)(param_1 + 0x1d3c) = *(undefined4 *)(param_3 + 0x6ac);
  *(undefined4 *)(param_1 + 0x1d40) = *(undefined4 *)(param_3 + 0x6b0);
  *(undefined4 *)(param_1 + 0x1d44) = *(undefined4 *)(param_3 + 0x6b4);
  *(undefined4 *)(param_1 + 0x1d48) = *(undefined4 *)(param_3 + 0x6b8);
  *(undefined4 *)(param_1 + 0x1e14) = *(undefined4 *)(param_3 + 0x13c0);
  *(double *)(param_1 + 0x1e18) =
       ((double)*(int *)(param_2 + 0x1484) * *(double *)(param_2 + 0x1478) +
       *(double *)(param_2 + 0x1470)) * *(double *)(param_3 + 0x13c8);
  *(double *)(param_1 + 0x1e20) =
       (double)*(int *)(param_2 + 0x14c4) * *(double *)(param_2 + 0x14b8) +
       *(double *)(param_2 + 0x14b0);
  *(double *)(param_1 + 0x1e28) =
       (double)*(int *)(param_2 + 0x1504) * *(double *)(param_2 + 0x14f8) +
       *(double *)(param_2 + 0x14f0);
  *(double *)(param_1 + 0x1e30) =
       (double)*(int *)(param_2 + 0x1544) * *(double *)(param_2 + 0x1538) +
       *(double *)(param_2 + 0x1530);
  *(undefined4 *)(param_1 + 0x1e38) = 0;
  *(undefined4 *)(param_1 + 0x1e3c) = 0;
  *(undefined4 *)(param_1 + 0x1e40) = 0;
  *(undefined4 *)(param_1 + 0x1e44) = 0;
  dVar1 = *(double *)(param_3 + 0x1374);
  *(double *)(param_1 + 0x1e48) = dVar1;
  *(double *)(param_1 + 0x1e50) = _DAT_0059e420 / dVar1;
  *(undefined4 *)(param_1 + 0x1e58) = *(undefined4 *)(param_3 + 0x137c);
  *(undefined4 *)(param_1 + 0x1e5c) = *(undefined4 *)(param_3 + 0x1380);
  *(undefined4 *)(param_1 + 0x1e60) = *(undefined4 *)(param_3 + 0x1384);
  *(undefined4 *)(param_1 + 0x1e64) = *(undefined4 *)(param_3 + 5000);
  *(undefined4 *)(param_1 + 0x1e68) = *(undefined4 *)(param_3 + 0x138c);
  *(undefined4 *)(param_1 + 0x1e6c) = *(undefined4 *)(param_3 + 0x1390);
  *(undefined4 *)(param_1 + 0x1e70) = *(undefined4 *)(param_3 + 0x1394);
  *(undefined4 *)(param_1 + 0x1e74) = *(undefined4 *)(param_3 + 0x1398);
  *(undefined1 *)(param_1 + 0x71) = *(undefined1 *)(param_3 + 0x139c);
  *(undefined1 *)(param_1 + 0x1e78) = *(undefined1 *)(param_3 + 0x139d);
  *(undefined4 *)(param_1 + 0x1e84) = *(undefined4 *)(param_3 + 0x13a0);
  *(undefined4 *)(param_1 + 0x1e88) = *(undefined4 *)(param_3 + 0x13a4);
  *(double *)(param_1 + 0x1e8c) = -*(double *)(param_3 + 0x13a8);
  *(undefined4 *)(param_1 + 0x1e94) = *(undefined4 *)(param_3 + 0x13b0);
  *(undefined4 *)(param_1 + 0x1e98) = *(undefined4 *)(param_3 + 0x13b4);
  *(double *)(param_1 + 0x1e9c) = -*(double *)(param_3 + 0x13b8);
  iVar10 = *(int *)(param_3 + 0x13c4);
  iVar11 = 0;
  *(int *)(param_1 + 0x1eac) = iVar10;
  if (-1 < iVar10) {
    local_b8 = (double *)(param_1 + 0x1eb0);
    do {
      fVar15 = (float10)FUN_0042ed00();
      if (iVar11 == 8) {
        local_b8 = (double *)(DAT_005c7530 + 0x40);
      }
      *local_b8 = (double)fVar15;
      local_b8 = local_b8 + 1;
      iVar11 = iVar11 + 1;
    } while (iVar11 <= *(int *)(param_1 + 0x1eac));
  }
  fVar15 = (float10)FUN_0042ed30();
  if (fVar15 == (float10)_DAT_0059e430) {
    *(undefined4 *)(param_1 + 0x1ea4) = 0;
    *(undefined4 *)(param_1 + 0x1ea8) = 0;
  }
  else {
    *(double *)(param_1 + 0x1ea4) = (double)((float10)_DAT_0059e420 / fVar15);
  }
  *(undefined4 *)(param_1 + 0x1c9c) = *(undefined4 *)(param_1 + 0x1c8c);
  *(undefined4 *)(param_1 + 0x1ca0) = *(undefined4 *)(param_1 + 0x1c90);
  *(undefined4 *)(param_1 + 0x1ca4) = *(undefined4 *)(param_1 + 0x1c8c);
  *(undefined4 *)(param_1 + 0x1ca8) = *(undefined4 *)(param_1 + 0x1c90);
  if (*(int *)(param_1 + 0x1eac) < 2) {
    *(undefined4 *)(param_1 + 0x1ef8) = 0;
    *(undefined4 *)(param_1 + 0x1ef0) = 0;
    *(undefined4 *)(param_1 + 0x1ef4) = 0;
    *(undefined4 *)(param_1 + 0x1efc) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0xfffffffe;
    *(undefined4 *)(param_1 + 0x34) = 3;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x1f04) = 0;
    *(undefined4 *)(param_1 + 0x1f08) = 0;
    *(undefined4 *)(param_1 + 0x1f0c) = 0;
    *(undefined4 *)(param_1 + 0x1f10) = 0;
    *(undefined4 *)(param_1 + 0x1f14) = 0;
    *(undefined4 *)(param_1 + 0x1f18) = 0;
    *(undefined4 *)(param_1 + 0x1f1c) = 0;
    *(undefined4 *)(param_1 + 0x1f20) = 0;
    *(undefined4 *)(param_1 + 0x1f24) = 0;
    *(undefined4 *)(param_1 + 0x1f28) = 0;
    *(undefined4 *)(param_1 + 0x1f2c) = 0;
    *(undefined4 *)(param_1 + 0x1f30) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0;
    *(undefined4 *)(param_1 + 0xb8) = 0;
    *(undefined4 *)(param_1 + 0xbc) = 0;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 0xec) = 0;
    *(undefined4 *)(param_1 + 0xf0) = 0;
    *(undefined4 *)(param_1 + 0xf4) = 0;
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(undefined4 *)(param_1 + 0xfc) = 0;
    *(undefined4 *)(param_1 + 0x100) = 0;
    *(undefined4 *)(param_1 + 0x104) = 0;
    *(undefined4 *)(param_1 + 0x108) = 0;
    *(undefined4 *)(param_1 + 0x10c) = 0;
    *(undefined4 *)(param_1 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x114) = 0;
    *(undefined4 *)(param_1 + 0x118) = 0;
    *(undefined4 *)(param_1 + 0x11c) = 0;
    *(undefined4 *)(param_1 + 0x120) = 0;
    *(undefined4 *)(param_1 + 0x124) = 0;
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined4 *)(param_1 + 0x130) = 0;
    *(undefined4 *)(param_1 + 0x134) = 0;
    *(undefined4 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x13c) = 0;
    return;
  }
  FUN_0059da54(unaff_ESI,unaff_EBX);
  return;
}


