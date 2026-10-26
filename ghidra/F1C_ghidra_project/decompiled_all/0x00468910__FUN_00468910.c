// Function: FUN_00468910 @ 00468910
// Strings:  [World Championships:, Wins:, Points:, Pole Positions:, Avg. Opponent Strength (%):, Avg. Race Length:, Avg. Finish Position:, Avg. Starting Position:]


undefined4 __fastcall FUN_00468910(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x44);
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  FUN_00486f30(s_Experience__Laps___005c6900,0xffffffff);
  FUN_00486f30(s_Starts__005c68f8,0xffffffff);
  FUN_00486f30(s_Avg__Starting_Position__005c68e0,0xffffffff);
  FUN_00486f30(s_Avg__Finish_Position__005c68c8,0xffffffff);
  FUN_00486f30(s_Avg__Race_Length__005c68b4,0xffffffff);
  FUN_00486f30(s_Avg__Opponent_Strength______005c6898,0xffffffff);
  FUN_00486f30(s_Pole_Positions__005c6888,0xffffffff);
  FUN_00486f30(s_Points__005c6880,0xffffffff);
  FUN_00486f30(s_Wins__005c6878,0xffffffff);
  FUN_00486f30(s_World_Championships__005c6860,0xffffffff);
  FUN_00468640();
  return 0;
}


