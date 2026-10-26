// Function: FUN_004c0cc0 @ 004c0cc0
// Strings:  [[PLAYER], [OPPONENT, %s%2.2d]]


uint __thiscall FUN_004c0cc0(int param_1,int *param_2,int param_3)

{
  uint in_EAX;
  int iVar1;
  undefined1 local_20 [32];
  
  if (*param_2 != 0) {
    if (param_3 != 0) {
      FUN_00566cf0(param_3);
      FUN_00566cf0(&DAT_005c30b4);
    }
    FUN_00566c30(param_2,s_SeasonStatus__d_005d28a0,*(undefined4 *)(param_1 + 0xb144));
    FUN_00566c30(param_2,s_RaceSession__d_005d2890,*(undefined4 *)(param_1 + 0xb14c));
    FUN_00566c30(param_2,s_RaceOver__d_005d2880,*(char *)(param_1 + 0xb150) != '\0');
    FUN_00566c30(param_2,s_CurrentRace__d_005d2870,*(undefined4 *)(param_1 + 0xb148));
    FUN_004c0690(param_2,s__PLAYER__005d284c);
    iVar1 = 0;
    do {
      if (*(char *)(param_1 + 0x1b0) != '\0') {
        FUN_0058815f(local_20,s__s_2_2d__005d2864,s__OPPONENT_005d2858,iVar1);
        FUN_004c0690(param_2,local_20);
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 0x1b4;
    } while (iVar1 < 0x67);
    in_EAX = FUN_00566c30(param_2,&DAT_005c30b4);
  }
  return in_EAX & 0xffffff00;
}


