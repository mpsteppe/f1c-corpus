// Function: FUN_004a3b50 @ 004a3b50
// Size (bytes): 1154


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004a3b50(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  uint uVar6;
  float10 fVar7;
  float10 fVar8;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  undefined4 local_7c;
  float local_78;
  undefined4 local_74;
  float local_6c;
  float local_68;
  float local_64 [2];
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  double local_34;
  double local_2c;
  double local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  double local_c;
  undefined4 local_4;
  
  FUN_004d1140(DAT_007c54e8,&local_8c,&local_7c);
  pfVar4 = (float *)FUN_00403640(&local_8c,0);
  if (pfVar4[0x4b] == 1.4013e-45) {
    pfVar1 = (float *)pfVar4[0x44];
    local_98 = *pfVar1 - *pfVar4;
    local_94 = pfVar1[1] - pfVar4[1];
    local_90 = pfVar1[2] - pfVar4[2];
    fVar2 = local_98 * local_98 + local_94 * local_94 + local_90 * local_90;
    if (fVar2 < DAT_0059e440 == (fVar2 == DAT_0059e440)) {
      fVar2 = _DAT_0059e43c / SQRT(fVar2);
      local_98 = local_98 * fVar2;
      local_94 = local_94 * fVar2;
      local_90 = fVar2 * local_90;
    }
    local_80 = (local_8c - *pfVar4) * local_98 +
               (local_84 - pfVar4[2]) * local_90 + local_94 * (local_88 - pfVar4[1]);
    fVar2 = ((local_8c - *pfVar4) * pfVar4[8] +
            (local_88 - pfVar4[1]) * pfVar4[9] + (local_84 - pfVar4[2]) * pfVar4[10]) *
            _DAT_0059e8b4;
    if ((((fVar2 < DAT_0059e440) || (fVar3 = _DAT_005acb30, _DAT_005acb30 <= fVar2)) &&
        (fVar3 = fVar2, fVar2 < DAT_0059e440 != (fVar2 == DAT_0059e440))) && (_DAT_005acb2c < fVar2)
       ) {
      fVar3 = _DAT_005acb2c;
    }
    local_68 = local_90 * local_80;
    local_64[0] = fVar3 * pfVar4[8] + *pfVar4;
    local_5c = fVar3 * pfVar4[10] + pfVar4[2];
    local_88 = fVar3 * pfVar4[9] + pfVar4[1] + local_94 * local_80;
    local_8c = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e448 +
               local_64[0] + local_98 * local_80;
    uVar6 = DAT_008aae70 + 2;
    local_84 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 1 & 0xff) * 4) * _DAT_0059e448 +
               local_5c + local_68;
    if (fVar3 < DAT_0059e440) {
      local_98 = -local_98;
      local_90 = -local_90;
    }
    DAT_008aae70 = DAT_008aae70 + 3;
    fVar7 = (float10)*(float *)(&DAT_008ab274 + (uVar6 & 0xff) * 4) * (float10)_DAT_0059e448;
    fVar8 = (float10)fpatan((float10)local_90,(float10)local_98);
  }
  else {
    uVar6 = DAT_008aae70 & 0xff;
    fVar3 = *(float *)(&DAT_008ab274 + (DAT_008aae70 + 1 & 0xff) * 4) * _DAT_0059e84c;
    DAT_008aae70 = DAT_008aae70 + 2;
    fVar2 = *(float *)(&DAT_008ab274 + uVar6 * 4) * _DAT_0059e84c - _DAT_0059e940;
    FUN_00566e40();
    local_80 = local_3c * DAT_0059e440;
    local_68 = local_40 * fVar3 + local_38 * fVar2 + local_80;
    local_8c = (float)((float10)fVar3 * (float10)local_58 + (float10)local_50 * (float10)fVar2 +
                       (float10)local_54 * (float10)DAT_0059e440 + (float10)local_8c);
    local_88 = local_48 * DAT_0059e440 + local_4c * fVar3 + local_44 * fVar2 + local_88;
    local_84 = local_68 + local_84;
    uVar6 = DAT_008aae70 & 0xff;
    DAT_008aae70 = DAT_008aae70 + 1;
    fVar7 = (float10)*(float *)(&DAT_008ab274 + uVar6 * 4) * (float10)_DAT_0059e448;
    fVar8 = (float10)fpatan((float10)local_38 * (float10)DAT_0059e440 +
                            (float10)local_40 * (float10)_DAT_0059e670 + (float10)local_80,
                            (float10)local_58 * (float10)_DAT_0059e670 +
                            (float10)local_50 * (float10)DAT_0059e440 +
                            (float10)local_54 * (float10)DAT_0059e440);
  }
  local_7c = 0;
  local_78 = (float)(fVar7 - fVar8);
  local_74 = 0;
  if (*(int *)(param_1 + 100) != 0) {
    FUN_004dd550(local_64);
    local_34 = (double)local_8c;
    local_2c = (double)local_88;
    local_24 = (double)local_84;
    local_1c = 0;
    local_18 = 0x40200000;
    local_14 = 0x40000000;
    local_10 = 0x479e17b8;
    local_4 = 0;
    iVar5 = FUN_0044c4c0(&local_34);
    if (iVar5 != 0) {
      local_88 = ((float)local_c - local_6c) - _DAT_005acb28;
    }
  }
  FUN_004a2800(&local_8c,&local_7c);
  return;
}


