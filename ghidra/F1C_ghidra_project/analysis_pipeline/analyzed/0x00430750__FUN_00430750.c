// Function: FUN_00430750 @ 00430750
// Size (bytes): 766


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00430750(int param_1,double param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  iVar4 = FUN_004d7880(&DAT_008adb88);
  if (iVar4 == 0) {
    return (float10)_DAT_0059e430;
  }
  iVar4 = FUN_004d7570(*(undefined4 *)(param_1 + 0xbc4));
  if (iVar4 != 0) {
    local_68 = (double)*(int *)(param_1 + 0xc44) * *(double *)(param_1 + 0xc38) +
               *(double *)(param_1 + 0xc30);
    local_78 = _DAT_0059e420 - local_68;
    FUN_00430600(&DAT_008adb00,&local_80,&local_88);
    local_60 = ((double)*(int *)(param_1 + 0xcc4) * *(double *)(param_1 + 0xcb8) +
               *(double *)(param_1 + 0xcb0)) * _DAT_0059ea60 + _DAT_008adb40;
    dVar1 = local_60 * _DAT_0059ea58 - (double)local_88._0_4_ * param_2 * param_2;
    dVar2 = dVar1 * local_78;
    dVar1 = dVar1 * local_68;
    dVar3 = (_DAT_008adb60 + _DAT_0059ea50) *
            (dVar2 * *(double *)(iVar4 + 0x18) + dVar1 * *(double *)(iVar4 + 0x160)) * _DAT_0059ea48
    ;
    local_78 = local_78 * dVar3;
    local_68 = dVar3 * local_68;
    local_80 = (dVar2 - local_78) * _DAT_0059e880;
    local_78 = (local_78 + dVar2) * _DAT_0059e880;
    if (local_80 < _DAT_0059e430) {
      local_78 = local_78 + local_80;
      local_80 = 0.0;
    }
    local_70 = (dVar1 - local_68) * _DAT_0059e880;
    local_88 = (local_68 + dVar1) * _DAT_0059e880;
    if (local_70 < _DAT_0059e430) {
      local_88 = local_88 + local_70;
      local_70 = 0.0;
    }
    FUN_004d5c70(*(undefined4 *)(iVar4 + 0x68),*(undefined4 *)(iVar4 + 0x6c),
                 *(undefined4 *)(iVar4 + 0x70),*(undefined4 *)(iVar4 + 0x74),
                 *(undefined4 *)(iVar4 + 0x78),*(undefined4 *)(iVar4 + 0x7c));
    FUN_004d5c70(*(undefined4 *)(iVar4 + 0x1b0),*(undefined4 *)(iVar4 + 0x1b4),
                 *(undefined4 *)(iVar4 + 0x1b8),*(undefined4 *)(iVar4 + 0x1bc),
                 *(undefined4 *)(iVar4 + 0x1c0),*(undefined4 *)(iVar4 + 0x1c4));
    fVar5 = (float10)local_80;
    fVar6 = fVar5;
    if ((float10)local_38 < fVar5) {
      fVar6 = (float10)local_38;
    }
    fVar7 = (float10)local_78;
    fVar8 = fVar7;
    if ((float10)local_38 < fVar7) {
      fVar8 = (float10)local_38;
    }
    fVar9 = (float10)local_70;
    fVar10 = fVar9;
    if ((float10)local_10 < fVar9) {
      fVar10 = (float10)local_10;
    }
    dVar1 = local_88;
    if (local_10 < local_88) {
      dVar1 = local_10;
    }
    fVar11 = (float10)dVar1;
    return (((((float10)local_30 * fVar11 + (float10)local_28) * fVar11 + (float10)local_20) *
             fVar11 + (float10)local_18) * (float10)*(double *)(iVar4 + 0x160) * (float10)local_88 +
            ((((float10)local_30 * fVar10 + (float10)local_28) * fVar10 + (float10)local_20) *
             fVar10 + (float10)local_18) * (float10)*(double *)(iVar4 + 0x160) * fVar9 +
            ((((float10)local_58 * fVar8 + (float10)local_50) * fVar8 + (float10)local_48) * fVar8 +
            (float10)local_40) * (float10)*(double *)(iVar4 + 0x18) * fVar7 +
           ((((float10)local_58 * fVar6 + (float10)local_50) * fVar6 + (float10)local_48) * fVar6 +
           (float10)local_40) * (float10)*(double *)(iVar4 + 0x18) * fVar5) / (float10)local_60;
  }
  return (float10)_DAT_0059e430;
}


