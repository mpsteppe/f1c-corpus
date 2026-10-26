// Function: FUN_004f3c80
// Address:  004f3c80
// Trigger:  "LifetimeVar"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004f3c80(int param_1,undefined4 param_2,undefined4 param_3)

{
  double *pdVar1;
  double *pdVar2;
  double dVar3;
  double dVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_348;
  double *local_344;
  undefined1 local_320 [384];
  undefined4 local_1a0;
  undefined1 local_19c;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188 [97];
  
  FUN_005668b0();
  puVar7 = local_188;
  for (iVar6 = 0x60; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_1a0 = 0;
  local_18c = 0;
  local_194 = 0;
  local_190 = 0;
  local_19c = 1;
  cVar5 = FUN_00566b20(param_2,0);
  if (cVar5 == '\0') {
    FUN_005668d0();
    return 0xffffffff;
  }
  local_348 = 0;
  iVar6 = FUN_00566cc0(local_188,0x180);
  if (iVar6 != 0) {
    local_344 = (double *)(param_1 + 0x6c8);
    do {
      iVar6 = FUN_005651b0();
      if (iVar6 == 1) break;
      if (iVar6 == 0) {
        FUN_00565aa0(s_FuelConsumption_005d572c,param_1 + 0x674,0,0,0);
        FUN_00565aa0(s_FuelEstimate_005d571c,param_1 + 0x67c,0,0,0);
        FUN_00565aa0(s_EngineInertia_005d570c,param_1 + 0x684,0,0,0);
        pdVar1 = (double *)(param_1 + 0x69c);
        iVar6 = FUN_00565aa0(s_IdleThrottle_005d56fc,pdVar1,0,0,0);
        if (iVar6 != 0) {
          if (_DAT_0059e430 <= *pdVar1) {
            if (*pdVar1 <= _DAT_0059e420) goto LAB_004f3dcd;
            *(undefined4 *)(param_1 + 0x6a0) = 0x3ff00000;
          }
          else {
            *(undefined4 *)(param_1 + 0x6a0) = 0;
          }
          *(undefined4 *)pdVar1 = 0;
        }
LAB_004f3dcd:
        pdVar1 = (double *)(param_1 + 0x694);
        pdVar2 = (double *)(param_1 + 0x68c);
        iVar6 = FUN_00565aa0(s_IdleRPMLogic_005d56ec,pdVar2,pdVar1,0,0);
        if (iVar6 != 0) {
          dVar3 = *pdVar2 * _DAT_005ad258;
          *pdVar2 = dVar3;
          dVar4 = *pdVar1 * _DAT_005ad258;
          *pdVar1 = dVar4;
          if ((dVar4 < dVar3 != (dVar4 == dVar3)) && (DAT_007c569c != 5)) {
            cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,599);
            if (cVar5 != '\0') {
              FUN_004d7aa0(&DAT_008ad25c);
            }
          }
        }
        FUN_00565aa0(s_LaunchEfficiency_005d56c0,param_1 + 0x6a4,0,0,0);
        pdVar1 = (double *)(param_1 + 0x6b4);
        pdVar2 = (double *)(param_1 + 0x6ac);
        iVar6 = FUN_00565aa0(s_LaunchRPMLogic_005d56b0,pdVar2,pdVar1,0,0);
        if (iVar6 != 0) {
          dVar3 = *pdVar2 * _DAT_005ad258;
          *pdVar2 = dVar3;
          dVar4 = *pdVar1 * _DAT_005ad258;
          *pdVar1 = dVar4;
          if ((dVar4 < dVar3 != (dVar4 == dVar3)) && (DAT_007c569c != 5)) {
            cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x263);
            if (cVar5 != '\0') {
              FUN_004d7aa0(&DAT_008ad25c);
            }
          }
        }
        pdVar1 = (double *)(param_1 + 0x6bc);
        iVar6 = FUN_00565aa0(s_RevLimitLogic_005d5688,pdVar1,0,0,0);
        if (iVar6 != 0) {
          *pdVar1 = *pdVar1 * _DAT_005ad258;
        }
        iVar6 = FUN_00565aa0(s_RPMTorque_005d567c,local_344,local_344 + 1,local_344 + 2,0);
        if (iVar6 != 0) {
          *local_344 = *local_344 * _DAT_005ad258;
          if ((0x7e < local_348) && (DAT_007c569c != 5)) {
            cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x272);
            if (cVar5 != '\0') {
              FUN_004d7aa0(&DAT_008ad25c,s_Too_many_RPM_torque_points____f_005d565c,
                           *local_344 * _DAT_0059ea38);
            }
          }
          if ((local_344[2] < local_344[1]) && (DAT_007c569c != 5)) {
            cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x278);
            if (cVar5 != '\0') {
              FUN_004d7aa0(&DAT_008ad25c,s_RPM_torque_brake_>_throttle____f_005d5638,
                           *local_344 * _DAT_0059ea38);
            }
          }
          if (((0 < local_348) && (*local_344 < local_344[-3] != (*local_344 == local_344[-3]))) &&
             (DAT_007c569c != 5)) {
            cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x27e);
            if (cVar5 != '\0') {
              FUN_004d7aa0(&DAT_008ad25c,s_RPM_torque_curve_out_of_order_____005d5614,
                           *local_344 * _DAT_0059ea38);
            }
          }
          local_348 = local_348 + 1;
          local_344 = local_344 + 3;
        }
        pdVar1 = (double *)(param_1 + 0x1318);
        pdVar2 = (double *)(param_1 + 0x1310);
        iVar6 = FUN_00565aa0(s_LifetimeEngineRPM_005d5600,pdVar2,pdVar1,0,0);
        if (iVar6 != 0) {
          *pdVar2 = *pdVar2 * _DAT_005ad258;
          *pdVar1 = *pdVar1 * _DAT_005ad258;
        }
        pdVar1 = (double *)(param_1 + 0x1320);
        iVar6 = FUN_00565aa0(s_LifetimeOilTemp_005d55f0,pdVar1,param_1 + 0x1328,0,0);
        if (iVar6 != 0) {
          *pdVar1 = *pdVar1 + _DAT_0059eac8;
        }
        FUN_00565aa0(s_LifetimeAvg_005d55e4,param_1 + 0x1330,0,0,0);
        FUN_00565aa0(s_LifetimeVar_005d55d8,param_1 + 0x1338,0,0,0);
        FUN_00565aa0(s_EngineEmission_005d55c8,param_1 + 0x1340,param_1 + 0x1348,param_1 + 0x1350,0)
        ;
        FUN_005655f0(s_OnboardStarter_005d55b8,param_1 + 0x1358,0,0,0);
        FUN_00565aa0(s_StarterTiming_005d55a8,param_1 + 0x135c,param_1 + 0x1364,param_1 + 0x136c,0);
        pdVar1 = (double *)(param_1 + 0x12c8);
        iVar6 = FUN_00565aa0(s_OptimumOilTemp_005d5598,pdVar1,0,0,0);
        if (iVar6 != 0) {
          *pdVar1 = *pdVar1 + _DAT_0059eac8;
        }
        FUN_00565aa0(s_CombustionHeat_005d5588,param_1 + 0x12d0,0,0,0);
        FUN_00565aa0(s_EngineSpeedHeat_005d5578,param_1 + 0x12d8,0,0,0);
        FUN_00565aa0(s_OilMinimumCooling_005d5564,param_1 + 0x12e0,0,0,0);
        FUN_00565aa0(s_OilWaterHeatTransfer_005d554c,param_1 + 0x12e8,param_1 + 0x12f0,0,0);
        FUN_00565aa0(s_WaterMinimumCooling_005d5538,param_1 + 0x12f8,0,0,0);
        FUN_00565aa0(s_RadiatorCooling_005d5528,param_1 + 0x1300,param_1 + 0x1308,0,0);
        FUN_004f3c10(local_320,param_3);
      }
      iVar6 = FUN_00566cc0(local_188,0x180);
    } while (iVar6 != 0);
    if (0 < local_348) {
      *(int *)(param_1 + 0x6c4) = local_348;
    }
  }
  FUN_00566b90();
  FUN_005668d0();
  return 0;
}


