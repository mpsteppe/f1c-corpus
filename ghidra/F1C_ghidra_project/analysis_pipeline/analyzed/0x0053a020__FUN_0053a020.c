// Function: FUN_0053a020 @ 0053a020
// Size (bytes): 1194


undefined4 __fastcall
FUN_0053a020(int *param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6,
            uint *param_7,int param_8,uint *param_9,uint *param_10)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  int iVar13;
  byte bVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint local_100;
  uint local_fc;
  int local_f8;
  uint *local_f4;
  uint local_ec;
  uint *local_e4;
  uint local_e0;
  undefined4 local_d8;
  uint local_d4;
  int local_cc;
  int local_c8;
  uint local_bc [47];
  
  uVar15 = 0;
  local_bc[0] = 0;
  local_bc[1] = 0;
  local_bc[2] = 0;
  local_bc[3] = 0;
  local_bc[4] = 0;
  local_bc[5] = 0;
  local_bc[6] = 0;
  local_bc[7] = 0;
  local_bc[8] = 0;
  local_bc[9] = 0;
  local_bc[10] = 0;
  local_bc[0xb] = 0;
  local_bc[0xc] = 0;
  local_bc[0xd] = 0;
  local_bc[0xe] = 0;
  local_bc[0xf] = 0;
  piVar6 = param_1;
  uVar12 = param_2;
  do {
    iVar13 = *piVar6;
    piVar6 = piVar6 + 1;
    uVar12 = uVar12 - 1;
    local_bc[iVar13] = local_bc[iVar13] + 1;
  } while (uVar12 != 0);
  if (local_bc[0] == param_2) {
    *param_6 = 0;
    *param_7 = 0;
  }
  else {
    local_fc = 1;
    do {
      if (local_bc[local_fc] != 0) break;
      local_fc = local_fc + 1;
    } while (local_fc < 0x10);
    local_100 = *param_7;
    if (*param_7 < local_fc) {
      local_100 = local_fc;
    }
    uVar12 = 0xf;
    do {
      if (local_bc[uVar12] != 0) break;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
    if (uVar12 < local_100) {
      local_100 = uVar12;
    }
    *param_7 = local_100;
    iVar13 = 1 << ((byte)local_fc & 0x1f);
    for (uVar7 = local_fc; uVar7 < uVar12; uVar7 = uVar7 + 1) {
      if ((int)(iVar13 - local_bc[uVar7]) < 0) {
        return 0xfffffffd;
      }
      iVar13 = (iVar13 - local_bc[uVar7]) * 2;
    }
    iVar13 = iVar13 - local_bc[uVar12];
    if (iVar13 < 0) {
      return 0xfffffffd;
    }
    local_bc[0x11] = 0;
    local_bc[uVar12] = local_bc[uVar12] + iVar13;
    iVar8 = 0;
    iVar17 = uVar12 - 1;
    if (iVar17 != 0) {
      iVar16 = 0;
      do {
        iVar8 = iVar8 + *(int *)((int)local_bc + iVar16 + 4);
        iVar17 = iVar17 + -1;
        *(int *)((int)local_bc + iVar16 + 0x48) = iVar8;
        iVar16 = iVar16 + 4;
      } while (iVar17 != 0);
    }
    uVar7 = 0;
    do {
      iVar8 = *param_1;
      param_1 = param_1 + 1;
      if (iVar8 != 0) {
        uVar18 = local_bc[iVar8 + 0x10];
        param_10[uVar18] = uVar7;
        local_bc[iVar8 + 0x10] = uVar18 + 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_2);
    uVar18 = 0;
    uVar7 = local_bc[uVar12 + 0x10];
    local_ec = 0;
    local_f4 = param_10;
    iVar8 = -local_100;
    local_bc[0x10] = 0;
    local_f8 = -1;
    local_bc[0x20] = 0;
    local_e0 = 0;
    if ((int)local_fc <= (int)uVar12) {
      local_c8 = local_fc - 1;
      local_e4 = local_bc + local_fc;
      do {
        uVar5 = *local_e4;
        uVar2 = local_d8;
        while (local_d8 = uVar2, uVar5 != 0) {
          local_d8._2_2_ = (undefined2)((uint)uVar2 >> 0x10);
          uVar9 = uVar5 - 1;
          local_cc = iVar8 + local_100;
          if (local_cc < (int)local_fc) {
            iVar17 = iVar8 - local_100;
            do {
              iVar16 = local_f8 + 1;
              iVar8 = iVar8 + local_100;
              iVar17 = iVar17 + local_100;
              local_cc = local_cc + local_100;
              uVar15 = uVar12 - iVar8;
              if (local_100 < uVar12 - iVar8) {
                uVar15 = local_100;
              }
              uVar10 = local_fc - iVar8;
              uVar18 = 1 << ((byte)uVar10 & 0x1f);
              if ((uVar5 < uVar18) &&
                 (iVar3 = uVar18 + (-1 - uVar9), puVar1 = local_e4, uVar10 < uVar15)) {
                while (uVar10 = uVar10 + 1, uVar10 < uVar15) {
                  if ((uint)(iVar3 * 2) <= puVar1[1]) break;
                  iVar3 = iVar3 * 2 - puVar1[1];
                  puVar1 = puVar1 + 1;
                }
              }
              uVar18 = 1 << ((byte)uVar10 & 0x1f);
              uVar15 = *param_9 + uVar18;
              if (0x5a0 < uVar15) {
                return 0xfffffffc;
              }
              local_e0 = param_8 + *param_9 * 8;
              local_bc[local_f8 + 0x21] = local_e0;
              *param_9 = uVar15;
              if (iVar16 == 0) {
                *param_6 = local_e0;
              }
              else {
                local_bc[local_f8 + 0x11] = local_ec;
                uVar4 = local_ec >> ((byte)iVar17 & 0x1f);
                local_d8._0_2_ = CONCAT11((undefined1)local_100,(byte)uVar10);
                uVar15 = local_bc[local_f8 + 0x20];
                local_d4 = ((int)(local_e0 - uVar15) >> 3) - uVar4;
                *(undefined4 *)(uVar15 + uVar4 * 8) = local_d8;
                *(uint *)(uVar15 + 4 + uVar4 * 8) = local_d4;
              }
              uVar15 = local_ec;
              local_f8 = iVar16;
            } while (local_cc < (int)local_fc);
          }
          bVar14 = (byte)iVar8;
          if (local_f4 < param_10 + uVar7) {
            local_d4 = *local_f4;
            if (local_d4 < param_3) {
              local_d8._0_1_ = (-(local_d4 < 0x100) & 0xa0U) + 0x60;
            }
            else {
              iVar17 = (local_d4 - param_3) * 4;
              local_d8._0_1_ = *(char *)(iVar17 + param_5) + 'P';
              local_d4 = *(uint *)(iVar17 + param_4);
            }
            local_f4 = local_f4 + 1;
          }
          else {
            local_d8._0_1_ = -0x40;
          }
          local_d8 = CONCAT31(CONCAT21(local_d8._2_2_,(char)local_fc - bVar14),(char)local_d8);
          iVar17 = 1 << ((char)local_fc - bVar14 & 0x1f);
          uVar5 = uVar15 >> (bVar14 & 0x1f);
          if (uVar5 < uVar18) {
            puVar11 = (undefined4 *)(local_e0 + uVar5 * 8);
            do {
              puVar11[1] = local_d4;
              *puVar11 = local_d8;
              uVar5 = uVar5 + iVar17;
              puVar11 = puVar11 + iVar17 * 2;
              uVar15 = local_ec;
            } while (uVar5 < uVar18);
          }
          uVar10 = 1 << ((byte)local_c8 & 0x1f);
          uVar5 = uVar15 & uVar10;
          while (uVar5 != 0) {
            uVar15 = uVar15 ^ uVar10;
            uVar10 = uVar10 >> 1;
            uVar5 = uVar15 & uVar10;
          }
          uVar15 = uVar15 ^ uVar10;
          iVar17 = local_f8;
          uVar5 = uVar9;
          local_ec = uVar15;
          uVar2 = local_d8;
          if (((1 << (bVar14 & 0x1f)) - 1U & uVar15) != local_bc[local_f8 + 0x10]) {
            do {
              local_f8 = iVar17 + -1;
              iVar8 = iVar8 - local_100;
              iVar16 = iVar17 + 0xf;
              iVar17 = local_f8;
            } while (((1 << ((byte)iVar8 & 0x1f)) - 1U & uVar15) != local_bc[iVar16]);
          }
        }
        local_fc = local_fc + 1;
        local_e4 = local_e4 + 1;
        local_c8 = local_c8 + 1;
      } while ((int)local_fc <= (int)uVar12);
    }
    if ((iVar13 != 0) && (uVar12 != 1)) {
      return 0xfffffffb;
    }
  }
  return 0;
}


