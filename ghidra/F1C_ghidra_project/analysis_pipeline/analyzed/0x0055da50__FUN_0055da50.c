// Function: FUN_0055da50 @ 0055da50
// Size (bytes): 2247


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0055da50(uint *param_1,int param_2)

{
  float fVar1;
  uint uVar2;
  uint *puVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  float fVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  undefined4 uVar13;
  int *piVar14;
  float *pfVar15;
  float unaff_ESI;
  float unaff_EDI;
  undefined4 *puVar16;
  int iVar17;
  float10 fVar18;
  undefined8 uVar19;
  short *psVar20;
  float fStack_100;
  float local_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float local_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  float fStack_b8;
  short sStack_b4;
  short sStack_b2;
  short sStack_b0;
  short sStack_ae;
  int iStack_a8;
  short sStack_a4;
  short sStack_a2;
  undefined4 uStack_a0;
  float fStack_9c;
  float fStack_98;
  uint uStack_94;
  uint uStack_90;
  uint uStack_8c;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  short sStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  undefined1 auStack_58 [4];
  short sStack_54;
  short sStack_52;
  short sStack_50;
  short sStack_4e;
  short sStack_4c;
  undefined2 uStack_4a;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  short sStack_3c;
  int iStack_38;
  short sStack_34;
  undefined2 uStack_32;
  short sStack_30;
  undefined2 uStack_2e;
  short sStack_2c;
  short sStack_28;
  undefined2 uStack_26;
  
  uVar2 = param_1[6];
  local_fc = *(float *)(DAT_008b8f28 + 0x120);
  (**(code **)*DAT_008b8f24)
            (DAT_008b8f24,(int)local_fc + 0x44,&local_e4,*(int *)(uVar2 + 0x138) + 0x154);
  (**(code **)*DAT_008b8f24)
            (DAT_008b8f24,uVar2 + 0x100,&fStack_d8,*(int *)(param_1[6] + 0x138) + 0x154);
  if (((*param_1 & 0x100) == 0) || (uStack_8c = 1, *(int *)(param_1[6] + 0x10c) < 1)) {
    uStack_8c = 0;
  }
  if (uStack_8c != 0) {
    uStack_a0 = 0;
    puVar16 = *(undefined4 **)(param_1[6] + 0x110);
    iVar17 = 0;
    if (0 < *(int *)(param_1[6] + 0x10c)) {
      do {
        uStack_a0 = iVar17;
        (**(code **)(*DAT_008b8f24 + 0x18))(0,*puVar16,param_1[1],&fStack_78);
        (**(code **)(*DAT_008b8f24 + 0x14))(*puVar16,param_1[1],auStack_58);
        uStack_a0 = uStack_a0 + 1;
        puVar16[5] = fStack_48 + fStack_78;
        puVar16[6] = fStack_44 + fStack_74;
        puVar16[7] = fStack_40 + fStack_70;
        puVar16 = puVar16 + 0xe;
        iVar17 = uStack_a0;
      } while (uStack_a0 < *(int *)(param_1[6] + 0x10c));
    }
  }
  fVar8 = local_fc;
  uVar2 = param_1[1];
  if ((*(uint *)(uVar2 + 0x9c) & 0x40) != 0) {
    if ((*(uint *)(uVar2 + 0x9c) & 0x4000000) == 0) {
      fStack_68 = *(float *)(uVar2 + 100) * *(float *)((int)local_fc + 0x24);
      fStack_60 = *(float *)(uVar2 + 0x68) * *(float *)((int)local_fc + 0x24);
      fStack_64 = *(float *)(uVar2 + 0x6c) * *(float *)((int)local_fc + 0x24);
    }
    else {
      fStack_68 = *(float *)(uVar2 + 100);
      fStack_60 = *(float *)(uVar2 + 0x68);
      fStack_64 = *(float *)(uVar2 + 0x6c);
    }
  }
  psVar20 = &sStack_b4;
  (**(code **)(*DAT_008b8f24 + 0x18))(DAT_008b8f28,local_fc,uVar2);
  (**(code **)(*DAT_008b8f24 + 0x14))(fVar8,param_1[1],&fStack_100);
  fVar1 = *(float *)(param_1[1] + 0x50);
  if ((*(uint *)(param_1[1] + 0x9c) & 0x4000) != 0) {
    fVar1 = fVar1 * *(float *)((int)fVar8 + 0x24);
  }
  sStack_ae = (short)ROUND(fVar1 * DAT_0059fec8);
  iStack_c0 = (int)param_1[4] / 3;
  iVar17 = 0;
  sStack_4e = 0;
  if (0 < iStack_c0) {
    uStack_a0._2_2_ = 0;
    iStack_bc = 0;
    do {
      iStack_c4 = *(int *)(param_1[6] + 0x124) + 0x10 + iStack_bc;
      uVar2 = param_1[5];
      uStack_94 = (uint)*(ushort *)(uVar2 + iVar17);
      uStack_90 = (uint)*(ushort *)(uVar2 + iVar17 + 2);
      uStack_8c = (uint)*(ushort *)(uVar2 + 2 + iVar17 + 2);
      iVar17 = iVar17 + 6;
      uStack_a0._0_2_ = 0;
      sStack_a2 = 0;
      sStack_a4 = 0;
      bVar9 = true;
      if (iStack_a8 != 0) {
        (**(code **)(*DAT_008b8f24 + 4))
                  (DAT_008b8f24,iStack_c4,&fStack_e8,*(int *)(param_1[6] + 0x138) + 0x114);
        piVar14 = *(int **)(param_1[6] + 0x110);
        iVar12 = *(int *)(param_1[6] + 0x10c);
        fStack_b8 = 0.0;
        fStack_98 = 0.0;
        fStack_9c = 0.0;
        if (0 < iVar12) {
          fStack_9c = 0.0;
          fStack_98 = 0.0;
          fStack_b8 = 0.0;
          do {
            puVar3 = (uint *)*piVar14;
            fStack_74 = (float)puVar3[0x14];
            fVar8 = ((float)puVar3[0x10] - fStack_e0) * ((float)puVar3[0x10] - fStack_e0) +
                    ((float)puVar3[0xf] - local_e4) * ((float)puVar3[0xf] - local_e4) +
                    ((float)puVar3[0xe] - fStack_e8) * ((float)puVar3[0xe] - fStack_e8);
            if (fVar8 < fStack_74 * fStack_74) {
              if ((*puVar3 & 0x100) == 0) {
                fVar8 = _DAT_0059e43c - SQRT(fVar8) * (float)piVar14[4];
                fStack_9c = fVar8 * (float)piVar14[5] + fStack_9c;
                fStack_98 = fVar8 * (float)piVar14[6] + fStack_98;
                fStack_b8 = fVar8 * (float)piVar14[7] + fStack_b8;
              }
              else {
                fStack_9c = fStack_9c + (float)piVar14[5];
                fStack_98 = fStack_98 + (float)piVar14[6];
                fStack_b8 = fStack_b8 + (float)piVar14[7];
              }
            }
            piVar14 = piVar14 + 0xe;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        sStack_a4 = (short)ROUND(fStack_9c);
        sStack_a2 = (short)ROUND(fStack_98);
        _sStack_30 = CONCAT22(uStack_2e,sStack_a2);
        uStack_a0._0_2_ = (short)ROUND(fStack_b8);
        fStack_68 = (float)CONCAT22(fStack_68._2_2_,(short)uStack_a0);
        bVar9 = (-1 < (short)uStack_a0 || -1 < sStack_a2) || -1 < sStack_a4;
        sStack_6c = sStack_a4;
      }
      if (*(int *)(param_1[6] + 0x13c) == 0) {
        pfVar15 = (float *)(uStack_94 * 0x30 + 0xc + param_1[3]);
      }
      else {
        pfVar15 = (float *)(uStack_94 * 0x40 + 0xc + param_1[8]);
      }
      sStack_b4 = (short)ROUND(fStack_d0);
      _sStack_28 = CONCAT22(uStack_26,sStack_b4);
      sStack_b2 = (short)ROUND(fStack_cc);
      fStack_70 = (float)CONCAT22(fStack_70._2_2_,sStack_b2);
      sStack_b0 = (short)ROUND(fStack_c8);
      fStack_78 = (float)CONCAT22(fStack_78._2_2_,sStack_b0);
      if (bVar9) {
        fVar8 = (-(fStack_100 * *pfVar15) - local_fc * pfVar15[1]) - fStack_f8 * pfVar15[2];
        if ((float)_DAT_0059e430 < fVar8) {
          _sStack_4c = CONCAT22(uStack_4a,(short)ROUND((float)psVar20 * fVar8));
          sStack_b4 = (short)ROUND((float)psVar20 * fVar8) + sStack_b4;
          fStack_44 = (float)CONCAT22(fStack_44._2_2_,(short)ROUND(unaff_EDI * fVar8));
          sStack_b2 = (short)ROUND(unaff_EDI * fVar8) + sStack_b2;
          _sStack_34 = CONCAT22(uStack_32,(short)ROUND(unaff_ESI * fVar8));
          sStack_b0 = (short)ROUND(unaff_ESI * fVar8) + sStack_b0;
        }
        if ((*(byte *)(param_1[1] + 0x9c) & 0x40) != 0) {
          fVar8 = fStack_f4 * *pfVar15 + fStack_ec * pfVar15[2] + fStack_f0 * pfVar15[1];
          if (fVar8 <= (float)_DAT_0059e430) {
            uVar13 = 0;
          }
          else {
            fVar18 = (float10)FUN_0053ac40(fVar8);
            sStack_54 = (short)ROUND((float)(fVar18 * (float10)fStack_80));
            sStack_52 = (short)ROUND((float)fVar18 * fStack_7c);
            sStack_50 = (short)ROUND((float)fVar18 * fStack_84);
            fStack_48 = (float)CONCAT22(fStack_48._2_2_,sStack_50);
            uVar13 = CONCAT13((0 < sStack_4e) * (sStack_4e < 0x100) * (char)sStack_4e -
                              (0xff < sStack_4e),
                              CONCAT12((0 < sStack_50) * (sStack_50 < 0x100) * (char)sStack_50 -
                                       (0xff < sStack_50),
                                       CONCAT11((0 < sStack_52) * (sStack_52 < 0x100) *
                                                (char)sStack_52 - (0xff < sStack_52),
                                                (0 < sStack_54) * (sStack_54 < 0x100) *
                                                (char)sStack_54 - (0xff < sStack_54))));
            sStack_3c = sStack_54;
            sStack_2c = sStack_52;
          }
          *(undefined4 *)(uStack_94 * 0x40 + 0x1c + param_1[8]) = uVar13;
          *(undefined4 *)(uStack_90 * 0x40 + 0x1c + param_1[8]) = uVar13;
          *(undefined4 *)(uStack_8c * 0x40 + 0x1c + param_1[8]) = uVar13;
        }
        uVar19 = paddsw(CONCAT26(sStack_ae,CONCAT24(sStack_b0,CONCAT22(sStack_b2,sStack_b4))),
                        CONCAT26(uStack_a0._2_2_,
                                 CONCAT24((short)uStack_a0,CONCAT22(sStack_a2,sStack_a4))));
        sVar4 = (short)uVar19;
        sVar5 = (short)((ulonglong)uVar19 >> 0x10);
        sVar6 = (short)((ulonglong)uVar19 >> 0x20);
        sVar7 = (short)((ulonglong)uVar19 >> 0x30);
        uVar13 = CONCAT13((0 < sVar7) * (sVar7 < 0x100) * (char)((ulonglong)uVar19 >> 0x30) -
                          (0xff < sVar7),
                          CONCAT12((0 < sVar6) * (sVar6 < 0x100) * (char)((ulonglong)uVar19 >> 0x20)
                                   - (0xff < sVar6),
                                   CONCAT11((0 < sVar5) * (sVar5 < 0x100) *
                                            (char)((ulonglong)uVar19 >> 0x10) - (0xff < sVar5),
                                            (0 < sVar4) * (sVar4 < 0x100) * (char)uVar19 -
                                            (0xff < sVar4))));
      }
      else {
        uVar13 = CONCAT13((0 < sStack_ae) * (sStack_ae < 0x100) * (char)sStack_ae -
                          (0xff < sStack_ae),
                          CONCAT12((0 < sStack_b0) * (sStack_b0 < 0x100) * (char)sStack_b0 -
                                   (0xff < sStack_b0),
                                   CONCAT11((0 < sStack_b2) * (sStack_b2 < 0x100) * (char)sStack_b2
                                            - (0xff < sStack_b2),
                                            (0 < sStack_b4) * (sStack_b4 < 0x100) * (char)sStack_b4
                                            - (0xff < sStack_b4))));
      }
      iVar12 = uStack_94 * 0x40;
      *(undefined4 *)(iVar12 + 0x18 + param_1[8]) = uVar13;
      fStack_40 = (float)(uStack_90 * 0x40);
      *(undefined4 *)(param_1[8] + 0x18 + (int)fStack_40) = uVar13;
      iStack_38 = uStack_8c * 0x40;
      *(undefined4 *)(param_1[8] + 0x18 + iStack_38) = uVar13;
      if (*(char *)(param_1[1] + 0x9c) < '\0') {
        if (iStack_a8 == 0) {
          (**(code **)(*DAT_008b8f24 + 4))
                    (DAT_008b8f24,iStack_c4,&fStack_e8,*(int *)(param_1[6] + 0x138) + 0x1a0);
        }
        (**(code **)*DAT_008b8f24)
                  (DAT_008b8f24,pfVar15,&fStack_dc,*(int *)(param_1[6] + 0x138) + 0x114);
        fStack_64 = fStack_e8 + *(float *)(param_2 + 0x24);
        fVar1 = local_e4 + *(float *)(param_2 + 0x28);
        fStack_5c = fStack_e0 + *(float *)(param_2 + 0x2c);
        fVar8 = _DAT_0059e43c / SQRT(fStack_64 * fStack_64 + fVar1 * fVar1 + fStack_5c * fStack_5c);
        fStack_64 = fVar8 * fStack_64;
        fVar10 = fStack_dc * fStack_64 + fStack_d8 * fVar8 * fVar1 + fVar8 * fStack_5c * fStack_d4;
        fVar10 = fVar10 + fVar10;
        fVar11 = (fStack_dc * fVar10 - fStack_64) * _DAT_0059e450 + _DAT_0059e450;
        *(float *)(iVar12 + 0x28 + param_1[8]) = fVar11;
        fVar8 = (fStack_d8 * fVar10 - fVar8 * fVar1) * _DAT_0059e450 + _DAT_0059e450;
        *(float *)(iVar12 + 0x2c + param_1[8]) = fVar8;
        *(float *)(param_1[8] + 0x28 + (int)fStack_40) = fVar11;
        *(float *)(param_1[8] + 0x2c + (int)fStack_40) = fVar8;
        *(float *)(param_1[8] + 0x28 + iStack_38) = fVar11;
        *(float *)(param_1[8] + 0x2c + iStack_38) = fVar8;
      }
      iStack_bc = iStack_bc + 0x24;
      iStack_c0 = iStack_c0 + -1;
    } while (iStack_c0 != 0);
  }
  return;
}


