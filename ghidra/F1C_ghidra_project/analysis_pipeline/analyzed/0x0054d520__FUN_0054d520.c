// Function: FUN_0054d520 @ 0054d520
// Size (bytes): 628


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0054d520(int param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  int local_4;
  
  local_4 = *(int *)(param_1 + 0x118);
  local_c = 1e+12;
  local_10 = 1e+12;
  local_18 = 1e+12;
  local_14 = -1e+12;
  local_1c = -1e+12;
  fVar1 = _DAT_005b8984;
  if (0 < local_4) {
    piVar5 = (int *)(*(int *)(param_1 + 0x11c) + 8);
    do {
      iVar7 = *piVar5;
      if (0 < iVar7) {
        pfVar8 = (float *)piVar5[1];
        pfVar9 = pfVar8;
        do {
          pfVar6 = pfVar9;
          if ((*(uint *)(param_1 + 0x14) & 0x800000) == 0) {
            pfVar6 = pfVar8;
          }
          if (*pfVar6 < local_18) {
            local_18 = *pfVar6;
          }
          if (local_1c < *pfVar6) {
            local_1c = *pfVar6;
          }
          if (pfVar6[1] < local_10) {
            local_10 = pfVar6[1];
          }
          if (local_14 < pfVar6[1]) {
            local_14 = pfVar6[1];
          }
          if (pfVar6[2] < local_c) {
            local_c = pfVar6[2];
          }
          if (fVar1 < pfVar6[2]) {
            fVar1 = pfVar6[2];
          }
          pfVar9 = pfVar9 + 0x10;
          pfVar8 = pfVar8 + 0xc;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      piVar5 = piVar5 + 0x10;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  *(float *)(param_1 + 0x30) = fVar1;
  *(float *)(param_1 + 0x3c) = fVar1;
  *(float *)(param_1 + 0x20) = local_10;
  *(float *)(param_1 + 0x60) = fVar1;
  *(float *)(param_1 + 0x6c) = fVar1;
  *(float *)(param_1 + 0x28) = local_1c;
  *(float *)(param_1 + 0x34) = local_18;
  *(float *)(param_1 + 0x40) = local_18;
  *(float *)(param_1 + 0x48) = local_c;
  *(float *)(param_1 + 0x1c) = local_1c;
  *(float *)(param_1 + 0x50) = local_14;
  *(float *)(param_1 + 0x24) = local_c;
  *(float *)(param_1 + 0x58) = local_1c;
  *(float *)(param_1 + 0x2c) = local_10;
  *(float *)(param_1 + 0x38) = local_10;
  *(float *)(param_1 + 0x44) = local_10;
  *(float *)(param_1 + 100) = local_18;
  *(float *)(param_1 + 0x70) = local_18;
  *(float *)(param_1 + 0x4c) = local_1c;
  *(float *)(param_1 + 0x78) = local_c;
  *(float *)(param_1 + 0x54) = local_c;
  *(float *)(param_1 + 0x5c) = local_14;
  *(float *)(param_1 + 0x68) = local_14;
  *(float *)(param_1 + 0x74) = local_14;
  if (local_18 == local_1c) {
    uVar4 = *(uint *)(param_1 + 0x14) & 0xffffffef;
  }
  else if (local_10 == local_14) {
    uVar4 = *(uint *)(param_1 + 0x14) & 0xffffffef;
  }
  else if (local_c == fVar1) {
    uVar4 = *(uint *)(param_1 + 0x14) & 0xffffffef;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x14) | 0x10;
  }
  *(uint *)(param_1 + 0x14) = uVar4;
  if ((param_2 & 1) != 0) {
    *(float *)(param_1 + 0xdc) = (local_1c + local_18) * _DAT_0059e450;
    *(float *)(param_1 + 0xe0) = (local_14 + local_10) * _DAT_0059e450;
    *(float *)(param_1 + 0xe4) = (local_c + fVar1) * _DAT_0059e450;
  }
  fVar2 = (local_1c - local_18) * _DAT_0059e450;
  fVar3 = (local_14 - local_10) * _DAT_0059e450;
  fVar1 = (fVar1 - local_c) * _DAT_0059e450;
  *(float *)(param_1 + 0x18) = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
  return;
}


