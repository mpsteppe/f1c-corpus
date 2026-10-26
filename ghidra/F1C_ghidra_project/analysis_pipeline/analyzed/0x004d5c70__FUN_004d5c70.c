// Function: FUN_004d5c70 @ 004d5c70
// Size (bytes): 545


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004d5c70(undefined4 *param_1,double param_2,double param_3,double param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  double local_70;
  double local_68;
  double local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  double local_48;
  double local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  double local_20;
  int local_18 [5];
  
  if (_DAT_0059e430 < param_2) {
    param_2 = -param_2;
  }
  local_50 = _DAT_0059e430;
  if ((_DAT_0059e430 <= param_3) && (local_50 = param_3, _DAT_0059e420 < param_3)) {
    local_50 = _DAT_0059e420;
  }
  *(double *)(param_1 + 8) = param_4;
  iVar1 = 0;
  puVar2 = &local_c0;
  do {
    local_18[iVar1] = (int)puVar2;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 10;
  } while (iVar1 < 4);
  local_68 = param_4 * param_4;
  local_74 = param_2._4_4_;
  local_c0 = 0;
  local_70 = local_68 * param_4;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0x3ff00000;
  local_60 = param_4;
  local_a0 = 0;
  local_9c = 0x3ff00000;
  local_98 = 0;
  local_94 = 0;
  local_48 = local_68 * _DAT_0059e7e0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0x3ff00000;
  local_80 = 0;
  local_40 = param_4 + param_4;
  local_7c = 0;
  local_78 = param_2._0_4_;
  local_58 = 0;
  local_54 = 0x3ff00000;
  local_38 = 0;
  local_34 = 0x3ff00000;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = local_68;
  iVar1 = FUN_005677b0();
  if (iVar1 != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0x3ff00000;
    return;
  }
  *param_1 = local_a0;
  param_1[1] = local_9c;
  param_1[2] = local_78;
  param_1[3] = local_74;
  param_1[4] = (undefined4)local_50;
  param_1[5] = local_50._4_4_;
  param_1[6] = local_28;
  param_1[7] = local_24;
  return;
}


