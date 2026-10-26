// Function: FUN_00531250 @ 00531250
// Size (bytes): 1385


undefined4 __thiscall FUN_00531250(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  byte local_15c [64];
  byte local_11c [192];
  byte local_5c [64];
  short *local_1c;
  byte *local_18;
  byte *local_14;
  uint local_10;
  byte *local_c;
  byte *local_8;
  
  iVar13 = param_2;
  pbVar9 = local_11c;
  if (*(int *)(param_1 + 0x24a4) != 0) {
    if (*(char *)(param_1 + 0x24be) == '\0') {
      iVar8 = (int)(char)(&DAT_005b65e0)
                         [(uint)*(byte *)(param_1 + 0x24c3) +
                          ((uint)*(byte *)(param_1 + 0x24c4) * 2 - *(int *)(param_1 + 0x24cc)) *
                          0x10];
    }
    else {
      iVar8 = 4;
    }
    pbVar5 = (byte *)(int)*(short *)(&DAT_005b6620 + iVar8 * 2);
    *(byte **)(param_1 + 0x24b8) = pbVar5;
    local_8 = (&PTR_DAT_005da760)[iVar8];
    local_1c = (short *)local_8;
    local_18 = (byte *)((int)pbVar5 * *(int *)(param_1 + 0x24cc));
    pbVar10 = local_5c;
    pbVar6 = local_c;
    pbVar3 = local_14;
    local_14 = pbVar5;
    if (*(int *)(param_1 + 0x24cc) == 2) {
      while (local_14 != (byte *)0x0) {
        iVar12 = (int)*(short *)local_8;
        uVar7 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        bVar4 = (byte)*(short *)local_8;
        iVar8 = *(int *)(param_1 + 0x24a8) + iVar12;
        *pbVar10 = (byte)((uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                          uVar7 << 0x18) >>
                         (-(((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) + bVar4) & 0x1f)) &
                   (byte)*(undefined4 *)(&DAT_005b4788 + iVar12 * 4);
        *(int *)(param_1 + 0x24a8) = iVar8;
        local_c = *(byte **)((iVar8 >> 3) + *(int *)(param_1 + 0x24a4));
        iVar8 = *(int *)(param_1 + 0x24a8);
        pbVar10[1] = (byte)(((uint)local_c >> 0x18 | ((uint)local_c & 0xff0000) >> 8 |
                             ((uint)local_c & 0xff00) << 8 | (int)local_c << 0x18) >>
                           (-(((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) + bVar4) & 0x1f)) &
                     (byte)*(undefined4 *)(&DAT_005b4788 + iVar12 * 4);
        *(int *)(param_1 + 0x24a8) = iVar8 + iVar12;
        pbVar10 = pbVar10 + 2;
        local_8 = (byte *)((int)local_8 + (1 << (bVar4 & 0x1f)) * 2 * 2);
        local_14 = local_14 + -1;
        pbVar3 = local_14;
      }
      local_14 = local_5c;
      local_8 = local_15c;
      if (local_18 != (byte *)0x0) {
        local_c = local_18;
        do {
          uVar1 = DAT_005b4790;
          bVar4 = *local_14;
          local_14 = local_14 + 1;
          if (bVar4 != 0) {
            local_10 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            iVar8 = *(int *)(param_1 + 0x24a8);
            *(int *)(param_1 + 0x24a8) = iVar8 + 2;
            *local_8 = (byte)((local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 |
                               (local_10 & 0xff00) << 8 | local_10 << 0x18) >>
                             (-((byte)iVar8 & 7) - 2 & 0x1f)) & (byte)uVar1;
            local_8 = local_8 + 1;
          }
          local_c = local_c + -1;
          pbVar3 = local_14;
        } while (local_c != (byte *)0x0);
      }
    }
    else {
      while (local_c = pbVar5, local_c != (byte *)0x0) {
        pbVar6 = (byte *)(int)*(short *)local_8;
        local_14 = pbVar6;
        local_10 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        iVar8 = *(int *)(param_1 + 0x24a8);
        bVar4 = (byte)*(short *)local_8;
        *pbVar10 = (byte)((local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 | (local_10 & 0xff00) << 8
                          | local_10 << 0x18) >> (-(((byte)iVar8 & 7) + bVar4) & 0x1f)) &
                   (byte)*(undefined4 *)(&DAT_005b4788 + (int)pbVar6 * 4);
        *(byte **)(param_1 + 0x24a8) = pbVar6 + iVar8;
        pbVar10 = pbVar10 + 1;
        local_8 = (byte *)((int)local_8 + (1 << (bVar4 & 0x1f)) * 2 * 2);
        pbVar6 = local_c + -1;
        pbVar3 = local_14;
        pbVar5 = local_c + -1;
      }
      local_14 = local_5c;
      local_8 = local_15c;
      local_c = pbVar6;
      if (*(byte **)(param_1 + 0x24b8) != (byte *)0x0) {
        local_c = *(byte **)(param_1 + 0x24b8);
        do {
          uVar1 = DAT_005b4790;
          bVar4 = *local_14;
          local_14 = local_14 + 1;
          if (bVar4 != 0) {
            local_10 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            iVar8 = *(int *)(param_1 + 0x24a8);
            *(int *)(param_1 + 0x24a8) = iVar8 + 2;
            *local_8 = (byte)((local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 |
                               (local_10 & 0xff00) << 8 | local_10 << 0x18) >>
                             (-((byte)iVar8 & 7) - 2 & 0x1f)) & (byte)uVar1;
            local_8 = local_8 + 1;
          }
          local_c = local_c + -1;
          pbVar3 = local_14;
        } while (local_c != (byte *)0x0);
      }
    }
    local_14 = pbVar3;
    local_8 = local_15c;
    if (local_18 != (byte *)0x0) {
      local_c = local_18;
      local_14 = local_5c;
      do {
        uVar2 = DAT_005b47d0;
        uVar7 = DAT_005b47b8;
        uVar1 = DAT_005b47a0;
        bVar4 = *local_14;
        local_14 = local_14 + 1;
        if (bVar4 != 0) {
          bVar4 = *local_8;
          local_8 = local_8 + 1;
          if (bVar4 == 0) {
            local_10 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            iVar8 = *(int *)(param_1 + 0x24a8);
            *(int *)(param_1 + 0x24a8) = iVar8 + 0x12;
            uVar7 = (local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 | (local_10 & 0xff00) << 8 |
                    local_10 << 0x18) >> (-((byte)iVar8 & 7) - 0x12 & 0x1f) & uVar2;
            *pbVar9 = (byte)(uVar7 >> 0xc) & 0x3f;
            bVar4 = (byte)(uVar7 >> 6) & 0x3f;
LAB_00531675:
            pbVar9[1] = bVar4;
            bVar4 = (byte)uVar7 & 0x3f;
          }
          else {
            if (bVar4 == 1) {
              local_10 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
              iVar8 = *(int *)(param_1 + 0x24a8);
              *(int *)(param_1 + 0x24a8) = iVar8 + 0xc;
              uVar7 = (local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 | (local_10 & 0xff00) << 8 |
                      local_10 << 0x18) >> (-((byte)iVar8 & 7) - 0xc & 0x1f) & uVar7;
              bVar4 = (byte)(uVar7 >> 6) & 0x3f;
              *pbVar9 = bVar4;
              goto LAB_00531675;
            }
            iVar8 = *(int *)(param_1 + 0x24a8) >> 3;
            if (bVar4 == 2) {
              local_10 = *(uint *)(iVar8 + *(int *)(param_1 + 0x24a4));
              iVar8 = *(int *)(param_1 + 0x24a8);
              *(int *)(param_1 + 0x24a8) = iVar8 + 6;
              bVar4 = (byte)((local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 |
                              (local_10 & 0xff00) << 8 | local_10 << 0x18) >>
                            (-((byte)iVar8 & 7) - 6 & 0x1f)) & (byte)uVar1;
              *pbVar9 = bVar4;
              pbVar9[1] = bVar4;
            }
            else {
              local_10 = *(uint *)(iVar8 + *(int *)(param_1 + 0x24a4));
              iVar8 = *(int *)(param_1 + 0x24a8);
              *(int *)(param_1 + 0x24a8) = iVar8 + 0xc;
              uVar7 = (local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 | (local_10 & 0xff00) << 8 |
                      local_10 << 0x18) >> (-((byte)iVar8 & 7) - 0xc & 0x1f) & uVar7;
              bVar4 = (byte)uVar7 & 0x3f;
              *pbVar9 = (byte)(uVar7 >> 6) & 0x3f;
              pbVar9[1] = bVar4;
            }
          }
          pbVar9[2] = bVar4;
          pbVar9 = pbVar9 + 3;
        }
        local_c = local_c + -1;
      } while (local_c != (byte *)0x0);
    }
    iVar8 = 0;
    if (param_2 == 0) {
      local_18 = (byte *)0x0;
    }
    else {
      local_18 = *(byte **)(param_1 + 0x24d0);
    }
    if (DAT_008b0108 == 0) {
      iVar13 = (int)local_18 * 2;
      do {
        FUN_00530050(local_5c,&DAT_008b1624,local_11c,iVar8 >> 2,local_1c);
        FUN_00531830(param_2,&DAT_008b1624);
        FUN_00531830(param_2 + iVar13,&DAT_008b1724);
        param_2 = param_2 + iVar13 + iVar13;
        FUN_00531830(param_2,&DAT_008b1824);
        param_2 = param_2 + iVar13;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0xc);
    }
    else {
      param_2 = 0;
      puVar11 = &DAT_008b0424;
      do {
        FUN_00530840(&DAT_005b2ba4,local_5c,puVar11,local_11c + (param_2 >> 2),local_1c);
        puVar11 = puVar11 + 0x180;
        param_2 = param_2 + 1;
      } while ((int)puVar11 < 0x8b1624);
      puVar11 = &DAT_008b04a4;
      iVar8 = (int)local_18 * 2;
      do {
        FUN_00532aa0(iVar13,puVar11 + -0x80);
        FUN_00532aa0(iVar13 + iVar8,puVar11);
        iVar13 = iVar13 + iVar8 + iVar8;
        FUN_00532aa0(iVar13,puVar11 + 0x80);
        puVar11 = puVar11 + 0x180;
        iVar13 = iVar13 + iVar8;
      } while ((int)puVar11 < 0x8b16a4);
    }
  }
  return 0;
}


