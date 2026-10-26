// Function: FUN_00531830 @ 00531830
// Size (bytes): 793


void __thiscall FUN_00531830(int param_1,undefined2 *param_2,int param_3)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  float *pfVar13;
  float *pfVar14;
  float *pfVar15;
  float *pfVar16;
  float *pfVar17;
  float *pfVar18;
  float *pfVar19;
  float *pfVar20;
  float *pfVar21;
  float *pfVar22;
  float *pfVar23;
  float *pfVar24;
  float *pfVar25;
  float *pfVar26;
  float *pfVar27;
  float *pfVar28;
  float fVar29;
  float fVar30;
  int iVar31;
  float *pfVar32;
  float *pfVar33;
  byte bVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  undefined2 *puVar39;
  int iVar40;
  float *pfVar41;
  float *pfVar42;
  uint uVar43;
  int local_18;
  undefined2 *local_c;
  int local_8;
  
  iVar31 = *(int *)(param_1 + 0x24cc);
  bVar34 = *(char *)(param_1 + 0x24bc) - 1U & 0xf;
  *(byte *)(param_1 + 0x24bc) = bVar34;
  uVar43 = bVar34 & 1;
  iVar37 = (uint)bVar34 + (uVar43 ^ 1);
  if (0 < iVar31) {
    local_c = param_2;
    local_8 = param_3;
    param_3 = param_1 + 4;
    iVar35 = (uVar43 ^ 1) * 0x480;
    iVar40 = iVar35 + 4 + iVar37 * 4 + param_1;
    local_18 = iVar31;
    do {
      FUN_00531b50(param_3 + ((*(byte *)(param_1 + 0x24bc) + uVar43 & 0xf) + uVar43 * 0x120) * 4,
                   iVar40,local_8);
      if (param_2 != (undefined2 *)0x0) {
        iVar38 = 0x10;
        puVar39 = local_c;
        pfVar32 = (float *)(&DAT_005b666c + iVar37 * -4);
        pfVar33 = (float *)(iVar35 + param_3);
        do {
          pfVar42 = pfVar33;
          pfVar41 = pfVar32;
          iVar36 = (int)ROUND((((pfVar41[10] * pfVar42[10] + pfVar41[4] * pfVar42[4]) -
                               pfVar41[3] * pfVar42[3]) - pfVar41[0xb] * pfVar42[0xb]) +
                              (((pfVar41[0xe] * pfVar42[0xe] + pfVar41[6] * pfVar42[6]) -
                               pfVar41[7] * pfVar42[7]) - pfVar41[0xf] * pfVar42[0xf]) +
                              (((pfVar41[0xc] * pfVar42[0xc] + pfVar41[2] * pfVar42[2]) -
                               pfVar41[5] * pfVar42[5]) - pfVar41[0xd] * pfVar42[0xd]) +
                              (((pfVar41[8] * pfVar42[8] + *pfVar41 * *pfVar42) -
                               pfVar41[1] * pfVar42[1]) - pfVar41[9] * pfVar42[9]));
          if (0x7fff < iVar36) {
            iVar36 = 0x7fff;
          }
          if (iVar36 < -0x8000) {
            iVar36 = -0x8000;
          }
          *puVar39 = (short)iVar36;
          puVar39 = puVar39 + iVar31;
          iVar38 = iVar38 + -1;
          pfVar32 = pfVar41 + 0x20;
          pfVar33 = pfVar42 + 0x10;
        } while (iVar38 != 0);
        iVar38 = (int)ROUND(pfVar41[0x2a] * pfVar42[0x1a] + pfVar41[0x24] * pfVar42[0x14] +
                            pfVar41[0x2e] * pfVar42[0x1e] + pfVar41[0x26] * pfVar42[0x16] +
                            pfVar41[0x2c] * pfVar42[0x1c] + pfVar41[0x22] * pfVar42[0x12] +
                            pfVar41[0x28] * pfVar42[0x18] + pfVar41[0x20] * pfVar42[0x10]);
        if (0x7fff < iVar38) {
          iVar38 = 0x7fff;
        }
        if (iVar38 < -0x8000) {
          iVar38 = -0x8000;
        }
        *puVar39 = (short)iVar38;
        pfVar41 = pfVar41 + iVar37 * 2;
        iVar38 = 0xf;
        do {
          puVar39 = puVar39 + iVar31;
          pfVar32 = pfVar41 + -1;
          fVar29 = *pfVar42;
          pfVar33 = pfVar41 + -2;
          pfVar1 = pfVar42 + 1;
          pfVar2 = pfVar41 + -3;
          pfVar3 = pfVar42 + 2;
          pfVar4 = pfVar41 + -4;
          pfVar5 = pfVar42 + 3;
          pfVar6 = pfVar41 + -5;
          pfVar7 = pfVar42 + 4;
          pfVar8 = pfVar41 + -6;
          pfVar9 = pfVar42 + 5;
          pfVar10 = pfVar41 + -7;
          pfVar11 = pfVar42 + 6;
          pfVar12 = pfVar41 + -8;
          pfVar13 = pfVar42 + 7;
          pfVar14 = pfVar41 + -9;
          pfVar15 = pfVar42 + 8;
          pfVar16 = pfVar41 + -10;
          pfVar17 = pfVar42 + 9;
          pfVar18 = pfVar41 + -0xb;
          pfVar19 = pfVar42 + 10;
          pfVar20 = pfVar41 + -0xc;
          pfVar21 = pfVar42 + 0xb;
          pfVar22 = pfVar41 + -0xd;
          pfVar23 = pfVar42 + 0xc;
          pfVar24 = pfVar41 + -0xe;
          pfVar25 = pfVar42 + 0xd;
          pfVar26 = pfVar41 + -0xf;
          pfVar27 = pfVar42 + 0xe;
          fVar30 = *pfVar41;
          pfVar28 = pfVar42 + 0xf;
          pfVar41 = pfVar41 + -0x20;
          pfVar42 = pfVar42 + -0x10;
          iVar36 = (int)ROUND(-(*pfVar24 * *pfVar25 +
                                *pfVar16 * *pfVar17 + *pfVar8 * *pfVar9 + *pfVar2 * *pfVar3 +
                                fVar30 * *pfVar28 +
                                *pfVar20 * *pfVar21 + *pfVar12 * *pfVar13 + *pfVar4 * *pfVar5 +
                               *pfVar26 * *pfVar27 +
                               *pfVar18 * *pfVar19 + *pfVar10 * *pfVar11 + *pfVar33 * *pfVar1 +
                               *pfVar22 * *pfVar23 +
                               *pfVar14 * *pfVar15 + *pfVar6 * *pfVar7 + *pfVar32 * fVar29));
          if (0x7fff < iVar36) {
            iVar36 = 0x7fff;
          }
          if (iVar36 < -0x8000) {
            iVar36 = -0x8000;
          }
          *puVar39 = (short)iVar36;
          iVar38 = iVar38 + -1;
        } while (iVar38 != 0);
      }
      param_3 = param_3 + 0x900;
      iVar40 = iVar40 + 0x900;
      local_8 = local_8 + 0x80;
      local_c = local_c + 1;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
  }
  return;
}


