// Function: FUN_00460a10 @ 00460a10
// Strings:  [terrain.ini]


undefined4 __thiscall FUN_00460a10(int param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  undefined1 *puVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  char *pcVar8;
  char local_50 [79];
  undefined1 local_1;
  
  *(undefined1 *)(param_1 + 0x1b76a) = 0;
  *(undefined1 *)(param_1 + 0x1b76b) = 0;
  *(undefined1 *)(param_1 + 0x1b76c) = 0;
  *(undefined1 *)(param_1 + 0x1b76d) = 0;
  *(undefined1 *)(param_1 + 0x1b76e) = 0;
  sVar2 = FUN_00460770(*(undefined1 *)(param_1 + 0x1b754),*(undefined1 *)(param_1 + 0x1b755));
  if (sVar2 == *(short *)(param_2 + 8)) {
    *(undefined1 *)(param_1 + 0x1b76a) = 1;
  }
  if (((param_3 != 0) && (cVar1 = FUN_0045c320(param_3,&param_3), cVar1 != '\0')) &&
     (param_3 == *(int *)(param_2 + 0xc))) {
    *(undefined1 *)(param_1 + 0x1b76b) = 1;
  }
  cVar1 = FUN_0045c320(s_terrain_ini_005c5b88,&param_3);
  if ((cVar1 != '\0') &&
     (param_3 = param_3 + -0x543edc8a + DAT_008aced8, param_3 == *(int *)(param_2 + 0x10))) {
    *(undefined1 *)(param_1 + 0x1b76c) = 1;
  }
  pcVar8 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  uVar4 = 0xffffffff;
  pcVar5 = pcVar8;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  for (pcVar5 = pcVar8 + (~uVar4 - 1); pcVar8 < pcVar5; pcVar5 = pcVar5 + -1) {
    if (*pcVar5 == '\\') {
      pcVar5 = pcVar5 + 1;
      break;
    }
  }
  _strncpy(local_50,pcVar5,0x4f);
  uVar4 = 0xffffffff;
  local_1 = 0;
  pcVar8 = local_50;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  pcVar8 = local_50 + (~uVar4 - 1);
  if (local_50 < pcVar8) {
    do {
      if (*pcVar8 == '.') {
        *pcVar8 = '\0';
        break;
      }
      pcVar8 = pcVar8 + -1;
    } while (local_50 < pcVar8);
  }
  iVar6 = -1;
  pcVar8 = local_50;
  do {
    pcVar5 = pcVar8;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar5 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar5;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar5 + -1) = DAT_005c5d24;
  pcVar5[3] = DAT_005c5d28;
  cVar1 = FUN_0045c320(local_50,&param_3);
  if ((cVar1 != '\0') && (param_3 == *(int *)(param_2 + 0x14))) {
    *(undefined1 *)(param_1 + 0x1b76d) = 1;
  }
  puVar7 = DAT_007d0434;
  if (DAT_007d0434 == (undefined1 *)0x0) {
    puVar7 = &DAT_005ea438;
  }
  puVar3 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_0058969d(local_50,0x50,&DAT_005be860,puVar3,puVar7);
  local_1 = 0;
  cVar1 = FUN_0045c320(local_50,&param_3);
  if ((cVar1 != '\0') && (param_3 == *(int *)(param_2 + 0x18))) {
    *(undefined1 *)(param_1 + 0x1b76e) = 1;
  }
  if ((((*(char *)(param_1 + 0x1b76a) != '\0') && (*(char *)(param_1 + 0x1b76b) != '\0')) &&
      (*(char *)(param_1 + 0x1b76c) != '\0')) &&
     ((*(char *)(param_1 + 0x1b76d) != '\0' && (*(char *)(param_1 + 0x1b76e) != '\0')))) {
    return 1;
  }
  return 0;
}


