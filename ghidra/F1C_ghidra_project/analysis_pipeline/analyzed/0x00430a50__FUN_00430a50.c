// Function: FUN_00430a50 @ 00430a50
// Size (bytes): 1196


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00430a50(int param_1,double param_2)

{
  double dVar1;
  double dVar2;
  int iVar3;
  float10 fVar4;
  double local_98;
  double local_90;
  undefined8 local_88;
  double local_80;
  int local_78;
  undefined4 uStack_74;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  undefined1 local_38 [8];
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  iVar3 = FUN_004d7880();
  if (iVar3 == 0) {
    return (float10)_DAT_0059e430;
  }
  iVar3 = FUN_004d7570();
  if (iVar3 == 0) {
    return (float10)_DAT_0059e430;
  }
  local_80 = (double)*(int *)(param_1 + 0xc44) * *(double *)(param_1 + 0xc38) +
             *(double *)(param_1 + 0xc30);
  local_98 = _DAT_0059e420 - local_80;
  if (DAT_008aeec0 == 0) {
    local_90 = *(double *)(iVar3 + 0x168);
    local_70 = *(double *)(iVar3 + 0x180) * _DAT_0059ea70;
    local_88 = local_80 * _DAT_0059ea78;
    local_78 = 2;
    FUN_004d5c70(*(undefined4 *)(iVar3 + 0x1b0),*(undefined4 *)(iVar3 + 0x1b4),
                 *(undefined4 *)(iVar3 + 0x1b8),*(undefined4 *)(iVar3 + 0x1bc),
                 *(undefined4 *)(iVar3 + 0x1c0),*(undefined4 *)(iVar3 + 0x1c4));
    local_98 = local_80;
  }
  else if (DAT_008aeec0 == 1) {
    local_88 = 1.0;
    local_70 = (*(double *)(iVar3 + 0x180) + *(double *)(iVar3 + 0x38)) * _DAT_0059e880;
    local_78 = 4;
    local_90 = (local_98 * *(double *)(iVar3 + 0x20) * _DAT_0059ea80 +
               local_80 * *(double *)(iVar3 + 0x168) * _DAT_0059ea78) *
               (_DAT_0059e880 / (local_80 * _DAT_0059ea78 + local_98 * _DAT_0059ea80));
    FUN_004d5c70((*(double *)(iVar3 + 0x1b0) + *(double *)(iVar3 + 0x68)) * _DAT_0059e880,
                 (*(double *)(iVar3 + 0x1b8) + *(double *)(iVar3 + 0x70)) * _DAT_0059e880,
                 (*(double *)(iVar3 + 0x1c0) + *(double *)(iVar3 + 0x78)) * _DAT_0059e880);
    local_98 = 1.0;
  }
  else {
    if (DAT_008aeec0 != 2) {
      return (float10)_DAT_0059e430;
    }
    local_70 = *(double *)(iVar3 + 0x38);
    local_88 = local_98 * _DAT_0059ea80;
    local_90 = *(double *)(iVar3 + 0x20);
    local_78 = 2;
    FUN_004d5c70(*(undefined4 *)(iVar3 + 0x68),*(undefined4 *)(iVar3 + 0x6c),
                 *(undefined4 *)(iVar3 + 0x70),*(undefined4 *)(iVar3 + 0x74),
                 *(undefined4 *)(iVar3 + 0x78),*(undefined4 *)(iVar3 + 0x7c));
  }
  local_70 = local_70 * _DAT_0059ea70;
  if (local_70 < _DAT_0059e430 != (local_70 == _DAT_0059e430)) {
LAB_00430cb6:
    return (float10)_DAT_0059e430;
  }
  FUN_00430600();
  local_48 = ((double)*(int *)(param_1 + 0xcc4) * *(double *)(param_1 + 0xcb8) +
             *(double *)(param_1 + 0xcb0)) * _DAT_0059ea60 + _DAT_008adb40;
  dVar1 = (local_48 * local_88 * _DAT_0059ea58 -
          (double)local_68._0_4_ * local_98 * param_2 * param_2) / (double)local_78;
  dVar2 = dVar1;
  if (local_10 < dVar1) {
    dVar2 = local_10;
  }
  local_68 = 0.0;
  iVar3 = 0x2c;
  local_50 = (((local_30 * dVar2 + local_28) * dVar2 + local_20) * dVar2 + local_18) * dVar1 *
             (double)local_78 * local_90;
  do {
    if (*(char *)(iVar3 * 0x40 + 0xbcc + param_1) == '\0') break;
    fVar4 = (float10)FUN_0042ed00();
    local_58 = (double)fVar4;
    if (fVar4 < (float10)_DAT_0059e430 != (fVar4 == (float10)_DAT_0059e430)) goto LAB_00430cb6;
    local_40 = _DAT_0059e420 / local_70;
    local_90 = local_40 * local_58 * param_2;
    local_60 = (double)*(int *)(param_1 + 0x1584) * *(double *)(param_1 + 0x1578) +
               *(double *)(param_1 + 0x1570);
    if (local_90 <= local_60) {
      FUN_004f6720(local_90,local_38,&local_88);
      if ((iVar3 == 0x2c) &&
         (local_60 = (local_60 - local_90) * _DAT_0059ea68,
         local_90 < _DAT_008ae194 != (local_90 == _DAT_008ae194))) {
        do {
          FUN_004f6720(local_90._0_4_,(int)((ulonglong)local_90 >> 0x20),local_38,&local_78);
          if (local_88 < (double)CONCAT44(uStack_74,local_78)) {
            local_88 = (double)CONCAT44(uStack_74,local_78);
          }
          local_90 = local_90 + local_60;
        } while (local_90 < _DAT_008ae194 != (local_90 == _DAT_008ae194));
      }
      dVar1 = local_40 * local_88 * local_58;
      if (local_50 < dVar1) {
        dVar1 = local_50;
      }
      if (local_68 < dVar1) {
        local_68 = dVar1;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x33);
  return ((float10)local_68 - (float10)local_80._0_4_ * (float10)param_2 * (float10)param_2) /
         (float10)local_48;
}


