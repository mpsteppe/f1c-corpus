// Function: FUN_0047bf30 @ 0047bf30
// Strings:  [*.Vcr]


void __fastcall FUN_0047bf30(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char local_c0;
  undefined4 local_bf;
  undefined1 local_81;
  char local_80;
  undefined4 local_7f;
  
  local_c0 = DAT_005ea438;
  puVar6 = &local_bf;
  for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  pcVar2 = (char *)FUN_00489920();
  *(undefined1 *)(param_1 + 0x131) = 0;
  if (pcVar2 != (char *)0x0) {
    _strncpy(&local_c0,pcVar2,0x3f);
    local_81 = 0;
  }
  FUN_00489cb0();
  FUN_00565eb0();
  puVar3 = DAT_005ec410;
  if (DAT_005ec410 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_00565f80(s___Vcr_005c71d4,1,puVar3,0);
  FUN_00566380(0);
  FUN_00565f50();
  iVar4 = FUN_00565ed0();
  do {
    if (iVar4 == 0) {
      FUN_00489ba0(&local_c0,0);
      FUN_00565eb0();
      return;
    }
    puVar6 = &local_7f;
    for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    *(undefined2 *)puVar6 = 0;
    *(undefined1 *)((int)puVar6 + 2) = 0;
    local_80 = DAT_005ea438;
    FUN_0047beb0(iVar4,&local_80);
    iVar4 = -1;
    pcVar2 = &local_80;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (iVar4 != -2) {
      FUN_00489600(&local_80,0,0,0,0);
    }
    FUN_00565f20();
    iVar4 = FUN_00565ed0();
  } while( true );
}


