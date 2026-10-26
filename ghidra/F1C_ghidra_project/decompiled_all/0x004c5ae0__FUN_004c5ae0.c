// Function: FUN_004c5ae0 @ 004c5ae0
// Strings:  [SeasonRaces, SeasonRaces]


void FUN_004c5ae0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char local_200;
  undefined4 uStack_1ff;
  undefined1 local_1;
  
  local_200 = DAT_005ea438;
  puVar5 = &uStack_1ff;
  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  _strncpy(&local_200,param_1,0x1ff);
  uVar4 = 0xffffffff;
  local_1 = 0;
  pcVar2 = &local_200;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = &stack0xfffffdff + ~uVar4;
  if (&local_200 < pcVar2) {
    do {
      if (*pcVar2 == '.') {
        *pcVar2 = '\0';
        break;
      }
      pcVar2 = pcVar2 + -1;
    } while (&local_200 < pcVar2);
  }
  iVar3 = -1;
  pcVar2 = &local_200;
  do {
    pcVar6 = pcVar2;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar6;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar6 + -1) = DAT_005c5d24;
  pcVar6[3] = DAT_005c5d28;
  iVar3 = FUN_00568210(s_SeasonRaces_005d31c8);
  if (iVar3 == 0) {
    iVar3 = FUN_00567fb0(s_SeasonRaces_005d31c8,0,0,0);
  }
  FUN_00567f40(&local_200,iVar3);
  return;
}


