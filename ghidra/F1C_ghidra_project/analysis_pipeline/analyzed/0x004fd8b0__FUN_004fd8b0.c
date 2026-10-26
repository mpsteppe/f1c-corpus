// Function: FUN_004fd8b0 @ 004fd8b0
// Size (bytes): 1358


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fd8b0(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  void *pvVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  float *pfVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  
  FUN_004fd840();
  fVar11 = (float10)FUN_004b3ce0();
  local_20 = (float)(fVar11 * (float10)_DAT_005acb0c);
  if ((float10)_DAT_005ad300 <= fVar11 * (float10)_DAT_005acb0c) {
    if (_DAT_0059e814 < local_20) {
      local_20 = 900.0;
    }
  }
  else {
    local_20 = -900.0;
  }
  local_14 = local_20 * _DAT_0059e7f8;
  if (_DAT_005ad300 <= local_14) {
    if (_DAT_0059e814 < local_14) {
      local_14 = 900.0;
    }
  }
  else {
    local_14 = -900.0;
  }
  fVar11 = (float10)FUN_004b3ce0();
  local_28 = (float)(fVar11 * (float10)_DAT_0059e8c8);
  if ((float10)_DAT_0059e670 <= fVar11 * (float10)_DAT_0059e8c8) {
    if (_DAT_0059e43c < local_28) {
      local_28 = 1.0;
    }
  }
  else {
    local_28 = -1.0;
  }
  local_18 = local_28 * _DAT_005ad148;
  if (_DAT_005ad184 <= local_18) {
    if (_DAT_0059e84c < local_18) {
      local_18 = 0.1;
    }
  }
  else {
    local_18 = -0.1;
  }
  fVar11 = (float10)FUN_004b3ce0();
  local_24 = (float)(fVar11 * (float10)_DAT_0059e7ec);
  if ((float10)_DAT_005ad2fc <= fVar11 * (float10)_DAT_0059e7ec) {
    if (_DAT_0059e8f0 < local_24) {
      local_24 = 12.5;
    }
  }
  else {
    local_24 = -12.5;
  }
  local_1c = local_24 * _DAT_005ad2f8;
  if (_DAT_0059e7f0 <= local_1c) {
    if (_DAT_0059e800 < local_1c) {
      local_1c = 2.0;
    }
  }
  else {
    local_1c = -2.0;
  }
  local_10 = local_28 + _DAT_0059e8b4;
  if (DAT_0059e440 <= local_10) {
    if (_DAT_0059e43c < local_10) {
      local_10 = 1.0;
    }
  }
  else {
    local_10 = 0.0;
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
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x3c);
  while( true ) {
    fVar12 = (float10)FUN_0058957a();
    fVar13 = (float10)fsin(fVar12 * (float10)_DAT_005ad2f0);
    fVar2 = (float10)_DAT_0059e5fc;
    fVar11 = (float10)_DAT_0059e8d8;
    fVar4 = (float10)_DAT_0059e450;
    fVar3 = (float10)_DAT_0059e7ec;
    fVar14 = (float10)FUN_004b3ce0();
    fVar14 = (fVar14 * (float10)_DAT_005ad2e8 + (float10)local_1c) -
             (float10)local_24 * (float10)_DAT_005ad2f8;
    local_1c = (float)(fVar14 - (float10)_DAT_0059e84c * fVar14);
    if (_DAT_0059e7f0 <= local_1c) {
      if (_DAT_0059e800 < local_1c) {
        local_1c = 2.0;
      }
    }
    else {
      local_1c = -2.0;
    }
    local_24 = local_1c + local_24;
    if (_DAT_005ad2fc <= local_24) {
      if (_DAT_0059e8f0 < local_24) {
        local_24 = 12.5;
      }
    }
    else {
      local_24 = -12.5;
    }
    fVar14 = (float10)FUN_004b3ce0();
    fVar14 = (fVar14 * (float10)_DAT_005ad2e4 + (float10)local_18) -
             (float10)local_28 * (float10)_DAT_005ad148;
    local_18 = (float)(fVar14 - (float10)_DAT_0059e868 * fVar14);
    if (_DAT_005ad184 <= local_18) {
      if (_DAT_0059e84c < local_18) {
        local_18 = 0.1;
      }
    }
    else {
      local_18 = -0.1;
    }
    local_28 = local_18 + local_28;
    if (_DAT_0059e670 <= local_28) {
      if (_DAT_0059e43c < local_28) {
        local_28 = 1.0;
      }
    }
    else {
      local_28 = -1.0;
    }
    *(float *)(*(int *)(param_1 + 0x38) + 4) =
         (float)((fVar13 * fVar2 + fVar11) - ((float10)local_10 - fVar4) * fVar3) + local_24;
    *(float *)(*(int *)(param_1 + 0x38) + 8) = local_28 + _DAT_0059e8b4;
    pfVar10 = (float *)(*(int *)(param_1 + 0x38) + 8);
    if (DAT_0059e440 <= *(float *)(*(int *)(param_1 + 0x38) + 8)) {
      if (_DAT_0059e43c < *pfVar10) {
        *pfVar10 = 1.0;
      }
    }
    else {
      *pfVar10 = 0.0;
    }
    iVar1 = *(int *)(param_1 + 0x38);
    local_10 = *(float *)(iVar1 + 8);
    if ((_DAT_0059e4e8 < *(float *)(iVar1 + 8)) && (*(float *)(iVar1 + 8) < _DAT_0059e8f8)) {
      if (_DAT_005ad2e0 <= *(float *)(iVar1 + 8)) {
        *(undefined4 *)(iVar1 + 8) = 0x3f266666;
      }
      else {
        *(undefined4 *)(iVar1 + 8) = 0x3f19999a;
      }
    }
    if (param_3 < **(float **)(param_1 + 0x38)) break;
    fVar11 = (float10)FUN_004b3ce0();
    fVar11 = (fVar11 * (float10)_DAT_0059e91c + (float10)local_14) -
             (float10)local_20 * (float10)_DAT_0059e7f8;
    local_14 = (float)(fVar11 - fVar11);
    if (_DAT_005ad300 <= local_14) {
      if (_DAT_0059e814 < local_14) {
        local_14 = 900.0;
      }
    }
    else {
      local_14 = -900.0;
    }
    fStack_c = 900.0;
    fVar6 = _DAT_005ad2dc;
    if ((_DAT_005ad2d8 < (float)fVar12) && ((float)fVar12 < _DAT_005ad2d4)) {
      fStack_c = 280.0;
      fVar6 = _DAT_0059e920;
    }
    fVar5 = local_14 + local_20;
    local_20 = -fStack_c;
    if ((local_20 <= fVar5) && (local_20 = fVar5, fStack_c < fVar5)) {
      local_20 = fStack_c;
    }
    pvVar7 = operator_new(0x10);
    if (pvVar7 == (void *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = FUN_004fc9a0();
    }
    *(undefined4 *)(*(int *)(param_1 + 0x38) + 0xc) = uVar9;
    *(float *)(*(float **)(param_1 + 0x38))[3] = fVar6 + local_20 + **(float **)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(*(int *)(param_1 + 0x38) + 0xc);
  }
  return;
}


