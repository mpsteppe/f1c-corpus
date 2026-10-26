// Function: FUN_004b0770 @ 004b0770
// Strings:  [Retcode: %d for renaming to %s, Attempting to save to %s, D:\dev\F1_1999_2002\Source\plrfile.cpp, D:\dev\F1_1999_2002\Source\plrfile.cpp]


/* WARNING: Removing unreachable block (ram,0x004b091c) */

undefined4 __fastcall FUN_004b0770(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  int local_11c [7];
  undefined1 local_100 [256];
  
  FUN_00568620(0x100);
  FUN_00566650(local_100);
  uVar3 = 0xffffffff;
  pcVar4 = &DAT_005ea438;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar4 = &DAT_005ea437 + ~uVar3;
  if (&DAT_005ea438 < pcVar4) {
    do {
      if (*pcVar4 == '.') {
        *pcVar4 = '\0';
        break;
      }
      pcVar4 = pcVar4 + -1;
    } while (&DAT_005ea438 < pcVar4);
  }
  FUN_005665b0(&DAT_005d2308);
  FUN_0058ba36(local_100,0x180);
  FUN_0058ba36(&DAT_005ea438,0x180);
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_plrfi_005d22e0,0x6e6);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Attempting_to_save_to__s_005d22c4,&DAT_005ea438);
  }
  FUN_005668b0();
  FUN_00566940(&DAT_005ea438,0,1,1);
  if (local_11c[0] != 0) {
    FUN_004a1d50(local_11c,s__________________________________005d2018);
  }
  FUN_00566b90();
  FUN_004b0930();
  FUN_004330d0(param_1);
  FUN_0058986e(local_100);
  uVar2 = FUN_005898d3(&DAT_005ea438,local_100);
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_plrfi_005d22e0,0x6fd);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Retcode___d_for_renaming_to__s_005d1ff4,uVar2,local_100);
  }
  FUN_005668d0();
  return 0;
}


