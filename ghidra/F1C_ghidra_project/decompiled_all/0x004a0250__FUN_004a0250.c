// Function: FUN_004a0250 @ 004a0250
// Strings:  [POST RACE MONITOR]


undefined4 FUN_004a0250(void)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  FUN_00554e10(DAT_008afe88);
  do {
    iVar2 = ShowCursor(1);
  } while (iVar2 < 1);
  if ((DAT_007c56a4 == 7) && (DAT_007d0410 != 6)) {
    cVar1 = FUN_004d21d0();
    bVar3 = DAT_007d0410 != 5;
    if (cVar1 == '\0') {
      if ((bVar3) && (DAT_007cec90 == 0)) {
        FUN_004a0da0();
        FUN_0042d210(1);
        FUN_004c8d60();
      }
    }
    else {
      if (*(int *)(DAT_007c54e8 + 13000) == 0) {
        FUN_004bc060(1);
      }
      if (bVar3) {
        iVar2 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x21);
        if (iVar2 != 0) {
          FUN_0046ba20(0);
          FUN_0046c030();
        }
      }
      FUN_00497940(s_POST_RACE_MONITOR_005ccfe8,0xffffffff);
    }
  }
  FUN_004d5840();
  FUN_004a0d30(1);
  cVar1 = FUN_0042bc10();
  if (cVar1 != '\0') {
    FUN_004efac0();
    FUN_004c6d90(0);
  }
  FUN_004c8d80();
  FUN_004c8180();
  iVar2 = 0;
  if (0 < DAT_005c329c) {
    do {
      if (*(char *)((&DAT_007c54f0)[iVar2] + 0xc4) != '\0') {
        FUN_004f7010(0);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_005c329c);
  }
  FUN_0040d410();
  FUN_0040d240(*(undefined4 *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894));
  FUN_00408450(0);
  FUN_004d8760(0xffffffff,0);
  return 0;
}


