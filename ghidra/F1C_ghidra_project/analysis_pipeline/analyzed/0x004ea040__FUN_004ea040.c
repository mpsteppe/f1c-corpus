// Function: FUN_004ea040 @ 004ea040
// Size (bytes): 2283


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ea040(int param_1,int param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  int iVar8;
  undefined4 *puVar9;
  double *pdVar10;
  float local_f4;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  float local_88 [10];
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  local_90 = *(undefined4 *)(param_2 + 0xc);
  local_8c = *(undefined4 *)(param_2 + 0x10);
  local_88[0] = *(float *)(param_2 + 0x14);
  pfVar7 = (float *)FUN_004ea930(&local_d8);
  local_e4 = *pfVar7;
  local_e0 = pfVar7[1];
  local_dc = pfVar7[2];
  fVar1 = local_e4 * *(float *)(param_1 + 0x34b0) +
          local_e0 * *(float *)(param_1 + 0x34bc) + local_dc * *(float *)(param_1 + 0x34c8);
  local_c8 = local_e4 * *(float *)(param_1 + 0x34b4) +
             local_e0 * *(float *)(param_1 + 0x34c0) + local_dc * *(float *)(param_1 + 0x34cc);
  local_c4 = local_e4 * *(float *)(param_1 + 0x34b8) +
             local_e0 * *(float *)(param_1 + 0x34c4) + local_dc * *(float *)(param_1 + 0x34d0);
  local_a0 = *(float *)(param_1 + 0x744) + *(float *)(param_1 + 0x72c);
  local_9c = *(float *)(param_1 + 0x748) + *(float *)(param_1 + 0x730);
  local_98 = *(float *)(param_1 + 0x74c) + *(float *)(param_1 + 0x734);
  local_b0 = *(float *)(param_1 + 0x750) + *(float *)(param_1 + 0x72c);
  local_ac = *(float *)(param_1 + 0x754) + *(float *)(param_1 + 0x730);
  local_a8 = *(float *)(param_1 + 0x758) + *(float *)(param_1 + 0x734);
  if ((((local_a0 - *(float *)(param_2 + 0x18) <= fVar1) &&
       (fVar1 <= *(float *)(param_2 + 0x18) + local_b0)) &&
      (local_9c - *(float *)(param_2 + 0x18) <= local_c8)) &&
     (((local_c8 <= *(float *)(param_2 + 0x18) + local_ac &&
       (local_98 - *(float *)(param_2 + 0x18) <= local_c4)) &&
      (local_c4 <= *(float *)(param_2 + 0x18) + local_a8)))) {
    local_d8 = (float)*(double *)(param_4 + 4);
    iVar8 = 0;
    pdVar10 = (double *)(param_4 + 0x1c);
    local_d4 = (float)*(double *)(param_4 + 0xc);
    local_d0 = (float)*(double *)(param_4 + 0x14);
    do {
      iVar8 = iVar8 + 1;
      local_88[iVar8] = (float)*pdVar10;
      pdVar10 = pdVar10 + 1;
    } while (iVar8 < 9);
    local_e8 = 3.4028235e+38;
    FUN_0054c230(0);
    local_94 = FUN_0054e100();
    if (0 < local_94) {
      iVar8 = 0;
      do {
        pfVar7 = (float *)FUN_0054e120(iVar8);
        fVar1 = *pfVar7;
        fVar2 = pfVar7[1];
        fVar3 = pfVar7[2];
        local_cc = local_88[1] * fVar1 + local_88[2] * fVar2 + local_88[3] * fVar3;
        local_c8 = local_88[4] * fVar1 + local_88[5] * fVar2 + local_88[6] * fVar3 + local_d4;
        local_c4 = local_88[7] * fVar1 + local_88[8] * fVar2 + local_88[9] * fVar3 + local_d0;
        fVar1 = (local_cc + local_d8) - *(float *)(param_1 + 0x34d4);
        fVar6 = local_c8 - *(float *)(param_1 + 0x34d8);
        fVar5 = local_c4 - *(float *)(param_1 + 0x34dc);
        fVar3 = fVar6 * *(float *)(param_1 + 0x34bc) +
                fVar1 * *(float *)(param_1 + 0x34b0) + fVar5 * *(float *)(param_1 + 0x34c8);
        fVar2 = fVar6 * *(float *)(param_1 + 0x34c0) +
                fVar1 * *(float *)(param_1 + 0x34b4) + fVar5 * *(float *)(param_1 + 0x34cc);
        fVar1 = fVar5 * *(float *)(param_1 + 0x34d0) +
                fVar6 * *(float *)(param_1 + 0x34c4) + fVar1 * *(float *)(param_1 + 0x34b8);
        if (((local_a0 < fVar3) && (fVar3 < local_b0)) &&
           (((local_9c < fVar2 && (((fVar2 < local_ac && (local_98 < fVar1)) && (fVar1 < local_a8)))
             ) && (fVar5 = fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1, fVar5 < local_e8)))) {
          local_e8 = fVar5;
          local_e4 = fVar3;
          local_e0 = fVar2;
          local_dc = fVar1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < local_94);
      if (local_e8 != _DAT_0059eae0) {
        puVar9 = (undefined4 *)FUN_004ea010();
        local_e8 = SQRT(local_e8);
        *puVar9 = 0xffffffff;
        uVar4 = *(undefined4 *)(param_2 + 0x1c);
        puVar9[4] = param_2;
        puVar9[3] = uVar4;
        fVar1 = *(float *)(param_1 + 0x3b70) - local_e8;
        if (fVar1 < DAT_0059e440) {
          fVar1 = DAT_0059e440;
        }
        local_cc = -local_e4;
        local_c8 = -local_e0;
        local_c4 = -local_dc;
        local_d4 = local_c8;
        local_f4 = local_cc;
        local_ec = local_c4;
        if (DAT_0059e440 < local_e8) {
          fVar1 = fVar1 / local_e8;
          local_d4 = local_c8 * fVar1;
          local_f4 = fVar1 * local_cc;
          local_ec = local_c4 * fVar1;
        }
        if (DAT_0059e440 <= local_e4) {
          local_d8 = local_b0 - local_e4;
        }
        else {
          local_d8 = local_e4 - local_a0;
        }
        if (DAT_0059e440 <= local_dc) {
          local_d0 = local_a8 - local_dc;
        }
        else {
          local_d0 = local_dc - local_98;
        }
        if (local_d0 <= local_d8) {
          if (DAT_0059e440 <= local_dc) {
            local_d0 = -local_d0;
          }
          local_d8 = 0.0;
        }
        else {
          local_d0 = DAT_0059e440;
          if (DAT_0059e440 <= local_e4) {
            local_d8 = -local_d8;
          }
        }
        local_d0 = local_ec + local_d0;
        fVar1 = (local_d8 + local_f4) * _DAT_0059e84c;
        fVar5 = local_d4 * _DAT_0059e84c;
        fVar3 = local_d0 * _DAT_0059e84c;
        fVar2 = SQRT(fVar1 * fVar1 + fVar5 * fVar5 + fVar3 * fVar3);
        puVar9[2] = fVar2;
        if (fVar2 <= DAT_0059e440) {
          puVar9[0xb] = 0;
          puVar9[0xc] = 0x3f800000;
          puVar9[0xd] = 0;
        }
        else {
          puVar9[0xb] = fVar1 * *(float *)(param_1 + 0x34b0) +
                        fVar5 * *(float *)(param_1 + 0x34b4) + fVar3 * *(float *)(param_1 + 0x34b8);
          puVar9[0xc] = fVar1 * *(float *)(param_1 + 0x34bc) +
                        fVar5 * *(float *)(param_1 + 0x34c0) + fVar3 * *(float *)(param_1 + 0x34c4);
          puVar9[0xd] = fVar1 * *(float *)(param_1 + 0x34c8) +
                        fVar5 * *(float *)(param_1 + 0x34cc) + fVar3 * *(float *)(param_1 + 0x34d0);
          fVar2 = _DAT_0059e43c / (float)puVar9[2];
          puVar9[0xb] = fVar2 * (float)puVar9[0xb];
          puVar9[0xc] = fVar2 * (float)puVar9[0xc];
          puVar9[0xd] = fVar2 * (float)puVar9[0xd];
        }
        local_e4 = local_e4 - fVar1;
        pfVar7 = (float *)(puVar9 + 5);
        local_e0 = local_e0 - fVar5;
        local_dc = local_dc - fVar3;
        *pfVar7 = local_e4 * *(float *)(param_1 + 0x34b0) +
                  local_e0 * *(float *)(param_1 + 0x34b4) + local_dc * *(float *)(param_1 + 0x34b8);
        puVar9[6] = local_e4 * *(float *)(param_1 + 0x34bc) +
                    local_e0 * *(float *)(param_1 + 0x34c0) +
                    local_dc * *(float *)(param_1 + 0x34c4);
        puVar9[7] = local_e4 * *(float *)(param_1 + 0x34c8) +
                    local_e0 * *(float *)(param_1 + 0x34cc) +
                    local_dc * *(float *)(param_1 + 0x34d0);
        *pfVar7 = *pfVar7 + *(float *)(param_1 + 0x34d4);
        puVar9[6] = *(float *)(param_1 + 0x34d8) + (float)puVar9[6];
        puVar9[7] = *(float *)(param_1 + 0x34dc) + (float)puVar9[7];
        FUN_004ed420(pfVar7,puVar9 + 0xb,&local_b4,&local_a4,&local_c0);
        local_20 = (double)*pfVar7;
        local_18 = (double)(float)puVar9[6];
        local_10 = (double)(float)puVar9[7];
        local_50 = (double)(float)puVar9[0xb];
        local_48 = (double)(float)puVar9[0xc];
        local_40 = (double)(float)puVar9[0xd];
        FUN_005694e0(&local_20,&local_50,&local_60,&local_58,&local_38);
        local_b4 = local_b4 - (float)local_60;
        local_b8 = local_b8 - (float)local_28;
        local_c0 = local_c0 - (float)local_38;
        local_bc = local_bc - (float)local_30;
        if (DAT_0059e440 < local_b4) {
          local_b4 = 0.0;
        }
        fVar1 = -(local_b4 / ((float)local_58 + local_a4));
        if ((float)_DAT_0059e420 < local_bc * local_bc + local_c0 * local_c0 + local_b8 * local_b8)
        {
          fVar2 = _DAT_0059e43c /
                  SQRT(local_bc * local_bc + local_c0 * local_c0 + local_b8 * local_b8);
          local_c0 = local_c0 * fVar2;
          local_bc = local_bc * fVar2;
          local_b8 = fVar2 * local_b8;
        }
        fVar3 = _DAT_0059e7e8 * fVar1;
        fVar5 = fVar1 * (float)puVar9[0xb] - local_c0 * fVar3;
        fVar2 = fVar1 * (float)puVar9[0xc] - fVar3 * local_bc;
        fVar3 = fVar1 * (float)puVar9[0xd] - fVar3 * local_b8;
        fVar1 = SQRT(fVar5 * fVar5 + fVar2 * fVar2 + fVar3 * fVar3);
        puVar9[1] = fVar1;
        if (DAT_0059e440 < fVar1) {
          fVar1 = _DAT_0059e43c / fVar1;
          puVar9[8] = fVar1 * fVar5;
          puVar9[9] = fVar2 * fVar1;
          puVar9[10] = fVar1 * fVar3;
          return;
        }
        puVar9[8] = 0;
        puVar9[9] = 0;
        puVar9[10] = 0;
      }
    }
  }
  return;
}


