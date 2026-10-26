// Function: FUN_004f2c60 @ 004f2c60
// Strings:  [BrakePadRange, BrakePadSetting, BrakeDiscRange, BrakeDiscSetting, FastReboundRange, FastReboundSetting, SlowReboundRange, SlowReboundSetting]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f2c60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  double *pdVar1;
  int iVar2;
  
  iVar2 = FUN_005351d0(0x180);
  while ((iVar2 != 0 && (iVar2 = FUN_005651b0(), iVar2 != 1))) {
    if (iVar2 == 0) {
      FUN_00565aa0(s_BumpTravel_005d52f0,param_1,0,0,0);
      FUN_00565aa0(s_ReboundTravel_005d52e0,param_1 + 8,0,0,0);
      FUN_00565aa0(s_BumpStopSpring_005d52d0,param_1 + 0x10,0,0,0);
      FUN_00565aa0(s_BumpStopRisingSpring_005d52b8,param_1 + 0x18,0,0,0);
      FUN_00565aa0(s_BumpStopDamper_005d52a8,param_1 + 0x20,0,0,0);
      FUN_00565aa0(s_BumpStopRisingDamper_005d5290,param_1 + 0x28,0,0,0);
      FUN_00565aa0(s_BumpStage2_005d5284,param_1 + 0x30,0,0,0);
      FUN_00565aa0(s_ReboundStage2_005d5274,param_1 + 0x38,0,0,0);
      FUN_00565aa0(s_FrictionTorque_005d5264,param_1 + 0xa8,0,0,0);
      FUN_00565aa0(s_BrakeTorque_005d5258,param_1 + 0xb0,0,0,0);
      FUN_00565aa0(s_BrakeWearRate_005d5248,param_1 + 0xf0,0,0,0);
      FUN_00565aa0(s_BrakeFailure_005d5238,param_1 + 0xf8,param_1 + 0x100,0,0);
      pdVar1 = (double *)(param_1 + 0xb8);
      iVar2 = FUN_00565aa0(s_BrakeOptimumTemp_005d5224,pdVar1,0,0,0);
      if (iVar2 != 0) {
        *pdVar1 = *pdVar1 + _DAT_0059eac8;
      }
      FUN_00565aa0(s_BrakeFadeRange_005d5214,param_1 + 0xc0,0,0,0);
      FUN_00565aa0(s_BrakeDiscInertia_005d5200,param_1 + 0xe8,0,0,0);
      FUN_00565aa0(s_BrakeHeating_005d51f0,param_1 + 200,0,0,0);
      FUN_00565aa0(s_BrakeCooling_005d51e0,param_1 + 0xd0,param_1 + 0xd8,0,0);
      FUN_00565aa0(s_BrakeDuctCooling_005d51cc,param_1 + 0xe0,0,0,0);
      FUN_00565aa0(s_SpinInertia_005d51c0,param_1 + 0x90,0,0,0);
      FUN_00565aa0(s_CGOffsetX_005d51b4,param_1 + 0x40,0,0,0);
      FUN_00565aa0(s_PushrodSpindle_005d51a4,param_1 + 0x48,param_1 + 0x50,param_1 + 0x58,0);
      FUN_00565aa0(s_PushrodBody_005d5198,param_1 + 0x60,param_1 + 0x68,param_1 + 0x70,0);
      FUN_0042e1f0(param_4,s_CamberRange_005d517c,s_CamberSetting_005d5188,0xa2529d39,0x3f91df46);
      FUN_0042e1f0(param_4,s_PressureRange_005d515c,s_PressureSetting_005d516c,0,0x3ff00000);
      FUN_0042e1f0(param_4,s_RideHeightRange_005d5138,s_RideHeightSetting_005d5148,0,0x3ff00000);
      FUN_0042e1f0(param_4,s_PackerRange_005d511c,s_PackerSetting_005d5128,0,0x3ff00000);
      FUN_0042e1f0(param_4,s_SpringRange_005d5100,s_SpringSetting_005d510c,0,0x3ff00000);
      FUN_0042e1f0(param_4,s_SlowBumpRange_005d50e0,s_SlowBumpSetting_005d50f0,0,0x3ff00000);
      FUN_0042e1f0(param_4,s_FastBumpRange_005d50c0,s_FastBumpSetting_005d50d0,0,0x3ff00000);
      FUN_0042e1f0(param_4,s_SlowReboundRange_005d5098,s_SlowReboundSetting_005d50ac,0,0x3ff00000);
      FUN_0042e1f0(param_4,s_FastReboundRange_005d5070,s_FastReboundSetting_005d5084,0,0x3ff00000);
      FUN_0042e1f0(param_4,s_BrakeDiscRange_005d504c,s_BrakeDiscSetting_005d505c,0,0x3ff00000);
      FUN_0042e1f0(param_4,s_BrakePadRange_005d502c,s_BrakePadSetting_005d503c,0,0x3ff00000);
    }
    iVar2 = FUN_005351d0(0x180);
  }
  return;
}


