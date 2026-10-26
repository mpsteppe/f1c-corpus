// Function: FUN_0042d370 @ 0042d370
// Strings:  [F1_2002.gdb, D:\dev\F1_1999_2002\Source\game.cpp, *.pit, *.rcd, Entered Game::Enter()]


undefined4 __fastcall FUN_0042d370(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 local_100 [256];
  
  *param_1 = 1;
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_game__005c3590,0x168);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_Game__Enter___005c3610);
  }
  iVar2 = FUN_004a18d0();
  if (iVar2 != 0) {
    return 1;
  }
  iVar2 = FUN_0042d260();
  if (iVar2 != 0) {
    return 1;
  }
  iVar2 = FUN_004fa000();
  if (iVar2 == 0) {
    FUN_004cee90();
    FUN_0042c130();
    FUN_004b1820();
    puVar3 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_0058815f(local_100,&DAT_005be860,puVar3,DAT_007d0434,DAT_007d0438);
    cVar1 = FUN_00567f40(local_100,0);
    if (cVar1 == '\0') {
      FUN_00566650(s_F1_2002_gdb_005bf970);
      puVar3 = DAT_005ec3d8;
      if (DAT_005ec3d8 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      FUN_0058815f(local_100,&DAT_005be860,puVar3,DAT_007d0434,DAT_007d0438);
      FUN_00567f40(local_100,0);
    }
    puVar3 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00565f80(s___rcd_005c3608,1,puVar3,0);
    iVar2 = FUN_005662d0();
    while (iVar2 != 0) {
      FUN_00567f40(iVar2,0);
      FUN_00565f20();
      iVar2 = FUN_005662d0();
    }
    puVar3 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00565f80(s___pit_005c3600,1,puVar3,0);
    iVar2 = FUN_005662d0();
    while (iVar2 != 0) {
      FUN_00567f40(iVar2,0);
      FUN_00565f20();
      iVar2 = FUN_005662d0();
    }
    iVar2 = FUN_004c8a20();
    if (iVar2 == 0) {
      iVar2 = FUN_00455bf0();
      if (iVar2 == 0) {
        FUN_004b0170();
        FUN_004b0170();
        FUN_0049ef40();
        FUN_004b0170();
        FUN_00463e20();
        return 0;
      }
      return 1;
    }
    return 1;
  }
  return 1;
}


