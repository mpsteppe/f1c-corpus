// Function: FUN_004e3090 @ 004e3090
// Size (bytes): 705


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e3090(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  float local_3c;
  float local_38;
  float local_24;
  float local_20;
  
  if (((*(int *)(param_2 + 0x70) != 0) && (*(char *)(param_2 + 0xb0) != '\0')) &&
     (*(int *)(param_1 + 0x8e4) != 0)) {
    local_3c = *(float *)(param_2 + 0xd4);
    fVar8 = *(float *)(param_2 + 0x74);
    fVar9 = *(float *)(param_2 + 0x78);
    fVar10 = *(float *)(param_2 + 0x124);
    local_38 = *(float *)(param_2 + 0xe0);
    if ((local_3c == DAT_0059e440) && (local_38 == DAT_0059e440)) {
      local_3c = 0.0;
      local_38 = 1.0;
      fVar11 = DAT_0059e440;
    }
    else {
      fVar11 = _DAT_0059e43c / SQRT(local_3c * local_3c + local_38 * local_38);
      local_3c = fVar11 * local_3c;
      local_38 = local_38 * fVar11;
      fVar11 = fVar11 * DAT_0059e440;
    }
    local_24 = local_38 - DAT_0059e440 * fVar11;
    local_20 = DAT_0059e440 * fVar11 - local_3c;
    fVar2 = local_3c * DAT_0059e440 - local_38 * DAT_0059e440;
    if (((local_24 == DAT_0059e440) && (local_20 == DAT_0059e440)) && (fVar2 == DAT_0059e440)) {
      local_24 = 1.0;
      local_20 = 0.0;
      fVar12 = DAT_0059e440;
    }
    else {
      fVar12 = _DAT_0059e43c / SQRT(local_24 * local_24 + local_20 * local_20 + fVar2 * fVar2);
      local_24 = local_24 * fVar12;
      local_20 = local_20 * fVar12;
      fVar12 = fVar12 * fVar2;
    }
    iVar14 = 0;
    if (0 < *(int *)(param_2 + 0x11c)) {
      iVar15 = 0;
      do {
        pfVar1 = (float *)(*(int *)(param_2 + 0x120) + 0xc + iVar15);
        pfVar13 = (float *)(*(int *)(param_2 + 0x120) + iVar15);
        iVar14 = iVar14 + 1;
        iVar15 = iVar15 + 0x20;
        fVar2 = pfVar13[3];
        fVar3 = pfVar13[4];
        fVar4 = pfVar13[5];
        fVar5 = pfVar13[3];
        fVar6 = pfVar13[4];
        fVar7 = pfVar13[5];
        *(float *)pfVar13[7] =
             ((fVar8 + (local_20 * fVar11 - fVar12 * local_38) * pfVar13[5] +
                       local_3c * pfVar13[4] + local_24 * *pfVar1) - *pfVar13) * pfVar13[6] +
             *pfVar13;
        *(float *)((int)pfVar13[7] + 4) =
             ((fVar9 + (local_3c * fVar12 - local_24 * fVar11) * fVar4 +
                       local_38 * fVar3 + local_20 * fVar2) - pfVar13[1]) * pfVar13[6] + pfVar13[1];
        *(float *)((int)pfVar13[7] + 8) =
             (((local_38 * local_24 - local_20 * local_3c) * fVar7 + fVar11 * fVar6 + fVar12 * fVar5
              + fVar10) - pfVar13[2]) * pfVar13[6] + pfVar13[2];
      } while (iVar14 < *(int *)(param_2 + 0x11c));
    }
    *(uint *)(*(int *)(param_1 + 0x8e4) + 0x14) =
         *(uint *)(*(int *)(param_1 + 0x8e4) + 0x14) & 0xfeffffdf;
  }
  return;
}


