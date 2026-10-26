// Function: FUN_004c18b0 @ 004c18b0
// Strings:  [TrackFile, Trackname, BestLapTime, TotalNumLaps, GAMEOPT_speed_comp, GAMEOPT_tire_mult, GAMEOPT_fuel_mult, GAMEOPT_opponents]


uint __thiscall FUN_004c18b0(int *param_1,int *param_2)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint3 uVar8;
  int iVar9;
  float10 fVar10;
  int local_104;
  undefined1 local_100 [256];
  
  if (*param_2 != 0) {
    pvVar2 = operator_new(0x18);
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_004c03a0();
    }
    while (iVar4 = FUN_00566cc0(&DAT_008ac1e8,0x100), iVar4 != 0) {
      iVar4 = FUN_005651b0();
      iVar9 = 0;
      if (iVar4 == 0) {
        iVar4 = FUN_00587c20(&DAT_008ac1e8,s__CAREERSEASON__005d2b28);
        if (iVar4 == 0) {
          iVar4 = FUN_00587c20(&DAT_008ac1e8,s__PLAYERTRACKSTAT__005d2b14);
          if (iVar4 == 0) {
            FUN_00565760(s_ABORTEDSEASONS_005d2b04,param_1 + 8,0,0,0);
            FUN_00565760(s_TOTALLAPS_005d2af8,param_1 + 9,0,0,0);
            FUN_00565760(s_TOTALRACES_005d2aec,param_1 + 10,0,0,0);
            FUN_00565760(s_TOTALRACESWITHAI_005d2ad8,param_1 + 0xb,0,0,0);
            FUN_00565760(s_TOTALPOINTSSCORED_005d2ac4,param_1 + 0xc,0,0,0);
            FUN_00565760(s_TOTALCHAMPIONSHIPS_005d2ab0,param_1 + 0xd,0,0,0);
            FUN_00565760(s_TOTALWINS_005d2aa4,param_1 + 0xe,0,0,0);
            FUN_00565760(s_TOTALPOLES_005d2a98,param_1 + 0xf,0,0,0);
            FUN_00565760(s_TOTALLAPRECORDS_005d2a88,param_1 + 0x10,0,0,0);
            iVar4 = FUN_00565520(s_AVGSTARTPOSITION_005d2a74,local_100,0);
            if (iVar4 != 0) {
              fVar10 = (float10)FUN_0058850f(local_100);
              param_1[0x11] = (int)(float)fVar10;
            }
            iVar4 = FUN_00565520(s_AVGFINISHPOSITION_005d2a60,local_100,0);
            if (iVar4 != 0) {
              fVar10 = (float10)FUN_0058850f(local_100);
              param_1[0x12] = (int)(float)fVar10;
            }
            iVar4 = FUN_00565520(s_AVGRACEDISTANCE_005d2a50,local_100,0);
            if (iVar4 != 0) {
              fVar10 = (float10)FUN_0058850f(local_100);
              param_1[0x13] = (int)(float)fVar10;
            }
            iVar4 = FUN_00565520(s_AVGOPPONENTSTRENGTH_005d2a3c,local_100,0);
            if (iVar4 != 0) {
              fVar10 = (float10)FUN_0058850f(local_100);
              param_1[0x14] = (int)(float)fVar10;
            }
            local_104 = 0;
            iVar4 = FUN_00565760(s_MECHFAIL_rate_005d2a2c,&local_104,0,0,0);
            if (iVar4 != 0) {
              param_1[0x15] = local_104;
            }
            FUN_00565760(s_RACECOND_reconnaissance_005d2a14,param_1 + 0x16,0,0,0);
            FUN_00565760(s_RACECOND_walkthrough_005d29fc,param_1 + 0x17,0,0,0);
            FUN_00565760(s_RACECOND_formation_005d29e8,param_1 + 0x18,0,0,0);
            FUN_00565760(s_RACECOND_flag_rules_005d29d4,param_1 + 0x19,0,0,0);
            iVar4 = FUN_00565760(s_RACECOND_weather_005d29c0,&local_104,0,0,0);
            if (iVar4 != 0) {
              param_1[0x1a] = local_104;
            }
            iVar4 = FUN_00565760(s_RACECOND_timescaled_weather_005d29a4,&local_104,0,0,0);
            if (iVar4 != 0) {
              *(bool *)(param_1 + 0x1b) = local_104 != 0;
            }
            FUN_00565760(s_GAMEOPT_qualify_laps_005d298c,param_1 + 0x1c,0,0,0);
            FUN_00565760(s_GAMEOPT_race_laps_005d2978,param_1 + 0x1d,0,0,0);
            FUN_00565760(s_GAMEOPT_race_time_005d2964,param_1 + 0x1e,0,0,0);
            FUN_00565870(s_GAMEOPT_race_length_005d2950,param_1 + 0x1f,0,0,0,0,0,0,0);
            FUN_00565760(s_GAMEOPT_opponents_005d293c,param_1 + 0x20,0,0,0);
            FUN_00565760(s_GAMEOPT_fuel_mult_005d2928,param_1 + 0x21,0,0,0);
            FUN_00565760(s_GAMEOPT_tire_mult_005d2914,param_1 + 0x22,0,0,0);
            FUN_00565760(s_GAMEOPT_speed_comp_005d2900,param_1 + 0x23,0,0,0);
            FUN_00565760(s_TotalNumLaps_005d28f0,piVar3 + 4,0,0,0);
            FUN_00565870(s_BestLapTime_005d28e4,piVar3 + 5,0,0,0,0,0,0,0);
            iVar4 = FUN_005654a0(s_Trackname_005d28d8,local_100);
            if (iVar4 != 0) {
              FUN_00566650(local_100);
            }
            iVar4 = FUN_005654a0(s_TrackFile_005d28cc,local_100);
            if (iVar4 != 0) {
              FUN_00566650(local_100);
            }
          }
          else {
            FUN_004c18b0(param_2);
          }
        }
        else {
          pvVar2 = operator_new(0xb154);
          if (pvVar2 != (void *)0x0) {
            iVar9 = FUN_004c0ab0();
          }
          cVar1 = FUN_004c0b70(param_2);
          if (cVar1 == '\0') {
            if (iVar9 != 0) {
              FUN_004c0b10();
              FUN_00587bcf(iVar9);
            }
          }
          else if (iVar9 != 0) {
            piVar7 = operator_new(0xc);
            if (piVar7 == (int *)0x0) {
              piVar7 = (int *)0x0;
            }
            else {
              *piVar7 = iVar9;
              piVar7[1] = 0;
              *(undefined1 *)(piVar7 + 2) = 1;
            }
            if (*param_1 == 0) {
              *param_1 = (int)piVar7;
              param_1[2] = (int)piVar7;
              param_1[1] = (int)piVar7;
              param_1[3] = param_1[3] + 1;
            }
            else {
              *(int **)(param_1[1] + 4) = piVar7;
              param_1[1] = (int)piVar7;
              param_1[3] = param_1[3] + 1;
            }
          }
        }
      }
      else if ((iVar4 == 1) || (iVar4 == 4)) break;
    }
    puVar5 = (undefined1 *)piVar3[2];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    param_2 = (int *)FUN_004c2860(puVar5);
    if (param_2 == (int *)0x0) {
      if (piVar3 != (int *)0x0) {
        puVar6 = operator_new(0xc);
        if (puVar6 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)0x0;
        }
        else {
          *puVar6 = piVar3;
          puVar6[1] = 0;
          *(undefined1 *)(puVar6 + 2) = 1;
        }
        uVar8 = (uint3)((uint)puVar6 >> 8);
        if (param_1[4] != 0) {
          *(undefined4 **)(param_1[5] + 4) = puVar6;
          param_1[5] = (int)puVar6;
          param_1[7] = param_1[7] + 1;
          return (uint)uVar8 << 8;
        }
        param_1[4] = (int)puVar6;
        param_1[6] = (int)puVar6;
        param_1[5] = (int)puVar6;
        param_1[7] = param_1[7] + 1;
        return (uint)uVar8 << 8;
      }
    }
    else if (piVar3 != (int *)0x0) {
      if (piVar3[2] != 0) {
        FUN_00587bcf(piVar3[2]);
      }
      if (*piVar3 != 0) {
        FUN_00587bcf(*piVar3);
      }
      param_2 = (int *)FUN_00587bcf(piVar3);
    }
  }
  return (uint)param_2 & 0xffffff00;
}


