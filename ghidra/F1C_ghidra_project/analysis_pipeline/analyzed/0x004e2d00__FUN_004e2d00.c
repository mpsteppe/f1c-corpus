// Function: FUN_004e2d00 @ 004e2d00
// Size (bytes): 838


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e2d00(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  float *pfVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  float local_28;
  int local_24;
  float local_20 [8];
  
  local_20[0] = 0.0;
  local_20[4] = 3.4028235e+38;
  local_20[1] = 0.0;
  local_20[2] = 0.0;
  local_20[5] = 3.4028235e+38;
  local_20[6] = 3.4028235e+38;
  local_20[3] = 0.0;
  puVar4 = (undefined4 *)(param_1 + 500);
  local_20[7] = 3.4028235e+38;
  iVar9 = 4;
  do {
    puVar4[-1] = 0;
    *puVar4 = 0;
    puVar4[1] = puVar4[-0x29];
    puVar4 = puVar4 + 0x4a;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *(undefined4 *)(param_1 + 0x8e4) = 0;
  if (*(int *)(param_1 + 0x890) != 0) {
    iVar9 = FUN_0054c210();
    iVar12 = 0;
    if (0 < iVar9) {
      do {
        iVar5 = FUN_0054c230(iVar12);
        if (*(float *)(iVar5 + 0xf4) == DAT_0059e440) {
          *(int *)(param_1 + 0x8e4) = iVar5;
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < iVar9);
    }
    if (*(int *)(param_1 + 0x8e4) != 0) {
      iVar9 = FUN_0054e100();
      iVar12 = 0;
      if (0 < iVar9) {
        do {
          pfVar6 = (float *)FUN_0054e120(iVar12);
          fVar1 = *pfVar6;
          iVar5 = 0;
          local_28 = 3.4028235e+38;
          iVar10 = 0;
          pfVar11 = (float *)(param_1 + 0x150);
          do {
            fVar2 = fVar1 - pfVar11[-2];
            fVar2 = fVar2 * fVar2 +
                    (pfVar6[1] - pfVar11[-1]) * (pfVar6[1] - pfVar11[-1]) +
                    (pfVar6[2] - *pfVar11) * (pfVar6[2] - *pfVar11);
            if (fVar2 < local_28) {
              iVar5 = iVar10;
              local_28 = fVar2;
            }
            iVar10 = iVar10 + 1;
            pfVar11 = pfVar11 + 0x4a;
          } while (iVar10 < 4);
          local_20[iVar5] = (float)((int)local_20[iVar5] + 1);
          fVar1 = ABS(fVar1);
          if (fVar1 < local_20[iVar5 + 4]) {
            local_20[iVar5 + 4] = fVar1;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 < iVar9);
      }
      local_20[4] = 0.1;
      local_20[5] = 0.1;
      local_20[6] = 0.1;
      local_20[7] = 0.1;
      iVar12 = 0;
      puVar4 = (undefined4 *)(param_1 + 500);
      do {
        pvVar7 = operator_new((int)local_20[iVar12] << 5);
        *puVar4 = pvVar7;
        iVar12 = iVar12 + 1;
        puVar4 = puVar4 + 0x4a;
      } while (iVar12 < 4);
      local_24 = 0;
      if (0 < iVar9) {
        do {
          pfVar6 = (float *)FUN_0054e120(local_24);
          local_20[0] = *pfVar6;
          iVar12 = 0;
          local_20[1] = pfVar6[1];
          local_28 = 3.4028235e+38;
          local_20[2] = pfVar6[2];
          iVar5 = 0;
          pfVar11 = (float *)(param_1 + 0x150);
          do {
            fVar1 = (local_20[0] - pfVar11[-2]) * (local_20[0] - pfVar11[-2]) +
                    (local_20[1] - pfVar11[-1]) * (local_20[1] - pfVar11[-1]) +
                    (local_20[2] - *pfVar11) * (local_20[2] - *pfVar11);
            if (fVar1 < local_28) {
              iVar12 = iVar5;
              local_28 = fVar1;
            }
            iVar5 = iVar5 + 1;
            pfVar11 = pfVar11 + 0x4a;
          } while (iVar5 < 4);
          iVar8 = iVar12 * 0x128;
          iVar10 = *(int *)(iVar8 + 0x1f0 + param_1);
          iVar5 = iVar8 + 0xd4 + param_1;
          pfVar11 = (float *)(iVar10 * 0x20 + *(int *)(iVar8 + 500 + param_1));
          *(int *)(iVar5 + 0x11c) = iVar10 + 1;
          *pfVar11 = local_20[0];
          pfVar11[1] = local_20[1];
          pfVar11[2] = local_20[2];
          fVar1 = local_20[0] - *(float *)(iVar5 + 0x74);
          fVar3 = local_20[1] - *(float *)(iVar5 + 0x78);
          fVar2 = local_20[2] - *(float *)(iVar5 + 0x7c);
          pfVar11[3] = fVar1 * *(float *)(iVar5 + 0x8c) +
                       fVar3 * *(float *)(iVar5 + 0x98) + fVar2 * *(float *)(iVar5 + 0xa4);
          pfVar11[4] = fVar1 * *(float *)(iVar5 + 0x90) +
                       fVar3 * *(float *)(iVar5 + 0x9c) + fVar2 * *(float *)(iVar5 + 0xa8);
          pfVar11[5] = fVar1 * *(float *)(iVar5 + 0x94) +
                       fVar3 * *(float *)(iVar5 + 0xa0) + fVar2 * *(float *)(iVar5 + 0xac);
          pfVar11[7] = (float)pfVar6;
          fVar1 = (ABS(*(float *)(iVar5 + 0x74)) - local_20[iVar12 + 4]) - _DAT_005ad15c;
          if (fVar1 < DAT_0059e440 == (fVar1 == DAT_0059e440)) {
            pfVar11[6] = (ABS(local_20[0]) - local_20[iVar12 + 4]) / fVar1;
          }
          else {
            pfVar11[6] = 0.0;
          }
          local_24 = local_24 + 1;
        } while (local_24 < iVar9);
      }
    }
  }
  return;
}


