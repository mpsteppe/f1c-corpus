// Function: FUN_004f24f0 @ 004f24f0
// Strings:  [Engine, Part%dCollParams, Part%dMassInertia, Part%dPos, Part%dRandom, Part%dDetach, Wheel%dCollParams, Wheel%dMassInertia]


undefined4 __thiscall FUN_004f24f0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_3b8;
  undefined1 local_398 [64];
  undefined1 local_358 [448];
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [96];
  
  FUN_005668b0();
  puVar5 = local_180;
  for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_198 = 0;
  local_184 = 0;
  local_18c = 0;
  local_188 = 0;
  local_194 = 1;
  cVar1 = FUN_00566b20(param_2,0);
  if (cVar1 != '\0') {
    iVar2 = FUN_00566cc0(local_180,0x180);
    while (iVar2 != 0) {
      iVar2 = FUN_005651b0();
      if ((iVar2 == 0) && (iVar2 = FUN_00587c20(local_180,s__PHYSICAL__005d5020), iVar2 != 0)) {
        iVar2 = FUN_00566cc0(local_180,0x180);
        while ((iVar2 != 0 && (iVar2 = FUN_005651b0(), iVar2 != 1))) {
          if (iVar2 == 0) {
            FUN_00565870(s_RadiusAdd_005d5014,param_1,0,0,0,0,0,0,0);
            FUN_00565870(s_RadiusMult_005d5008,param_1 + 4,0,0,0,0,0,0,0);
            FUN_00565870(s_RadiusMax_005d4ffc,param_1 + 8,0,0,0,0,0,0,0);
            FUN_00565870(s_Engine_005c316c,param_1 + 0xc,0,0,0,0,0,0,0);
            FUN_00565870(s_AeroDiv_005d4ff4,param_1 + 0x10,0,0,0,0,0,0,0);
            FUN_00565870(s_AeroMin_005d4fec,param_1 + 0x14,0,0,0,0,0,0,0);
            FUN_00565870(s_VertMult_005d4fe0,param_1 + 0x18,0,0,0,0,0,0,0);
            FUN_00565870(s_FrontWingDetach_005d4fd0,param_1 + 0x1c,0,0,0,0,0,0,0);
            FUN_00565870(s_FrontWingRandom_005d4fc0,param_1 + 0x20,0,0,0,0,0,0,0);
            FUN_00565870(s_FrontWingPos_005d4fb0,param_1 + 0x24,param_1 + 0x28,param_1 + 0x2c,0,0,0,
                         0,0);
            FUN_00565870(s_FrontWingMassInertia_005d4f98,param_1 + 0x30,param_1 + 0x34,
                         param_1 + 0x38,param_1 + 0x3c,0,0,0,0);
            FUN_00565870(s_FrontWingCollParams_005d4f84,param_1 + 0x40,param_1 + 0x44,param_1 + 0x48
                         ,0,0,0,0,0);
            FUN_00565870(s_RearWingDetach_005d4f74,param_1 + 0x4c,0,0,0,0,0,0,0);
            FUN_00565870(s_RearWingRandom_005d4f64,param_1 + 0x50,0,0,0,0,0,0,0);
            FUN_00565870(s_RearWingPos_005d4f58,param_1 + 0x54,param_1 + 0x58,param_1 + 0x5c,0,0,0,0
                         ,0);
            FUN_00565870(s_RearWingMassInertia_005d4f44,param_1 + 0x60,param_1 + 100,param_1 + 0x68,
                         param_1 + 0x6c,0,0,0,0);
            FUN_00565870(s_RearWingCollParams_005d4f30,param_1 + 0x70,param_1 + 0x74,param_1 + 0x78,
                         0,0,0,0,0);
            FUN_00565870(s_WheelBend_005d4f24,param_1 + 0x7c,0,0,0,0,0,0,0);
            FUN_00565870(s_WheelDetach_005d4f18,param_1 + 0x80,0,0,0,0,0,0,0);
            FUN_00565870(s_WheelRandom_005d4f0c,param_1 + 0x84,0,0,0,0,0,0,0);
            iVar3 = 0;
            iVar2 = param_1 + 0x90;
            do {
              FUN_0058815f(local_358,s_Wheel_dMassInertia_005d4ef8,iVar3);
              FUN_00565870(local_358,iVar2 + -8,iVar2 + -4,iVar2,iVar2 + 4,0,0,0,0);
              FUN_0058815f(local_358,s_Wheel_dCollParams_005d4ee4,iVar3);
              FUN_00565870(local_358,iVar2 + 8,iVar2 + 0xc,iVar2 + 0x10,0,0,0,0,0);
              iVar3 = iVar3 + 1;
              iVar2 = iVar2 + 0x1c;
            } while (iVar3 < 4);
            local_3b8 = param_1 + 0x118;
            iVar4 = 0;
            iVar2 = param_1 + 0x1a0;
            iVar3 = param_1 + 0x13c;
            do {
              FUN_0058815f(local_398,s_Part_dDetach_005d4ed4,iVar4);
              FUN_00565870(local_398,local_3b8 + -0x20,0,0,0,0,0,0,0);
              FUN_0058815f(local_398,s_Part_dRandom_005d4ec4,iVar4);
              FUN_00565870(local_398,local_3b8,0,0,0,0,0,0,0);
              FUN_0058815f(local_398,s_Part_dPos_005d4eb8,iVar4);
              FUN_00565870(local_398,iVar3 + -4,iVar3,iVar3 + 4,0,0,0,0,0);
              FUN_0058815f(local_398,s_Part_dMassInertia_005d4ea4,iVar4);
              FUN_00565870(local_398,iVar2 + -8,iVar2 + -4,iVar2,iVar2 + 4,0,0,0,0);
              FUN_0058815f(local_398,s_Part_dCollParams_005d4e90,iVar4);
              FUN_00565870(local_398,iVar2 + 8,iVar2 + 0xc,iVar2 + 0x10,0,0,0,0,0);
              iVar4 = iVar4 + 1;
              local_3b8 = local_3b8 + 4;
              iVar3 = iVar3 + 0xc;
              iVar2 = iVar2 + 0x1c;
            } while (iVar4 < 8);
          }
          iVar2 = FUN_00566cc0(local_180,0x180);
        }
      }
      iVar2 = FUN_00566cc0(local_180,0x180);
    }
    FUN_00566b90();
    FUN_005668d0();
    return 0;
  }
  FUN_005668d0();
  return 0xffffffff;
}


