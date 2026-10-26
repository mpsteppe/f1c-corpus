// Function: FUN_00438da0 @ 00438da0
// Strings:  [driver_head, fuel_tank, rear_axle, rr_spindle, rr_wheel, rl_spindle, rl_wheel, fr_spindle]


void __thiscall FUN_00438da0(int param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_0056d930(param_2);
  pvVar1 = operator_new(*(int *)(param_1 + 0x15ac) * 0x30);
  *(void **)(param_1 + 0x162c) = pvVar1;
  uVar2 = FUN_0056ead0(&DAT_005c41d4);
  *(undefined4 *)(param_1 + 0x15f0) = uVar2;
  iVar3 = FUN_0056eb30(s_fl_steering_005c41c8);
  if (*(int *)(iVar3 + 4) == *(int *)(param_1 + 0x15f0)) {
    uVar2 = *(undefined4 *)(iVar3 + 8);
  }
  else {
    uVar2 = *(undefined4 *)(iVar3 + 0x10);
  }
  *(undefined4 *)(param_1 + 0x1630) = uVar2;
  iVar3 = FUN_0056eb30(s_fr_steering_005c41bc);
  if (*(int *)(iVar3 + 4) == *(int *)(param_1 + 0x15f0)) {
    uVar2 = *(undefined4 *)(iVar3 + 8);
  }
  else {
    uVar2 = *(undefined4 *)(iVar3 + 0x10);
  }
  *(undefined4 *)(param_1 + 0x1644) = uVar2;
  uVar2 = FUN_0056ead0(s_fl_wheel_005c41b0);
  *(undefined4 *)(param_1 + 1000) = uVar2;
  uVar2 = FUN_0056ead0(s_fl_spindle_005c41a4);
  *(undefined4 *)(param_1 + 0x3ec) = uVar2;
  uVar2 = FUN_0056ead0(s_fr_wheel_005c4198);
  *(undefined4 *)(param_1 + 0x84c) = uVar2;
  uVar2 = FUN_0056ead0(s_fr_spindle_005c418c);
  *(undefined4 *)(param_1 + 0x850) = uVar2;
  uVar2 = FUN_0056ead0(s_rl_wheel_005c4180);
  *(undefined4 *)(param_1 + 0xcb0) = uVar2;
  uVar2 = FUN_0056ead0(s_rl_spindle_005c4174);
  *(undefined4 *)(param_1 + 0xcb4) = uVar2;
  uVar2 = FUN_0056ead0(s_rr_wheel_005c4168);
  *(undefined4 *)(param_1 + 0x1114) = uVar2;
  uVar2 = FUN_0056ead0(s_rr_spindle_005c415c);
  *(undefined4 *)(param_1 + 0x1118) = uVar2;
  uVar2 = FUN_0056ead0(s_rear_axle_005c4150);
  *(undefined4 *)(param_1 + 0x141c) = uVar2;
  uVar2 = FUN_0056ead0(s_fuel_tank_005c4144);
  *(undefined4 *)(param_1 + 0x1d4) = uVar2;
  uVar2 = FUN_0056ead0(s_driver_head_005c4138);
  *(undefined4 *)(param_1 + 0x1e8) = uVar2;
  return;
}


