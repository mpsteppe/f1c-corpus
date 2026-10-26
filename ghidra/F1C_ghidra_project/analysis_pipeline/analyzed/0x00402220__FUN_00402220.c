// Function: FUN_00402220 @ 00402220
// Size (bytes): 712


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00402220(float *param_1,float *param_2,float *param_3,int param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float local_60;
  double local_3c;
  double local_34;
  double local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  double local_14;
  int local_c;
  
  if (param_4 == 0) {
    fVar6 = param_2[0x47] + param_2[6];
  }
  else {
    if (param_4 == 1) {
      fVar6 = param_2[7];
      fVar2 = param_2[9];
      fVar3 = param_2[10];
      fVar4 = param_2[1];
      fVar5 = param_2[2];
      *param_3 = fVar6 * param_2[8] + *param_2;
      param_3[1] = fVar6 * fVar2 + fVar4;
      param_3[2] = fVar6 * fVar3 + fVar5;
      fVar6 = param_1[1];
      goto LAB_004022ed;
    }
    fVar6 = param_2[6];
  }
  fVar2 = param_2[9];
  fVar3 = param_2[10];
  fVar4 = param_2[1];
  fVar5 = param_2[2];
  *param_3 = fVar6 * param_2[8] + *param_2;
  param_3[1] = fVar6 * fVar2 + fVar4;
  param_3[2] = fVar6 * fVar3 + fVar5;
  fVar6 = *param_1;
LAB_004022ed:
  fVar6 = fVar6 * _DAT_0059e450;
  pfVar1 = param_3 + 3;
  local_24 = 0;
  local_20 = 0x3ff00000;
  local_1c = 0x40000000;
  local_18 = 0x479e17b8;
  local_c = 0;
  fVar2 = param_2[9];
  fVar3 = param_2[10];
  *pfVar1 = fVar6 * param_2[8];
  param_3[4] = fVar6 * fVar2;
  local_3c = (double)*param_3;
  param_3[5] = fVar6 * fVar3;
  local_34 = (double)param_3[1];
  local_2c = (double)param_3[2];
  local_c = FUN_0044c4c0(&local_3c);
  if (local_c != 0) {
    fVar6 = (float)local_14;
    local_24 = 0;
    local_3c = (double)(*param_3 - *pfVar1);
    local_20 = 0x40140000;
    local_34 = (double)param_3[1];
    local_1c = 0x40000000;
    local_18 = 0x479e17b8;
    local_2c = (double)(param_3[2] - param_3[5]);
    local_c = FUN_0044c4c0(&local_3c);
    local_60 = fVar6;
    if (local_c != 0) {
      local_60 = (float)local_14;
    }
    local_24 = 0;
    local_3c = (double)(*pfVar1 + *param_3);
    local_20 = 0x40140000;
    local_34 = (double)param_3[1];
    local_1c = 0x40000000;
    local_18 = 0x479e17b8;
    local_2c = (double)(param_3[5] + param_3[2]);
    iVar7 = FUN_0044c4c0(&local_3c);
    fVar2 = fVar6;
    if (iVar7 != 0) {
      fVar2 = (float)local_14;
    }
    fVar3 = (fVar6 + fVar6) - local_60;
    if (((_DAT_0059e458 + fVar3 < fVar2) || (fVar4 = fVar2, fVar2 < fVar3 - _DAT_0059e458)) &&
       (fVar4 = fVar3, ABS(fVar2 - fVar6) <= ABS(local_60 - fVar6))) {
      local_60 = (fVar6 + fVar6) - fVar2;
      fVar4 = fVar2;
    }
    fVar2 = (local_60 + fVar4) * _DAT_0059e450;
    if (fVar2 < fVar6) {
      fVar2 = fVar6;
    }
    param_3[1] = fVar2 + _DAT_0059e454;
    param_3[4] = (fVar4 - local_60) * _DAT_0059e450;
  }
  return;
}


