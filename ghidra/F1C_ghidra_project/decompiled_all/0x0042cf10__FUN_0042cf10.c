// Function: FUN_0042cf10 @ 0042cf10
// Strings:  [Multiplayer mode: setting vehicle places for RACE, D:\dev\F1_1999_2002\Source\game.cpp]


void __thiscall FUN_0042cf10(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  
  cVar5 = FUN_00461db0();
  if (cVar5 == '\0') {
    if (((param_2 == 2) || (param_2 == 3)) || (param_2 == 4)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    iVar7 = *(int *)(param_1 + 8);
    if ((iVar7 == 4) && (param_2 == 5)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((iVar7 == 5) && (param_2 == 6)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((iVar7 == 6) && (param_2 == 7)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if ((bVar1) || (bVar2)) {
      FUN_004c01a0();
    }
    else if (bVar3) {
      if ((DAT_007cebc4 != '\0') || (DAT_007d0410 == 4)) {
        iVar7 = 0;
        if (0 < DAT_005c329c) {
          do {
            FUN_004bc320();
            iVar7 = iVar7 + 1;
          } while (iVar7 < DAT_005c329c);
        }
        if (DAT_007d0410 == 4) {
          FUN_004c2830(1);
        }
      }
    }
    else if ((bVar4) && (iVar7 = 0, 0 < DAT_005c329c)) {
      do {
        FUN_004bc330();
        iVar7 = iVar7 + 1;
      } while (iVar7 < DAT_005c329c);
    }
  }
  else {
    cVar5 = FUN_00461dc0();
    if (((cVar5 != '\0') && (*(int *)(param_1 + 8) == 5)) && (iVar7 = 0, 0 < DAT_005c329c)) {
      do {
        FUN_004bc320();
        iVar7 = iVar7 + 1;
      } while (iVar7 < DAT_005c329c);
    }
    if (param_2 == 7) {
      if ((DAT_007c569c != 5) &&
         (cVar6 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_game__005c3590,0xd7), cVar6 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s_Multiplayer_mode__setting_vehicl_005c355c);
      }
      if (cVar5 == '\0') {
        FUN_00462e20();
      }
      else {
        FUN_00462a10();
      }
      iVar7 = 0;
      if (0 < DAT_005c329c) {
        do {
          FUN_004bc330();
          iVar7 = iVar7 + 1;
        } while (iVar7 < DAT_005c329c);
      }
      iVar7 = 0;
      if (0 < DAT_005c329c) {
        do {
          FUN_004c6f10();
          iVar7 = iVar7 + 1;
        } while (iVar7 < DAT_005c329c);
      }
    }
  }
  *(int *)(param_1 + 8) = param_2;
  DAT_007d00ec = param_2;
  if (DAT_007d00f4 <= param_2) {
    if (DAT_007d00f8 < param_2) {
      DAT_007d00ec = DAT_007d00f8;
    }
    return;
  }
  DAT_007d00ec = DAT_007d00f4;
  return;
}


