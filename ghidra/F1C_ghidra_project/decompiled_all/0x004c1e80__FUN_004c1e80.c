// Function: FUN_004c1e80 @ 004c1e80
// Strings:  [GAMEOPT_speed_comp, GAMEOPT_tire_mult, GAMEOPT_fuel_mult, GAMEOPT_opponents, GAMEOPT_race_length, GAMEOPT_race_time, GAMEOPT_race_laps, GAMEOPT_qualify_laps]


uint __thiscall FUN_004c1e80(int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  float10 fVar5;
  int local_104;
  undefined1 local_100 [256];
  
  piVar4 = param_2;
  if (*param_2 != 0) {
    while( true ) {
      iVar2 = FUN_00566cc0(&DAT_008ac1e8,0x100);
      piVar4 = (int *)0x0;
      if (iVar2 == 0) break;
      iVar2 = FUN_005651b0();
      if (iVar2 == 0) {
        iVar2 = FUN_00587c20(&DAT_008ac1e8,s__CAREERSEASON__005d2b28);
        if (iVar2 == 0) {
          iVar2 = FUN_00587c20(&DAT_008ac1e8,s__PLAYERTRACKSTAT__005d2b14);
          if (iVar2 == 0) {
            FUN_00565760(s_ABORTEDSEASONS_005d2b04,param_1 + 8,0,0,0);
            FUN_00565760(s_TOTALLAPS_005d2af8,param_1 + 9,0,0,0);
            FUN_00565760(s_TOTALRACES_005d2aec,param_1 + 10,0,0,0);
            FUN_00565760(s_TOTALRACESWITHAI_005d2ad8,param_1 + 0xb,0,0,0);
            FUN_00565760(s_TOTALPOINTSSCORED_005d2ac4,param_1 + 0xc,0,0,0);
            FUN_00565760(s_TOTALCHAMPIONSHIPS_005d2ab0,param_1 + 0xd,0,0,0);
            FUN_00565760(s_TOTALWINS_005d2aa4,param_1 + 0xe,0,0,0);
            FUN_00565760(s_TOTALPOLES_005d2a98,param_1 + 0xf,0,0,0);
            FUN_00565760(s_TOTALLAPRECORDS_005d2a88,param_1 + 0x10,0,0,0);
            iVar2 = FUN_00565520(s_AVGSTARTPOSITION_005d2a74,local_100,0);
            if (iVar2 != 0) {
              fVar5 = (float10)FUN_0058850f(local_100);
              param_1[0x11] = (int)(float)fVar5;
            }
            iVar2 = FUN_00565520(s_AVGFINISHPOSITION_005d2a60,local_100,0);
            if (iVar2 != 0) {
              fVar5 = (float10)FUN_0058850f(local_100);
              param_1[0x12] = (int)(float)fVar5;
            }
            iVar2 = FUN_00565520(s_AVGRACEDISTANCE_005d2a50,local_100,0);
            if (iVar2 != 0) {
              fVar5 = (float10)FUN_0058850f(local_100);
              param_1[0x13] = (int)(float)fVar5;
            }
            iVar2 = FUN_00565520(s_AVGOPPONENTSTRENGTH_005d2a3c,local_100,0);
            if (iVar2 != 0) {
              fVar5 = (float10)FUN_0058850f(local_100);
              param_1[0x14] = (int)(float)fVar5;
            }
            local_104 = 0;
            iVar2 = FUN_00565760(s_MECHFAIL_rate_005d2a2c,&local_104,0,0,0);
            if (iVar2 != 0) {
              param_1[0x15] = local_104;
            }
            FUN_00565760(s_RACECOND_reconnaissance_005d2a14,param_1 + 0x16,0,0,0);
            FUN_00565760(s_RACECOND_walkthrough_005d29fc,param_1 + 0x17,0,0,0);
            FUN_00565760(s_RACECOND_formation_005d29e8,param_1 + 0x18,0,0,0);
            FUN_00565760(s_RACECOND_flag_rules_005d29d4,param_1 + 0x19,0,0,0);
            iVar2 = FUN_00565760(s_RACECOND_weather_005d29c0,&local_104,0,0,0);
            if (iVar2 != 0) {
              param_1[0x1a] = local_104;
            }
            iVar2 = FUN_00565760(s_RACECOND_timescaled_weather_005d29a4,&local_104,0,0,0);
            if (iVar2 != 0) {
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
          }
          else {
            FUN_004c18b0(param_2);
          }
        }
        else {
          pvVar3 = operator_new(0xb154);
          if (pvVar3 == (void *)0x0) {
            iVar2 = 0;
          }
          else {
            iVar2 = FUN_004c0ab0();
          }
          cVar1 = FUN_004c0b70(param_2);
          if (cVar1 == '\0') {
            if (iVar2 != 0) {
              FUN_004c0b10();
              FUN_00587bcf(iVar2);
            }
          }
          else if (iVar2 != 0) {
            piVar4 = operator_new(0xc);
            if (piVar4 == (int *)0x0) {
              piVar4 = (int *)0x0;
            }
            else {
              *piVar4 = iVar2;
              piVar4[1] = 0;
              *(undefined1 *)(piVar4 + 2) = 1;
            }
            if (*param_1 == 0) {
              *param_1 = (int)piVar4;
              param_1[2] = (int)piVar4;
              param_1[1] = (int)piVar4;
              param_1[3] = param_1[3] + 1;
            }
            else {
              *(int **)(param_1[1] + 4) = piVar4;
              param_1[1] = (int)piVar4;
              param_1[3] = param_1[3] + 1;
            }
          }
        }
      }
      else {
        piVar4 = (int *)0x0;
        if ((iVar2 == 1) || (piVar4 = (int *)0x0, iVar2 == 4)) break;
      }
    }
  }
  return (uint)piVar4 & 0xffffff00;
}


