// Function: FUN_0042d260 @ 0042d260
// Strings:  [D:\dev\F1_1999_2002\Source\game.cpp, D:\dev\F1_1999_2002\Source\game.cpp, No vehicle files found, No scene files found]


undefined4 __fastcall FUN_0042d260(int param_1)

{
  char cVar1;
  DWORD DVar2;
  undefined1 *puVar3;
  char *pcVar4;
  CHAR local_100 [256];
  
  DVar2 = GetModuleFileNameA((HMODULE)0x0,local_100,0x100);
  if (DVar2 != 0) {
    FUN_00568a60(7,param_1 + 0x1c);
  }
  puVar3 = DAT_005ec408;
  if (DAT_005ec408 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_00423890(puVar3,0);
  FUN_004b3bd0();
  FUN_004d7660();
  FUN_004c52c0();
  if (DAT_008ac488 < 1) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_game__005c3590,0x146);
    if (cVar1 == '\0') {
      return 1;
    }
    pcVar4 = s_No_scene_files_found_005c35e8;
  }
  else {
    FUN_004c3d80();
    if (0 < DAT_008ac390) {
      return 0;
    }
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_game__005c3590,0x14f);
    if (cVar1 == '\0') {
      return 1;
    }
    pcVar4 = s_No_vehicle_files_found_005c35d0;
  }
  FUN_004d7aa0(&DAT_008ad25c,pcVar4);
  return 1;
}


