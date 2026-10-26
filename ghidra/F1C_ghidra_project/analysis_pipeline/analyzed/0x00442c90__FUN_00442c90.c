// Function: FUN_00442c90 @ 00442c90
// Size (bytes): 1208


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00442c90(int param_1)

{
  double dVar1;
  int iVar2;
  float10 fVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  int iVar9;
  double *pdVar10;
  double *pdVar11;
  undefined4 *puVar12;
  double *pdVar13;
  float10 fVar14;
  int local_c8;
  undefined4 *local_b4;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80 [2];
  double local_70;
  undefined4 local_68 [4];
  double local_58 [10];
  
  local_b4 = local_68;
  pdVar10 = (double *)(param_1 + 0x410);
  local_c8 = 4;
  do {
    if (*(char *)((int)pdVar10 + 0x7c) == '\0') {
      iVar9 = *(int *)((int)pdVar10 + -0x24);
      if (iVar9 == 0) {
        iVar9 = *(int *)(param_1 + 0x141c);
      }
      FUN_00435e00(pdVar10 + -4,pdVar10 + -1);
      local_b0 = pdVar10[-1] + *(double *)(iVar9 + 4);
      local_a8 = *(double *)(iVar9 + 0xc) + *pdVar10;
      local_a0 = *(double *)(iVar9 + 0x14) + pdVar10[1];
      FUN_00435e00(pdVar10 + 2,pdVar10 + 5);
      iVar2 = *(int *)(param_1 + 0x15f0);
      local_70 = *(double *)(iVar2 + 0x14) + pdVar10[7];
      dVar1 = local_b0 - (*(double *)(iVar2 + 4) + pdVar10[5]);
      dVar4 = local_a8 - (*(double *)(iVar2 + 0xc) + pdVar10[6]);
      dVar6 = local_a0 - local_70;
      dVar7 = SQRT(dVar1 * dVar1 + dVar4 * dVar4 + dVar6 * dVar6);
      dVar5 = _DAT_0059e420 / dVar7;
      local_b0 = dVar1 * dVar5;
      local_a8 = dVar4 * dVar5;
      local_a0 = dVar6 * dVar5;
      pdVar11 = &local_b0;
      puVar12 = local_b4;
      for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar12 = *(undefined4 *)pdVar11;
        pdVar11 = (double *)((int)pdVar11 + 4);
        puVar12 = puVar12 + 1;
      }
      local_88 = *pdVar10 * *(double *)(iVar9 + 0x7c) - *(double *)(iVar9 + 0x84) * pdVar10[-1];
      local_80[0] = (*(double *)(iVar2 + 0x84) * pdVar10[7] - *(double *)(iVar2 + 0x8c) * pdVar10[6]
                    ) + *(double *)(iVar2 + 100);
      local_70 = (pdVar10[6] * *(double *)(iVar2 + 0x7c) - *(double *)(iVar2 + 0x84) * pdVar10[5]) +
                 *(double *)(iVar2 + 0x74);
      local_98 = ((*(double *)(iVar9 + 0x84) * pdVar10[1] - *(double *)(iVar9 + 0x8c) * *pdVar10) +
                 *(double *)(iVar9 + 100)) - local_80[0];
      local_90 = ((*(double *)(iVar9 + 0x8c) * pdVar10[-1] - *(double *)(iVar9 + 0x7c) * pdVar10[1])
                 + *(double *)(iVar9 + 0x6c)) -
                 ((*(double *)(iVar2 + 0x8c) * pdVar10[5] - pdVar10[7] * *(double *)(iVar2 + 0x7c))
                 + *(double *)(iVar2 + 0x6c));
      FUN_004380b0(dVar7,local_98 * dVar1 * dVar5 +
                         dVar4 * dVar5 * local_90 +
                         dVar6 * dVar5 * ((local_88 + *(double *)(iVar9 + 0x74)) - local_70));
    }
    local_b4 = local_b4 + 6;
    pdVar10 = (double *)((int)pdVar10 + 0x464);
    local_c8 = local_c8 + -1;
  } while (local_c8 != 0);
  if (DAT_007ce958 != 0) {
    iVar9 = *(int *)(param_1 + 0x15f0);
    dVar1 = *(double *)(iVar9 + 0x74) * *(double *)(iVar9 + 0x74) +
            *(double *)(iVar9 + 0x6c) * *(double *)(iVar9 + 0x6c) +
            *(double *)(iVar9 + 100) * *(double *)(iVar9 + 100);
    dVar4 = dVar1 * *(double *)(param_1 + 0x1448);
    *(double *)(param_1 + 0x490) = dVar4 + *(double *)(param_1 + 0x490);
    *(double *)(param_1 + 0x8f4) = dVar4 + *(double *)(param_1 + 0x8f4);
    dVar1 = dVar1 * *(double *)(param_1 + 0x1450);
    *(double *)(param_1 + 0xd58) = dVar1 + *(double *)(param_1 + 0xd58);
    *(double *)(param_1 + 0x11bc) = dVar1 + *(double *)(param_1 + 0x11bc);
  }
  if ((*(char *)(param_1 + 0x48c) == '\0') && (*(char *)(param_1 + 0x8f0) == '\0')) {
    dVar1 = ((*(double *)(param_1 + 0x474) - *(double *)(param_1 + 0x484)) -
            (*(double *)(param_1 + 0x8d8) - *(double *)(param_1 + 0x8e8))) *
            *(double *)(param_1 + 0x1438);
    dVar4 = dVar1 + *(double *)(param_1 + 0x490);
    *(double *)(param_1 + 0x490) = dVar4;
    dVar1 = *(double *)(param_1 + 0x8f4) - dVar1;
    *(double *)(param_1 + 0x8f4) = dVar1;
    if (*(char *)(param_1 + 0x1460) != '\0') {
      fVar14 = (float10)FUN_00436610((*(double *)(param_1 + 0x8d8) + *(double *)(param_1 + 0x474)) *
                                     _DAT_0059e880,
                                     (*(double *)(param_1 + 0x8e0) + *(double *)(param_1 + 0x47c)) *
                                     _DAT_0059e880);
      fVar3 = (float10)_DAT_0059e880;
      *(double *)(param_1 + 0x490) = (double)((float10)dVar4 + fVar14 * fVar3);
      *(double *)(param_1 + 0x8f4) = (double)((float10)dVar1 + fVar14 * fVar3);
    }
  }
  if ((*(char *)(param_1 + 0xd54) == '\0') && (*(char *)(param_1 + 0x11b8) == '\0')) {
    dVar1 = ((*(double *)(param_1 + 0xd3c) - *(double *)(param_1 + 0xd4c)) -
            (*(double *)(param_1 + 0x11a0) - *(double *)(param_1 + 0x11b0))) *
            *(double *)(param_1 + 0x1440);
    dVar4 = dVar1 + *(double *)(param_1 + 0xd58);
    *(double *)(param_1 + 0xd58) = dVar4;
    dVar1 = *(double *)(param_1 + 0x11bc) - dVar1;
    *(double *)(param_1 + 0x11bc) = dVar1;
    if (*(char *)(param_1 + 0x1460) != '\0') {
      fVar14 = (float10)FUN_00436610((*(double *)(param_1 + 0x11a0) + *(double *)(param_1 + 0xd3c))
                                     * _DAT_0059e880,
                                     (*(double *)(param_1 + 0x11a8) + *(double *)(param_1 + 0xd44))
                                     * _DAT_0059e880);
      fVar3 = (float10)_DAT_0059e880;
      *(double *)(param_1 + 0xd58) = (double)((float10)dVar4 + fVar14 * fVar3);
      *(double *)(param_1 + 0x11bc) = (double)((float10)dVar1 + fVar14 * fVar3);
    }
  }
  pdVar10 = local_58;
  param_1 = param_1 + 0x3ec;
  local_c8 = 4;
  do {
    if (*(char *)(param_1 + 0xa0) == '\0') {
      dVar1 = *(double *)(param_1 + 0xa4);
      local_98 = dVar1 * pdVar10[-2];
      local_90 = dVar1 * pdVar10[-1];
      local_88 = dVar1 * *pdVar10;
      pdVar11 = &local_98;
      pdVar13 = local_80;
      for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(undefined4 *)pdVar13 = *(undefined4 *)pdVar11;
        pdVar11 = (double *)((int)pdVar11 + 4);
        pdVar13 = (double *)((int)pdVar13 + 4);
      }
      FUN_00569ad0(param_1 + 0x1c,local_80);
      FUN_00569b70(param_1 + 0x4c,local_80);
    }
    param_1 = param_1 + 0x464;
    pdVar10 = pdVar10 + 3;
    local_c8 = local_c8 + -1;
  } while (local_c8 != 0);
  return;
}


