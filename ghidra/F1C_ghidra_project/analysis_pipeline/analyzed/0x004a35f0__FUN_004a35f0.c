// Function: FUN_004a35f0 @ 004a35f0
// Size (bytes): 553


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a35f0(int param_1,float *param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_64;
  float local_60 [6];
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  
  fVar5 = param_2[0xd] + *param_2;
  if (*(char *)(param_2 + 1) == '\0') {
    local_60[0] = 99999.0;
    local_60[2] = 99999.0;
    local_40 = 99999.0;
    local_3c = 99999.0;
    local_38 = 99999.0;
    local_34 = 99999.0;
    local_30 = 99999.0;
    local_60[1] = 99999.0;
    local_60[3] = 99999.0;
  }
  else {
    local_60[0] = 0.0;
    local_40 = param_2[2] + *param_2;
    local_60[2] = 0.0;
    fVar2 = param_2[3] + *param_2;
    local_3c = fVar2;
    local_38 = param_2[4] + *param_2;
    local_34 = param_2[5] + *param_2;
    local_30 = local_34 + _DAT_0059e800;
    fVar3 = fVar2;
    if (fVar2 < local_40) {
      fVar3 = local_40;
    }
    fVar4 = local_34;
    if (local_34 < local_38) {
      fVar4 = local_38;
    }
    if (fVar3 <= fVar4) {
      fVar2 = local_34;
      if (local_34 < local_38) {
        fVar2 = local_38;
      }
    }
    else if (fVar2 < local_40) {
      fVar2 = local_40;
    }
    local_60[1] = (fVar2 + param_2[6]) - _DAT_0059e43c;
    local_60[3] = local_60[1];
    fVar2 = fVar2 + param_2[6] + param_2[7];
    if (fVar5 < fVar2) {
      fVar5 = fVar2;
    }
  }
  if (*(char *)(param_2 + 8) == '\0') {
    local_48 = 99999.0;
    local_44 = 99999.0;
  }
  else {
    local_48 = param_2[9] + *param_2;
    fVar2 = param_2[0xb] + param_2[10] + param_2[9] + *param_2;
    local_44 = fVar2 - _DAT_0059e43c;
    fVar2 = fVar2 + param_2[0xc];
    if (fVar5 < fVar2) {
      fVar5 = fVar2;
    }
  }
  local_60[5] = fVar5 - _DAT_005acaf4;
  local_60[4] = 0.0;
  local_64 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    param_2 = (float *)0x0;
    local_60[1] = local_60[3];
    do {
      iVar8 = *(int *)(param_1 + 0x10) + (int)param_2;
      iVar9 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 0x10) + 0x70 + (int)param_2)) {
        iVar7 = 0;
        do {
          iVar1 = *(int *)(iVar8 + 0x74);
          iVar6 = iVar1 + iVar7;
          FUN_004a1fd0(local_60[*(int *)(iVar1 + 0x18 + iVar7)],
                       (*(float *)(iVar6 + 0x10) - *(float *)(iVar6 + 0xc)) +
                       local_60[*(int *)(iVar1 + 0x18 + iVar7)]);
          iVar9 = iVar9 + 1;
          iVar7 = iVar7 + 0x1c;
        } while (iVar9 < *(int *)(iVar8 + 0x70));
      }
      local_64 = local_64 + 1;
      param_2 = (float *)((int)param_2 + 0x78);
    } while (local_64 < *(int *)(param_1 + 0xc));
  }
  return;
}


