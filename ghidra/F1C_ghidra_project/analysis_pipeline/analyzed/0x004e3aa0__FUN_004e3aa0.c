// Function: FUN_004e3aa0 @ 004e3aa0
// Size (bytes): 601


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e3aa0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  double local_34;
  double local_2c;
  double local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  double local_c;
  float local_4;
  
  local_4 = param_1[0x3a];
  local_34 = (double)*param_1;
  local_2c = (double)param_1[1];
  local_24 = (double)param_1[2];
  local_1c = 0x40000000;
  local_18 = 0x3ff33333;
  local_14 = 0x40000000;
  local_10 = 0x479e17b8;
  fVar5 = (float)FUN_0044c550(&local_34,&local_4c);
  param_1[0x3a] = fVar5;
  if (fVar5 == 0.0) {
    local_4c = 0.0;
    local_48 = 1.0;
    local_44 = 0.0;
    local_50 = 1e+37;
  }
  else {
    local_50 = ((param_1[1] - (float)local_c) - param_1[0x39]) * local_48;
  }
  param_1[0xe] = local_48 * param_2[3] + local_4c * *param_2 + local_44 * param_2[6];
  param_1[0xf] = local_44 * param_2[7] + local_4c * param_2[1] + local_48 * param_2[4];
  param_1[0x10] = local_4c * param_2[2] + local_48 * param_2[5] + local_44 * param_2[8];
  fVar5 = param_1[0x24] - local_50;
  bVar2 = fVar5 < DAT_0059e440;
  param_1[0x1d] = fVar5;
  if (bVar2) {
    param_1[0x11] = 0.0;
    param_1[0xd] = 0.0;
    return;
  }
  fVar3 = param_1[6] * param_1[0xe] + param_1[0xf] * param_1[7] + param_1[0x10] * param_1[8];
  if (param_1[0xf] <= _DAT_005ad168) {
    if (param_1[0x1f] < ABS(fVar3)) {
      fVar1 = (param_1[0x1f] + param_1[0x1f]) / (ABS(fVar3) + param_1[0x1f]);
      fVar3 = fVar1 * fVar3;
      param_1[0x1d] = fVar5 * fVar1;
    }
    param_1[0xd] = param_1[0x1e] * param_1[0x1d] * param_1[0xf];
    fVar4 = (*param_1 - local_4c * local_50) - *param_3;
    fVar5 = (param_1[1] - local_48 * local_50) - param_3[1];
    fVar1 = (param_1[2] - local_44 * local_50) - param_3[2];
    param_1[0x33] = fVar1 * param_2[6] + fVar5 * param_2[3] + fVar4 * *param_2;
    param_1[0x34] = fVar5 * param_2[4] + fVar1 * param_2[7] + fVar4 * param_2[1];
    fVar1 = fVar1 * param_2[8] + fVar4 * param_2[2] + fVar5 * param_2[5];
  }
  else {
    param_1[0xd] = fVar5 * param_1[0x1e];
    fVar1 = param_1[5];
    param_1[0x33] = param_1[3];
    param_1[0x34] = (fVar5 * param_1[0x1e] + param_1[0x18]) - param_1[0x24];
  }
  param_1[0x35] = fVar1;
  param_1[0x11] = param_1[0x3b] * param_1[0x1d] - fVar3 * param_1[0x3c];
  return;
}


