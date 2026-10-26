// Function: FUN_00558310 @ 00558310
// Strings:  [Error creating vertex buffer]


undefined4 __fastcall FUN_00558310(int param_1)

{
  short *psVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  short sVar10;
  short sVar11;
  undefined4 *puVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  int local_8;
  
  if ((*(uint *)(param_1 + 0x20) & 1) == 0) {
    if ((*(uint *)(param_1 + 0x20) & 2) == 0) {
      return 0;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x38) = 0x20;
    *(int *)(*(int *)(param_1 + 0x50) + 8) = *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x2c);
    *(int *)(*(int *)(param_1 + 0x50) + 0x10) = *(int *)(param_1 + 0x28) * *(int *)(param_1 + 0x2c);
    puVar3 = operator_new(0x24);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[5] = 0;
      puVar3[4] = 0;
      puVar3[3] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      *puVar3 = 0;
      puVar3[7] = 0;
      puVar3[6] = 0;
      puVar3[8] = 0;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x50) + 0x1c) = puVar3;
    **(undefined4 **)(*(int *)(param_1 + 0x50) + 0x1c) =
         *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x38);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + 0x1c) + 0xc) =
         *(undefined4 *)(*(int *)(param_1 + 0x50) + 8);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + 0x1c) + 8) = 0x40;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + 0x1c) + 4) = 0x4d2;
    iVar4 = FUN_00540df0(*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x1c));
    if (iVar4 != 0) goto LAB_0055865b;
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x2c) = 0;
    puVar3 = operator_new(0x1c);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[3] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      *puVar3 = 0;
      puVar3[5] = 0;
      puVar3[4] = 0;
      puVar3[6] = 0;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x50) + 0x24) = puVar3;
    **(undefined4 **)(*(int *)(param_1 + 0x50) + 0x24) = 2;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + 0x24) + 4) =
         *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10);
    iVar4 = FUN_00540fc0(*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x24));
    if (iVar4 != 0) goto LAB_0055865b;
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x30) = 0;
    if (-1 < *(char *)(param_1 + 0x20)) {
      *(undefined4 *)(*(int *)(param_1 + 0x50) + 8) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10) = *(undefined4 *)(param_1 + 0x28);
    }
    FUN_00540d40(*(undefined4 *)(param_1 + 0x50),0x2c);
    local_8 = 0;
    if (0 < *(int *)(param_1 + 0x2c)) {
      do {
        psVar1 = (short *)(*(int *)(*(int *)(param_1 + 0x50) + 0x14) +
                          *(int *)(param_1 + 0x28) * local_8 * 2);
        sVar7 = *(short *)(param_1 + 0x24) * (short)local_8;
        iVar4 = *(int *)(param_1 + 0x24) * local_8 * 0x40 +
                *(int *)(*(int *)(param_1 + 0x50) + 0x20);
        puVar3 = (undefined4 *)(iVar4 + 0x24);
        puVar12 = (undefined4 *)(iVar4 + 0x20);
        iVar4 = 6;
        do {
          *puVar12 = 0;
          *puVar3 = 0;
          puVar12[0x10] = 0;
          puVar3[0x10] = 0x3f800000;
          puVar12[0x20] = 0x3f800000;
          puVar3[0x20] = 0x3f800000;
          puVar12[0x30] = 0x3f800000;
          puVar3[0x30] = 0x3f800000;
          puVar12[0x40] = 0x3f800000;
          puVar3[0x40] = 0;
          puVar12[0x50] = 0;
          puVar3[0x50] = 0;
          puVar12 = puVar12 + 0x60;
          puVar3 = puVar3 + 0x60;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        bVar2 = **(byte **)(param_1 + 0x50);
        sVar11 = sVar7 + 1;
        *psVar1 = sVar7;
        psVar1[1] = sVar11;
        if ((bVar2 & 0x10) == 0) {
          psVar1[5] = sVar7;
          sVar10 = sVar7 + 2;
          psVar1[2] = sVar10;
          psVar1[3] = sVar10;
          sVar16 = sVar7 + 3;
          psVar1[4] = sVar16;
          psVar1[7] = sVar10;
          psVar1[6] = sVar16;
          psVar1[0xb] = sVar16;
          sVar13 = sVar7 + 7;
          psVar1[10] = sVar13;
          sVar17 = sVar7 + 6;
          psVar1[8] = sVar17;
          psVar1[9] = sVar17;
          psVar1[0xc] = sVar13;
          psVar1[0xd] = sVar17;
          sVar14 = sVar7 + 5;
          psVar1[0xe] = sVar14;
          psVar1[0xf] = sVar14;
          psVar1[0x10] = sVar7 + 4;
          psVar1[0x11] = sVar13;
          psVar1[0x16] = sVar7;
          psVar1[0x12] = sVar7 + 4;
          psVar1[0x13] = sVar14;
          psVar1[0x14] = sVar11;
          psVar1[0x15] = sVar11;
          sVar15 = sVar7 + 4;
          psVar1[0x17] = sVar15;
          psVar1[0x19] = sVar7;
          psVar1[0x1c] = sVar13;
          psVar1[0x18] = sVar15;
          psVar1[0x1a] = sVar16;
          psVar1[0x1b] = sVar16;
          psVar1[0x1d] = sVar15;
          psVar6 = psVar1 + 0x1e;
          psVar1[0x1f] = sVar14;
          psVar1[0x20] = sVar17;
          psVar1[0x21] = sVar17;
          psVar1[0x23] = sVar11;
        }
        else {
          psVar1[7] = sVar7;
          psVar1[2] = sVar11;
          sVar16 = sVar7 + 2;
          psVar1[3] = sVar16;
          psVar1[4] = sVar16;
          sVar17 = sVar7 + 3;
          psVar1[5] = sVar17;
          psVar1[6] = sVar17;
          psVar1[8] = sVar17;
          psVar1[9] = sVar16;
          psVar1[10] = sVar16;
          psVar1[0xf] = sVar17;
          sVar10 = sVar7 + 6;
          psVar1[0xb] = sVar10;
          psVar1[0xc] = sVar10;
          sVar13 = sVar7 + 7;
          psVar1[0xd] = sVar13;
          psVar1[0xe] = sVar13;
          psVar1[0x10] = sVar13;
          psVar1[0x11] = sVar10;
          psVar1[0x12] = sVar10;
          sVar14 = sVar7 + 5;
          psVar1[0x13] = sVar14;
          psVar1[0x14] = sVar14;
          psVar1[0x15] = sVar7 + 4;
          psVar1[0x16] = sVar7 + 4;
          psVar1[0x17] = sVar13;
          psVar1[0x1d] = sVar7;
          psVar1[0x1e] = sVar7;
          psVar1[0x1b] = sVar11;
          psVar1[0x1c] = sVar11;
          psVar1[0x18] = sVar7 + 4;
          psVar1[0x19] = sVar14;
          psVar1[0x1a] = sVar14;
          sVar15 = sVar7 + 4;
          psVar1[0x1f] = sVar15;
          psVar1[0x21] = sVar7;
          psVar1[0x22] = sVar7;
          psVar1[0x25] = sVar13;
          psVar1[0x26] = sVar13;
          psVar1[0x20] = sVar15;
          psVar1[0x23] = sVar17;
          psVar1[0x24] = sVar17;
          psVar1[0x27] = sVar15;
          psVar6 = psVar1 + 0x28;
          psVar1[0x29] = sVar14;
          psVar1[0x2a] = sVar14;
          psVar1[0x2b] = sVar10;
          psVar1[0x2d] = sVar16;
          psVar1[0x2e] = sVar16;
          psVar1[0x2f] = sVar11;
        }
        *psVar6 = sVar11;
        psVar6[4] = sVar10;
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)(param_1 + 0x2c));
    }
    iVar4 = *(int *)(param_1 + 0x50);
    puVar3 = *(undefined4 **)(iVar4 + 0x28);
    if (puVar3 == (undefined4 *)0x0) goto LAB_00558975;
    puVar12 = *(undefined4 **)(iVar4 + 0x14);
    if (-1 < *(char *)(param_1 + 0x20)) goto LAB_0055895e;
    uVar8 = *(uint *)(iVar4 + 0x10) << 1;
    for (uVar9 = (*(uint *)(iVar4 + 0x10) & 0x7fffffff) >> 1; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar3 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x38) = 0x20;
    *(int *)(*(int *)(param_1 + 0x50) + 8) = *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x2c);
    *(int *)(*(int *)(param_1 + 0x50) + 0x10) = *(int *)(param_1 + 0x28) * *(int *)(param_1 + 0x2c);
    puVar3 = operator_new(0x24);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[5] = 0;
      puVar3[4] = 0;
      puVar3[3] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      *puVar3 = 0;
      puVar3[7] = 0;
      puVar3[6] = 0;
      puVar3[8] = 0;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x50) + 0x1c) = puVar3;
    **(undefined4 **)(*(int *)(param_1 + 0x50) + 0x1c) =
         *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x38);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + 0x1c) + 0xc) =
         *(undefined4 *)(*(int *)(param_1 + 0x50) + 8);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + 0x1c) + 8) = 0x40;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + 0x1c) + 4) = 0x4d2;
    iVar4 = FUN_00540df0(*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x1c));
    if (iVar4 != 0) {
LAB_0055865b:
      FUN_0053c590(0xffffffff,s_Error_creating_vertex_buffer_005dbd40);
      return 0xffffffff;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x2c) = 0;
    puVar3 = operator_new(0x1c);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[3] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      *puVar3 = 0;
      puVar3[5] = 0;
      puVar3[4] = 0;
      puVar3[6] = 0;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x50) + 0x24) = puVar3;
    **(undefined4 **)(*(int *)(param_1 + 0x50) + 0x24) = 2;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + 0x24) + 4) =
         *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10);
    iVar4 = FUN_00540fc0(*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x24));
    if (iVar4 != 0) goto LAB_0055865b;
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x30) = 0;
    FUN_00540d40(*(undefined4 *)(param_1 + 0x50),0x2c);
    if (-1 < *(char *)(param_1 + 0x20)) {
      *(undefined4 *)(*(int *)(param_1 + 0x50) + 8) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10) = *(undefined4 *)(param_1 + 0x28);
      iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
      *(undefined4 *)(iVar4 + 0x1c) = 0;
      *(undefined4 *)(iVar4 + 0x20) = 0;
      *(undefined4 *)(iVar4 + 0x40) = 0;
      *(undefined4 *)(iVar4 + 0x44) = 0x3f800000;
      *(undefined4 *)(iVar4 + 100) = 0x3f800000;
      *(undefined4 *)(iVar4 + 0x68) = 0x3f800000;
      *(undefined4 *)(iVar4 + 0x88) = 0x3f800000;
      *(undefined4 *)(iVar4 + 0x8c) = 0;
    }
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x2c)) {
      do {
        psVar1 = (short *)(*(int *)(*(int *)(param_1 + 0x50) + 0x14) +
                          *(int *)(param_1 + 0x28) * iVar4 * 2);
        sVar10 = *(short *)(param_1 + 0x24) * (short)iVar4;
        iVar5 = *(int *)(param_1 + 0x24) * iVar4 * 0x40 + *(int *)(*(int *)(param_1 + 0x50) + 0x20);
        *(undefined4 *)(iVar5 + 0x20) = 0;
        *(undefined4 *)(iVar5 + 0x24) = 0;
        *(undefined4 *)(iVar5 + 100) = 0x3f800000;
        *(undefined4 *)(iVar5 + 0x60) = 0;
        *(undefined4 *)(iVar5 + 0xa0) = 0x3f800000;
        *(undefined4 *)(iVar5 + 0xa4) = 0x3f800000;
        *(undefined4 *)(iVar5 + 0xe0) = 0x3f800000;
        *(undefined4 *)(iVar5 + 0xe4) = 0;
        psVar1[1] = sVar10 + 1;
        sVar7 = sVar10 + 2;
        sVar11 = sVar10 + 3;
        *psVar1 = sVar10;
        psVar1[2] = sVar7;
        psVar1[3] = sVar7;
        psVar1[4] = sVar11;
        psVar1[5] = sVar10;
        if ((*(byte *)(param_1 + 0x21) & 2) == 0) {
          psVar1[7] = sVar7;
          psVar1[6] = sVar11;
          psVar1[8] = sVar10 + 1;
          psVar1[9] = sVar10 + 1;
          psVar1[10] = sVar10;
          psVar1[0xb] = sVar11;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x2c));
    }
    iVar4 = *(int *)(param_1 + 0x50);
    puVar3 = *(undefined4 **)(iVar4 + 0x28);
    if (puVar3 == (undefined4 *)0x0) goto LAB_00558975;
    puVar12 = *(undefined4 **)(iVar4 + 0x14);
    if (*(char *)(param_1 + 0x20) < '\0') {
      uVar8 = *(uint *)(iVar4 + 0x10) << 1;
      for (uVar9 = (*(uint *)(iVar4 + 0x10) & 0x7fffffff) >> 1; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar3 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else {
LAB_0055895e:
      uVar9 = *(int *)(param_1 + 0x28) * *(int *)(param_1 + 0x2c);
      uVar8 = uVar9 * 2;
      for (uVar9 = (uVar9 & 0x7fffffff) >> 1; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar3 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar3 = puVar3 + 1;
      }
    }
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)puVar12;
    puVar12 = (undefined4 *)((int)puVar12 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
LAB_00558975:
  FUN_00540da0(*(undefined4 *)(param_1 + 0x50),0xc);
  return 0;
}


