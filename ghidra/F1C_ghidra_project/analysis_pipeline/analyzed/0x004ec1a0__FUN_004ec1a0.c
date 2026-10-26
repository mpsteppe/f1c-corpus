// Function: FUN_004ec1a0 @ 004ec1a0
// Size (bytes): 3722


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ec1a0(int *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  float *pfVar12;
  int iVar13;
  int *piVar14;
  float *pfVar15;
  float local_54;
  undefined1 local_50;
  int local_34;
  float local_30;
  float local_2c;
  float local_28;
  int local_24;
  int local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*param_1 == DAT_007c54e8) {
    if (DAT_007c749f != '\0') {
      return;
    }
    if (((char)param_1[0xd10] != '\0') && (DAT_007c74a4 != '\0')) {
      return;
    }
  }
  else if (param_1[0xcaf] == 1) {
    if (DAT_007c56a8 == 1) {
      return;
    }
    if (DAT_007c56a8 == 3) {
      return;
    }
  }
  param_4 = ABS(param_4);
  fVar3 = (float)DAT_007d0014 * param_4 * _DAT_0059e444;
  fVar1 = fVar3 * (float)param_1[0xf5f] + (float)param_1[0xf5e];
  if ((float)param_1[0xf60] < fVar1) {
    fVar1 = (float)param_1[0xf60];
  }
  fVar1 = fVar1 * fVar1;
  if ((float)param_1[0xf61] < fVar3) {
    FUN_004efae0();
  }
  local_54 = fVar3 * (float)param_1[0xf62];
  if ((float)param_1[0xf63] < param_4) {
    if (_DAT_0059e43c < local_54) {
      local_54 = 1.0;
    }
    if (_DAT_0059e670 <= param_2[2]) {
      if (_DAT_0059e43c <= param_2[2]) {
        FUN_004ed220(local_54);
      }
      else {
        FUN_004ed1f0(local_54);
      }
    }
    else {
      FUN_004ed1c0(local_54);
    }
    iVar13 = DAT_008aae64;
    fVar4 = local_54 * (float)param_1[0xf64];
    if (_DAT_0059e43c < local_54 * (float)param_1[0xf64]) {
      fVar4 = _DAT_0059e43c;
    }
    param_4 = SQRT(fVar4) / param_4;
    fVar4 = *param_3 * param_4;
    fVar5 = param_3[1] * param_4;
    param_4 = param_3[2] * param_4;
    if (DAT_0083ee60 < 0x3ff) {
      DAT_0083ee60 = DAT_0083ee60 + 1;
      DAT_008aae64 = DAT_008aae64 + 0x1b0;
    }
    FUN_004b33b0(2,7,10,param_1[1],(float)_DAT_008afea0,0);
    fVar6 = *param_2 * _DAT_0059e450;
    fVar7 = param_2[1] * _DAT_005ad1f4;
    fVar8 = param_2[2] * _DAT_005ad1f0;
    if (fVar6 <= _DAT_0059e43c) {
      if (_DAT_0059e670 <= fVar6) {
        local_50 = (undefined1)(int)ROUND(fVar6 * _DAT_005ad1ec);
      }
      else {
        local_50 = 0x81;
      }
    }
    else {
      local_50 = 0x7f;
    }
    *(undefined1 *)(iVar13 + 8) = local_50;
    if (fVar7 <= _DAT_0059e43c) {
      if (_DAT_0059e670 <= fVar7) {
        local_50 = (undefined1)(int)ROUND(fVar7 * _DAT_005ad1ec);
      }
      else {
        local_50 = 0x81;
      }
    }
    else {
      local_50 = 0x7f;
    }
    *(undefined1 *)(iVar13 + 9) = local_50;
    if (fVar8 <= _DAT_0059e43c) {
      if (_DAT_0059e670 <= fVar8) {
        local_50 = (undefined1)(int)ROUND(fVar8 * _DAT_005ad1ec);
      }
      else {
        local_50 = 0x81;
      }
    }
    else {
      local_50 = 0x7f;
    }
    *(undefined1 *)(iVar13 + 10) = local_50;
    if (fVar4 <= _DAT_0059e43c) {
      if (_DAT_0059e670 <= fVar4) {
        local_50 = (undefined1)(int)ROUND(fVar4 * _DAT_005ad1ec);
      }
      else {
        local_50 = 0x81;
      }
    }
    else {
      local_50 = 0x7f;
    }
    *(undefined1 *)(iVar13 + 0xb) = local_50;
    if (fVar5 <= _DAT_0059e43c) {
      if (_DAT_0059e670 <= fVar5) {
        local_50 = (undefined1)(int)ROUND(fVar5 * _DAT_005ad1ec);
      }
      else {
        local_50 = 0x81;
      }
    }
    else {
      local_50 = 0x7f;
    }
    *(undefined1 *)(iVar13 + 0xc) = local_50;
    if (param_4 <= _DAT_0059e43c) {
      if (_DAT_0059e670 <= param_4) {
        local_50 = (undefined1)(int)ROUND(param_4 * _DAT_005ad1ec);
      }
      else {
        local_50 = 0x81;
      }
    }
    else {
      local_50 = 0x7f;
    }
    *(undefined1 *)(iVar13 + 0xd) = local_50;
    *(int *)(iVar13 + 0xe) = param_1[0xd2b];
    FUN_004a56b0(1);
  }
  if ((((param_1[0x332] != 0) && ((char)param_1[0x342] != '\0')) &&
      (fVar4 = (param_2[1] - (float)param_1[0xf68]) * (param_2[1] - (float)param_1[0xf68]) +
               (param_2[2] - (float)param_1[0xf69]) * (param_2[2] - (float)param_1[0xf69]),
      fVar4 < fVar1)) &&
     (((float)param_1[0xf65] < (_DAT_0059e43c - fVar4 / fVar1) * fVar3 &&
      (uVar11 = DAT_008aae70 & 0xff, DAT_008aae70 = DAT_008aae70 + 1,
      *(float *)(&DAT_008aae74 + uVar11 * 4) < (float)param_1[0xf66])))) {
    FUN_004ed250(4);
    local_34 = param_1[0xd2b];
    local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7e8 +
               (float)param_1[0xf67] * (float)param_1[0xd2c] +
               (float)param_1[0xd2d] * (float)param_1[0xf68] +
               (float)param_1[0xd2e] * (float)param_1[0xf69] + (float)param_1[0xd35];
    local_2c = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 1 & 0xff) * 4) * _DAT_0059e7e8 +
               (float)param_1[0xd2f] * (float)param_1[0xf67] +
               (float)param_1[0xd30] * (float)param_1[0xf68] +
               (float)param_1[0xd31] * (float)param_1[0xf69] + (float)param_1[0xd36];
    local_28 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 2 & 0xff) * 4) * _DAT_0059e7e8 +
               (float)param_1[0xd32] * (float)param_1[0xf67] +
               (float)param_1[0xd33] * (float)param_1[0xf68] +
               (float)param_1[0xd34] * (float)param_1[0xf69] + (float)param_1[0xd37];
    uVar11 = DAT_008aae70 + 4;
    local_18 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 3 & 0xff) * 4) +
               *(float *)(&DAT_008ab274 + (DAT_008aae70 + 3 & 0xff) * 4);
    uVar9 = DAT_008aae70 + 5;
    DAT_008aae70 = DAT_008aae70 + 6;
    local_14 = *(float *)(&DAT_008ab274 + (uVar11 & 0xff) * 4) +
               *(float *)(&DAT_008ab274 + (uVar11 & 0xff) * 4) + _DAT_0059e7ec;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    local_24 = param_1[0xd38];
    local_20 = param_1[0xd39];
    local_1c = param_1[0xd3a];
    local_10 = *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4) +
               *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4);
    FUN_00411330(4,param_1 + 0xf6a,param_1[1],0,&local_34);
  }
  if (((param_1[0x343] != 0) && ((char)param_1[0x353] != '\0')) &&
     ((fVar4 = (param_2[1] - (float)param_1[0xf74]) * (param_2[1] - (float)param_1[0xf74]) +
               (param_2[2] - (float)param_1[0xf75]) * (param_2[2] - (float)param_1[0xf75]),
      fVar4 < fVar1 &&
      (((float)param_1[0xf71] < (_DAT_0059e43c - fVar4 / fVar1) * fVar3 &&
       (uVar11 = DAT_008aae70 & 0xff, DAT_008aae70 = DAT_008aae70 + 1,
       *(float *)(&DAT_008aae74 + uVar11 * 4) < (float)param_1[0xf72])))))) {
    FUN_004ed250(5);
    local_34 = param_1[0xd2b];
    local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7e8 +
               (float)param_1[0xf73] * (float)param_1[0xd2c] +
               (float)param_1[0xd2d] * (float)param_1[0xf74] +
               (float)param_1[0xd2e] * (float)param_1[0xf75] + (float)param_1[0xd35];
    local_2c = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 1 & 0xff) * 4) * _DAT_0059e7e8 +
               (float)param_1[0xd2f] * (float)param_1[0xf73] +
               (float)param_1[0xd30] * (float)param_1[0xf74] +
               (float)param_1[0xd31] * (float)param_1[0xf75] + (float)param_1[0xd36];
    local_28 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 2 & 0xff) * 4) * _DAT_0059e7e8 +
               (float)param_1[0xd32] * (float)param_1[0xf73] +
               (float)param_1[0xd33] * (float)param_1[0xf74] +
               (float)param_1[0xd34] * (float)param_1[0xf75] + (float)param_1[0xd37];
    uVar11 = DAT_008aae70 + 4;
    local_18 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 3 & 0xff) * 4) +
               *(float *)(&DAT_008ab274 + (DAT_008aae70 + 3 & 0xff) * 4);
    uVar9 = DAT_008aae70 + 5;
    DAT_008aae70 = DAT_008aae70 + 6;
    local_14 = *(float *)(&DAT_008ab274 + (uVar11 & 0xff) * 4) +
               *(float *)(&DAT_008ab274 + (uVar11 & 0xff) * 4) + _DAT_0059e7ec;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    local_24 = param_1[0xd38];
    local_20 = param_1[0xd39];
    local_1c = param_1[0xd3a];
    local_10 = *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4) +
               *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4);
    FUN_00411330(4,param_1 + 0xf76,param_1[1],1,&local_34);
  }
  pfVar12 = (float *)(param_1 + 0xfa4);
  piVar10 = param_1 + 0x354;
  iVar13 = 0;
  piVar14 = param_1 + 0xfc4;
  pfVar15 = (float *)(param_1 + 0xfad);
  do {
    if ((((*piVar10 != 0) && ((char)piVar10[0x10] != '\0')) &&
        (fVar4 = (*param_2 - pfVar15[-1]) * (*param_2 - pfVar15[-1]) +
                 (param_2[1] - *pfVar15) * (param_2[1] - *pfVar15) +
                 (param_2[2] - pfVar15[1]) * (param_2[2] - pfVar15[1]), fVar4 < fVar1)) &&
       ((pfVar12[-8] < (_DAT_0059e43c - fVar4 / fVar1) * fVar3 &&
        (uVar11 = DAT_008aae70 & 0xff, DAT_008aae70 = DAT_008aae70 + 1,
        *(float *)(&DAT_008aae74 + uVar11 * 4) < *pfVar12)))) {
      FUN_004ed250(iVar13 + 6);
      local_34 = param_1[0xd2b];
      local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7e8 +
                 (float)param_1[0xd2c] * pfVar15[-1] +
                 (float)param_1[0xd2d] * *pfVar15 + (float)param_1[0xd2e] * pfVar15[1] +
                 (float)param_1[0xd35];
      local_2c = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 1 & 0xff) * 4) * _DAT_0059e7e8 +
                 (float)param_1[0xd2f] * pfVar15[-1] +
                 (float)param_1[0xd30] * *pfVar15 + (float)param_1[0xd31] * pfVar15[1] +
                 (float)param_1[0xd36];
      local_28 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 2 & 0xff) * 4) * _DAT_0059e7e8 +
                 (float)param_1[0xd32] * pfVar15[-1] +
                 (float)param_1[0xd33] * *pfVar15 + (float)param_1[0xd34] * pfVar15[1] +
                 (float)param_1[0xd37];
      uVar11 = DAT_008aae70 + 4;
      local_c = 0;
      uVar9 = DAT_008aae70 + 5;
      local_18 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 3 & 0xff) * 4) +
                 *(float *)(&DAT_008ab274 + (DAT_008aae70 + 3 & 0xff) * 4) +
                 (float)param_1[0xd3b] * _DAT_0059e8b4;
      local_8 = 0;
      local_4 = 0;
      DAT_008aae70 = DAT_008aae70 + 6;
      local_14 = *(float *)(&DAT_008ab274 + (uVar11 & 0xff) * 4) +
                 *(float *)(&DAT_008ab274 + (uVar11 & 0xff) * 4) +
                 (float)param_1[0xd3c] * _DAT_0059e8b4 + _DAT_0059e7ec;
      local_24 = param_1[0xd38];
      local_20 = param_1[0xd39];
      local_1c = param_1[0xd3a];
      local_10 = *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4) +
                 *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4) +
                 (float)param_1[0xd3d] * _DAT_0059e8b4;
      FUN_00411330(5,piVar14,param_1[1],iVar13,&local_34);
    }
    iVar13 = iVar13 + 1;
    pfVar12 = pfVar12 + 1;
    piVar10 = piVar10 + 0x11;
    pfVar15 = pfVar15 + 3;
    piVar14 = piVar14 + 7;
  } while (iVar13 < 8);
  piVar10 = param_1 + 0x20a;
  iVar13 = 0;
  piVar14 = param_1 + 0xf80;
  pfVar12 = (float *)(param_1 + 0xd64);
  do {
    if (((*piVar10 != 0) && ((char)piVar10[0x10] != '\0')) &&
       ((fVar4 = (*param_2 - pfVar12[-1]) * (*param_2 - pfVar12[-1]) +
                 (param_2[1] - *pfVar12) * (param_2[1] - *pfVar12) +
                 (param_2[2] - pfVar12[1]) * (param_2[2] - pfVar12[1]), fVar4 < fVar1 &&
        (fVar4 = (_DAT_0059e43c - fVar4 / fVar1) * fVar3, (float)param_1[0xf7d] < fVar4)))) {
      if ((fVar4 <= (float)param_1[0xf7e]) ||
         (uVar11 = DAT_008aae70 & 0xff, DAT_008aae70 = DAT_008aae70 + 1,
         (float)param_1[0xf7f] <= *(float *)(&DAT_008aae74 + uVar11 * 4))) {
        if ((param_1[0xcaf] == 0) &&
           ((float)_DAT_0059e430 < (float)param_1[0xf7e] - (float)param_1[0xf7d])) {
          param_3 = (float *)((fVar4 - (float)param_1[0xf7d]) /
                             ((float)param_1[0xf7e] - (float)param_1[0xf7d]));
          if (_DAT_0059e43c < (float)param_3) {
            param_3 = (float *)0x3f800000;
          }
          FUN_00442060(iVar13,param_3);
        }
      }
      else {
        FUN_004ed250(iVar13);
        local_34 = param_1[0xd2b];
        local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7e8 +
                   (float)param_1[0xd2c] * pfVar12[-1] +
                   (float)param_1[0xd2e] * pfVar12[1] + (float)param_1[0xd2d] * *pfVar12 +
                   (float)param_1[0xd35];
        local_2c = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 1 & 0xff) * 4) * _DAT_0059e7e8 +
                   (float)param_1[0xd2f] * pfVar12[-1] +
                   (float)param_1[0xd31] * pfVar12[1] + (float)param_1[0xd30] * *pfVar12 +
                   (float)param_1[0xd36];
        local_28 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 2 & 0xff) * 4) * _DAT_0059e7e8 +
                   (float)param_1[0xd32] * pfVar12[-1] +
                   (float)param_1[0xd34] * pfVar12[1] + (float)param_1[0xd33] * *pfVar12 +
                   (float)param_1[0xd37];
        uVar11 = DAT_008aae70 + 4;
        local_18 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 3 & 0xff) * 4) +
                   *(float *)(&DAT_008ab274 + (DAT_008aae70 + 3 & 0xff) * 4);
        uVar9 = DAT_008aae70 + 5;
        DAT_008aae70 = DAT_008aae70 + 6;
        local_14 = *(float *)(&DAT_008ab274 + (uVar11 & 0xff) * 4) +
                   *(float *)(&DAT_008ab274 + (uVar11 & 0xff) * 4) + _DAT_0059e7ec;
        local_c = 0;
        local_8 = 0;
        local_4 = 0;
        local_24 = param_1[0xd38];
        local_20 = param_1[0xd39];
        local_1c = param_1[0xd3a];
        local_10 = *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4) +
                   *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4);
        FUN_00411330(3,piVar14,param_1[1],iVar13,&local_34);
        iVar2 = param_1[0xe6d];
        if (iVar2 == 0) {
          if ((iVar13 == 2) || (iVar13 == 3)) {
            FUN_004efae0();
          }
        }
        else if ((iVar2 == 1) || ((iVar2 == 2 && ((iVar13 == 0 || (iVar13 == 1)))))) {
          FUN_004efae0();
        }
      }
    }
    iVar13 = iVar13 + 1;
    piVar10 = piVar10 + 0x4a;
    pfVar12 = pfVar12 + 0x3e;
    piVar14 = piVar14 + 7;
  } while (iVar13 < 4);
  return;
}


