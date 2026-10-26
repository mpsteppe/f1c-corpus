// Function: FUN_0040e2b0 @ 0040e2b0
// Size (bytes): 449


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040e2b0(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  float local_48;
  float local_44;
  float local_40;
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
  
  FUN_004dd550(&local_24);
  local_48 = 0.0;
  local_44 = 0.0;
  local_4 = local_1c + local_10;
  local_40 = 0.0;
  fVar1 = (local_24 + local_18) * _DAT_0059e450;
  fVar2 = (local_20 + local_14) * _DAT_0059e450;
  fVar3 = local_4 * _DAT_0059e450;
  FUN_0054c230(0);
  iVar7 = FUN_0054e100();
  iVar9 = 0;
  if (0 < iVar7) {
    do {
      pfVar8 = (float *)FUN_0054e120(iVar9);
      local_48 = local_48 + *pfVar8;
      iVar9 = iVar9 + 1;
      local_44 = local_44 + pfVar8[1];
      local_40 = local_40 + pfVar8[2];
    } while (iVar9 < iVar7);
    if (0 < iVar7) {
      fVar4 = _DAT_0059e43c / (float)iVar7;
      local_48 = local_48 * fVar4;
      local_44 = local_44 * fVar4;
      local_40 = fVar4 * local_40;
    }
  }
  fVar4 = _DAT_0059e6e8;
  if (param_2 == 2) {
    fVar4 = _DAT_0059e458;
  }
  fVar5 = _DAT_0059e43c - fVar4;
  fVar6 = fVar1 * fVar4 + local_48 * fVar5;
  fVar1 = fVar2 * fVar4 + local_44 * fVar5;
  fVar2 = fVar3 * fVar4 + fVar5 * local_40;
  local_c = fVar6;
  local_8 = fVar1;
  local_4 = fVar2;
  FUN_0054b420(&local_30,&local_2c,&local_28);
  FUN_0054b3b0(fVar6 + local_30,fVar1 + local_2c,fVar2 + local_28);
  FUN_0040e1f0();
  return;
}


