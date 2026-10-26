// Function: FUN_0053b6f0 @ 0053b6f0
// Size (bytes): 1068


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053b6f0(undefined8 *param_1,double *param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  bool bVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  double *pdVar10;
  int iVar11;
  double *pdVar12;
  undefined4 *puVar13;
  double *pdVar14;
  int iVar15;
  undefined8 *puVar16;
  double *pdVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  double *pdVar20;
  int local_78;
  int local_70;
  int local_6c;
  int local_68;
  int local_5c;
  undefined8 local_38;
  double adStack_30 [5];
  
  iVar15 = 3;
  puVar13 = param_3;
  puVar18 = param_3;
  do {
    puVar19 = puVar18;
    for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar19 = 0;
      puVar19 = puVar19 + 1;
    }
    *puVar13 = 0;
    puVar13[1] = 0x3ff00000;
    puVar18 = puVar18 + 6;
    puVar13 = puVar13 + 8;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  puVar16 = &local_38;
  for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
    *(undefined4 *)puVar16 = 0;
    puVar16 = (undefined8 *)((int)puVar16 + 4);
  }
  iVar15 = 0;
  puVar16 = param_1;
  do {
    uVar2 = *puVar16;
    puVar1 = (undefined8 *)((int)adStack_30 + iVar15 + 0x10);
    iVar15 = iVar15 + 8;
    *(undefined8 *)(((int)param_2 - (int)(adStack_30 + 2)) + (int)puVar1) = uVar2;
    puVar16 = puVar16 + 4;
    *puVar1 = uVar2;
  } while (iVar15 < 0x18);
  local_70 = 0;
  do {
    iVar11 = 0;
    iVar15 = 1;
    dVar7 = _DAT_0059e430;
    do {
      if (iVar15 < 3) {
        pdVar17 = (double *)(param_1 + iVar15 + iVar11);
        iVar9 = 3 - iVar15;
        do {
          dVar3 = *pdVar17;
          pdVar17 = pdVar17 + 1;
          iVar9 = iVar9 + -1;
          dVar7 = ABS(dVar3) + dVar7;
        } while (iVar9 != 0);
      }
      iVar11 = iVar11 + 3;
      bVar6 = iVar15 < 2;
      iVar15 = iVar15 + 1;
    } while (bVar6);
    if (dVar7 == _DAT_0059e430) {
      return;
    }
    dVar3 = _DAT_0059e430;
    if (local_70 < 4) {
      dVar3 = dVar7 * _DAT_005b8970;
    }
    local_5c = 0;
    pdVar17 = param_2;
    iVar15 = 1;
    do {
      if (iVar15 < 3) {
        iVar11 = (int)adStack_30 + (-8 - (int)param_2);
        local_78 = iVar15 + 1;
        pdVar14 = (double *)(param_1 + local_5c + iVar15);
        pdVar20 = pdVar17;
        local_6c = iVar15;
        local_68 = local_5c;
        do {
          local_68 = local_68 + 3;
          pdVar20 = pdVar20 + 1;
          dVar7 = _DAT_0059ea20 * ABS(*pdVar14);
          if (((local_70 < 5) || (ABS(*pdVar17) != ABS(dVar7 + *pdVar17))) ||
             (ABS(*pdVar20) != ABS(dVar7 + *pdVar20))) {
            if (dVar3 < ABS(*pdVar14)) {
              dVar4 = *pdVar20 - *pdVar17;
              if (dVar7 + ABS(dVar4) == ABS(dVar4)) {
                dVar4 = *pdVar14 / dVar4;
              }
              else {
                dVar7 = (_DAT_0059e880 / *pdVar14) * dVar4;
                dVar4 = _DAT_0059e420 / (ABS(dVar7) + SQRT(dVar7 * dVar7 + _DAT_0059e420));
                if (dVar7 < _DAT_0059e430) {
                  dVar4 = -dVar4;
                }
              }
              dVar8 = _DAT_0059e420 / SQRT(dVar4 * dVar4 + _DAT_0059e420);
              dVar7 = dVar8 * dVar4;
              dVar8 = dVar7 / (dVar8 + _DAT_0059e420);
              dVar4 = dVar4 * *pdVar14;
              *(double *)(iVar11 + (int)pdVar17) = *(double *)(iVar11 + (int)pdVar17) - dVar4;
              *(double *)(iVar11 + (int)pdVar20) = dVar4 + *(double *)(iVar11 + (int)pdVar20);
              *pdVar17 = *pdVar17 - dVar4;
              *pdVar20 = dVar4 + *pdVar20;
              *(undefined4 *)pdVar14 = 0;
              *(undefined4 *)((int)pdVar14 + 4) = 0;
              if (iVar15 != 2 && -1 < iVar15 + -2) {
                iVar9 = iVar15 + -2;
                pdVar10 = (double *)(((int)param_1 - (int)param_2) + (int)pdVar17);
                pdVar12 = (double *)(((int)param_1 - (int)param_2) + (int)pdVar20);
                do {
                  dVar4 = *pdVar10;
                  dVar5 = *pdVar12;
                  iVar9 = iVar9 + -1;
                  *pdVar10 = dVar4 - (dVar8 * dVar4 + dVar5) * dVar7;
                  *pdVar12 = (dVar4 - dVar8 * dVar5) * dVar7 + dVar5;
                  pdVar10 = pdVar10 + 3;
                  pdVar12 = pdVar12 + 3;
                } while (iVar9 != 0);
              }
              if (iVar15 < local_78 + -2) {
                iVar9 = (local_78 - iVar15) + -2;
                pdVar10 = (double *)(param_1 + local_5c + iVar15);
                pdVar12 = (double *)(param_1 + local_6c + iVar15 * 3);
                do {
                  dVar4 = *pdVar10;
                  dVar5 = *pdVar12;
                  iVar9 = iVar9 + -1;
                  *pdVar10 = dVar4 - (dVar8 * dVar4 + dVar5) * dVar7;
                  *pdVar12 = (dVar4 - dVar8 * dVar5) * dVar7 + dVar5;
                  pdVar10 = pdVar10 + 1;
                  pdVar12 = pdVar12 + 3;
                } while (iVar9 != 0);
              }
              if (local_78 < 3) {
                iVar9 = 3 - local_78;
                pdVar12 = (double *)(param_1 + local_78 + local_68);
                pdVar10 = pdVar14;
                do {
                  pdVar10 = pdVar10 + 1;
                  dVar4 = *pdVar10;
                  dVar5 = *pdVar12;
                  iVar9 = iVar9 + -1;
                  *pdVar10 = dVar4 - (dVar8 * dVar4 + dVar5) * dVar7;
                  *pdVar12 = (dVar4 - dVar8 * dVar5) * dVar7 + dVar5;
                  pdVar12 = pdVar12 + 1;
                } while (iVar9 != 0);
              }
              iVar9 = 3;
              pdVar10 = (double *)(((int)param_3 - (int)param_2) + (int)pdVar17);
              pdVar12 = (double *)(((int)param_3 - (int)param_2) + (int)pdVar20);
              do {
                dVar4 = *pdVar10;
                dVar5 = *pdVar12;
                iVar9 = iVar9 + -1;
                *pdVar10 = dVar4 - (dVar8 * dVar4 + dVar5) * dVar7;
                *pdVar12 = (dVar4 - dVar8 * dVar5) * dVar7 + dVar5;
                pdVar10 = pdVar10 + 3;
                pdVar12 = pdVar12 + 3;
              } while (iVar9 != 0);
            }
          }
          else {
            *(undefined4 *)pdVar14 = 0;
            *(undefined4 *)((int)pdVar14 + 4) = 0;
          }
          local_6c = local_6c + 1;
          local_78 = local_78 + 1;
          pdVar14 = pdVar14 + 1;
        } while (local_78 < 4);
      }
      local_5c = local_5c + 3;
      pdVar17 = pdVar17 + 1;
      bVar6 = iVar15 < 2;
      iVar15 = iVar15 + 1;
    } while (bVar6);
    iVar15 = 0;
    do {
      dVar7 = *(double *)((int)adStack_30 + iVar15 + -8) +
              *(double *)((int)adStack_30 + iVar15 + 0x10);
      pdVar17 = (double *)((int)adStack_30 + iVar15 + 0x10);
      *(undefined4 *)((int)adStack_30 + iVar15 + -8) = 0;
      *(undefined4 *)((int)adStack_30 + iVar15 + -4) = 0;
      iVar15 = iVar15 + 8;
      *pdVar17 = dVar7;
      *(double *)(((int)param_2 - (int)(adStack_30 + 2)) + (int)pdVar17) = dVar7;
    } while (iVar15 < 0x18);
    local_70 = local_70 + 1;
  } while (local_70 < 0x32);
  return;
}


