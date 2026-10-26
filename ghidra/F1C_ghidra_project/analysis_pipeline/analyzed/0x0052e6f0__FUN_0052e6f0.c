// Function: FUN_0052e6f0 @ 0052e6f0
// Size (bytes): 6487


undefined4 __thiscall FUN_0052e6f0(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  float *pfVar4;
  undefined2 uVar5;
  uint uVar6;
  int *piVar7;
  float fVar8;
  float *pfVar9;
  uint *puVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  byte *pbVar14;
  byte bVar15;
  int *piVar16;
  uint *puVar17;
  undefined1 *puVar18;
  undefined2 *puVar19;
  undefined1 local_760 [768];
  undefined1 local_460 [4];
  undefined2 local_45c [382];
  float local_160 [32];
  float local_e0;
  uint local_dc [4];
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  byte local_60 [32];
  byte local_40 [5];
  char local_3b;
  char local_3a;
  char local_39;
  char local_38;
  char local_37;
  char local_36;
  char local_35;
  char local_34;
  char local_33;
  char local_32;
  char local_31;
  char local_30;
  char local_2f;
  char local_2e;
  char local_2d;
  char local_2c;
  char local_2b;
  char local_2a;
  char local_29;
  char local_28;
  char local_27;
  char local_26;
  char local_25;
  undefined4 local_24;
  float *local_20;
  uint local_1c;
  float *local_18;
  int *local_14;
  float *local_10;
  uint *local_c;
  uint local_8;
  
  iVar13 = *(int *)(param_1 + 0x24a4);
  if (iVar13 == 0) {
    return 0xffffffff;
  }
  if (DAT_008b0108 != 0) {
    iVar11 = *(int *)(param_1 + 0x24a8);
    if (*(int *)(param_1 + 0x24cc) == 2) {
      puVar17 = (uint *)((iVar11 >> 3) + iVar13);
      *(int *)(param_1 + 0x24a8) = iVar11 + 0x100;
      pfVar9 = &local_e0;
      local_c = puVar17;
      local_1c = 0;
      local_10 = pfVar9;
      pbVar14 = local_60 + 1;
      do {
        bVar1 = *(byte *)(local_1c + (int)puVar17);
        local_10 = pfVar9;
        pbVar14[-1] = bVar1 >> 4;
        *pbVar14 = bVar1 & 0xf;
        if (pbVar14[-1] != 0) {
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar13 = *(int *)(param_1 + 0x24a8);
          pfVar9[-0x20] =
               (float)((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                       local_8 << 0x18) >>
                       (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 6 & 0x1f) & DAT_005b47a0);
          *(int *)(param_1 + 0x24a8) = iVar13 + 6;
          puVar17 = local_c;
        }
        puVar10 = local_c;
        if (*pbVar14 != 0) {
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          fVar8 = (float)((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                          local_8 << 0x18) >> (-((byte)*(int *)(param_1 + 0x24a8) & 7) - 6 & 0x1f) &
                         DAT_005b47a0);
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 6;
          *local_10 = fVar8;
          puVar17 = puVar10;
          pfVar9 = local_10;
        }
        pbVar14 = pbVar14 + 2;
        local_1c = local_1c + 1;
        pfVar9 = pfVar9 + 1;
        local_10 = pfVar9;
      } while ((int)local_1c < 0x20);
      puVar18 = local_760;
      iVar13 = 0xc;
      do {
        FUN_0052e5e0(0,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(1,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(2,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(3,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(4,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(5,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(6,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(7,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(8,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(9,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(10,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0xb,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0xc,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0xd,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0xe,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0xf,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x10,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x11,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x12,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x13,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x14,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x15,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x16,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x17,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x18,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x19,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x1a,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x1b,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x1c,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x1d,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x1e,local_60,local_160,puVar18,&DAT_005b2ba4);
        FUN_0052e5e0(0x1f,local_60,local_160,puVar18,&DAT_005b2ba4);
        puVar18 = puVar18 + 0x80;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      puVar18 = local_760;
      local_c = (uint *)0xc;
      do {
        FUN_00532aa0(param_2,puVar18);
        puVar18 = puVar18 + 0x80;
        param_2 = param_2 + *(int *)(param_1 + 0x24d0) * 2;
        local_c = (uint *)((int)local_c + -1);
      } while (local_c != (uint *)0x0);
    }
    else {
      puVar17 = local_dc;
      local_8 = (iVar11 >> 3) + iVar13;
      *(int *)(param_1 + 0x24a8) = iVar11 + 0x80;
      local_18 = (float *)0x0;
      local_c = puVar17;
      do {
        pfVar9 = local_18;
        bVar1 = *(byte *)(((int)local_18 >> 1) + local_8);
        bVar15 = bVar1 & 0xf;
        local_c = puVar17;
        local_40[(int)local_18] = bVar1 >> 4;
        local_40[(int)pfVar9 + 1] = bVar15;
        pfVar4 = local_18;
        if (local_40[(int)pfVar9] != 0) {
          local_1c = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar13 = *(int *)(param_1 + 0x24a8);
          local_c[-1] = (local_1c >> 0x18 | (local_1c & 0xff0000) >> 8 | (local_1c & 0xff00) << 8 |
                        local_1c << 0x18) >> (-((byte)iVar13 & 7) - 6 & 0x1f) & DAT_005b47a0;
          *(int *)(param_1 + 0x24a8) = iVar13 + 6;
          pfVar9 = pfVar4;
          puVar17 = local_c;
        }
        if (bVar15 != 0) {
          uVar6 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar13 = *(int *)(param_1 + 0x24a8);
          *puVar17 = (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
                     uVar6 << 0x18) >> (-((byte)iVar13 & 7) - 6 & 0x1f) & DAT_005b47a0;
          *(int *)(param_1 + 0x24a8) = iVar13 + 6;
          pfVar9 = local_18;
        }
        puVar17 = puVar17 + 2;
        local_18 = (float *)((int)pfVar9 + 2);
        local_c = puVar17;
      } while ((int)pfVar9 + 2 < 0x20);
      puVar19 = local_45c;
      local_18 = (float *)(int)(char)local_24;
      local_20 = (float *)(int)(char)((uint)local_24 >> 8);
      local_c = (uint *)0xc;
      local_14 = (int *)(int)(char)((uint)local_24 >> 0x10);
      local_10 = (float *)(int)(char)((uint)local_24 >> 0x18);
      do {
        iVar13 = (int)(char)local_40[0];
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + (int)local_e0) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)(char)local_40[1];
        puVar19[-2] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_dc[0]) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)(char)local_40[2];
        puVar19[-1] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_dc[1]) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)(char)local_40[3];
        *puVar19 = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_dc[2]) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)(char)local_40[4];
        puVar19[1] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_dc[3]) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_3b;
        puVar19[2] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_cc) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_3a;
        puVar19[3] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_c8) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_39;
        puVar19[4] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_c4) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_38;
        puVar19[5] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_c0) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_37;
        puVar19[6] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_bc) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_36;
        puVar19[7] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_b8) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_35;
        puVar19[8] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_b4) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_34;
        puVar19[9] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_b0) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_33;
        puVar19[10] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_ac) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_32;
        puVar19[0xb] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_a8) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_31;
        puVar19[0xc] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_a4) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_30;
        puVar19[0xd] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_a0) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_2f;
        puVar19[0xe] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_9c) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_2e;
        puVar19[0xf] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_98) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_2d;
        puVar19[0x10] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_94) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_2c;
        puVar19[0x11] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_90) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_2b;
        puVar19[0x12] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_8c) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_2a;
        puVar19[0x13] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_88) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_29;
        puVar19[0x14] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_84) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_28;
        puVar19[0x15] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_80) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_27;
        puVar19[0x16] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_7c) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_26;
        puVar19[0x17] = uVar5;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_78) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        iVar13 = (int)local_25;
        puVar19[0x18] = uVar5;
        pfVar9 = local_18;
        uVar5 = 0;
        if (iVar13 != 0) {
          iVar11 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar3 = *(undefined4 *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + *(int *)(param_1 + 0x24a8);
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + (iVar13 * 0x40 + local_74) * 4) *
                        (*(int *)(&DAT_005b4820 + iVar13 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)uVar3 & 7) + (char)iVar11) & 0x1f) & uVar6)))
                  >> 0xc);
        }
        puVar19[0x19] = uVar5;
        pfVar4 = local_20;
        uVar5 = 0;
        if (pfVar9 != (float *)0x0) {
          iVar13 = (int)pfVar9 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar11 = *(int *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar13 * 4);
          *(int *)(param_1 + 0x24a8) = iVar13 + iVar11;
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + ((int)local_18 * 0x40 + local_70) * 4) *
                        (*(int *)(&DAT_005b4820 + (int)local_18 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)iVar11 & 7) + (char)iVar13) & 0x1f) & uVar6))
                        ) >> 0xc);
        }
        puVar19[0x1a] = uVar5;
        piVar7 = local_14;
        uVar5 = 0;
        if (pfVar4 != (float *)0x0) {
          iVar11 = (int)pfVar4 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar13 = *(int *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar13 + iVar11;
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + ((int)local_20 * 0x40 + local_6c) * 4) *
                        (*(int *)(&DAT_005b4820 + (int)local_20 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)iVar13 & 7) + (char)iVar11) & 0x1f) & uVar6))
                        ) >> 0xc);
        }
        puVar19[0x1b] = uVar5;
        pfVar9 = local_10;
        uVar5 = 0;
        if (piVar7 != (int *)0x0) {
          iVar11 = (int)piVar7 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar13 = *(int *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar13 + iVar11;
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + ((int)local_14 * 0x40 + local_68) * 4) *
                        (*(int *)(&DAT_005b4820 + (int)local_14 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)iVar13 & 7) + (char)iVar11) & 0x1f) & uVar6))
                        ) >> 0xc);
        }
        puVar19[0x1c] = uVar5;
        uVar5 = 0;
        if (pfVar9 != (float *)0x0) {
          iVar11 = (int)pfVar9 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar13 = *(int *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar13 + iVar11;
          uVar5 = (undefined2)
                  ((int)(*(int *)(&DAT_005b2ca4 + ((int)local_10 * 0x40 + local_64) * 4) *
                        (*(int *)(&DAT_005b4820 + (int)local_10 * 4) +
                        ((local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                         local_8 << 0x18) >> (-(((byte)iVar13 & 7) + (char)iVar11) & 0x1f) & uVar6))
                        ) >> 0xc);
        }
        puVar19[0x1d] = uVar5;
        puVar19 = puVar19 + 0x20;
        local_c = (uint *)((int)local_c + -1);
      } while (local_c != (uint *)0x0);
      puVar18 = local_460;
      local_c = (uint *)0xc;
      do {
        FUN_00532aa0(param_2,puVar18);
        puVar18 = puVar18 + 0x40;
        local_c = (uint *)((int)local_c + -1);
        param_2 = param_2 + *(int *)(param_1 + 0x24d0) * 2;
      } while (local_c != (uint *)0x0);
    }
    return 0;
  }
  puVar17 = &DAT_008b0124;
  if (*(int *)(param_1 + 0x24cc) == 2) {
    local_10 = (float *)0x20;
    puVar10 = &DAT_008b0324;
    do {
      uVar6 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
      uVar6 = (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18) >>
              (-((byte)*(undefined4 *)(param_1 + 0x24a8) & 7) - 8 & 0x1f) & DAT_005b47a8;
      *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 8;
      *puVar10 = (int)uVar6 >> 4;
      puVar10[1] = uVar6 & 0xf;
      local_10 = (float *)((int)local_10 + -1);
      puVar10 = puVar10 + 2;
    } while (local_10 != (float *)0x0);
    piVar7 = &DAT_008b0324;
    local_10 = (float *)0x20;
    do {
      uVar6 = DAT_005b47a0;
      piVar16 = piVar7 + 1;
      if (*piVar7 != 0) {
        uVar2 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        iVar13 = *(int *)(param_1 + 0x24a8);
        *(int *)(param_1 + 0x24a8) = iVar13 + 6;
        *puVar17 = (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18)
                   >> (-((byte)iVar13 & 7) - 6 & 0x1f) & uVar6;
        puVar17 = puVar17 + 1;
      }
      uVar6 = DAT_005b47a0;
      piVar7 = piVar7 + 2;
      if (*piVar16 != 0) {
        uVar2 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        iVar13 = *(int *)(param_1 + 0x24a8);
        *(int *)(param_1 + 0x24a8) = iVar13 + 6;
        *puVar17 = (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18)
                   >> (-((byte)iVar13 & 7) - 6 & 0x1f) & uVar6;
        puVar17 = puVar17 + 1;
      }
      local_10 = (float *)((int)local_10 + -1);
    } while (local_10 != (float *)0x0);
  }
  else {
    local_10 = (float *)0x20;
    puVar10 = &DAT_008b0324;
    do {
      uVar2 = DAT_005b4798;
      uVar6 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
      uVar3 = *(undefined4 *)(param_1 + 0x24a8);
      *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 4;
      *puVar10 = (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18)
                 >> (-((byte)uVar3 & 7) - 4 & 0x1f) & uVar2;
      local_10 = (float *)((int)local_10 + -1);
      puVar10 = puVar10 + 1;
    } while (local_10 != (float *)0x0);
    piVar7 = &DAT_008b0324;
    local_10 = (float *)0x20;
    do {
      uVar6 = DAT_005b47a0;
      iVar13 = *piVar7;
      piVar7 = piVar7 + 1;
      if (iVar13 != 0) {
        uVar2 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
        iVar13 = *(int *)(param_1 + 0x24a8);
        *(int *)(param_1 + 0x24a8) = iVar13 + 6;
        *puVar17 = (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18)
                   >> (-((byte)iVar13 & 7) - 6 & 0x1f) & uVar6;
        puVar17 = puVar17 + 1;
      }
      local_10 = (float *)((int)local_10 + -1);
    } while (local_10 != (float *)0x0);
  }
  local_c = (uint *)0xc;
  do {
    local_10 = (float *)&DAT_008b0124;
    if (*(int *)(param_1 + 0x24cc) == 2) {
      local_18 = &local_e0;
      local_20 = local_160;
      piVar7 = &DAT_008b0324;
      puVar17 = &DAT_008b0224;
      local_1c = 0x20;
      do {
        piVar16 = piVar7 + 1;
        if (*piVar7 != 0) {
          iVar11 = *piVar7 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar13 = *(int *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + iVar13;
          *puVar17 = (local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                     local_8 << 0x18) >> (-(((byte)iVar13 & 7) + (char)iVar11) & 0x1f) & uVar6;
          puVar17 = puVar17 + 1;
        }
        piVar7 = piVar7 + 2;
        if (*piVar16 != 0) {
          iVar11 = *piVar16 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar13 = *(int *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
          *(int *)(param_1 + 0x24a8) = iVar11 + iVar13;
          *puVar17 = (local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                     local_8 << 0x18) >> (-(((byte)iVar13 & 7) + (char)iVar11) & 0x1f) & uVar6;
          puVar17 = puVar17 + 1;
        }
        piVar16 = &DAT_008b0124;
        local_1c = local_1c + -1;
      } while (local_1c != 0);
      piVar12 = &DAT_008b0324;
      piVar7 = &DAT_008b0224;
      local_1c = 0x20;
      do {
        iVar13 = *piVar12;
        if (iVar13 == 0) {
          *local_20 = 0.0;
          local_20 = local_20 + 1;
        }
        else {
          local_8 = (*piVar7 - (1 << ((byte)iVar13 & 0x1f))) + 1;
          piVar7 = piVar7 + 1;
          pfVar9 = local_20 + 1;
          *local_20 = (float)(int)local_8 *
                      *(float *)(&DAT_005b11a4 + (iVar13 * 0x40 + *piVar16) * 4);
          local_20 = pfVar9;
          piVar16 = piVar16 + 1;
        }
        iVar13 = piVar12[1];
        piVar12 = piVar12 + 2;
        local_14 = piVar12;
        if (iVar13 == 0) {
          *local_18 = 0.0;
          local_18 = local_18 + 1;
        }
        else {
          local_8 = (*piVar7 - (1 << ((byte)iVar13 & 0x1f))) + 1;
          piVar7 = piVar7 + 1;
          pfVar9 = local_18 + 1;
          *local_18 = (float)(int)local_8 *
                      *(float *)(&DAT_005b11a4 + (iVar13 * 0x40 + *piVar16) * 4);
          local_18 = pfVar9;
          piVar16 = piVar16 + 1;
        }
        local_1c = local_1c + -1;
      } while (local_1c != 0);
      local_1c = 0;
    }
    else {
      local_18 = local_160;
      puVar17 = &DAT_008b0224;
      local_14 = &DAT_008b0324;
      local_1c = 0x20;
      do {
        iVar13 = *local_14;
        local_14 = local_14 + 1;
        if (iVar13 != 0) {
          iVar13 = iVar13 + 1;
          local_8 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          iVar11 = *(int *)(param_1 + 0x24a8);
          uVar6 = *(uint *)(&DAT_005b4788 + iVar13 * 4);
          *(int *)(param_1 + 0x24a8) = iVar13 + iVar11;
          *puVar17 = (local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                     local_8 << 0x18) >> (-(((byte)iVar11 & 7) + (char)iVar13) & 0x1f) & uVar6;
          puVar17 = puVar17 + 1;
        }
        local_1c = local_1c + -1;
      } while (local_1c != 0);
      piVar7 = &DAT_008b0324;
      iVar13 = 0;
      local_1c = 0x20;
      do {
        iVar11 = *piVar7;
        piVar7 = piVar7 + 1;
        if (iVar11 == 0) {
          *local_18 = 0.0;
          local_18 = local_18 + 1;
        }
        else {
          piVar16 = (int *)((int)&DAT_008b0124 + iVar13);
          local_8 = (*(int *)((int)&DAT_008b0224 + iVar13) - (1 << ((byte)iVar11 & 0x1f))) + 1;
          iVar13 = iVar13 + 4;
          pfVar9 = local_18 + 1;
          *local_18 = (float)(int)local_8 *
                      *(float *)(&DAT_005b11a4 + (*piVar16 + iVar11 * 0x40) * 4);
          local_18 = pfVar9;
        }
        local_1c = local_1c + -1;
      } while (local_1c != 0);
    }
    FUN_00531830(param_2,local_160);
    param_2 = param_2 + *(int *)(param_1 + 0x24d0) * 2;
    local_c = (uint *)((int)local_c + -1);
  } while (local_c != (uint *)0x0);
  return 0;
}


