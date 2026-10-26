// Function: FUN_004d24d0 @ 004d24d0
// Strings:  [F1 Challenge 99-02, raceresults.txt, %d_%0.2d_%0.2d_%0.2d_%0.2d_%0.2d.txt, %d/%0.2d/%0.2d %0.2d:%0.2d:%0.2d, Results\]


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d24d0(void)

{
  int iVar1;
  float fVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  uint _Count;
  char *pcVar10;
  int iVar11;
  float10 fVar12;
  double dVar13;
  undefined1 local_4c0 [28];
  float local_4a4;
  char *local_4a0;
  undefined4 local_49c;
  undefined1 local_498 [4];
  undefined4 local_494;
  float local_490;
  float local_48c;
  undefined1 local_488;
  undefined4 local_487;
  undefined1 local_448 [64];
  char local_408 [1028];
  
  local_4a0 = operator_new(0x100);
  *local_4a0 = '\0';
  local_49c = 0x100;
  FUN_00566650();
  FUN_005665b0();
  pcVar8 = local_4a0;
  if (local_4a0 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  uVar6 = 0xffffffff;
  _Count = 0;
  pcVar10 = pcVar8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar3 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar3 != '\0');
  if (0 < (int)(~uVar6 - 1)) {
    do {
      if (0x3ff < _Count) break;
      if ((local_408 + _Count)[(int)pcVar8 - (int)local_408] == '\\') {
        _strncpy(local_408,pcVar8,_Count);
        local_408[_Count] = '\0';
        FUN_00589671();
      }
      _Count = _Count + 1;
    } while ((int)_Count < (int)(~uVar6 - 1));
  }
  FUN_00589671();
  local_488 = DAT_005ea438;
  puVar4 = &local_487;
  for (iVar7 = 0xf; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  FUN_005896ee(CONCAT44(pcVar8,local_498));
  puVar4 = (undefined4 *)FUN_00589e6c(local_498);
  FUN_0058815f(&local_488,s__d__0_2d__0_2d__0_2d__0_2d__0_2d_005d4164,puVar4[5] + 0x76c,
               puVar4[4] + 1,puVar4[3],puVar4[2],puVar4[1],*puVar4);
  if (DAT_007d0b28 == '\0') {
    if (DAT_007c56a4 != 7) goto LAB_004d2da2;
  }
  else {
    FUN_0058815f(local_448,s__d__0_2d__0_2d__0_2d__0_2d__0_2d_005d413c,puVar4[5] + 0x76c,
                 puVar4[4] + 1,puVar4[3],puVar4[2],puVar4[1],*puVar4);
  }
  FUN_005665b0();
  FUN_005668b0();
  cVar3 = FUN_00566940();
  if (cVar3 == '\x01') {
    FUN_00566c30(local_4c0,s__Header__005d4120);
    FUN_00566c30(local_4c0,s_Game__s_005d4114,s_F1_Challenge_99_02_005c6620);
    FUN_00566c30(local_4c0,s_Version___3f_005d4104,0,0x3ff06a7f);
    FUN_00566c30(local_4c0,s_TimeString__s_005d40f4,&local_488);
    FUN_00566c30(local_4c0,&DAT_005c30b4);
    FUN_00566c30(local_4c0,s__Race__005d40ec);
    FUN_00566c30(local_4c0,s_RaceMode__d_005d40dc,DAT_007d0410);
    puVar5 = DAT_007ce5d0;
    if (DAT_007ce5d0 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    FUN_00566c30(local_4c0,s_Scene__s_005d40d0,puVar5);
    puVar5 = DAT_007ce608;
    if (DAT_007ce608 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    FUN_00566c30(local_4c0,s_AIDB__s_005d40c4,puVar5);
    FUN_00566c30(local_4c0,s_Qualify_Laps__d_005d40b0,DAT_007d04a4);
    FUN_00566c30(local_4c0,s_Race_Laps__d_005d40a0,DAT_007d05a0);
    fVar2 = (_DAT_008acf94 - _DAT_008acf90) * _DAT_0059e9c0;
    local_4a4 = (float)(int)ROUND(fVar2);
    FUN_00566c30(local_4c0,s_Race_Time__d_005d4090,local_4a4);
    FUN_00566c30();
    dVar13 = (double)DAT_005ea3fc;
    puVar5 = local_4c0;
    pcVar8 = s_Track_Length___4f_005d4068;
    FUN_00566c30();
    FUN_00566c30(local_4c0,&DAT_005c30b4,puVar5,pcVar8,dVar13);
    if (DAT_007d0b28 != '\0') {
      FUN_00566c30(local_4c0,s__Local_Settings__005d4054);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_steering_help__d_005d4038,DAT_007ce6ac);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_steering_help_func__d_005d4014,DAT_007ce6d0);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_throttle_control__d_005d3ff4,DAT_007ce6f4);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_brake_help__d_005d3fd8,DAT_007ce718);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_antilock_brakes__d_005d3fb8,DAT_007ce73c);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_spin_recovery__d_005d3f9c,DAT_007ce760);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_invulnerable__d_005d3f80,DAT_007ce784);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_autopit__d_005d3f68,DAT_007ce7a8);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_opposite_lock__d_005d3f4c,DAT_007ce7cc);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_stability_control__d_005d3f2c,DAT_007ce7f0);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_no_ai_control__d_005d3f10,DAT_007ce814);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_allow_pitcrew_push__d_005d3eec,DAT_007ce838);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_auto_clutch__d_005d3ed0,DAT_007ce850);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_auto_lift__d_005d3eb8,DAT_007ce874);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_auto_blip__d_005d3ea0,DAT_007ce88c);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_shift_mode__d_005d3e84,DAT_007ce8a4);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_auto_reverse__d_005d3e68,DAT_007ce910);
      dVar13 = (double)_DAT_007ce934;
      puVar5 = local_4c0;
      pcVar8 = s_DRIVEAIDS_speed_sens_steering____005d3e44;
      FUN_00566c30();
      FUN_00566c30(local_4c0,s_DRIVEAIDS_half_rate__d_005d3e2c,DAT_007ce958,puVar5,pcVar8,dVar13);
      FUN_00566c30(local_4c0,s_DRIVEAIDS_extra_tire_sampling__d_005d3e08,DAT_007ce994);
      FUN_00566c30(local_4c0,s_MECHFAIL_rate__d_005d2ce0,DAT_007cea5c);
      FUN_00566c30(local_4c0,s_GAMEOPT_damagemultiplier__d_005d3de8,DAT_007d0014);
      FUN_00566c30(local_4c0,s_Fuel_Mult__d_005d3dd8,DAT_007d0b64);
      FUN_00566c30(local_4c0,s_Tire_Mult__d_005d3dc8,DAT_007d0c60);
      FUN_00566c30(local_4c0,s_Vehicles_Allowed__s_005d3db0,DAT_007d0d5c,DAT_007d0d60);
      FUN_00566c30(local_4c0,s_Multi_Data_Rate__d_005d3d9c,DAT_007d0e98);
      FUN_00566c30(local_4c0,&DAT_005c30b4);
      FUN_00566c30(local_4c0,s__Controls__005d3d90);
      iVar7 = 0;
      puVar4 = &DAT_007d1b08;
      do {
        FUN_00566c30(local_4c0,s__d___d__d__005d3d84,iVar7,*puVar4,puVar4[1]);
        puVar4 = puVar4 + 7;
        iVar7 = iVar7 + 1;
      } while ((int)puVar4 < 0x7d1fd8);
      FUN_00566c30(local_4c0,&DAT_005c30b4);
    }
    iVar7 = 0;
    iVar11 = DAT_005c329c;
    if (0 < DAT_005c329c) {
      do {
        iVar9 = 0;
        iVar7 = iVar7 + 1;
        if (0 < iVar11) {
          do {
            iVar1 = (&DAT_007c54f0)[iVar9];
            if (*(int *)(iVar1 + 0x4060) == iVar7) {
              FUN_00566c30(local_4c0,s__Slot_03d__005d3d78,iVar9);
              FUN_00566c30(local_4c0,s_Driver__s_005d3d6c,iVar1 + 0x4620);
              FUN_00566c30(local_4c0,s_Vehicle__s_005d3d60,iVar1 + 0x4678);
              FUN_00566c30(local_4c0,s_QualPlace__d_005d3d50,*(undefined4 *)(iVar1 + 0x4058));
              if (*(float *)(iVar1 + 0x405c) <= DAT_0059e440) {
                FUN_00566c30(local_4c0);
              }
              else {
                FUN_005676c0();
                FUN_00566c30(local_4c0,s_QualTime__d__06_3f_005d3d3c,fVar2,(double)local_4a4);
              }
              FUN_00566c30(local_4c0,s_RacePlace__d_005d3d18,iVar7);
              FUN_00566c30(local_4c0);
              if ((DAT_007d0b28 != '\0') && (0 < *(int *)(iVar1 + 0x403c))) {
                iVar11 = 0;
                do {
                  fVar12 = (float10)FUN_004bc2a0();
                  local_48c = (float)fVar12;
                  if ((float10)DAT_0059e440 < fVar12) {
                    fVar12 = (float10)FUN_004bc270();
                    local_490 = (float)fVar12;
                    FUN_005676c0();
                    FUN_00566c30(local_4c0,s_Lap___d____3f___d__06_3f__005d3cec,iVar11,
                                 (double)local_490,fVar2,(double)local_4a4);
                  }
                  iVar11 = iVar11 + 1;
                } while (iVar11 < *(int *)(iVar1 + 0x403c));
              }
              if (*(float *)(iVar1 + 0x409c) <= DAT_0059e440) {
                FUN_00566c30(local_4c0);
              }
              else {
                FUN_005676c0();
                FUN_00566c30(local_4c0,s_RaceBestLap__d__06_3f_005d3cd4,fVar2,(double)local_4a4);
              }
              switch(*(undefined4 *)(iVar1 + 0x4064)) {
              case 0:
              case 2:
                FUN_00566c30(local_4c0);
                FUN_00566c30(local_4c0,s_Reason__d_005d3c84,*(undefined4 *)(iVar1 + 0x4068));
                break;
              case 1:
                FUN_00567700(*(undefined4 *)(iVar1 + 0x40b8),&local_4a4);
                FUN_00566c30(local_4c0,s_RaceTime__d__02d__06_3f_005d3ca0,local_494,fVar2,
                             (double)local_4a4);
                break;
              case 3:
                FUN_00566c30(local_4c0);
              }
              if (DAT_0059e440 < *(float *)(iVar1 + 0x40d8)) {
                FUN_00566c30();
              }
              FUN_00566c30();
              iVar11 = DAT_005c329c;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar11);
        }
      } while (iVar7 < iVar11);
    }
    FUN_00566b90();
  }
  FUN_005668d0();
LAB_004d2da2:
  if (local_4a0 != (char *)0x0) {
    FUN_00587bcf();
  }
  return;
}


