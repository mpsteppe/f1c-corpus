// Function: FUN_004fe350 @ 004fe350
// Strings:  [Minute, Minute, TrackTemp, AmbientTemp, AmbientTemp, OffPathWetness, OnPathWetness, TrackWetness]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004fe350(int param_1,float param_2)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  undefined4 *puVar8;
  int iVar9;
  float10 fVar10;
  float local_18;
  int local_10 [4];
  
  local_18 = 0.3;
  local_10[0] = FUN_0042ce30();
  local_10[1] = 0;
  local_10[2] = 0;
  local_10[3] = FUN_0042ce30();
  switch(DAT_007c56a4) {
  case 1:
  case 7:
    break;
  case 2:
    goto LAB_004fe3d3;
  case 3:
  case 4:
    local_10[1] = FUN_0042ce30();
    local_10[2] = FUN_0042ce30();
    goto switchD_004fe397_default;
  case 5:
    break;
  case 6:
LAB_004fe3d3:
    local_10[1] = FUN_0042ce30();
    local_10[2] = FUN_0042ce30();
  default:
    goto switchD_004fe397_default;
  }
  local_10[1] = FUN_0042ce30();
switchD_004fe397_default:
  iVar9 = 0;
  while ((local_10[iVar9] == 0 || (param_2 = (float)FUN_005679c0(local_10[iVar9]), param_2 == 0.0)))
  {
    iVar9 = iVar9 + 1;
    if (3 < iVar9) goto LAB_004fe4d1;
  }
  iVar2 = __ftol();
  uVar6 = FUN_00567970();
  iVar3 = FUN_00587ece(uVar6);
  if (iVar3 < 1) {
    iVar3 = 100;
  }
  iVar9 = local_10[iVar9];
  while (iVar4 = FUN_0049adb0(), iVar4 != 0) {
    uVar6 = FUN_00499e20(iVar9);
    iVar5 = FUN_00588410(uVar6);
    if (iVar5 == 0) {
      uVar6 = FUN_00567970();
      iVar5 = FUN_00587ece(uVar6);
      if (iVar5 < 1) {
        iVar5 = 100;
      }
      if ((iVar2 <= iVar5) && (iVar5 < iVar3)) {
        param_2 = (float)iVar4;
        iVar3 = iVar5;
      }
    }
  }
LAB_004fe4d1:
  if (param_2 == 0.0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0x41a00000;
  *(undefined4 *)(param_1 + 0x34) = 0x41b00000;
  iVar9 = FUN_005679c0(s_Conditions_005d7028);
  if (iVar9 != 0) {
    uVar6 = FUN_00567970();
    fVar10 = (float10)FUN_004fe0d0(uVar6);
    local_18 = (float)fVar10;
    FUN_004fde00(local_18);
  }
  iVar9 = FUN_005679c0(s_TrackWetness_005d7018);
  if (iVar9 != 0) {
    uVar6 = FUN_00567970();
    fVar10 = (float10)FUN_004fe1e0(uVar6);
    *(float *)(param_1 + 0x28) = (float)fVar10;
    *(float *)(param_1 + 0x2c) = (float)fVar10;
  }
  iVar9 = FUN_005679c0(s_OnPathWetness_005d7008);
  if (iVar9 != 0) {
    uVar6 = FUN_00567970();
    fVar10 = (float10)FUN_004fe1e0(uVar6);
    *(float *)(param_1 + 0x28) = (float)fVar10;
  }
  iVar9 = FUN_005679c0(s_OffPathWetness_005d6ff8);
  if (iVar9 != 0) {
    uVar6 = FUN_00567970();
    fVar10 = (float10)FUN_004fe1e0(uVar6);
    *(float *)(param_1 + 0x2c) = (float)fVar10;
  }
  if (*(float *)(param_1 + 0x2c) < *(float *)(param_1 + 0x28)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x28);
  }
  iVar9 = FUN_005679c0(s_AmbientTemp_005d6fec);
  if (iVar9 != 0) {
    uVar6 = FUN_00567970();
    fVar10 = (float10)FUN_004fe2b0(uVar6);
    *(float *)(param_1 + 0x30) = (float)fVar10;
    *(float *)(param_1 + 0x34) = (float)(fVar10 + (float10)_DAT_0059e800);
  }
  iVar9 = FUN_005679c0(s_TrackTemp_005d6fe0);
  if (iVar9 != 0) {
    uVar6 = FUN_00567970();
    fVar10 = (float10)FUN_004fe2b0(uVar6);
    *(float *)(param_1 + 0x34) = (float)fVar10;
  }
  pvVar7 = operator_new(0x10);
  if (pvVar7 == (void *)0x0) {
    puVar8 = (undefined4 *)0x0;
  }
  else {
    puVar8 = (undefined4 *)FUN_004fc9a0();
  }
  *(undefined4 **)(param_1 + 0x3c) = puVar8;
  *puVar8 = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x3c) + 4) = *(undefined4 *)(param_1 + 0x30);
  *(float *)(*(int *)(param_1 + 0x3c) + 8) = local_18;
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x3c);
  param_2 = _DAT_005ea408;
  if ((_DAT_005ea408 < _DAT_0059eed0) || (_DAT_005acee4 < _DAT_005ea408)) {
    param_2 = 92.0;
  }
  iVar9 = FUN_005679c0(s_Minute_005d6fd8);
  if (iVar9 != 0) goto LAB_004fe762;
  iVar9 = FUN_005679c0(&DAT_005c330c);
  if (iVar9 != 0) {
    do {
      uVar6 = FUN_00567970();
      fVar10 = (float10)FUN_0058850f(uVar6);
      fVar10 = fVar10 * (float10)param_2;
      while( true ) {
        pvVar7 = operator_new(0x10);
        if (pvVar7 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_004fc9a0();
        }
        *(undefined4 *)(*(int *)(param_1 + 0x38) + 0xc) = uVar6;
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x38) + 0xc) + 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x38) + 4);
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x38) + 0xc) + 8) =
             *(undefined4 *)(*(int *)(param_1 + 0x38) + 8);
        pfVar1 = *(float **)(*(int *)(param_1 + 0x38) + 0xc);
        *(float **)(param_1 + 0x38) = pfVar1;
        *pfVar1 = (float)fVar10;
        *(undefined4 *)(*(int *)(param_1 + 0x38) + 0xc) = 0;
        iVar9 = FUN_005679c0(s_Conditions_005d7028);
        if (iVar9 != 0) {
          uVar6 = FUN_00567970();
          fVar10 = (float10)FUN_004fe0d0(uVar6);
          *(float *)(*(int *)(param_1 + 0x38) + 8) = (float)fVar10;
        }
        iVar9 = FUN_005679c0(s_AmbientTemp_005d6fec);
        if (iVar9 != 0) {
          uVar6 = FUN_00567970();
          fVar10 = (float10)FUN_004fe2b0(uVar6);
          *(float *)(*(int *)(param_1 + 0x38) + 4) = (float)fVar10;
        }
        iVar9 = FUN_0049adb0();
        if (iVar9 == 0) {
          return 0;
        }
        uVar6 = FUN_00499e20(s_Minute_005d6fd8);
        iVar9 = FUN_00588410(uVar6);
        if (iVar9 != 0) break;
LAB_004fe762:
        uVar6 = FUN_00567970();
        fVar10 = (float10)FUN_0058850f(uVar6);
        fVar10 = fVar10 * (float10)_DAT_0059f118;
      }
      uVar6 = FUN_00499e20(&DAT_005c330c);
      iVar9 = FUN_00588410(uVar6);
    } while (iVar9 == 0);
  }
  return 0;
}


