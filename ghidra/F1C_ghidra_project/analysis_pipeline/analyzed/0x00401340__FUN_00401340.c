// Function: FUN_00401340 @ 00401340
// Size (bytes): 1474


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00401340(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
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
  float local_94;
  float local_90;
  float local_8c;
  int local_88;
  int local_84;
  int local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  double local_64;
  double local_5c;
  double local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  double local_3c;
  int local_34;
  int local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_18;
  float local_c;
  
  local_2c = 0.0;
  local_28 = 0xc11cf5c3;
  local_24 = 0;
  if (param_2 == 0) {
    local_80 = *(int *)(param_1 + 0x130);
  }
  else {
    local_80 = 1;
  }
  iVar10 = 0;
  if (0 < local_80) {
    local_88 = 0;
    local_30 = param_1;
    do {
      iVar9 = param_2;
      if (param_2 == 0) {
        iVar9 = *(int *)(local_30 + 0x134) + local_88;
      }
      local_84 = *(int *)(iVar9 + 0x110);
      *(undefined4 *)(iVar9 + 0x70) = 0;
      *(undefined4 *)(iVar9 + 0x74) = 0;
      *(float *)(iVar9 + 0x78) = local_2c;
      *(undefined4 *)(iVar9 + 0x7c) = local_28;
      iVar1 = *(int *)(iVar9 + 0x10c);
      *(undefined4 *)(iVar9 + 0x80) = local_24;
      if ((local_84 != 0) && (iVar1 != 0)) {
        local_b8 = *(float *)(iVar1 + 0x94);
        local_b4 = *(float *)(iVar1 + 0x98);
        local_b0 = *(float *)(iVar1 + 0x9c);
        local_64 = (double)local_b8;
        local_5c = (double)local_b4;
        local_54 = (double)local_b0;
        local_4c = 0;
        local_48 = 0x3ff00000;
        local_44 = 0x40000000;
        local_40 = 0x479e17b8;
        local_34 = iVar10;
        iVar10 = FUN_0044c4c0();
        if (iVar10 != 0) {
          local_b4 = (float)local_3c;
          local_ac = *(float *)(iVar9 + 0x94);
          local_a8 = *(float *)(iVar9 + 0x98);
          local_a4 = *(float *)(iVar9 + 0x9c);
          local_64 = (double)local_ac;
          local_5c = (double)local_a8;
          local_54 = (double)local_a4;
          local_4c = 0;
          local_48 = 0x3ff00000;
          local_44 = 0x40000000;
          local_40 = 0x479e17b8;
          local_34 = iVar10;
          iVar10 = FUN_0044c550(&local_64,&local_d0);
          if (iVar10 != 0) {
            local_a8 = (float)local_3c;
            local_a0 = *(float *)(local_84 + 0x94);
            local_9c = *(float *)(local_84 + 0x98);
            local_98 = *(float *)(local_84 + 0x9c);
            local_64 = (double)local_a0;
            local_5c = (double)local_9c;
            local_54 = (double)local_98;
            local_4c = 0;
            local_48 = 0x3ff00000;
            local_44 = 0x40000000;
            local_40 = 0x479e17b8;
            local_34 = iVar10;
            iVar10 = FUN_0044c4c0();
            if (iVar10 != 0) {
              local_9c = (float)local_3c;
              fVar2 = local_b8 - local_a0;
              fVar3 = local_b4 - local_9c;
              fVar4 = local_b0 - local_98;
              if (SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar4 * fVar4) != DAT_0059e440) {
                local_94 = local_cc * fVar4 - local_c8 * fVar3;
                local_90 = local_c8 * fVar2 - local_d0 * fVar4;
                local_bc = local_d0 * fVar3 - local_cc * fVar2;
                fVar2 = local_94 * local_94 + local_90 * local_90 + local_bc * local_bc;
                local_c4 = local_94;
                local_c0 = local_90;
                local_8c = local_bc;
                if (SQRT(fVar2) != DAT_0059e440) {
                  fVar2 = _DAT_0059e43c / SQRT(fVar2);
                  local_c4 = local_94 * fVar2;
                  local_c0 = local_90 * fVar2;
                  fVar2 = fVar2 * local_bc;
                  fVar7 = local_c0 * local_c8 - fVar2 * local_cc;
                  fVar6 = fVar2 * local_d0 - local_c8 * local_c4;
                  fVar4 = local_cc * local_c4 - local_c0 * local_d0;
                  fVar3 = local_c8 * DAT_0059e440;
                  fVar8 = local_cc * _DAT_0059e438;
                  fVar5 = local_d0 * DAT_0059e440;
                  *(float *)(iVar9 + 0x78) =
                       local_c4 * DAT_0059e440 + local_c0 * _DAT_0059e438 + fVar2 * DAT_0059e440;
                  *(float *)(iVar9 + 0x7c) = fVar5 + fVar8 + fVar3;
                  *(float *)(iVar9 + 0x80) =
                       fVar7 * DAT_0059e440 + fVar6 * _DAT_0059e438 + DAT_0059e440 * fVar4;
                  fVar3 = local_b8 - local_ac;
                  fVar5 = local_b4 - local_a8;
                  local_c = local_b0 - local_a4;
                  local_70 = fVar3 * local_c4 + local_c0 * fVar5 + fVar2 * local_c;
                  local_6c = fVar3 * local_d0 + local_cc * fVar5 + local_c8 * local_c;
                  local_68 = fVar3 * fVar7 + fVar5 * fVar6 + local_c * fVar4;
                  fVar3 = local_a0 - local_ac;
                  fVar5 = local_9c - local_a8;
                  local_18 = local_98 - local_a4;
                  local_7c = fVar3 * local_c4 + local_c0 * fVar5 + fVar2 * local_18;
                  local_78 = fVar3 * local_d0 + local_cc * fVar5 + local_c8 * local_18;
                  local_74 = fVar3 * fVar7 + fVar5 * fVar6 + local_18 * fVar4;
                  fVar11 = (float10)FUN_00401180((double)local_70,(double)local_68,0,0,0,0,
                                                 (double)local_7c,(double)local_74);
                  *(float *)(iVar9 + 0x70) = (float)fVar11;
                  if (local_70 + local_7c < DAT_0059e440) {
                    *(float *)(iVar9 + 0x70) = (float)-fVar11;
                  }
                  fVar11 = (float10)FUN_00401180((double)local_6c,(double)local_68,0,0,0,0,
                                                 (double)local_78,(double)local_74);
                  *(float *)(iVar9 + 0x74) = (float)fVar11;
                  if (DAT_0059e440 < local_6c + local_78) {
                    *(float *)(iVar9 + 0x74) = (float)-fVar11;
                  }
                }
              }
            }
          }
        }
      }
      local_88 = local_88 + 0x13c;
      local_80 = local_80 + -1;
    } while (local_80 != 0);
  }
  return;
}


