// Function: FUN_004d8450 @ 004d8450
// Strings:  [HUD Off, HUD Off, HUD On, HUD On, Broadcast Displays Off, Broadcast Displays Off, Broadcast Displays On, Broadcast Displays On]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d8450(int *param_1)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  char *pcVar4;
  char acStack_100 [127];
  undefined1 uStack_81;
  char acStack_80 [127];
  undefined1 uStack_1;
  
  FUN_004d82d0();
  if ((*param_1 != -1) && (_DAT_005ea4e8 <= DAT_0059e440)) {
    if ((float)param_1[0x37] <= DAT_0059e440) {
      if (param_1[*param_1 + 4] == 0) {
        *param_1 = -1;
      }
      else {
        iVar1 = FUN_004d7e00();
        if (iVar1 == 1) {
          *param_1 = -1;
          param_1[0x37] = DAT_005acf34;
        }
      }
    }
    else {
      param_1[0x37] = (int)((float)param_1[0x37] - (float)_DAT_008afe98);
    }
  }
  if ((param_1[1] != -1) && (iVar1 = FUN_004d7e00(), iVar1 == 1)) {
    param_1[1] = -1;
  }
  if (param_1[2] != -1) {
    FUN_004d7e00();
  }
  iVar1 = 0;
  if (0 < DAT_007cb218) {
    psVar3 = &DAT_007cb21c;
    do {
      if (*psVar3 == 3) {
        DAT_007cf788 = (uint)(DAT_007cf788 == 0);
        if (DAT_007cf788 == 0) {
          FUN_004d8880(0xffffffff);
          iVar2 = FUN_00423a00(s_HUD_Off_005d4a98,&DAT_005ec4cc);
          if (iVar2 != 0) {
            iVar2 = 0;
            do {
              pcVar4 = s_HUD_Off_005d4a98 + iVar2;
              (&DAT_005ec4cc)[iVar2] = *pcVar4;
              iVar2 = iVar2 + 1;
            } while (*pcVar4 != '\0');
          }
          _strncpy(acStack_80,&DAT_005ec4cc,0x7f);
          uStack_1 = 0;
          pcVar4 = acStack_80;
        }
        else {
          iVar2 = FUN_00423a00(s_HUD_On_005d4aa0,&DAT_005ec4cc);
          if (iVar2 != 0) {
            iVar2 = 0;
            do {
              pcVar4 = s_HUD_On_005d4aa0 + iVar2;
              (&DAT_005ec4cc)[iVar2] = *pcVar4;
              iVar2 = iVar2 + 1;
            } while (*pcVar4 != '\0');
          }
          _strncpy(acStack_80,&DAT_005ec4cc,0x7f);
          pcVar4 = acStack_80;
          uStack_1 = 0;
        }
LAB_004d86c1:
        FUN_0045bd10(pcVar4,3,0x1020304);
      }
      else if (*psVar3 == 4) {
        DAT_007cf638 = (uint)(DAT_007cf638 == 0);
        if (DAT_007cf638 == 0) {
          FUN_004d8760(0xffffffff,0);
          iVar2 = FUN_00423a00(s_Broadcast_Displays_Off_005d4aa8,&DAT_005ec4cc);
          if (iVar2 != 0) {
            iVar2 = 0;
            do {
              pcVar4 = s_Broadcast_Displays_Off_005d4aa8 + iVar2;
              (&DAT_005ec4cc)[iVar2] = *pcVar4;
              iVar2 = iVar2 + 1;
            } while (*pcVar4 != '\0');
          }
          _strncpy(acStack_100,&DAT_005ec4cc,0x7f);
          pcVar4 = acStack_100;
          uStack_81 = 0;
        }
        else {
          iVar2 = FUN_00423a00(s_Broadcast_Displays_On_005d4ac0,&DAT_005ec4cc);
          if (iVar2 != 0) {
            iVar2 = 0;
            do {
              pcVar4 = s_Broadcast_Displays_On_005d4ac0 + iVar2;
              (&DAT_005ec4cc)[iVar2] = *pcVar4;
              iVar2 = iVar2 + 1;
            } while (*pcVar4 != '\0');
          }
          _strncpy(acStack_100,&DAT_005ec4cc,0x7f);
          uStack_81 = 0;
          pcVar4 = acStack_100;
        }
        goto LAB_004d86c1;
      }
      iVar1 = iVar1 + 1;
      psVar3 = psVar3 + 1;
    } while (iVar1 < DAT_007cb218);
  }
  if ((((char)param_1[0x3b] != '\0') && (param_1[0x36] != 0)) &&
     ((DAT_005ea518 != DAT_005ea528 || (*(int *)(DAT_005ea528 + 0x34) != 1)))) {
    FUN_004d7e00();
  }
  return;
}


