// Function: FUN_004e3d00 @ 004e3d00
// Size (bytes): 1732


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e3d00(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_44;
  float local_40;
  float local_3c;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  
  if (param_1[0xf] <= _DAT_005ad168) {
    if ((float)_DAT_005ad178 <= ABS(param_1[0xe])) {
      fVar3 = param_1[0x2f] * param_1[0xf] - param_1[0x10] * DAT_0059e440;
      fVar2 = param_1[0x30] * param_1[0x10] - param_1[0x2f] * param_1[0xe];
      fVar1 = param_1[0xe] * DAT_0059e440 - param_1[0x30] * param_1[0xf];
      fVar4 = _DAT_0059e43c / SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
      local_24 = fVar3 * fVar4;
      local_20 = fVar2 * fVar4;
      local_1c = fVar4 * fVar1;
      local_30 = local_20 * param_1[0x10] - local_1c * param_1[0xf];
      local_2c = local_1c * param_1[0xe] - local_24 * param_1[0x10];
      local_28 = local_24 * param_1[0xf] - local_20 * param_1[0xe];
    }
    else {
      fVar3 = param_1[0x10] * DAT_0059e440 - -param_1[0x30] * param_1[0xf];
      fVar2 = -param_1[0x30] * param_1[0xe] - param_1[0x2f] * param_1[0x10];
      fVar1 = param_1[0x2f] * param_1[0xf] - param_1[0xe] * DAT_0059e440;
      fVar4 = _DAT_0059e43c / SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
      local_30 = fVar3 * fVar4;
      local_2c = fVar2 * fVar4;
      local_28 = fVar4 * fVar1;
      local_24 = local_28 * param_1[0xf] - local_2c * param_1[0x10];
      local_20 = local_30 * param_1[0x10] - local_28 * param_1[0xe];
      local_1c = local_2c * param_1[0xe] - local_30 * param_1[0xf];
    }
    local_40 = local_24 * param_1[6] + local_20 * param_1[7] + local_1c * param_1[8];
    local_44 = local_30 * param_1[6] + local_2c * param_1[7] + local_28 * param_1[8];
  }
  else if (param_1[0x2f] == 1.0) {
    local_40 = param_1[6];
    local_44 = param_1[8];
  }
  else {
    local_40 = param_1[0x2f] * param_1[6] - param_1[8] * param_1[0x30];
    local_44 = param_1[0x30] * param_1[6] + param_1[8] * param_1[0x2f];
  }
  fVar2 = local_44 - param_1[0x24] * param_1[0xc];
  fVar3 = param_1[0x2e] * param_1[0x11] + param_1[0x16];
  fVar1 = param_1[0x11];
  param_1[0x16] = fVar3;
  if (param_1[0x2b] < fVar1) {
    fVar1 = param_1[0x2b];
  }
  param_1[0x12] = 5.0;
  param_1[0x13] = (fVar1 * param_1[0x2a] + _DAT_0059e43c) * param_1[0x27] * param_1[0x11];
  if (param_1[0x13] < DAT_0059e440 != (param_1[0x13] == DAT_0059e440)) {
    param_1[0x13] = 0.0;
    param_1[0x14] = 0.0;
    param_1[0x36] = 0.0;
    param_1[0x37] = 0.0;
    param_1[0x38] = 0.0;
    return;
  }
  param_1[0x14] = 1.0;
  if (param_1[0xc] == DAT_0059e440) {
    fVar1 = param_1[0x31] - *param_1;
    fVar4 = param_1[0x32] - param_1[2];
    if (fVar1 * fVar1 + fVar4 * fVar4 < _DAT_005ad148) {
      fVar5 = param_2[3] * DAT_0059e440 + fVar1 * *param_2 + fVar4 * param_2[6];
      fVar6 = param_2[4] * DAT_0059e440 + fVar1 * param_2[1] + fVar4 * param_2[7];
      local_3c = param_2[5] * DAT_0059e440 + fVar1 * param_2[2] + fVar4 * param_2[8];
      if (param_1[0xf] <= _DAT_005ad168) {
        fVar1 = local_1c * local_3c;
        local_3c = local_30 * fVar5 + local_28 * local_3c + fVar6 * local_2c;
        fVar5 = local_24 * fVar5 + fVar1 + fVar6 * local_20;
      }
      else if (param_1[0x2f] != 1.0) {
        fVar1 = local_3c * param_1[0x30];
        local_3c = fVar5 * param_1[0x30] + local_3c * param_1[0x2f];
        fVar5 = fVar5 * param_1[0x2f] - fVar1;
      }
      param_2 = (float *)(fVar5 * _DAT_005ad170 - local_40 * _DAT_005ad16c);
      fVar1 = local_3c * _DAT_005ad170 - local_44 * _DAT_005ad16c;
      if ((float)param_2 * (float)param_2 + fVar1 * fVar1 < param_1[0x13] * param_1[0x13])
      goto LAB_004e42fc;
    }
  }
  param_1[0x31] = *param_1;
  param_1[0x32] = param_1[2];
  fVar1 = SQRT(local_40 * local_40 + local_44 * local_44);
  if (fVar1 < _DAT_0059e43c) {
    fVar1 = _DAT_0059e43c;
  }
  fVar4 = -((param_1[0x13] / fVar1) * param_1[0x25]);
  param_2 = (float *)(local_40 * fVar4);
  fVar4 = fVar4 * fVar2;
  fVar1 = (float)param_2 * (float)param_2 + fVar4 * fVar4;
  if (param_1[0x13] * param_1[0x13] < fVar1) {
    fVar1 = param_1[0x13] / SQRT(fVar1);
    param_1[0x14] = fVar1;
    param_2 = (float *)((float)param_2 * fVar1);
    fVar4 = fVar1 * fVar4;
    param_1[0x16] = (fVar1 * _DAT_0059e7f8 + _DAT_0059e7fc) * fVar3;
  }
  fVar3 = param_1[0x15] - fVar4 * param_1[0x24];
  if (param_1[0xc] <= DAT_0059e440) {
    fVar3 = fVar3 + param_1[0x16];
  }
  else {
    fVar3 = fVar3 - param_1[0x16];
  }
  fVar5 = param_1[0x1c] * param_1[0x1b] * param_1[0x24] * fVar3;
  fVar5 = fVar5 + fVar5;
  fVar6 = fVar2 - fVar5;
  fVar1 = fVar4;
  if (fVar2 * fVar6 < DAT_0059e440) {
    fVar2 = ABS((fVar6 / (fVar5 * param_1[0x24])) * fVar3);
    fVar1 = DAT_0059e440;
    if (fVar4 <= DAT_0059e440) {
      if (fVar2 <= -fVar4) {
        fVar1 = fVar4 + fVar2;
      }
    }
    else if (fVar2 <= fVar4) {
      fVar1 = fVar4 - fVar2;
    }
  }
LAB_004e42fc:
  param_1[0x15] = param_1[0x15] - fVar1 * param_1[0x24];
  if (param_1[0xf] <= _DAT_005ad168) {
    param_1[0x36] = local_24 * (float)param_2 + local_30 * fVar1;
    param_1[0x37] = local_20 * (float)param_2 + local_2c * fVar1;
    param_1[0x38] = local_1c * (float)param_2 + local_28 * fVar1;
    return;
  }
  param_1[0x37] = 0.0;
  if (param_1[0x2f] != 1.0) {
    param_1[0x36] = (float)param_2 * param_1[0x2f] + fVar1 * param_1[0x30];
    param_1[0x38] = (float)param_2 * param_1[0x30] + fVar1 * param_1[0x2f];
    return;
  }
  param_1[0x38] = fVar1;
  param_1[0x36] = (float)param_2;
  return;
}


