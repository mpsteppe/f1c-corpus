// Function: FUN_0055e320 @ 0055e320
// Size (bytes): 2062


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0055e320(uint *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  short sVar7;
  float fVar8;
  int iVar9;
  int *piVar10;
  float unaff_ESI;
  float unaff_EDI;
  undefined4 *puVar11;
  float fVar12;
  int iVar13;
  float10 fVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  float fVar17;
  float *pfStack_104;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  undefined1 local_c4 [4];
  float fStack_c0;
  float fStack_bc;
  float local_b8;
  float *pfStack_b0;
  short sStack_ac;
  float fStack_a8;
  short sStack_a4;
  short sStack_a2;
  short sStack_a0;
  undefined2 uStack_9e;
  int iStack_98;
  int local_94;
  int iStack_90;
  float local_8c;
  float fStack_88;
  short sStack_84;
  float fStack_80;
  undefined4 uStack_7c;
  short local_78;
  short sStack_76;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_64;
  undefined1 auStack_60 [4];
  short sStack_5c;
  short sStack_5a;
  undefined4 uStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  short sStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  short sStack_34;
  int iStack_30;
  short sStack_2c;
  short sStack_28;
  undefined2 uStack_26;
  uint uStack_20;
  
  uVar4 = param_1[6];
  local_f0 = (float)(uVar4 + 0x100);
  uVar5 = param_1[3];
  local_78 = (short)uVar5;
  sStack_76 = (short)(uVar5 >> 0x10);
  if ((*(uint *)(uVar4 + 0x14) & 0x800000) == 0) {
    local_94 = uVar5 + 0xc;
    local_8c = 1.68156e-44;
  }
  else {
    local_94 = uVar5 + 0x1c;
    local_8c = 2.24208e-44;
  }
  fVar12 = *(float *)(DAT_008b8f28 + 0x120);
  pfStack_104 = (float *)(*(int *)(uVar4 + 0x138) + 0x154);
  local_b8 = fVar12;
  (**(code **)*DAT_008b8f24)(DAT_008b8f24,(int)fVar12 + 0x44,local_c4);
  (**(code **)*DAT_008b8f24)(DAT_008b8f24,local_f0,&fStack_d0,*(int *)(param_1[6] + 0x138) + 0x154);
  if ((*param_1 & 0x100) != 0) {
    iVar13 = *(int *)(param_1[6] + 0x10c);
    if (0 < iVar13) {
      fStack_74 = 1.4013e-45;
      uStack_7c = 0;
      fVar12 = local_b8;
      puVar11 = *(undefined4 **)(param_1[6] + 0x110);
      iVar9 = 0;
      if (0 < iVar13) {
        do {
          pfStack_104 = &fStack_40;
          uStack_7c = iVar9;
          (**(code **)(*DAT_008b8f24 + 0x18))(0,*puVar11,param_1[1]);
          (**(code **)(*DAT_008b8f24 + 0x14))(*puVar11,param_1[1],auStack_60);
          uStack_7c = uStack_7c + 1;
          puVar11[5] = fStack_50 + fStack_40;
          puVar11[6] = fStack_4c + fStack_3c;
          puVar11[7] = fStack_48 + fStack_38;
          fVar12 = local_b8;
          puVar11 = puVar11 + 0xe;
          iVar9 = uStack_7c;
        } while (uStack_7c < *(int *)(param_1[6] + 0x10c));
      }
      goto LAB_0055e491;
    }
  }
  fStack_74 = 0.0;
LAB_0055e491:
  uVar4 = param_1[1];
  local_f0 = *(float *)(uVar4 + 0x9c);
  uStack_20 = (uint)local_f0 & 0x40;
  if (uStack_20 != 0) {
    if (((uint)local_f0 & 0x4000000) == 0) {
      uStack_58 = *(float *)(uVar4 + 100) * *(float *)((int)fVar12 + 0x24);
      fStack_6c = *(float *)(uVar4 + 0x68) * *(float *)((int)fVar12 + 0x24);
      fStack_54 = *(float *)(uVar4 + 0x6c) * *(float *)((int)fVar12 + 0x24);
    }
    else {
      uStack_58 = *(float *)(uVar4 + 100);
      fStack_6c = *(float *)(uVar4 + 0x68);
      fStack_54 = *(float *)(uVar4 + 0x6c);
    }
  }
  pfStack_104 = (float *)&sStack_a4;
  fVar17 = fVar12;
  (**(code **)(*DAT_008b8f24 + 0x18))(DAT_008b8f28,fVar12,uVar4);
  (**(code **)(*DAT_008b8f24 + 0x14))(fVar12,param_1[1],local_c4);
  if (((uint)fVar17 & 0x4000) == 0) {
    fVar12 = *(float *)(param_1[1] + 0x50);
  }
  else {
    fVar12 = *(float *)(param_1[1] + 0x50) * *(float *)((int)fVar12 + 0x24);
  }
  sStack_ac = (short)ROUND(fVar12 * DAT_0059fec8);
  sStack_76 = sStack_ac;
  sVar1 = (short)ROUND(fStack_c0);
  sVar2 = (short)ROUND(fStack_bc);
  sVar3 = (short)ROUND(local_b8);
  uVar15 = CONCAT13((0 < sStack_ac) * (sStack_ac < 0x100) * (char)sStack_ac - (0xff < sStack_ac),
                    CONCAT12((0 < sVar3) * (sVar3 < 0x100) * (char)sVar3 - (0xff < sVar3),
                             CONCAT11((0 < sVar2) * (sVar2 < 0x100) * (char)sVar2 - (0xff < sVar2),
                                      (0 < sVar1) * (sVar1 < 0x100) * (char)sVar1 - (0xff < sVar1)))
                   );
  uStack_58._2_2_ = 0;
  iStack_98 = 0;
  if (0 < (int)param_1[2]) {
    fStack_38 = (float)((uint)fVar17 & 0x80);
    iStack_30 = (int)fStack_a8 * 4;
    uStack_9e = 0;
    iVar13 = 0;
    do {
      sStack_a0 = 0;
      sStack_a2 = 0;
      sStack_a4 = 0;
      if (iStack_90 == 0) {
LAB_0055e7c6:
        fVar12 = (-(fStack_e0 * *pfStack_b0) - fStack_dc * pfStack_b0[1]) -
                 fStack_d8 * pfStack_b0[2];
        if (fVar12 <= (float)_DAT_0059e430) {
          *(undefined4 *)(iVar13 + 0x18 + param_1[8]) = uVar15;
        }
        else {
          sVar1 = (short)ROUND(fStack_d0 * fVar12 + fStack_c0);
          fStack_4c = (float)CONCAT22(fStack_4c._2_2_,sVar1);
          sStack_44 = (short)ROUND(fStack_cc * fVar12 + fStack_bc);
          local_78 = (short)ROUND(fStack_c8 * fVar12 + local_b8);
          uStack_7c = CONCAT22(sStack_44,sVar1);
          uVar16 = paddsw(CONCAT26(sStack_76,CONCAT24(local_78,uStack_7c)),
                          CONCAT26(uStack_9e,CONCAT24(sStack_a0,CONCAT22(sStack_a2,sStack_a4))));
          sVar1 = (short)uVar16;
          sVar2 = (short)((ulonglong)uVar16 >> 0x10);
          sVar3 = (short)((ulonglong)uVar16 >> 0x20);
          sVar7 = (short)((ulonglong)uVar16 >> 0x30);
          *(uint *)(iVar13 + 0x18 + param_1[8]) =
               CONCAT13((0 < sVar7) * (sVar7 < 0x100) * (char)((ulonglong)uVar16 >> 0x30) -
                        (0xff < sVar7),
                        CONCAT12((0 < sVar3) * (sVar3 < 0x100) * (char)((ulonglong)uVar16 >> 0x20) -
                                 (0xff < sVar3),
                                 CONCAT11((0 < sVar2) * (sVar2 < 0x100) *
                                          (char)((ulonglong)uVar16 >> 0x10) - (0xff < sVar2),
                                          (0 < sVar1) * (sVar1 < 0x100) * (char)uVar16 -
                                          (0xff < sVar1))));
          sStack_34 = local_78;
        }
        if (fStack_3c != 0.0) {
          fVar12 = fStack_e8 * pfStack_b0[1] + fStack_e4 * pfStack_b0[2] + fStack_ec * *pfStack_b0;
          if ((float)_DAT_0059e430 < fVar12) {
            fVar14 = (float10)FUN_0053ac40(fVar12);
            sStack_5c = (short)ROUND((float)(fVar14 * (float10)fStack_70));
            sStack_5a = (short)ROUND((float)fVar14 * fStack_88);
            fStack_48 = (float)CONCAT22(fStack_48._2_2_,sStack_5a);
            uStack_58._0_2_ = (short)ROUND((float)fVar14 * fStack_74);
            fStack_40 = (float)CONCAT22(fStack_40._2_2_,(short)uStack_58);
            *(uint *)(iVar13 + 0x1c + param_1[8]) =
                 CONCAT13((0 < uStack_58._2_2_) * (uStack_58._2_2_ < 0x100) * (char)uStack_58._2_2_
                          - (0xff < uStack_58._2_2_),
                          CONCAT12((0 < (short)uStack_58) * ((short)uStack_58 < 0x100) *
                                   (char)(short)uStack_58 - (0xff < (short)uStack_58),
                                   CONCAT11((0 < sStack_5a) * (sStack_5a < 0x100) * (char)sStack_5a
                                            - (0xff < sStack_5a),
                                            (0 < sStack_5c) * (sStack_5c < 0x100) * (char)sStack_5c
                                            - (0xff < sStack_5c))));
            sStack_2c = sStack_5c;
          }
          else {
            *(undefined4 *)(iVar13 + 0x1c + param_1[8]) = 0;
          }
        }
      }
      else {
        (**(code **)(*DAT_008b8f24 + 4))
                  (DAT_008b8f24,local_94,&pfStack_104,*(int *)(param_1[6] + 0x138) + 0x1a0);
        piVar10 = *(int **)(param_1[6] + 0x110);
        iVar9 = *(int *)(param_1[6] + 0x10c);
        fStack_d4 = 0.0;
        fStack_a8 = 0.0;
        local_8c = 0.0;
        if (0 < iVar9) {
          local_8c = 0.0;
          fStack_a8 = 0.0;
          fStack_d4 = 0.0;
          do {
            puVar6 = (uint *)*piVar10;
            fStack_80 = (float)puVar6[0x14];
            fVar12 = ((float)puVar6[0x10] - unaff_ESI) * ((float)puVar6[0x10] - unaff_ESI) +
                     ((float)puVar6[0xf] - unaff_EDI) * ((float)puVar6[0xf] - unaff_EDI) +
                     ((float)puVar6[0xe] - (float)pfStack_104) *
                     ((float)puVar6[0xe] - (float)pfStack_104);
            if (fVar12 < fStack_80 * fStack_80) {
              if ((*puVar6 & 0x100) == 0) {
                fVar12 = _DAT_0059e43c - SQRT(fVar12) * (float)piVar10[4];
                local_8c = fVar12 * (float)piVar10[5] + local_8c;
                fStack_a8 = fVar12 * (float)piVar10[6] + fStack_a8;
                fStack_d4 = fVar12 * (float)piVar10[7] + fStack_d4;
              }
              else {
                local_8c = local_8c + (float)piVar10[5];
                fStack_a8 = fStack_a8 + (float)piVar10[6];
                fStack_d4 = fStack_d4 + (float)piVar10[7];
              }
            }
            piVar10 = piVar10 + 0xe;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        sStack_ac = (short)ROUND(local_8c);
        sStack_a2 = (short)ROUND(fStack_a8);
        _sStack_28 = CONCAT22(uStack_26,sStack_a2);
        sStack_a0 = (short)ROUND(fStack_d4);
        sStack_a4 = sStack_ac;
        sStack_84 = sStack_a0;
        if ((-1 < sStack_a0 || -1 < sStack_a2) || -1 < sStack_ac) goto LAB_0055e7c6;
        *(undefined4 *)(iVar13 + 0x18 + param_1[8]) = uVar15;
        *(undefined4 *)(iVar13 + 0x1c + param_1[8]) = 0;
      }
      if (fStack_38 != 0.0) {
        if (iStack_90 == 0) {
          (**(code **)(*DAT_008b8f24 + 4))
                    (DAT_008b8f24,local_94,&pfStack_104,*(int *)(param_1[6] + 0x138) + 0x1a0);
        }
        (**(code **)*DAT_008b8f24)
                  (DAT_008b8f24,pfStack_b0,&fStack_f8,*(int *)(param_1[6] + 0x138) + 0x114);
        fStack_6c = (float)pfStack_104 + *(float *)(param_2 + 0x24);
        fVar17 = unaff_EDI + *(float *)(param_2 + 0x28);
        fStack_64 = unaff_ESI + *(float *)(param_2 + 0x2c);
        fVar12 = _DAT_0059e43c /
                 SQRT(fStack_6c * fStack_6c + fVar17 * fVar17 + fStack_64 * fStack_64);
        fStack_6c = fVar12 * fStack_6c;
        fVar8 = fStack_f8 * fStack_6c + fStack_f4 * fVar12 * fVar17 + fVar12 * fStack_64 * local_f0;
        fVar8 = fVar8 + fVar8;
        *(float *)(iVar13 + 0x28 + param_1[8]) =
             (fStack_f8 * fVar8 - fStack_6c) * _DAT_0059e450 + _DAT_0059e450;
        *(float *)(iVar13 + 0x2c + param_1[8]) =
             (fStack_f4 * fVar8 - fVar12 * fVar17) * _DAT_0059e450 + _DAT_0059e450;
      }
      pfStack_b0 = (float *)((int)pfStack_b0 + iStack_30);
      local_94 = local_94 + iStack_30;
      iStack_98 = iStack_98 + 1;
      iVar13 = iVar13 + 0x40;
    } while (iStack_98 < (int)param_1[2]);
  }
  return;
}


