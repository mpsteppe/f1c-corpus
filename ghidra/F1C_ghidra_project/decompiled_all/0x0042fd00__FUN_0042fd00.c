// Function: FUN_0042fd00 @ 0042fd00
// Strings:  [Failed to open %s for writing, D:\dev\F1_1999_2002\Source\garage.cpp]


undefined4 __thiscall FUN_0042fd00(char *param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined8 uVar7;
  undefined1 local_a0 [28];
  char local_84 [128];
  undefined1 local_4;
  
  if ((param_3 == '\0') && (*param_1 == '\0')) {
    return 0;
  }
  FUN_005668b0();
  cVar1 = FUN_00566940(param_2,0,0,1);
  if (cVar1 != '\x01') {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_garag_005c3efc,0x564);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Failed_to_open__s_for_writing_005c3edc,param_2);
    }
    FUN_005668d0();
    return 0xffffffff;
  }
  FUN_00566c30();
  iVar5 = 0;
  do {
    puVar2 = *(undefined1 **)(param_1 + 0x68);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    _strncpy(local_84,puVar2 + iVar5,0x80);
    local_4 = 0;
    FUN_00566c30(local_a0,s_Notes___s__005c3ec4,local_84);
    uVar4 = 0xffffffff;
    pcVar6 = local_84;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (~uVar4 - 1 < 0x80) break;
    iVar5 = iVar5 + 0x80;
  } while( true );
  FUN_00566c30(local_a0,s_Symmetric__d_005c3eb4,param_1[0x19a5]);
  FUN_00566c30(local_a0,s_CGRightSetting__d_005c3ea0,*(undefined4 *)(param_1 + 0xc04));
  FUN_00566c30(local_a0,s_CGRearSetting__d_005c3e8c,*(undefined4 *)(param_1 + 0xc44));
  FUN_00566c30(local_a0,s_WedgeSetting__d_005c3e78,*(undefined4 *)(param_1 + 0xc84));
  FUN_00566c30(local_a0,s_TireCompoundSetting__d_005c3e60,*(undefined4 *)(param_1 + 0xbc4));
  FUN_00566c30(local_a0,s_FuelSetting__d_005c3e50,*(undefined4 *)(param_1 + 0xcc4));
  FUN_00566c30(local_a0,s_NumPitstopsSetting__d_005c3e38,*(undefined4 *)(param_1 + 0x1884));
  FUN_00566c30(local_a0,s_Pitstop1Setting__d_005c3e24,*(undefined4 *)(param_1 + 0x18c4));
  FUN_00566c30(local_a0,s_Pitstop2Setting__d_005c3e10,*(undefined4 *)(param_1 + 0x1904));
  FUN_00566c30(local_a0,s_Pitstop3Setting__d_005c3dfc,*(undefined4 *)(param_1 + 0x1944));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  FUN_00566c30(local_a0,s__LEFTFENDER__005c3dec);
  FUN_00566c30(local_a0,s_FenderFlareSetting__d_005c3dd4,*(undefined4 *)(param_1 + 0xe04));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  FUN_00566c30(local_a0,s__RIGHTFENDER__005c3dc4);
  FUN_00566c30(local_a0,s_FenderFlareSetting__d_005c3dd4,*(undefined4 *)(param_1 + 0xe44));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  FUN_00566c30(local_a0,s__FRONTWING__005c3db4);
  FUN_00566c30(local_a0,s_FWSetting__d_005c3da4,*(undefined4 *)(param_1 + 0x1284));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  FUN_00566c30(local_a0,s__REARWING__005c3d98);
  FUN_00566c30(local_a0,s_RWSetting__d_005c3d88,*(undefined4 *)(param_1 + 0x12c4));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  FUN_00566c30(local_a0,s__BODYAERO__005c3d7c);
  FUN_00566c30(local_a0,s_RadiatorSetting__d_005c3d68,*(undefined4 *)(param_1 + 0x1304));
  FUN_00566c30(local_a0,s_BrakeDuctSetting__d_005c3d50,*(undefined4 *)(param_1 + 0x1344));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  FUN_00566c30(local_a0,s__SUSPENSION__005c3d40);
  FUN_00566c30(local_a0,s_FrontAntiSwaySetting__d_005c3d24,*(undefined4 *)(param_1 + 0xd04));
  FUN_00566c30(local_a0,s_RearAntiSwaySetting__d_005c3d0c,*(undefined4 *)(param_1 + 0xd44));
  FUN_00566c30(local_a0,s_FrontToeInSetting__d_005c3cf4,*(undefined4 *)(param_1 + 0xd84));
  FUN_00566c30(local_a0,s_RearToeInSetting__d_005c3cdc,*(undefined4 *)(param_1 + 0xdc4));
  FUN_00566c30(local_a0,s_LeftCasterSetting__d_005c3cc4,*(undefined4 *)(param_1 + 0xe84));
  FUN_00566c30(local_a0,s_RightCasterSetting__d_005c3cac,*(undefined4 *)(param_1 + 0xec4));
  FUN_00566c30(local_a0,s_LeftTrackBarSetting__d_005c3c94,*(undefined4 *)(param_1 + 0xf04));
  FUN_00566c30(local_a0,s_RightTrackBarSetting__d_005c3c78,*(undefined4 *)(param_1 + 0xf44));
  FUN_00566c30(local_a0,s_Front3rdPackerSetting__d_005c3c5c,*(undefined4 *)(param_1 + 0xf84));
  FUN_00566c30(local_a0,s_Front3rdSpringSetting__d_005c3c40,*(undefined4 *)(param_1 + 0xfc4));
  FUN_00566c30(local_a0,s_Front3rdSlowBumpSetting__d_005c3c24,*(undefined4 *)(param_1 + 0x1004));
  FUN_00566c30(local_a0,s_Front3rdFastBumpSetting__d_005c3c08,*(undefined4 *)(param_1 + 0x1044));
  FUN_00566c30(local_a0,s_Front3rdSlowReboundSetting__d_005c3be8,*(undefined4 *)(param_1 + 0x1084));
  FUN_00566c30(local_a0,s_Front3rdFastReboundSetting__d_005c3bc8,*(undefined4 *)(param_1 + 0x10c4));
  FUN_00566c30(local_a0,s_Rear3rdPackerSetting__d_005c3bac,*(undefined4 *)(param_1 + 0x1104));
  FUN_00566c30(local_a0,s_Rear3rdSpringSetting__d_005c3b90,*(undefined4 *)(param_1 + 0x1144));
  FUN_00566c30(local_a0,s_Rear3rdSlowBumpSetting__d_005c3b74,*(undefined4 *)(param_1 + 0x1184));
  FUN_00566c30(local_a0,s_Rear3rdFastBumpSetting__d_005c3b58,*(undefined4 *)(param_1 + 0x11c4));
  FUN_00566c30(local_a0,s_Rear3rdSlowReboundSetting__d_005c3b38,*(undefined4 *)(param_1 + 0x1204));
  FUN_00566c30(local_a0,s_Rear3rdFastReboundSetting__d_005c3b18,*(undefined4 *)(param_1 + 0x1244));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  FUN_00566c30(local_a0,s__CONTROLS__005c3b0c);
  FUN_00566c30(local_a0,s_SteerLockSetting__d_005c3af4,*(undefined4 *)(param_1 + 0x1444));
  FUN_00566c30(local_a0,s_RearBrakeSetting__d_005c3adc,*(undefined4 *)(param_1 + 0x1384));
  FUN_00566c30(local_a0,s_BrakePressureSetting__d_005c3ac0,*(undefined4 *)(param_1 + 0x13c4));
  FUN_00566c30(local_a0,s_HandbrakePressSetting__d_005c3aa4,*(undefined4 *)(param_1 + 0x1404));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  FUN_00566c30(local_a0,s__ENGINE__005c3a98);
  FUN_00566c30(local_a0,s_RevLimitSetting__d_005c3a84,*(undefined4 *)(param_1 + 0x1584));
  FUN_00566c30(local_a0,s_EngineMapSetting__d_005c3a6c,*(undefined4 *)(param_1 + 0x15c4));
  FUN_00566c30(local_a0,s_EngineBrakeMapSetting__d_005c3a50,*(undefined4 *)(param_1 + 0x1604));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  piVar3 = (int *)(param_1 + 0x1704);
  iVar5 = 6;
  do {
    if (*piVar3 < piVar3[-0x10]) {
      *piVar3 = piVar3[-0x10];
    }
    piVar3 = piVar3 + 0x10;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_00566c30(local_a0,s__DRIVELINE__005c3a40);
  FUN_00566c30(local_a0,s_FinalDriveSetting__d_005c3a28,*(undefined4 *)(param_1 + 0x1644));
  FUN_00566c30(local_a0,s_ReverseSetting__d_005c3a14,*(undefined4 *)(param_1 + 0x1684));
  iVar5 = 0x2c;
  pcVar6 = param_1 + 0x16c4;
  do {
    if (pcVar6[8] != '\0') {
      FUN_00566c30(local_a0,s_Gear_dSetting__d_005c3a00,iVar5 + -0x2b,*(undefined4 *)pcVar6);
    }
    iVar5 = iVar5 + 1;
    pcVar6 = pcVar6 + 0x40;
  } while (iVar5 < 0x33);
  FUN_00566c30(local_a0,s_DiffPumpSetting__d_005c39ec,*(undefined4 *)(param_1 + 0x1484));
  FUN_00566c30(local_a0,s_DiffPowerSetting__d_005c39d4,*(undefined4 *)(param_1 + 0x14c4));
  FUN_00566c30(local_a0,s_DiffCoastSetting__d_005c39bc,*(undefined4 *)(param_1 + 0x1504));
  FUN_00566c30(local_a0,s_DiffPreloadSetting__d_005c39a4,*(undefined4 *)(param_1 + 0x1544));
  FUN_00566c30(local_a0,&DAT_005c30b4);
  iVar5 = 0;
  do {
    switch(iVar5) {
    case 0:
      pcVar6 = s__FRONTLEFT__005c3994;
      goto LAB_004303f5;
    case 1:
      uVar7 = CONCAT44(s__FRONTRIGHT__005c3984,local_a0);
      break;
    case 2:
      uVar7 = CONCAT44(s__REARLEFT__005c3978,local_a0);
      break;
    case 3:
      pcVar6 = s__REARRIGHT__005c3968;
LAB_004303f5:
      uVar7 = CONCAT44(pcVar6,local_a0);
      break;
    default:
      goto switchD_004303ca_default;
    }
    FUN_00566c30(uVar7);
switchD_004303ca_default:
    FUN_00566c30(local_a0,s_CamberSetting__d_005c3954);
    FUN_00566c30(local_a0,s_PressureSetting__d_005c3940,
                 *(undefined4 *)(param_1 + iVar5 * 0x2c0 + 0x104));
    FUN_00566c30(local_a0,s_PackerSetting__d_005c392c,
                 *(undefined4 *)(param_1 + iVar5 * 0x2c0 + 0x184));
    FUN_00566c30(local_a0,s_SpringSetting__d_005c3918,
                 *(undefined4 *)(param_1 + iVar5 * 0x2c0 + 0x1c4));
    FUN_00566c30(local_a0,s_RideHeightSetting__d_005c3900,
                 *(undefined4 *)(param_1 + iVar5 * 0x2c0 + 0x144));
    FUN_00566c30(local_a0,s_SlowBumpSetting__d_005c38ec,
                 *(undefined4 *)(param_1 + iVar5 * 0x2c0 + 0x204));
    FUN_00566c30(local_a0,s_FastBumpSetting__d_005c38d8);
    FUN_00566c30(local_a0,s_SlowReboundSetting__d_005c38c0,
                 *(undefined4 *)(param_1 + iVar5 * 0x2c0 + 0x284));
    FUN_00566c30(local_a0,s_FastReboundSetting__d_005c38a8,
                 *(undefined4 *)(param_1 + iVar5 * 0x2c0 + 0x2c4));
    FUN_00566c30(local_a0,s_BrakeDiscSetting__d_005c3890,
                 *(undefined4 *)(param_1 + iVar5 * 0x2c0 + 0x304));
    FUN_00566c30(local_a0,s_BrakePadSetting__d_005c387c,
                 *(undefined4 *)(param_1 + iVar5 * 0x2c0 + 0x344));
    FUN_00566c30(local_a0,&DAT_005c30b4);
    iVar5 = iVar5 + 1;
    if (3 < iVar5) {
      FUN_00566c30(local_a0,s__BASIC__005c3870);
      FUN_00566c30(local_a0,s_Downforce__f_005c3860,(double)*(float *)(param_1 + 0x1ca8));
      FUN_00566c30(local_a0,s_Balance__f_005c3854,(double)*(float *)(param_1 + 0x1cac));
      FUN_00566c30(local_a0,s_Ride__f_005c3848,(double)*(float *)(param_1 + 0x1cb0));
      FUN_00566c30(local_a0,s_Gearing__f_005c383c,(double)*(float *)(param_1 + 0x1cb4));
      FUN_00566c30(local_a0,s_Custom__d_005c3830,param_1[0x19a4]);
      FUN_00566c30(local_a0,&DAT_005c30b4);
      FUN_00566b90();
      *param_1 = '\0';
      FUN_005668d0();
      return 0;
    }
  } while( true );
}


