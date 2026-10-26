// Function: FUN_0043b590 @ 0043b590
// Strings:  [fr_steering, fl_steering, fr_fore_lower, fr_fore_upper, fl_fore_lower, fl_fore_upper]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043b590(int param_1,int param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  double *pdVar5;
  double *pdVar6;
  float10 fVar7;
  float10 fVar8;
  double local_a0;
  double local_98;
  double local_90;
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
  
  FUN_0043af50(s_fl_steering_005c41c8,*(undefined4 *)(param_1 + 0x3ec),&local_20);
  FUN_0043af50(s_fr_steering_005c41bc,*(undefined4 *)(param_1 + 0x850),&local_68);
  iVar4 = *(int *)(param_1 + 0x15f0);
  FUN_004361d0(iVar4 + 4,&local_20,&local_38);
  FUN_004361d0(iVar4 + 4,&local_68,&local_20);
  *(undefined4 *)(param_1 + 0x1634) = **(undefined4 **)(param_1 + 0x1630);
  *(undefined4 *)(param_1 + 0x1638) = (*(undefined4 **)(param_1 + 0x1630))[1];
  *(undefined4 *)(param_1 + 0x1648) = **(undefined4 **)(param_1 + 0x1644);
  *(undefined4 *)(param_1 + 0x164c) = (*(undefined4 **)(param_1 + 0x1644))[1];
  fVar7 = (float10)*(int *)(param_2 + 0x1444) * (float10)*(double *)(param_2 + 0x1438) +
          (float10)*(double *)(param_2 + 0x1430);
  if (fVar7 <= (float10)_DAT_0059e430) {
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  else {
    *(double *)(param_1 + 0x8c) = (double)((float10)_DAT_0059e420 / fVar7);
  }
  fVar8 = (float10)(*(int *)(param_2 + 0x1440) + -1) * (float10)*(double *)(param_2 + 0x1438) +
          (float10)*(double *)(param_2 + 0x1430);
  if (fVar8 <= (float10)_DAT_0059e430) {
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  else {
    *(double *)(param_1 + 0x84) = (double)(fVar7 / fVar8);
  }
  fVar8 = (float10)fsin(fVar7);
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  local_88 = (double)ABS(fVar8);
  *(double *)(param_1 + 0x94) = (double)(fVar7 * (float10)_DAT_0059ec10);
  FUN_0043af50(s_fl_fore_upper_005c42e4,*(undefined4 *)(param_1 + 0x3ec),&local_80);
  FUN_0043af50(s_fl_fore_lower_005c42d4,*(undefined4 *)(param_1 + 0x3ec),&local_50);
  dVar1 = local_80 - local_50;
  local_68 = dVar1;
  dVar3 = local_78 - local_48;
  local_60 = dVar3;
  dVar2 = local_70 - local_40;
  local_58 = dVar2;
  pdVar5 = &local_68;
  pdVar6 = &local_a0;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pdVar6 = *(undefined4 *)pdVar5;
    pdVar5 = (double *)((int)pdVar5 + 4);
    pdVar6 = (double *)((int)pdVar6 + 4);
  }
  dVar1 = _DAT_0059e420 / SQRT(dVar1 * dVar1 + dVar3 * dVar3 + dVar2 * dVar2);
  local_a0 = local_68 * dVar1;
  local_98 = local_98 * dVar1;
  local_90 = local_90 * dVar1;
  local_60 = local_90 * _DAT_0059e428 - local_a0 * _DAT_0059e430;
  *(double *)(param_1 + 0x163c) =
       -(ABS((local_38 - local_80) * (local_98 * _DAT_0059e430 - local_90 * _DAT_0059e430) +
             (local_30 - local_78) * local_60 +
             (local_28 - local_70) * (local_a0 * _DAT_0059e430 - local_98 * _DAT_0059e428)) *
        local_88);
  FUN_0043af50(s_fr_fore_upper_005c42c4,*(undefined4 *)(param_1 + 0x850),&local_80);
  FUN_0043af50(s_fr_fore_lower_005c42b4,*(undefined4 *)(param_1 + 0x850),&local_50);
  local_38 = local_80 - local_50;
  local_30 = local_78 - local_48;
  local_28 = local_70 - local_40;
  pdVar5 = &local_38;
  pdVar6 = &local_a0;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pdVar6 = *(undefined4 *)pdVar5;
    pdVar5 = (double *)((int)pdVar5 + 4);
    pdVar6 = (double *)((int)pdVar6 + 4);
  }
  dVar1 = _DAT_0059e420 / SQRT(local_38 * local_38 + local_30 * local_30 + local_28 * local_28);
  dVar2 = local_38 * dVar1 * _DAT_0059e430;
  *(double *)(param_1 + 0x1650) =
       -(ABS((local_20 - local_80) *
             (local_98 * dVar1 * _DAT_0059e430 - local_90 * dVar1 * _DAT_0059e430) +
             (local_18 - local_78) * (local_90 * dVar1 * _DAT_0059e428 - dVar2) +
             (local_10 - local_70) * (dVar2 - local_98 * dVar1 * _DAT_0059e428)) * local_88);
  return;
}


