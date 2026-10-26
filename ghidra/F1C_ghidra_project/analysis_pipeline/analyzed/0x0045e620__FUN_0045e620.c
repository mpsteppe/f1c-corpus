// Function: FUN_0045e620 @ 0045e620
// Size (bytes): 1243


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0045e620(float param_1,uint *param_2)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  uint uVar5;
  float fVar6;
  char cVar7;
  float *pfVar8;
  float *pfVar9;
  float local_68;
  float local_60;
  float *local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_68 = (float)_DAT_008afe98;
  uVar5 = *param_2;
  if (DAT_0059e440 <= local_68) {
    if (_DAT_0059e474 < local_68) {
      local_68 = 0.033333335;
    }
  }
  else {
    local_68 = 0.0;
  }
  pfVar3 = (float *)((uVar5 & 0xff) * 0x38 + 0x1b7a0 + (int)param_1);
  local_3c = (float)param_2[2];
  local_38 = (float)param_2[3];
  local_34 = (float)param_2[4];
  pfVar1 = pfVar3 + 2;
  local_24 = local_3c - *pfVar1;
  local_20 = local_38 - pfVar3[3];
  local_1c = local_34 - pfVar3[4];
  local_58 = _DAT_0059e43c / local_68;
  local_60 = param_1;
  local_18 = local_24;
  local_14 = local_20;
  local_10 = local_1c;
  pfVar8 = (float *)FUN_0045eb00(&local_c,local_58);
  fVar4 = DAT_007d1158;
  local_44 = pfVar8[1];
  local_40 = pfVar8[2];
  fVar6 = *pfVar8;
  local_5c = (float *)(DAT_007d108c - DAT_007d1158);
  local_48 = fVar6;
  cVar7 = FUN_0045ca20(uVar5 & 0xff,&local_60,1);
  if (((cVar7 != '\0') && (local_60 < fVar4 == (local_60 == fVar4))) &&
     ((float)local_5c < DAT_0059e440 == ((float)local_5c == DAT_0059e440))) {
    fVar6 = (local_60 - fVar4) / (float)local_5c;
    if (_DAT_0059e43c <= fVar6) {
      fVar6 = _DAT_0059e43c;
    }
    fVar6 = (_DAT_0059e43c - fVar6) * (_DAT_007d11a0 - _DAT_007d117c) + _DAT_007d117c;
    if ((float)_DAT_0059eb08 < ABS(fVar6 - *pfVar3)) {
      *pfVar3 = fVar6;
      pfVar3[1] = SQRT(fVar6) * _DAT_007d11c4 + SQRT(fVar6) * _DAT_007d11c4;
    }
    pfVar8 = pfVar3 + 0xb;
    pfVar2 = pfVar3 + 8;
    local_24 = *pfVar8;
    local_20 = pfVar3[0xc];
    local_1c = pfVar3[0xd];
    local_5c = pfVar3 + 5;
    local_18 = local_68 * *pfVar8 + *pfVar2;
    local_14 = local_68 * pfVar3[0xc] + pfVar3[9];
    local_10 = local_68 * pfVar3[0xd] + pfVar3[10];
    local_30 = local_48 - *local_5c;
    local_2c = local_44 - pfVar3[6];
    local_28 = local_40 - pfVar3[7];
    local_c = local_30;
    local_8 = local_2c;
    local_4 = local_28;
    pfVar9 = (float *)FUN_0045eb00(&local_30,local_58);
    local_54 = *pfVar9;
    local_50 = pfVar9[1];
    local_4c = pfVar9[2];
    fVar6 = local_54 * local_54 + local_50 * local_50 + local_4c * local_4c;
    if (_DAT_0059f110 < fVar6) {
      fVar6 = _DAT_0059e828 / SQRT(fVar6);
      local_54 = local_54 * fVar6;
      local_50 = local_50 * fVar6;
      local_4c = local_4c * fVar6;
    }
    local_18 = local_3c - local_18;
    local_14 = local_38 - local_14;
    local_10 = local_34 - local_10;
    if (local_18 * local_18 + local_14 * local_14 + local_10 * local_10 <= _DAT_0059f10c) {
      fVar6 = pfVar3[1];
      fVar4 = *pfVar3;
      *pfVar8 = (local_18 * fVar4 + (local_48 - local_24) * fVar6 + local_54) * local_68 + *pfVar8;
      pfVar3[0xc] = (local_14 * fVar4 + (local_44 - local_20) * fVar6 + local_50) * local_68 +
                    pfVar3[0xc];
      pfVar3[0xd] = (local_4c + fVar4 * local_10 + (local_40 - local_1c) * fVar6) * local_68 +
                    pfVar3[0xd];
      local_68 = local_68 * _DAT_0059e450;
      *pfVar2 = local_68 * (local_24 + *pfVar8) + *pfVar2;
      pfVar3[9] = local_68 * (local_20 + pfVar3[0xc]) + pfVar3[9];
      pfVar3[10] = local_68 * (local_1c + pfVar3[0xd]) + pfVar3[10];
    }
    else {
      *pfVar2 = local_3c;
      pfVar3[9] = local_38;
      pfVar3[10] = local_34;
      *pfVar8 = local_48;
      pfVar3[0xc] = local_44;
      pfVar3[0xd] = local_40;
    }
    param_2[2] = (uint)*pfVar2;
    param_2[3] = (uint)pfVar3[9];
    param_2[4] = (uint)pfVar3[10];
    *pfVar1 = local_3c;
    pfVar3[3] = local_38;
    pfVar3[4] = local_34;
    *local_5c = local_48;
    local_5c[1] = local_44;
    local_5c[2] = local_40;
    return;
  }
  pfVar3[8] = local_3c;
  pfVar3[9] = local_38;
  pfVar3[10] = local_34;
  pfVar3[0xb] = fVar6;
  pfVar3[0xc] = local_44;
  *pfVar1 = local_3c;
  pfVar3[3] = local_38;
  pfVar3[5] = fVar6;
  pfVar3[0xd] = local_40;
  pfVar3[6] = local_44;
  pfVar3[4] = local_34;
  pfVar3[7] = local_40;
  return;
}


