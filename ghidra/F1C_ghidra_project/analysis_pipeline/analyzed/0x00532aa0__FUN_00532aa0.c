// Function: FUN_00532aa0 @ 00532aa0
// Size (bytes): 5752


void __thiscall FUN_00532aa0(int param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  int local_24;
  undefined2 *local_10;
  int local_c;
  
  local_24 = 0;
  bVar2 = *(char *)(param_1 + 0x24bc) - 1U & 0xf;
  *(byte *)(param_1 + 0x24bc) = bVar2;
  uVar7 = bVar2 & 1;
  iVar1 = (uint)bVar2 + (uVar7 ^ 1);
  if (0 < *(int *)(param_1 + 0x24cc)) {
    local_10 = param_2;
    local_c = param_3;
    param_3 = param_1 + 4;
    iVar6 = (uVar7 ^ 1) * 0x240;
    iVar3 = iVar6 + 4 + iVar1 * 2 + param_1;
    do {
      puVar5 = (undefined8 *)(param_3 + iVar6);
      FUN_00534120(param_3 + ((*(byte *)(param_1 + 0x24bc) + uVar7 & 0xf) + uVar7 * 0x120) * 2,iVar3
                   ,local_c);
      if (param_2 != (undefined2 *)0x0) {
        if (*(int *)(param_1 + 0x24cc) == 2) {
          iVar4 = iVar1 * 0x220;
          uVar8 = pmaddwd(*puVar5,*(undefined8 *)(&DAT_008b3724 + iVar4));
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b372c + iVar4),puVar5[1]);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3734 + iVar4),puVar5[2]);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b373c + iVar4),puVar5[3]);
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b3744 + iVar4),puVar5[4]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b374c + iVar4),puVar5[5]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3754 + iVar4),puVar5[6]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b375c + iVar4),puVar5[7]);
          *local_10 = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b3764 + iVar4),puVar5[8]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b376c + iVar4),puVar5[9]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3774 + iVar4),puVar5[10]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b377c + iVar4),puVar5[0xb]);
          local_10[2] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b3784 + iVar4),puVar5[0xc]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b378c + iVar4),puVar5[0xd]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3794 + iVar4),puVar5[0xe]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b379c + iVar4),puVar5[0xf]);
          local_10[4] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b37a4 + iVar4),puVar5[0x10]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b37ac + iVar4),puVar5[0x11]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b37b4 + iVar4),puVar5[0x12]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b37bc + iVar4),puVar5[0x13]);
          local_10[6] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b37c4 + iVar4),puVar5[0x14]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b37cc + iVar4),puVar5[0x15]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b37d4 + iVar4),puVar5[0x16]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b37dc + iVar4),puVar5[0x17]);
          local_10[8] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b37e4 + iVar4),puVar5[0x18]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b37ec + iVar4),puVar5[0x19]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b37f4 + iVar4),puVar5[0x1a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b37fc + iVar4),puVar5[0x1b]);
          local_10[10] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b3804 + iVar4),puVar5[0x1c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b380c + iVar4),puVar5[0x1d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3814 + iVar4),puVar5[0x1e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b381c + iVar4),puVar5[0x1f]);
          local_10[0xc] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b3824 + iVar4),puVar5[0x20]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b382c + iVar4),puVar5[0x21]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3834 + iVar4),puVar5[0x22]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b383c + iVar4),puVar5[0x23]);
          local_10[0xe] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b3844 + iVar4),puVar5[0x24]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b384c + iVar4),puVar5[0x25]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3854 + iVar4),puVar5[0x26]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b385c + iVar4),puVar5[0x27]);
          local_10[0x10] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b3864 + iVar4),puVar5[0x28]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b386c + iVar4),puVar5[0x29]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3874 + iVar4),puVar5[0x2a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b387c + iVar4),puVar5[0x2b]);
          local_10[0x12] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b3884 + iVar4),puVar5[0x2c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b388c + iVar4),puVar5[0x2d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3894 + iVar4),puVar5[0x2e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b389c + iVar4),puVar5[0x2f]);
          local_10[0x14] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b38a4 + iVar4),puVar5[0x30]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b38ac + iVar4),puVar5[0x31]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b38b4 + iVar4),puVar5[0x32]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b38bc + iVar4),puVar5[0x33]);
          local_10[0x16] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b38c4 + iVar4),puVar5[0x34]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b38cc + iVar4),puVar5[0x35]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b38d4 + iVar4),puVar5[0x36]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b38dc + iVar4),puVar5[0x37]);
          local_10[0x18] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b38e4 + iVar4),puVar5[0x38]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b38ec + iVar4),puVar5[0x39]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b38f4 + iVar4),puVar5[0x3a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b38fc + iVar4),puVar5[0x3b]);
          local_10[0x1a] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b3904 + iVar4),puVar5[0x3c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b390c + iVar4),puVar5[0x3d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b3914 + iVar4),puVar5[0x3e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b391c + iVar4),puVar5[0x3f]);
          local_10[0x1c] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmulhw(*(undefined8 *)(&DAT_008b3924 + iVar4),puVar5[0x40]);
          uVar11 = pmulhw(*(undefined8 *)(&DAT_008b392c + iVar4),puVar5[0x41]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmulhw(*(undefined8 *)(&DAT_008b3934 + iVar4),puVar5[0x42]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar15 = pmulhw(*(undefined8 *)(&DAT_008b393c + iVar4),puVar5[0x43]);
          iVar4 = iVar1 * 0x1e0;
          local_10[0x1e] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar11 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar13 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar15 >> 0x20) * 0x10000;
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b1924 + iVar1 * 0x78),puVar5[0x3c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b192c + iVar4),puVar5[0x3d]);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b1934 + iVar4),puVar5[0x3e]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 * 0x10000 + (int)uVar11 * 0x10000 + (int)uVar13 * 0x10000 +
                           (int)uVar15 * 0x10000 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b193c + iVar4),puVar5[0x3f]);
          uVar8 = packssdw(uVar8,uVar8);
          local_10[0x20] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar14 >> 0x20) + (int)((ulonglong)uVar13 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b1944 + iVar1 * 0x78),puVar5[0x38]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b194c + iVar4),puVar5[0x39]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar14 + (int)uVar13 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1954 + iVar4),puVar5[0x3a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b195c + iVar4),puVar5[0x3b]);
          local_10[0x22] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b1964 + iVar1 * 0x78),puVar5[0x34]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b196c + iVar4),puVar5[0x35]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1974 + iVar4),puVar5[0x36]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b197c + iVar4),puVar5[0x37]);
          local_10[0x24] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b1984 + iVar4),puVar5[0x30]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b198c + iVar4),puVar5[0x31]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1994 + iVar4),puVar5[0x32]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b199c + iVar4),puVar5[0x33]);
          local_10[0x26] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b19a4 + iVar4),puVar5[0x2c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b19ac + iVar4),puVar5[0x2d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b19b4 + iVar4),puVar5[0x2e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b19bc + iVar4),puVar5[0x2f]);
          local_10[0x28] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b19c4 + iVar4),puVar5[0x28]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b19cc + iVar4),puVar5[0x29]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b19d4 + iVar4),puVar5[0x2a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b19dc + iVar4),puVar5[0x2b]);
          local_10[0x2a] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b19e4 + iVar4),puVar5[0x24]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b19ec + iVar4),puVar5[0x25]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b19f4 + iVar4),puVar5[0x26]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b19fc + iVar4),puVar5[0x27]);
          local_10[0x2c] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b1a04 + iVar4),puVar5[0x20]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b1a0c + iVar4),puVar5[0x21]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1a14 + iVar4),puVar5[0x22]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b1a1c + iVar4),puVar5[0x23]);
          local_10[0x2e] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b1a24 + iVar4),puVar5[0x1c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b1a2c + iVar4),puVar5[0x1d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1a34 + iVar4),puVar5[0x1e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b1a3c + iVar4),puVar5[0x1f]);
          local_10[0x30] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b1a44 + iVar4),puVar5[0x18]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b1a4c + iVar4),puVar5[0x19]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1a54 + iVar4),puVar5[0x1a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b1a5c + iVar4),puVar5[0x1b]);
          local_10[0x32] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b1a64 + iVar4),puVar5[0x14]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b1a6c + iVar4),puVar5[0x15]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1a74 + iVar4),puVar5[0x16]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b1a7c + iVar4),puVar5[0x17]);
          local_10[0x34] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b1a84 + iVar4),puVar5[0x10]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b1a8c + iVar4),puVar5[0x11]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1a94 + iVar4),puVar5[0x12]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b1a9c + iVar4),puVar5[0x13]);
          local_10[0x36] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b1aa4 + iVar4),puVar5[0xc]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b1aac + iVar4),puVar5[0xd]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1ab4 + iVar4),puVar5[0xe]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b1abc + iVar4),puVar5[0xf]);
          local_10[0x38] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_008b1ac4 + iVar4),puVar5[8]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b1acc + iVar4),puVar5[9]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1ad4 + iVar4),puVar5[10]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_008b1adc + iVar4),puVar5[0xb]);
          local_10[0x3a] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_008b1ae4 + iVar4),puVar5[4]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_008b1aec + iVar4),puVar5[5]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_008b1af4 + iVar4),puVar5[6]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_008b1afc + iVar4),puVar5[7]);
          local_10[0x3c] = (short)uVar8;
          iVar4 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar11 >> 0x20) + (int)((ulonglong)uVar13 >> 0x20);
          uVar8 = CONCAT44(iVar4 >> 0xd,
                           (int)uVar10 + (int)uVar12 + (int)uVar11 + (int)uVar13 + iVar4 >> 0xd);
          uVar8 = packssdw(uVar8,uVar8);
          local_10[0x3e] = (short)uVar8;
        }
        else {
          iVar4 = iVar1 * -2;
          uVar8 = pmaddwd(*puVar5,*(undefined8 *)((int)&DAT_005b730a + iVar4 + 2));
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_005b7314 + iVar4),puVar5[1]);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b731c + iVar4),puVar5[2]);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b7324 + iVar4),puVar5[3]);
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)((int)&DAT_005b734c + iVar4),puVar5[4]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_005b7354 + iVar4),puVar5[5]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b735c + iVar4),puVar5[6]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b7364 + iVar4),puVar5[7]);
          *local_10 = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_005b738c + iVar4),puVar5[8]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_005b7394 + iVar4),puVar5[9]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b739c + iVar4),puVar5[10]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b73a4 + iVar4),puVar5[0xb]);
          local_10[1] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_005b73cc + iVar4),puVar5[0xc]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_005b73d4 + iVar4),puVar5[0xd]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b73dc + iVar4),puVar5[0xe]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b73e4 + iVar4),puVar5[0xf]);
          local_10[2] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_005b740c + iVar4),puVar5[0x10]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_005b7414 + iVar4),puVar5[0x11]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b741c + iVar4),puVar5[0x12]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b7424 + iVar4),puVar5[0x13]);
          local_10[3] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_005b744c + iVar4),puVar5[0x14]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_005b7454 + iVar4),puVar5[0x15]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b745c + iVar4),puVar5[0x16]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b7464 + iVar4),puVar5[0x17]);
          local_10[4] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_005b748c + iVar4),puVar5[0x18]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_005b7494 + iVar4),puVar5[0x19]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b749c + iVar4),puVar5[0x1a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b74a4 + iVar4),puVar5[0x1b]);
          local_10[5] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_005b74cc + iVar4),puVar5[0x1c]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_005b74d4 + iVar4),puVar5[0x1d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b74dc + iVar4),puVar5[0x1e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b74e4 + iVar4),puVar5[0x1f]);
          local_10[6] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_005b750c + iVar4),puVar5[0x20]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_005b7514 + iVar4),puVar5[0x21]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b751c + iVar4),puVar5[0x22]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b7524 + iVar4),puVar5[0x23]);
          local_10[7] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_005b754c + iVar4),puVar5[0x24]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_005b7554 + iVar4),puVar5[0x25]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b755c + iVar4),puVar5[0x26]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b7564 + iVar4),puVar5[0x27]);
          local_10[8] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_005b758c + iVar4),puVar5[0x28]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_005b7594 + iVar4),puVar5[0x29]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b759c + iVar4),puVar5[0x2a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b75a4 + iVar4),puVar5[0x2b]);
          local_10[9] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_005b75cc + iVar4),puVar5[0x2c]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_005b75d4 + iVar4),puVar5[0x2d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b75dc + iVar4),puVar5[0x2e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b75e4 + iVar4),puVar5[0x2f]);
          local_10[10] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_005b760c + iVar4),puVar5[0x30]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_005b7614 + iVar4),puVar5[0x31]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b761c + iVar4),puVar5[0x32]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b7624 + iVar4),puVar5[0x33]);
          local_10[0xb] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_005b764c + iVar4),puVar5[0x34]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_005b7654 + iVar4),puVar5[0x35]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b765c + iVar4),puVar5[0x36]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b7664 + iVar4),puVar5[0x37]);
          local_10[0xc] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_005b768c + iVar4),puVar5[0x38]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_005b7694 + iVar4),puVar5[0x39]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b769c + iVar4),puVar5[0x3a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b76a4 + iVar4),puVar5[0x3b]);
          local_10[0xd] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_005b76cc + iVar4),puVar5[0x3c]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_005b76d4 + iVar4),puVar5[0x3d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_005b76dc + iVar4),puVar5[0x3e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_005b76e4 + iVar4),puVar5[0x3f]);
          local_10[0xe] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmulhw(*(undefined8 *)(&UNK_005b770c + iVar4),puVar5[0x40]);
          uVar11 = pmulhw(*(undefined8 *)(&UNK_005b7714 + iVar4),puVar5[0x41]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmulhw(*(undefined8 *)(&UNK_005b771c + iVar4),puVar5[0x42]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar15 = pmulhw(*(undefined8 *)(&UNK_005b7724 + iVar4),puVar5[0x43]);
          local_10[0xf] = (short)uVar10;
          iVar4 = iVar1 * -2;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar11 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar13 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar15 >> 0x20) * 0x10000;
          uVar10 = pmaddwd(*(undefined8 *)((int)&DAT_005b6f0a + iVar4 + 2),puVar5[0x3c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_005b6f14 + iVar4),puVar5[0x3d]);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b6f1c + iVar4),puVar5[0x3e]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 * 0x10000 + (int)uVar11 * 0x10000 + (int)uVar13 * 0x10000 +
                           (int)uVar15 * 0x10000 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b6f24 + iVar4),puVar5[0x3f]);
          uVar8 = packssdw(uVar8,uVar8);
          local_10[0x10] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar14 >> 0x20) + (int)((ulonglong)uVar13 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)((int)&DAT_005b6f4c + iVar4),puVar5[0x38]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_005b6f54 + iVar4),puVar5[0x39]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar14 + (int)uVar13 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b6f5c + iVar4),puVar5[0x3a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b6f64 + iVar4),puVar5[0x3b]);
          local_10[0x11] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_005b6f8c + iVar4),puVar5[0x34]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_005b6f94 + iVar4),puVar5[0x35]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b6f9c + iVar4),puVar5[0x36]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b6fa4 + iVar4),puVar5[0x37]);
          local_10[0x12] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_005b6fcc + iVar4),puVar5[0x30]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_005b6fd4 + iVar4),puVar5[0x31]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b6fdc + iVar4),puVar5[0x32]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b6fe4 + iVar4),puVar5[0x33]);
          local_10[0x13] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_005b700c + iVar4),puVar5[0x2c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_005b7014 + iVar4),puVar5[0x2d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b701c + iVar4),puVar5[0x2e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b7024 + iVar4),puVar5[0x2f]);
          local_10[0x14] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_005b704c + iVar4),puVar5[0x28]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_005b7054 + iVar4),puVar5[0x29]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b705c + iVar4),puVar5[0x2a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b7064 + iVar4),puVar5[0x2b]);
          local_10[0x15] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_005b708c + iVar4),puVar5[0x24]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_005b7094 + iVar4),puVar5[0x25]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b709c + iVar4),puVar5[0x26]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b70a4 + iVar4),puVar5[0x27]);
          local_10[0x16] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_005b70cc + iVar4),puVar5[0x20]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_005b70d4 + iVar4),puVar5[0x21]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b70dc + iVar4),puVar5[0x22]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b70e4 + iVar4),puVar5[0x23]);
          local_10[0x17] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_005b710c + iVar4),puVar5[0x1c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_005b7114 + iVar4),puVar5[0x1d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b711c + iVar4),puVar5[0x1e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b7124 + iVar4),puVar5[0x1f]);
          local_10[0x18] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_005b714c + iVar4),puVar5[0x18]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_005b7154 + iVar4),puVar5[0x19]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b715c + iVar4),puVar5[0x1a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b7164 + iVar4),puVar5[0x1b]);
          local_10[0x19] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_005b718c + iVar4),puVar5[0x14]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_005b7194 + iVar4),puVar5[0x15]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b719c + iVar4),puVar5[0x16]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b71a4 + iVar4),puVar5[0x17]);
          local_10[0x1a] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_005b71cc + iVar4),puVar5[0x10]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_005b71d4 + iVar4),puVar5[0x11]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b71dc + iVar4),puVar5[0x12]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b71e4 + iVar4),puVar5[0x13]);
          local_10[0x1b] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_005b720c + iVar4),puVar5[0xc]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_005b7214 + iVar4),puVar5[0xd]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b721c + iVar4),puVar5[0xe]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b7224 + iVar4),puVar5[0xf]);
          local_10[0x1c] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_005b724c + iVar4),puVar5[8]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_005b7254 + iVar4),puVar5[9]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b725c + iVar4),puVar5[10]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_005b7264 + iVar4),puVar5[0xb]);
          local_10[0x1d] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_005b728c + iVar4),puVar5[4]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_005b7294 + iVar4),puVar5[5]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_005b729c + iVar4),puVar5[6]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_005b72a4 + iVar4),puVar5[7]);
          local_10[0x1e] = (short)uVar8;
          iVar4 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar11 >> 0x20) + (int)((ulonglong)uVar13 >> 0x20);
          uVar8 = CONCAT44(iVar4 >> 0xd,
                           (int)uVar10 + (int)uVar12 + (int)uVar11 + (int)uVar13 + iVar4 >> 0xd);
          uVar8 = packssdw(uVar8,uVar8);
          local_10[0x1f] = (short)uVar8;
        }
      }
      param_3 = param_3 + 0x480;
      iVar3 = iVar3 + 0x480;
      local_c = local_c + 0x40;
      local_24 = local_24 + 1;
      local_10 = local_10 + 1;
    } while (local_24 < *(int *)(param_1 + 0x24cc));
  }
  return;
}


