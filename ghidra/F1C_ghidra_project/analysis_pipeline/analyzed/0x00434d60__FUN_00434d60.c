// Function: FUN_00434d60 @ 00434d60
// Size (bytes): 1236


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00434d60(int param_1,char param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  float fVar6;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [12];
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_14;
  float local_10;
  float local_8;
  float local_4;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 == 0) {
    return;
  }
  if (*(int *)(iVar2 + 0xb0) == 0) {
    return;
  }
  local_64 = *(undefined4 *)(iVar2 + 0xbc);
  iVar2 = FUN_004582a0(*(int *)(param_1 + 0x2c) + -1);
  iVar3 = FUN_004582a0(*(undefined4 *)(param_1 + 0x2c));
  pfVar4 = (float *)FUN_004582a0(*(int *)(param_1 + 0x2c) + 1);
  local_70 = -1.0;
  if ((iVar2 != 0) && (iVar3 != 0)) {
    local_70 = (*(float *)(iVar3 + 0x18) - *(float *)(*(int *)(param_1 + 0xc) + 0xbc)) /
               (*(float *)(iVar3 + 0x18) - *(float *)(iVar2 + 0x18));
    local_6c = local_70 * *(float *)(param_1 + 0x30);
  }
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if ((((*(int *)(param_1 + 0x1c) < 0) || (*(int *)(param_1 + 0x18) < 0)) ||
      (DAT_005c329c <= *(int *)(param_1 + 0x1c))) || (*(int *)(param_1 + 4) == 5)) {
    iVar2 = FUN_004582a0(4);
    if ((iVar2 == 0) || (iVar2 = FUN_004582a0(4), iVar2 == 0)) {
      FUN_00403cd0(0,&local_60,local_3c);
    }
    else {
      iVar2 = FUN_004582a0(4);
      iVar3 = FUN_004582a0(4);
      pfVar4 = (float *)FUN_004582a0(4);
      local_58 = -*(float *)(iVar2 + 8);
      local_5c = -*(float *)(iVar3 + 4);
      local_60 = -*pfVar4;
    }
  }
  else {
    FUN_004e1fd0(&local_54,local_3c);
    FUN_00403cd0(*(undefined4 *)(param_1 + 0x18),&local_48,local_3c);
    if (*(int *)(&DAT_005eb978 + *(int *)(param_1 + 0x1c) * 4) == 0) {
      if (pfVar4 != (float *)0x0) {
        local_60 = -*pfVar4;
        local_5c = -pfVar4[1];
        local_58 = -pfVar4[2];
        local_30 = local_60;
        local_2c = local_5c;
        local_28 = local_58;
      }
      FUN_00456060(&local_68,&local_70);
      if ((local_68 < *(float *)(param_1 + 0x10)) &&
         (local_68 = (float)_DAT_008afe98 * _DAT_0059e8ec + local_68,
         *(float *)(param_1 + 0x10) < local_68)) {
        local_68 = *(float *)(param_1 + 0x10);
      }
      iVar2 = *(int *)(param_1 + 0xc);
      *(float *)(iVar2 + 0x38) = local_68;
      *(float *)(iVar2 + 0x3c) = local_70;
    }
    else {
      if ((local_70 <= DAT_0059e440) || (local_70 < _DAT_0059e43c == (local_70 == _DAT_0059e43c))) {
        local_58 = local_4c;
        local_60 = local_54;
        local_5c = local_50;
        if (_DAT_0059e43c < local_70) {
          local_58 = local_40;
          local_60 = local_48;
          local_5c = local_44;
        }
      }
      else {
        fVar6 = _DAT_0059e43c - local_70;
        local_8 = local_50 * fVar6;
        local_4 = local_4c * fVar6;
        local_14 = local_44 * local_70;
        local_10 = local_40 * local_70;
        local_30 = local_48 * local_70 + local_54 * fVar6;
        local_2c = local_14 + local_8;
        local_28 = local_10 + local_4;
        local_58 = local_28;
        local_60 = local_30;
        local_5c = local_2c;
      }
      FUN_00456060(&local_70,&local_68);
      if ((*(float *)(param_1 + 0x14) < local_70) &&
         (local_70 = local_70 - (float)_DAT_008afe98 * _DAT_0059e7ec,
         local_70 < *(float *)(param_1 + 0x14))) {
        local_70 = *(float *)(param_1 + 0x14);
      }
      iVar2 = *(int *)(param_1 + 0xc);
      *(float *)(iVar2 + 0x38) = local_70;
      *(float *)(iVar2 + 0x3c) = local_68;
      FUN_004e1fd0(&local_54,local_3c);
    }
  }
  FUN_004582c0(local_64);
  local_68 = (float)_DAT_008afe98;
  if (*(char *)(param_1 + 1) != '\0') {
    local_64 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xa8);
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xa8) = 0;
    (**(code **)(**(int **)(param_1 + 0xc) + 0x18))
              (&local_60,local_3c,&local_24,0x447a0000,0x447a0000);
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xa8) = local_64;
    *(undefined1 *)(param_1 + 1) = 0;
  }
  piVar5 = *(int **)(param_1 + 0xc);
  if (param_2 == '\0') {
    fVar6 = 0.0;
    goto LAB_00435210;
  }
  local_70 = (float)piVar5[0x2a];
  if (local_6c <= local_70) {
    fVar6 = local_70;
    if ((local_6c < local_70) && (fVar6 = local_70 - local_68 * _DAT_0059e8a4, fVar6 < local_6c))
    goto LAB_004351c0;
  }
  else {
    fVar6 = local_70 + local_68;
    if (local_6c < local_70 + local_68) {
LAB_004351c0:
      fVar6 = local_6c;
    }
  }
  local_68 = *(float *)(param_1 + 0x30);
  fVar1 = DAT_0059e440;
  if ((DAT_0059e440 <= fVar6) && (fVar1 = fVar6, local_68 < fVar6)) {
    fVar1 = local_68;
  }
  piVar5[0x2a] = (int)fVar1;
  fVar6 = (float)_DAT_008afe98;
  piVar5 = *(int **)(param_1 + 0xc);
LAB_00435210:
  (**(code **)(*piVar5 + 0x18))(&local_60,local_3c,&local_24,(float)_DAT_008afe90,fVar6);
  return;
}


