// Function: FUN_004b7500 @ 004b7500
// Strings:  [Saving Replay, Saving Replay, Saving Replay, Saving Replay]


/* WARNING: Removing unreachable block (ram,0x004b7816) */

void __thiscall FUN_004b7500(int param_1,char param_2)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 local_41c [28];
  undefined1 local_400 [1024];
  
  FUN_004b52a0();
  if (*(int *)(param_1 + 0x6e4) != 0) {
    if (*(int *)(param_1 + 0x700) == 1) {
      iVar6 = 0;
      do {
        FUN_004b6190(iVar6);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x68);
      FUN_004b7a00();
      if (((DAT_007c569c != 4) &&
          (DAT_0059e440 < *(float *)(param_1 + 0xf34) - *(float *)(param_1 + 0xf30))) &&
         (param_2 != '\0')) {
        iVar6 = FUN_00423a00(s_Saving_Replay_005d2444,&DAT_005ec4cc);
        if (iVar6 != 0) {
          iVar6 = 0;
          do {
            pcVar1 = s_Saving_Replay_005d2444 + iVar6;
            (&DAT_005ec4cc)[iVar6] = *pcVar1;
            iVar6 = iVar6 + 1;
          } while (*pcVar1 != '\0');
        }
        cVar3 = FUN_004a0e70(&DAT_005ec4cc);
        if (cVar3 != '\0') {
          Sleep(100);
        }
        FUN_005668b0();
        switch(*(undefined4 *)(param_1 + 0x9a4)) {
        case 0:
          uVar4 = 0;
          break;
        case 1:
          uVar4 = 1;
          break;
        case 2:
          uVar4 = 2;
          break;
        case 3:
          uVar4 = 3;
          break;
        default:
          uVar4 = 4;
        }
        puVar5 = *(undefined1 **)(param_1 + 0x70c);
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        FUN_00566940(puVar5,uVar4,0,1);
        FUN_004b6a10(local_41c,*(undefined4 *)(param_1 + 0xf30),*(undefined4 *)(param_1 + 0xf34));
        FUN_00566b90();
        puVar5 = *(undefined1 **)(param_1 + 0x704);
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        FUN_00566b20(puVar5,0);
        while (iVar6 = FUN_00566c00(local_400,0x400), 0 < iVar6) {
          FUN_00566bd0(local_400,iVar6);
        }
        FUN_00566b90();
        FUN_005668d0();
      }
      FUN_00566b90();
      FUN_004b8010();
    }
    else if (*(char *)(param_1 + 0x6d0) == '\0') {
      FUN_00566b90();
    }
    else {
      *(undefined1 *)(param_1 + 0x6d0) = 0;
      iVar6 = FUN_00423a00(s_Saving_Replay_005d2444,&DAT_005ec4cc);
      if (iVar6 != 0) {
        iVar6 = 0;
        do {
          pcVar1 = s_Saving_Replay_005d2444 + iVar6;
          (&DAT_005ec4cc)[iVar6] = *pcVar1;
          iVar6 = iVar6 + 1;
        } while (*pcVar1 != '\0');
      }
      cVar3 = FUN_004a0e70(&DAT_005ec4cc);
      if (cVar3 != '\0') {
        Sleep(100);
      }
      FUN_00568540();
      FUN_005668b0();
      puVar5 = *(undefined1 **)(param_1 + 0xf94);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      cVar3 = FUN_00566940(puVar5,4,0,1);
      if (cVar3 != '\0') {
        puVar5 = *(undefined1 **)(param_1 + 0x6e8);
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        FUN_00566650(puVar5);
        FUN_004b6a10(local_41c,*(undefined4 *)(param_1 + 0xf30),*(undefined4 *)(param_1 + 0xf34));
        piVar2 = *(int **)(param_1 + 0x714);
        *(int **)(param_1 + 0x71c) = piVar2;
        if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
          FUN_00566db0(*(undefined4 *)(*piVar2 + 4));
          while (iVar6 = FUN_00566c00(local_400,0x400), 0 < iVar6) {
            FUN_00566bd0(local_400,iVar6);
          }
          FUN_00566b90();
          FUN_00566b90();
          FUN_00568540();
        }
      }
      FUN_005668d0();
    }
  }
  *(undefined4 *)(param_1 + 0x700) = 0;
  FUN_004b5f60();
  return;
}


