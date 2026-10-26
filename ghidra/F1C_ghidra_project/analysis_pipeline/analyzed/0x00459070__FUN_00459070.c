// Function: FUN_00459070 @ 00459070
// Size (bytes): 702


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00459070(int param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float *pfVar2;
  undefined4 uVar3;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_4;
  
  fVar1 = *(float *)(param_1 + 0xa8);
  local_18 = *(float *)(param_1 + 0xc);
  local_14 = *(float *)(param_1 + 0x10);
  local_10 = *(float *)(param_1 + 0x14);
  if ((*(byte *)(param_1 + 0x74) & 2) != 0) {
    if (*(char *)(param_1 + 0xcc) == '\0') {
      pfVar2 = (float *)FUN_004582c0(0);
      local_18 = *pfVar2 * _DAT_0059e670;
      local_14 = pfVar2[1] * _DAT_0059e670;
      local_10 = pfVar2[2] * _DAT_0059e670;
      pfVar2 = (float *)FUN_004582c0(*(undefined4 *)(param_1 + 0xb8));
      local_4 = pfVar2[2] * _DAT_0059e670;
      local_24 = local_18 - *param_2;
      local_20 = local_14 - param_2[1];
      local_1c = local_10 - param_2[2];
      local_18 = *pfVar2 * _DAT_0059e670 - *param_2;
      fVar1 = pfVar2[1] * _DAT_0059e670 - param_2[1];
      if (local_18 * local_18 + fVar1 * fVar1 + (local_4 - param_2[2]) * (local_4 - param_2[2]) <
          local_24 * local_24 + local_20 * local_20 + local_1c * local_1c) {
        uVar3 = *(undefined4 *)(param_1 + 0xb8);
        *(undefined4 *)(param_1 + 0xac) = 0xbf800000;
      }
      else {
        *(undefined4 *)(param_1 + 0xac) = 0x3f800000;
        uVar3 = 0;
      }
      pfVar2 = (float *)FUN_004582c0(uVar3);
      local_24 = *pfVar2;
      local_20 = pfVar2[1];
      local_1c = pfVar2[2];
      FUN_00456110(&local_24);
      local_24 = 0.0;
      local_20 = 0.0;
      local_1c = 0.0;
      FUN_00456150(&local_24);
      return;
    }
    fVar1 = SQRT(param_3[2] * param_3[2] + param_3[1] * param_3[1] + *param_3 * *param_3) *
            *(float *)(param_1 + 0xa8);
  }
  pfVar2 = (float *)FUN_004582c0(fVar1 * *(float *)(param_1 + 0xac) * param_4 +
                                 *(float *)(param_1 + 0xbc));
  local_24 = *pfVar2;
  local_20 = pfVar2[1];
  local_1c = pfVar2[2];
  FUN_00456110(&local_24);
  if (param_4 <= DAT_0059e440) {
    local_1c = 0.0;
    local_24 = DAT_0059e440;
    local_20 = DAT_0059e440;
  }
  else {
    local_4 = local_1c - local_10;
    local_1c = _DAT_0059e43c / param_4;
    local_18 = local_1c * (local_24 - local_18);
    local_14 = local_1c * (local_20 - local_14);
    local_1c = local_1c * local_4;
    local_10 = local_1c;
    local_24 = local_18;
    local_20 = local_14;
  }
  local_24 = local_24 * _DAT_0059e670;
  local_20 = local_20 * _DAT_0059e670;
  local_1c = local_1c * _DAT_0059e670;
  FUN_00456150(&local_24);
  return;
}


