// Function: FUN_004a0490 @ 004a0490
// Strings:  [MAIN MENU]


undefined4 FUN_004a0490(void)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  if (DAT_007c569c == 5) {
    DAT_005cc9e8 = 3;
    FUN_0042d210(0);
  }
  if (DAT_007d0410 == 4) {
    FUN_004b0770(0);
    pcVar1 = DAT_007ce630;
    if (DAT_007ce630 == (char *)0x0) {
      pcVar1 = &DAT_005ea438;
    }
    if (*pcVar1 != '\0') {
      puVar2 = (undefined4 *)FUN_004c40b0(pcVar1);
      if (puVar2 != (undefined4 *)0x0) {
        puVar3 = (undefined1 *)*puVar2;
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_005ea438;
        }
        FUN_00566650(puVar3);
        FUN_00566650(puVar2 + 0x2f);
      }
    }
  }
  else if (DAT_007d0410 == 5) {
    FUN_00463140();
  }
  else if (DAT_007d0410 == 6) {
    DAT_007d0410 = 1;
    if (DAT_007d0418 < 2) {
      if (DAT_007d041c < 1) {
        DAT_007d0410 = DAT_007d041c;
      }
    }
    else {
      DAT_007d0410 = DAT_007d0418;
    }
  }
  if (DAT_005eb10c != (int *)0x0) {
    (**(code **)(*DAT_005eb10c + 0xc))();
  }
  FUN_004186a0();
  FUN_0042bd60();
  FUN_00497940(s_MAIN_MENU_005be708,0xffffffff);
  return 0;
}


