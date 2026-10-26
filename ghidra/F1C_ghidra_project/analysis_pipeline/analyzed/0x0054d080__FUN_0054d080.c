// Function: FUN_0054d080 @ 0054d080
// Size (bytes): 1111


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0054d080(int param_1)

{
  ushort *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  int local_4;
  
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0x120)) {
    iVar14 = 0;
    do {
      puVar1 = (ushort *)(iVar14 + *(int *)(param_1 + 0x124));
      iVar8 = *(int *)(*(int *)(puVar1 + 4) + 0xc);
      uVar7 = (uint)*puVar1;
      uVar15 = (uint)puVar1[1];
      uVar9 = (uint)puVar1[2];
      if ((*(uint *)(param_1 + 0x14) & 0x800000) == 0) {
        pfVar10 = (float *)(uVar15 * 0x30 + iVar8);
        iVar13 = uVar7 * 0x30 + iVar8;
        pfVar11 = (float *)(uVar9 * 0x30 + iVar8);
        fVar2 = *(float *)(uVar7 * 0x30 + iVar8) + *pfVar10 + *pfVar11;
        fVar4 = *(float *)(iVar13 + 4) + pfVar10[1] + pfVar11[1];
        fVar3 = *(float *)(iVar13 + 8) + pfVar10[2] + pfVar11[2];
      }
      else {
        pfVar10 = (float *)(uVar7 * 0x40 + iVar8);
        pfVar11 = (float *)(uVar15 * 0x40 + iVar8);
        pfVar12 = (float *)(uVar9 * 0x40 + iVar8);
        fVar2 = *pfVar10 + *pfVar11 + *pfVar12;
        fVar4 = pfVar10[1] + pfVar11[1] + pfVar12[1];
        fVar3 = pfVar10[2] + pfVar11[2] + pfVar12[2];
      }
      *(float *)(puVar1 + 8) = fVar2 * _DAT_0059e98c;
      *(float *)(iVar14 + 0x14 + *(int *)(param_1 + 0x124)) = fVar4 * _DAT_0059e98c;
      *(float *)(iVar14 + 0x18 + *(int *)(param_1 + 0x124)) = fVar3 * _DAT_0059e98c;
      if ((*(uint *)(param_1 + 0x14) & 0x800000) == 0) {
        local_18 = *(float *)(uVar7 * 0x30 + iVar8);
        pfVar10 = (float *)(uVar7 * 0x30 + iVar8);
        local_1c = pfVar10[1];
        pfVar11 = (float *)(uVar15 * 0x30 + iVar8);
        fVar2 = pfVar10[2];
        fVar3 = local_18;
        if (*pfVar11 <= local_18) {
          fVar3 = *pfVar11;
        }
        pfVar12 = (float *)(iVar8 + uVar9 * 0x30);
        if (*(float *)(iVar8 + uVar9 * 0x30) <= fVar3) {
          fVar3 = *pfVar12;
        }
        if (local_18 <= *pfVar11) {
          local_18 = *pfVar11;
        }
        if (local_18 <= *pfVar12) {
          local_18 = *pfVar12;
        }
        local_10 = local_1c;
        if (pfVar11[1] <= local_1c) {
          local_10 = pfVar11[1];
        }
        if (pfVar12[1] <= local_10) {
          local_10 = pfVar12[1];
        }
        if (local_1c <= pfVar11[1]) {
          local_1c = pfVar11[1];
        }
        if (local_1c <= pfVar12[1]) {
          local_1c = pfVar12[1];
        }
        local_14 = fVar2;
        if (pfVar11[2] <= fVar2) {
          local_14 = pfVar11[2];
        }
        if (pfVar12[2] <= local_14) {
          local_14 = pfVar12[2];
        }
        if (fVar2 <= pfVar11[2]) {
          fVar2 = pfVar11[2];
        }
        if (fVar2 <= pfVar12[2]) {
          fVar2 = pfVar12[2];
        }
        fVar3 = (fVar2 - local_14) * (fVar2 - local_14) +
                (local_1c - local_10) * (local_1c - local_10) +
                (local_18 - fVar3) * (local_18 - fVar3);
      }
      else {
        iVar13 = iVar14 + *(int *)(param_1 + 0x124);
        fVar3 = *(float *)(iVar14 + 0x10 + *(int *)(param_1 + 0x124)) -
                *(float *)(uVar7 * 0x40 + iVar8);
        pfVar10 = (float *)(uVar7 * 0x40 + iVar8);
        fVar4 = *(float *)(iVar13 + 0x14) - pfVar10[1];
        pfVar11 = (float *)(uVar15 * 0x40 + iVar8);
        fVar2 = *(float *)(iVar13 + 0x18) - pfVar10[2];
        fVar3 = fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2;
        fVar2 = *(float *)(iVar13 + 0x10) - *pfVar11;
        fVar5 = *(float *)(iVar13 + 0x14) - pfVar11[1];
        fVar4 = *(float *)(iVar13 + 0x18) - pfVar11[2];
        fVar2 = fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4;
        if (fVar3 <= fVar2) {
          fVar3 = fVar2;
        }
        fVar2 = *(float *)(iVar13 + 0x10) - *(float *)(uVar9 * 0x40 + iVar8);
        iVar8 = uVar9 * 0x40 + iVar8;
        fVar5 = *(float *)(iVar13 + 0x14) - *(float *)(iVar8 + 4);
        fVar4 = *(float *)(iVar13 + 0x18) - *(float *)(iVar8 + 8);
        fVar2 = fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4;
        if (fVar3 <= fVar2) {
          fVar3 = fVar2;
        }
      }
      *(float *)(iVar14 + 0x1c + *(int *)(param_1 + 0x124)) = SQRT(fVar3);
      iVar8 = *(int *)(*(int *)(param_1 + 0x124) + 0xc + iVar14) * 0x10;
      pfVar11 = (float *)(iVar8 + *(int *)(param_1 + 300));
      *(float *)(*(int *)(param_1 + 0x124) + iVar14 + 0x20) =
           *pfVar10 * *pfVar11 +
           pfVar10[1] * pfVar11[1] + pfVar10[2] * *(float *)(iVar8 + 8 + *(int *)(param_1 + 300));
      if (ABS(*pfVar11) <= ABS(pfVar11[1])) {
        if (ABS(pfVar11[1]) <= ABS(pfVar11[2])) goto LAB_0054d48a;
        uVar6 = 2;
        if (pfVar11[1] <= DAT_0059e440) {
          uVar6 = 3;
        }
      }
      else if (ABS(*pfVar11) <= ABS(pfVar11[2])) {
LAB_0054d48a:
        uVar6 = 4;
        if (pfVar11[2] <= DAT_0059e440) {
          uVar6 = 5;
        }
      }
      else if (*pfVar11 <= DAT_0059e440) {
        uVar6 = 1;
      }
      else {
        uVar6 = 0;
      }
      *(undefined2 *)(iVar14 + 6 + *(int *)(param_1 + 0x124)) = uVar6;
      local_4 = local_4 + 1;
      iVar14 = iVar14 + 0x24;
    } while (local_4 < *(int *)(param_1 + 0x120));
  }
  return;
}


