// Function: FUN_004c0b70 @ 004c0b70
// Strings:  [CURRENTRACE, RACEOVER, RACESESSION, SEASONSTATUS, [PLAYER], [OPPONENT, [OPPONENT, [OPPONENT]


undefined1 __thiscall FUN_004c0b70(int param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  char *pcVar7;
  
  piVar2 = param_2;
  uVar5 = 0;
  uVar6 = 0;
  if (*param_2 != 0) {
    while (uVar5 = uVar6, iVar3 = FUN_00566cc0(&DAT_008ac1e8,0x100), iVar3 != 0) {
      uVar6 = 1;
      iVar3 = FUN_005651b0();
      if (iVar3 == 0) {
        iVar3 = FUN_00587c20(&DAT_008ac1e8,s__OPPONENT_005d2858);
        if (iVar3 == 0) {
          iVar3 = FUN_00587c20(&DAT_008ac1e8,s__PLAYER__005d284c);
          if (iVar3 == 0) {
            iVar3 = FUN_00565760(s_SEASONSTATUS_005d283c,&param_2,0,0,0);
            if (iVar3 == 0) {
              FUN_00565760(s_RACESESSION_005d2830,param_1 + 0xb14c,0,0,0);
              iVar3 = FUN_00565760(s_RACEOVER_005d2824,&param_2,0,0,0);
              if (iVar3 != 0) {
                *(bool *)(param_1 + 0xb150) = param_2 != (int *)0x0;
              }
              FUN_00565760(s_CURRENTRACE_005d2818,param_1 + 0xb148,0,0,0);
            }
            else {
              *(int **)(param_1 + 0xb144) = param_2;
            }
          }
          else {
            FUN_004c03f0(piVar2);
          }
        }
        else {
          uVar4 = 0xffffffff;
          pcVar7 = s__OPPONENT_005d2858;
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_00587ece(iVar3 + (~uVar4 - 1));
          FUN_004c03f0(piVar2);
        }
      }
      else {
        if (iVar3 == 1) {
          return 1;
        }
        if (iVar3 == 4) {
          return 1;
        }
      }
    }
  }
  return uVar5;
}


