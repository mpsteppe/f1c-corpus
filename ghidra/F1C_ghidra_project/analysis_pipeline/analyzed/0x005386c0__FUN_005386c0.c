// Function: FUN_005386c0 @ 005386c0
// Size (bytes): 522


void __fastcall FUN_005386c0(int param_1,int *param_2)

{
  ushort *puVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  uint uVar16;
  ushort *puVar17;
  int local_20;
  int *local_1c;
  uint local_18;
  int local_14;
  int local_10;
  
  iVar3 = param_2[1];
  piVar4 = (int *)param_2[2];
  iVar5 = *param_2;
  iVar14 = *piVar4;
  iVar8 = piVar4[1];
  iVar6 = piVar4[2];
  uVar11 = piVar4[4];
  iVar12 = 0;
  puVar15 = (undefined4 *)(param_1 + 0xb32);
  for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar15 = 0;
    puVar15 = puVar15 + 1;
  }
  local_20 = 0;
  *(undefined2 *)(iVar5 + 2 + *(int *)(param_1 + 0xb52 + *(int *)(param_1 + 0x144a) * 4) * 4) = 0;
  local_14 = *(int *)(param_1 + 0x144a) + 1;
  if (local_14 < 0x23d) {
    local_1c = (int *)(param_1 + 0xb52 + local_14 * 4);
    local_10 = 0x23d - local_14;
    local_14 = local_14 + local_10;
    do {
      iVar9 = *local_1c;
      uVar7 = *(ushort *)(iVar5 + 2 + (uint)*(ushort *)(iVar5 + 2 + iVar9 * 4) * 4) + 1;
      if ((int)uVar11 < (int)uVar7) {
        iVar12 = iVar12 + 1;
        uVar7 = uVar11;
        local_20 = iVar12;
      }
      *(short *)(iVar5 + 2 + iVar9 * 4) = (short)uVar7;
      if (iVar9 <= iVar3) {
        psVar10 = (short *)(param_1 + 0xb32 + uVar7 * 2);
        *psVar10 = *psVar10 + 1;
        iVar13 = 0;
        if (iVar6 <= iVar9) {
          iVar13 = *(int *)(iVar8 + (iVar9 - iVar6) * 4);
        }
        uVar16 = (uint)*(ushort *)(iVar5 + iVar9 * 4);
        *(int *)(param_1 + 0x169b) = *(int *)(param_1 + 0x169b) + (uVar7 + iVar13) * uVar16;
        iVar12 = local_20;
        if (iVar14 != 0) {
          *(uint *)(param_1 + 0x169f) =
               *(int *)(param_1 + 0x169f) +
               ((uint)*(ushort *)(iVar14 + 2 + iVar9 * 4) + iVar13) * uVar16;
        }
      }
      local_1c = local_1c + 1;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    if (iVar12 != 0) {
      iVar14 = uVar11 - 1;
      puVar17 = (ushort *)(param_1 + 0xb32 + uVar11 * 2);
      do {
        psVar10 = (short *)(param_1 + 0xb32 + iVar14 * 2);
        sVar2 = *(short *)(param_1 + 0xb32 + iVar14 * 2);
        iVar8 = iVar14;
        while (sVar2 == 0) {
          psVar10 = psVar10 + -1;
          iVar8 = iVar8 + -1;
          sVar2 = *psVar10;
        }
        psVar10 = (short *)(param_1 + 0xb32 + iVar8 * 2);
        *psVar10 = *psVar10 + -1;
        psVar10 = (short *)(param_1 + 0xb34 + iVar8 * 2);
        *psVar10 = *psVar10 + 2;
        *puVar17 = *puVar17 - 1;
        iVar12 = iVar12 + -2;
      } while (0 < iVar12);
      for (; uVar11 != 0; uVar11 = uVar11 - 1) {
        uVar7 = (uint)*puVar17;
        if (uVar7 != 0) {
          iVar14 = param_1 + 0xb52 + local_14 * 4;
          local_18 = uVar7;
          do {
            iVar8 = *(int *)(iVar14 + -4);
            local_14 = local_14 + -1;
            iVar14 = iVar14 + -4;
            if (iVar8 <= iVar3) {
              puVar1 = (ushort *)(iVar5 + 2 + iVar8 * 4);
              uVar7 = (uint)*puVar1;
              if (uVar7 != uVar11) {
                *(uint *)(param_1 + 0x169b) =
                     *(int *)(param_1 + 0x169b) +
                     (uVar11 - uVar7) * (uint)*(ushort *)(iVar5 + iVar8 * 4);
                *puVar1 = (ushort)uVar11;
              }
              uVar7 = local_18 - 1;
              local_18 = uVar7;
            }
          } while (uVar7 != 0);
        }
        puVar17 = puVar17 + -1;
      }
    }
  }
  return;
}


