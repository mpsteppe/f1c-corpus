// Function: FUN_004c9fb0 @ 004c9fb0
// Size (bytes): 713


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c9fb0(int *param_1,int param_2)

{
  float *pfVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_10;
  float local_c;
  float local_4;
  
  if ((param_2 != 0) && (iVar7 = FUN_0054c230(0), iVar7 != 0)) {
    *param_1 = param_2;
    FUN_004dd550(&local_24);
    pfVar1 = (float *)(param_1 + 1);
    FUN_0054b420(pfVar1,param_1 + 2,param_1 + 3);
    local_10 = local_28 + local_1c;
    local_c = (local_30 + local_24) * _DAT_0059e450;
    fVar5 = (local_20 + local_2c) * _DAT_0059e450;
    fVar6 = local_10 * _DAT_0059e450;
    *pfVar1 = local_c + *pfVar1;
    param_1[2] = (int)(fVar5 + (float)param_1[2]);
    param_1[3] = (int)(fVar6 + (float)param_1[3]);
    param_1[4] = (int)(SQRT((local_24 - local_30) * (local_24 - local_30) +
                            (local_20 - local_2c) * (local_20 - local_2c) +
                            (local_1c - local_28) * (local_1c - local_28)) * _DAT_0059e450);
    local_20 = local_20 - local_2c;
    if (local_20 < DAT_0059e440 == (local_20 == DAT_0059e440)) {
      uVar11 = DAT_008aae70 & 0xff;
      DAT_008aae70 = DAT_008aae70 + 1;
      fVar5 = *(float *)(&DAT_008ab274 + uVar11 * 4) * _DAT_0059e868;
      param_1[7] = 0x3a766a55;
      param_1[6] = (int)(fVar5 + _DAT_0059e43c);
      uVar11 = DAT_008aae70 & 0xff;
      DAT_008aae70 = DAT_008aae70 + 1;
      param_1[8] = (int)(((*(float *)(&DAT_008ab274 + uVar11 * 4) * _DAT_0059e8c8 + _DAT_005ace94) *
                         (float)_DAT_0059ed28) / (local_20 + _DAT_0059e478));
      fVar14 = (float10)*(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) *
               (float10)_DAT_0059e450 + (float10)_DAT_0059e6e8;
      uVar11 = DAT_008aae70 + 2;
      fVar15 = (float10)fcos(fVar14);
      fVar14 = (float10)fsin((float10)(float)fVar14);
      local_4 = (float)fVar14;
      if (_DAT_0059e7e8 <= *(float *)(&DAT_008ab274 + (DAT_008aae70 + 1 & 0xff) * 4)) {
        fVar14 = -fVar14;
        fVar16 = fVar15;
      }
      else {
        fVar16 = -fVar15;
      }
      DAT_008aae70 = DAT_008aae70 + 3;
      fVar17 = (float10)*(float *)(&DAT_008ab274 + (uVar11 & 0xff) * 4) * (float10)_DAT_0059e7e8 +
               (float10)_DAT_0059e450;
      param_1[10] = (int)local_4;
      local_18 = (float)(fVar17 * fVar14);
      param_1[0xb] = (int)local_18;
      param_1[9] = (int)(float)fVar15;
      param_1[0xc] = (int)(float)(fVar17 * fVar16);
      iVar7 = FUN_0054e100();
      iVar12 = 0;
      param_1[0xd] = 0;
      if (0 < iVar7) {
        do {
          iVar8 = FUN_0054e120(iVar12);
          if (local_2c < *(float *)(iVar8 + 4)) {
            param_1[0xd] = param_1[0xd] + 1;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 < iVar7);
      }
      pvVar9 = operator_new(param_1[0xd] * 0x14);
      iVar12 = 0;
      param_1[0xe] = (int)pvVar9;
      if (0 < iVar7) {
        iVar8 = 0;
        do {
          puVar10 = (undefined4 *)FUN_0054e120(iVar12);
          iVar13 = iVar8;
          if (local_2c < (float)puVar10[1]) {
            *(undefined4 **)(iVar8 + param_1[0xe]) = puVar10;
            uVar3 = puVar10[2];
            uVar4 = puVar10[1];
            puVar2 = (undefined4 *)(iVar8 + 4 + param_1[0xe]);
            *puVar2 = *puVar10;
            iVar13 = iVar8 + 0x14;
            puVar2[1] = uVar4;
            puVar2[2] = uVar3;
            *(float *)(iVar8 + 0x10 + param_1[0xe]) =
                 ((float)puVar10[1] - local_2c) * ((float)puVar10[1] - local_2c);
          }
          iVar12 = iVar12 + 1;
          iVar8 = iVar13;
        } while (iVar12 < iVar7);
        return;
      }
    }
  }
  return;
}


