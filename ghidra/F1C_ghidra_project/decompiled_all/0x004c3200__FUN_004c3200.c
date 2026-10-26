// Function: FUN_004c3200 @ 004c3200
// Strings:  [Driver, Engine, Classes, Could not open %s, #%.4s %.50s, Format is: TrackLivery="<trackname>,<liveryname>" in file "%s", TrackLivery, PitcrewLivery]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004c3200(undefined4 *param_1)

{
  char *pcVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  undefined1 *puVar6;
  int iVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 *puVar13;
  undefined1 local_618 [64];
  undefined1 local_5d8 [64];
  undefined1 local_598 [64];
  undefined1 local_558 [448];
  undefined4 local_398;
  undefined1 local_394;
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_384;
  undefined4 local_380 [95];
  char acStack_202 [258];
  char local_100;
  char local_ff [255];
  
  puVar13 = local_380;
  for (iVar10 = 0x60; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
  puVar6 = (undefined1 *)*param_1;
  local_398 = 0;
  local_384 = 0;
  local_38c = 0;
  local_388 = 0;
  local_394 = 1;
  bVar3 = false;
  bVar4 = false;
  local_618[0] = 0;
  local_598[0] = 0;
  local_558[0] = 0;
  local_5d8[0] = 0;
  if (puVar6 == (undefined1 *)0x0) {
    puVar6 = &DAT_005ea438;
  }
  iVar10 = FUN_00587db0(puVar6,&DAT_005c36f0);
  if (iVar10 == 0) {
    cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_setup_005d3044,0x73);
    if (cVar5 != '\0') {
      puVar6 = (undefined1 *)*param_1;
      if (puVar6 == (undefined1 *)0x0) {
        puVar6 = &DAT_005ea438;
      }
      FUN_004d7aa0(&DAT_008ad25c,s_Could_not_open__s_005c6810,puVar6);
    }
    return 0xffffffff;
  }
  iVar7 = FUN_00587ca0(local_380,0x180,iVar10);
  if (iVar7 != 0) {
    do {
      FUN_005651b0();
      FUN_005654a0(s_HDVehicle_005d3038,local_598);
      FUN_005654a0(s_HeadPhysics_005d302c,local_618);
      FUN_005654a0(s_Sounds_005d3024,local_5d8);
      FUN_005654a0(s_Graphics_005d3018,local_558);
      FUN_005654a0(s_GenString_005d300c,param_1 + 10);
      puVar13 = param_1 + 0xe;
      iVar7 = FUN_00565870(s_Eyepoint_005d3000,puVar13,param_1 + 0xf,param_1 + 0x10,0,0,0,0,0);
      if (iVar7 != 0) {
        if (!bVar3) {
          param_1[0x11] = *puVar13;
          param_1[0x12] = param_1[0xf];
          param_1[0x13] = param_1[0x10];
        }
        if (!bVar4) {
          fVar2 = (float)param_1[0xf] - _DAT_005acb28;
          param_1[0x14] = *puVar13;
          param_1[0x15] = fVar2;
          param_1[0x16] = param_1[0x10];
        }
      }
      iVar7 = FUN_00565870(s_CameraTarget_005d2ff0,param_1 + 0x11,param_1 + 0x12,param_1 + 0x13,0,0,
                           0,0,0);
      if (iVar7 != 0) {
        bVar3 = true;
      }
      iVar7 = FUN_00565870(s_MirrorPos_005d2fe4,param_1 + 0x14,param_1 + 0x15,param_1 + 0x16,0,0,0,0
                           ,0);
      if (iVar7 != 0) {
        bVar4 = true;
      }
      FUN_00565870(s_MirrorNorm_005d2fd8,param_1 + 0x17,param_1 + 0x18,param_1 + 0x19,0,0,0,0,0);
      FUN_00565870(s_SteeringWheelAxis_005d2fc4,param_1 + 0x1a,param_1 + 0x1b,param_1 + 0x1c,0,0,0,0
                   ,0);
      FUN_005654a0(s_Number_005d2fbc,param_1 + 0x1d);
      FUN_005654a0(&DAT_005d2fb4,param_1 + 0x1f);
      FUN_005654a0(s_Driver_005bea08,param_1 + 0x2f);
      FUN_005654a0(s_Description_005d2fa8,param_1 + 0x3f);
      FUN_005654a0(s_Engine_005c316c,param_1 + 0x4f);
      FUN_005654a0(s_Manufacturer_005d2f98,param_1 + 0x5f);
      FUN_005654a0(s_Classes_005c401c,param_1 + 0x6f);
      FUN_005654a0(s_FullTeamName_005d2f88,param_1 + 0xaf);
      FUN_005654a0(s_TeamFounded_005d2f7c,param_1 + 0xcf);
      FUN_005654a0(s_TeamHeadquarters_005d2f68,param_1 + 0xd3);
      FUN_005654a0(s_TeamStarts_005d2f5c,param_1 + 0xe3);
      FUN_005654a0(s_TeamPoles_005d2f50,param_1 + 0xe7);
      FUN_005654a0(s_TeamWins_005d2f44,param_1 + 0xeb);
      FUN_005654a0(s_TeamWorldChampionships_005d2f2c,param_1 + 0xef);
      iVar7 = FUN_005654a0(s_DefaultLivery_005d2f1c,&local_100);
      if (iVar7 != 0) {
        FUN_00566650(&local_100);
      }
      iVar7 = FUN_005654a0(s_PitcrewLivery_005d2f0c,&local_100);
      if (iVar7 != 0) {
        FUN_00566650(&local_100);
      }
      iVar7 = FUN_005654a0(s_TrackLivery_005d2f00,&local_100);
      if (iVar7 != 0) {
        pcVar8 = (char *)FUN_00587c20(&local_100,&DAT_005d251c);
        if (pcVar8 == (char *)0x0) {
          cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_setup_005d3044,0xad);
          if (cVar5 != '\0') {
            puVar6 = (undefined1 *)*param_1;
            if (puVar6 == (undefined1 *)0x0) {
              puVar6 = &DAT_005ea438;
            }
            FUN_004d7aa0(&DAT_008ad25c,s_Format_is__TrackLivery__<trackna_005d2ec0,puVar6);
          }
        }
        else {
          puVar9 = operator_new(0x14);
          puVar13 = (undefined4 *)0x0;
          if (puVar9 != (undefined4 *)0x0) {
            *puVar9 = 0;
            puVar9[1] = 0xffffffff;
            puVar9[2] = 0;
            puVar9[3] = 0xffffffff;
            puVar13 = puVar9;
          }
          pcVar12 = &local_100;
          cVar5 = local_100;
          while (pcVar1 = pcVar8, cVar5 == ' ') {
            pcVar1 = pcVar12 + 1;
            pcVar12 = pcVar12 + 1;
            cVar5 = *pcVar1;
          }
          for (; (pcVar12 < pcVar1 && ((*pcVar1 == ' ' || (*pcVar1 == ',')))); pcVar1 = pcVar1 + -1)
          {
          }
          pcVar1[1] = '\0';
          FUN_00566650(pcVar12);
          cVar5 = pcVar8[1];
          while (pcVar12 = pcVar8 + 1, cVar5 == ' ') {
            cVar5 = pcVar8[2];
            pcVar8 = pcVar12;
          }
          uVar11 = 0xffffffff;
          pcVar8 = pcVar12;
          do {
            if (uVar11 == 0) break;
            uVar11 = uVar11 - 1;
            cVar5 = *pcVar8;
            pcVar8 = pcVar8 + 1;
          } while (cVar5 != '\0');
          for (pcVar8 = pcVar12 + (~uVar11 - 1);
              (pcVar12 < pcVar8 && ((*pcVar8 == ' ' || (*pcVar8 == '\0')))); pcVar8 = pcVar8 + -1) {
          }
          pcVar8[1] = '\0';
          FUN_00566650(pcVar12);
          puVar13[4] = param_1[0xf5];
          param_1[0xf5] = puVar13;
        }
      }
      iVar7 = FUN_00587ca0(local_380,0x180,iVar10);
    } while (iVar7 != 0);
  }
  FUN_00587d02(iVar10);
  FUN_004c38d0();
  if (*(char *)(param_1 + 0x3f) == '\0') {
    FUN_0058815f(param_1 + 0x3f,s____4s___50s_005d2eb4,param_1 + 0x1d,param_1 + 0x1f);
  }
  pcVar8 = (char *)*param_1;
  if (pcVar8 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  pcVar12 = acStack_202 + 2;
  do {
    cVar5 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    *pcVar12 = cVar5;
    pcVar12 = pcVar12 + 1;
  } while (cVar5 != '\0');
  uVar11 = 0xffffffff;
  pcVar8 = acStack_202 + 2;
  do {
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    cVar5 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar5 != '\0');
  if ((0 < (int)(~uVar11 - 1)) && (pcVar8 = acStack_202 + ~uVar11, acStack_202 + 2 <= pcVar8)) {
    do {
      if (*pcVar8 == '\\') break;
      *pcVar8 = '\0';
      pcVar8 = pcVar8 + -1;
    } while (acStack_202 + 2 <= pcVar8);
  }
  FUN_004c40d0(local_598,&DAT_005d2eac,acStack_202 + 2,param_1 + 2);
  FUN_004c40d0(local_618,&DAT_005d2ea4,acStack_202 + 2,param_1 + 4);
  FUN_004c40d0(local_558,&DAT_005d2e9c,acStack_202 + 2,param_1 + 8);
  FUN_004c40d0(local_5d8,&DAT_005d2e94,acStack_202 + 2,param_1 + 6);
  return 0;
}


