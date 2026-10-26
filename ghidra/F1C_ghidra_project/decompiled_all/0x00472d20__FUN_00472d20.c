// Function: FUN_00472d20 @ 00472d20
// Strings:  [REPLAY PLAYBACK, DRIVING SCHOOL, MULTIPLAYER, CHAMPIONSHIP, QUICKRACE, TEST DAY, CURRENT]


undefined4 __fastcall FUN_00472d20(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_0048c0e0();
  iVar1 = *(int *)(param_1 + 0x44);
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    FUN_00418d60(1);
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  FUN_00486f30(s_CURRENT_005c7020,0xffffffff);
  FUN_00486f30(s_TEST_DAY_005c7014,0xffffffff);
  FUN_00486f30(s_QUICKRACE_005c7008,0xffffffff);
  FUN_00486f30(&DAT_005c7000,0xffffffff);
  FUN_00486f30(s_CHAMPIONSHIP_005c6ff0,0xffffffff);
  FUN_00486f30(s_MULTIPLAYER_005c6fe4,0xffffffff);
  FUN_00486f30(s_DRIVING_SCHOOL_005c6fd4,0xffffffff);
  FUN_00486f30(s_REPLAY_PLAYBACK_005c6fc4,0xffffffff);
  if ((((DAT_007d0410 == 0) || (DAT_007d0410 == 2)) || (DAT_007d0410 == 6)) &&
     ((DAT_007d0410 = 3, iVar1 = DAT_007d0418, 3 < DAT_007d0418 ||
      (iVar1 = DAT_007d041c, DAT_007d041c < 3)))) {
    DAT_007d0410 = iVar1;
  }
  uVar2 = FUN_00487010(DAT_007d0410);
  FUN_00566650(uVar2);
  *(int *)(param_1 + 800) = DAT_007d0410;
  return 0;
}


