// Function: FUN_004c2420 @ 004c2420
// Strings:  [[PLAYERTRACKSTAT], [CAREERSEASON]]


uint __thiscall FUN_004c2420(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint in_EAX;
  undefined4 *puVar2;
  
  if (*param_2 != 0) {
    if (param_3 != 0) {
      FUN_00566c30(param_2,param_3);
      FUN_00566c30(param_2,&DAT_005c30b4);
    }
    FUN_00566c30(param_2,s_AbortedSeasons__d_005d2e74,*(undefined4 *)(param_1 + 0x20));
    FUN_00566c30(param_2,s_TotalLaps__d_005d2e64,*(undefined4 *)(param_1 + 0x24));
    FUN_00566c30(param_2,s_TotalRaces__d_005d2e54,*(undefined4 *)(param_1 + 0x28));
    FUN_00566c30(param_2,s_TotalRacesWithAI__d_005d2e3c,*(undefined4 *)(param_1 + 0x2c));
    FUN_00566c30(param_2,s_TotalPointsScored__d_005d2e24,*(undefined4 *)(param_1 + 0x30));
    FUN_00566c30(param_2,s_TotalChampionships__d_005d2e0c,*(undefined4 *)(param_1 + 0x34));
    FUN_00566c30(param_2,s_TotalWins__d_005d2dfc,*(undefined4 *)(param_1 + 0x38));
    FUN_00566c30(param_2,s_TotalPoles__d_005d2dec,*(undefined4 *)(param_1 + 0x3c));
    FUN_00566c30(param_2,s_TotalLapRecords__d_005d2dd8,*(undefined4 *)(param_1 + 0x40));
    FUN_00566c30(param_2,s_AvgStartPosition__f_005d2dc0,(double)*(float *)(param_1 + 0x44));
    FUN_00566c30(param_2,s_AvgFinishPosition__f_005d2da8,(double)*(float *)(param_1 + 0x48));
    FUN_00566c30(param_2,s_AvgRaceDistance__f_005d2d94,(double)*(float *)(param_1 + 0x4c));
    FUN_00566c30(param_2,s_AvgOpponentStrength__f_005d2d7c,(double)*(float *)(param_1 + 0x50));
    FUN_00566c30(param_2,s____Championship_Settings__these_a_005d2cf8);
    FUN_00566c30(param_2,s_MECHFAIL_rate__d_005d2ce0,*(undefined4 *)(param_1 + 0x54));
    FUN_00566c30(param_2,s_RACECOND_reconnaissance__d_005d2cc4,*(undefined4 *)(param_1 + 0x58));
    FUN_00566c30(param_2,s_RACECOND_walkthrough__d_005d2ca8,*(undefined4 *)(param_1 + 0x5c));
    FUN_00566c30(param_2,s_RACECOND_formation__d_005d2c90,*(undefined4 *)(param_1 + 0x60));
    FUN_00566c30(param_2,s_RACECOND_flag_rules__d_005d2c78,*(undefined4 *)(param_1 + 100));
    FUN_00566c30(param_2,s_RACECOND_weather__d_005d2c60,*(undefined4 *)(param_1 + 0x68));
    FUN_00566c30(param_2,s_RACECOND_timescaled_weather__d_005d2c40,*(undefined1 *)(param_1 + 0x6c));
    FUN_00566c30(param_2,s_GAMEOPT_qualify_laps__d_005d2c24,*(undefined4 *)(param_1 + 0x70));
    FUN_00566c30(param_2,s_GAMEOPT_race_laps__d_005d2c0c,*(undefined4 *)(param_1 + 0x74));
    FUN_00566c30(param_2,s_GAMEOPT_race_time__d_005d2bf4,*(undefined4 *)(param_1 + 0x78));
    FUN_00566c30(param_2,s_GAMEOPT_race_length__f_005d2bdc,(double)*(float *)(param_1 + 0x7c));
    FUN_00566c30(param_2,s_GAMEOPT_opponents__d_005d2bc4,*(undefined4 *)(param_1 + 0x80));
    FUN_00566c30(param_2,s_GAMEOPT_fuel_mult__d_005d2bac,*(undefined4 *)(param_1 + 0x84));
    FUN_00566c30(param_2,s_GAMEOPT_tire_mult__d_005d2b94,*(undefined4 *)(param_1 + 0x88));
    FUN_00566c30(param_2,s_GAMEOPT_speed_comp__d_005d2b7c,*(undefined4 *)(param_1 + 0x8c));
    piVar1 = *(int **)(param_1 + 4);
    *(int **)(param_1 + 8) = piVar1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
      while( true ) {
        FUN_004c0cc0(param_2,s__CAREERSEASON__005d2b28);
        if (*(int *)(param_1 + 8) == 0) break;
        piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
        *(int **)(param_1 + 8) = piVar1;
        if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) break;
      }
    }
    piVar1 = *(int **)(param_1 + 0x10);
    *(int **)(param_1 + 0x18) = piVar1;
    if ((piVar1 != (int *)0x0) && (puVar2 = (undefined4 *)*piVar1, puVar2 != (undefined4 *)0x0)) {
      while( true ) {
        FUN_00566c30(param_2,&DAT_005c4064,s__PLAYERTRACKSTAT__005d2b14);
        FUN_00566c30(param_2,s_TrackName__s_005d2b6c,*puVar2,puVar2[1]);
        FUN_00566c30(param_2,s_TrackFile__s_005d2b5c,puVar2[2],puVar2[3]);
        FUN_00566c30(param_2,s_TotalNumLaps__d_005d2b48,puVar2[4]);
        FUN_00566c30(param_2,s_BestLapTime__f_005d2b38,(double)(float)puVar2[5]);
        if (*(int *)(param_1 + 0x18) == 0) break;
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 4);
        *(undefined4 **)(param_1 + 0x18) = puVar2;
        if ((puVar2 == (undefined4 *)0x0) ||
           (puVar2 = (undefined4 *)*puVar2, puVar2 == (undefined4 *)0x0)) break;
      }
    }
    in_EAX = FUN_00566c30(param_2,&DAT_005c30b4);
  }
  return in_EAX & 0xffffff00;
}


