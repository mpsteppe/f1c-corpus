// Function: FUN_0049b0a0 @ 0049b0a0
// Strings:  [SSj j SSSVh, ingame.mas, NextSession.bmp, NextSession.bmp, NextTrack.bmp, NetProblem.bmp, VehicleDisplay.bmp]


void FUN_0049b0a0(void)

{
  undefined1 *puVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  undefined4 local_204;
  undefined1 local_200 [512];
  
  local_200[0] = 0;
  puVar1 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0058815f(local_200,&DAT_005be860,puVar1,PTR_s_ingame_mas_005ccb54);
  local_204 = 0;
  iVar2 = FUN_0053cbc0(&local_204,local_200);
  if (iVar2 == 0) {
    iVar2 = 0;
    do {
      pcVar5 = (char *)0x0;
      switch(iVar2) {
      case 0:
        pcVar5 = s_VehicleDisplay_bmp_005cce04;
        break;
      case 1:
        pcVar5 = s_NetProblem_bmp_005ccdf4;
        break;
      case 2:
        pcVar5 = s_NextTrack_bmp_005ccde4;
        break;
      case 3:
        pcVar5 = s_NextSession_bmp_005ccdd4;
      }
      pvVar3 = operator_new(0x28);
      if (pvVar3 == (void *)0x0) {
        pvVar3 = (void *)0x0;
      }
      else {
        FUN_004dcb70();
      }
      (&DAT_007ce23c)[iVar2] = pvVar3;
      iVar4 = FUN_004dcba0(0xff000000,pcVar5,0,0,0,0x20,0x20,0,0);
      if (iVar4 != 0) {
        iVar4 = (&DAT_007ce23c)[iVar2];
        if (iVar4 != 0) {
          FUN_004dcd10();
          FUN_00587bcf(iVar4);
        }
        (&DAT_007ce23c)[iVar2] = 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    FUN_0053ce40(local_204);
  }
  return;
}


