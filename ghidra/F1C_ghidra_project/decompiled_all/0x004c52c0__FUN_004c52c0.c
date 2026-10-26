// Function: FUN_004c52c0 @ 004c52c0
// Strings:  [D:\dev\F1_1999_2002\Source\setup.cpp, D:\dev\F1_1999_2002\Source\setup.cpp, D:\dev\F1_1999_2002\Source\setup.cpp, D:\dev\F1_1999_2002\Source\setup.cpp,   3) There are no scene files!,   2) We do not have read permission for those directories,   1) Incorrect season or tracks directory specified in config.ini, Could not find any scene files.  Possible problems:]


undefined4 FUN_004c52c0(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  DAT_008ac398 = 0;
  DAT_008ac3e8 = 0;
  DAT_008ac438 = 0;
  DAT_008ac488 = 0;
  DAT_008ac48c = 0;
  DAT_008ac490 = (undefined4 *)0x0;
  puVar4 = DAT_005ec420;
  if (DAT_005ec420 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  puVar2 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_0058815f(local_200,&DAT_005be860,puVar2,puVar4);
  FUN_00565f80(s___scn_005d31b0,1,local_200,1);
  if (DAT_008ac490 != (undefined4 *)0x0) {
    FUN_00587bcf(DAT_008ac490);
  }
  iVar3 = FUN_00565f70();
  DAT_008ac490 = operator_new(iVar3 * 0x18c);
  puVar7 = DAT_008ac490;
  for (uVar5 = (uint)(iVar3 * 0x18c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar7 = 0;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  if (iVar3 == 0) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_setup_005d3044,0x502);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Could_not_find_any_scene_files__P_005d317c);
    }
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_setup_005d3044,0x503);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_1__Incorrect_season_or_tracks_di_005d3138);
    }
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_setup_005d3044,0x504);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_2__We_do_not_have_read_permissio_005d30fc);
    }
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_setup_005d3044,0x505);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_3__There_are_no_scene_files__005d30dc);
    }
  }
  FUN_00565f50();
  iVar3 = FUN_005662d0();
  while (iVar3 != 0) {
    FUN_0058815f(local_100,&DAT_005be860,local_200,iVar3);
    iVar3 = FUN_00587db0(local_100,&DAT_005c36f0);
    if (iVar3 != 0) {
      FUN_004c51a0(iVar3,0,local_100,DAT_008ac490);
      FUN_00587d02(iVar3);
    }
    cVar1 = FUN_00565f20();
    if (cVar1 == '\0') break;
    iVar3 = FUN_005662d0();
  }
  FUN_00565eb0();
  FUN_004c5940();
  return DAT_008ac488;
}


