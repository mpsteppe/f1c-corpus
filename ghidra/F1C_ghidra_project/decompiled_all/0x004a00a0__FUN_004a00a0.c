// Function: FUN_004a00a0 @ 004a00a0
// Strings:  [FIAShort.bik]


undefined4 FUN_004a00a0(void)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 local_100 [256];
  
  uVar4 = 0;
  do {
    iVar2 = ShowCursor(0);
  } while (-1 < iVar2);
  if (((DAT_007d0410 == 4) && (DAT_007c56a4 == 7)) && (DAT_007d032c == 1)) {
    puVar3 = DAT_005ec418;
    if (DAT_005ec418 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_0058815f(local_100,&DAT_005be860,puVar3,s_FIAShort_bik_005c6bb0);
    uVar4 = FUN_004f9b70(local_100,1);
  }
  FUN_00463e00();
  FUN_004a0d30(0);
  FUN_0042d210(0);
  FUN_004f9f70(0);
  FUN_00453560();
  FUN_0040d410();
  DAT_007c54e0 = (&DAT_007c54f0)[DAT_007c54e4];
  DAT_007c54dc = DAT_007c54e4;
  FUN_0040d100();
  FUN_0040d090();
  FUN_00408450(0);
  FUN_00495060();
  FUN_004950c0();
  FUN_0045bdf0();
  FUN_004b9fd0();
  cVar1 = FUN_0042bc10();
  if (cVar1 != '\0') {
    FUN_00434000();
    FUN_004c6d90(0);
    if (*(int *)(DAT_007c54e8 + 0x32e0) != 0) {
      if (*(char *)(DAT_007c54e8 + 0x344c) != '\0') {
        FUN_004a4000();
      }
      FUN_004a3b50();
    }
    if ((DAT_007c56a4 != 7) || (((DAT_007c56a8 != 2 && (DAT_007c56a8 != 3)) && (DAT_007c56a8 != 4)))
       ) {
      FUN_004efa40(0);
    }
    FUN_004e4910();
  }
  FUN_004d4a80();
  return uVar4;
}


