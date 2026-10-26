// Function: FUN_004ba1f0 @ 004ba1f0
// Strings:  [Prepping Replay, Prepping Replay, Loading VCR File for playback, D:\dev\F1_1999_2002\Source\Replay.cpp]


void __fastcall FUN_004ba1f0(int *param_1)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 local_444;
  undefined1 *local_440;
  undefined4 local_43c;
  undefined1 local_400 [1024];
  
  if (*param_1 != 2) {
    cVar2 = FUN_00404f10();
    if ((cVar2 == '\0') && ((DAT_007d0038 != 0 || (DAT_007d005c != 0)))) {
      *param_1 = 1;
      return;
    }
    *param_1 = 0;
    return;
  }
  cVar3 = '\0';
  cVar2 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_Repla_005d24dc,0x1589);
  if (cVar2 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Loading_VCR_File_for_playback_005d24bc);
  }
  puVar6 = *(undefined1 **)(param_1[2] + 0xf94);
  if (puVar6 == (undefined1 *)0x0) {
    puVar6 = &DAT_005ea438;
  }
  FUN_005668b0();
  cVar2 = FUN_00566b20(puVar6,0);
  if (cVar2 != '\0') {
    iVar4 = FUN_00423a00(s_Prepping_Replay_005d24ac,&DAT_005ec4cc);
    if (iVar4 != 0) {
      iVar4 = 0;
      do {
        pcVar1 = s_Prepping_Replay_005d24ac + iVar4;
        (&DAT_005ec4cc)[iVar4] = *pcVar1;
        iVar4 = iVar4 + 1;
      } while (*pcVar1 != '\0');
    }
    FUN_004a0e70(&DAT_005ec4cc);
    Sleep(0xfa);
    local_440 = operator_new(0x80);
    *local_440 = 0;
    local_43c = 0x80;
    FUN_004b9830(&local_440);
    FUN_00568540();
    FUN_005668b0();
    puVar6 = local_440;
    if (local_440 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    cVar2 = FUN_00566940(puVar6,0,0,1);
    if (cVar2 != '\0') {
      while (iVar4 = FUN_00566c00(local_400,0x400), 0 < iVar4) {
        FUN_00566bd0(local_400,iVar4);
      }
      FUN_00566b90();
      FUN_00566b90();
      puVar6 = local_440;
      if (local_440 == (undefined1 *)0x0) {
        puVar6 = &DAT_005ea438;
      }
      cVar3 = FUN_004b97d0(puVar6,0);
      if (cVar3 != '\0') {
        FUN_004b9810();
        *param_1 = 2;
        FUN_004b9da0(5);
      }
    }
    FUN_005668d0();
    if (local_440 != (undefined1 *)0x0) {
      FUN_00587bcf(local_440);
    }
    if (cVar3 != '\0') {
      uVar5 = FUN_004b9820();
      FUN_0042bbd0(uVar5);
      uVar5 = FUN_004b9820();
      FUN_0042bc40(uVar5);
      iVar4 = param_1[2];
      local_444 = 0;
      FUN_004b87a0(&local_444,&local_440);
      *(undefined4 *)(iVar4 + 0xf3c) = local_444;
      FUN_004b86e0(local_444);
      FUN_005668d0();
      return;
    }
  }
  *param_1 = 0;
  FUN_005668d0();
  return;
}


