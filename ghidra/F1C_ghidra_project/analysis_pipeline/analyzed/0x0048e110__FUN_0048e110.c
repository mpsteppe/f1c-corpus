// Function: FUN_0048e110 @ 0048e110
// Size (bytes): 310


undefined4 __fastcall FUN_0048e110(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  char local_80 [128];
  
  piVar1 = (int *)(param_1 + 0xe0);
  if (*(int *)(param_1 + 0xe0) != 0) {
    FUN_00551f80(*(int *)(param_1 + 0xe0));
    *piVar1 = 0;
  }
  puVar3 = *(undefined1 **)(param_1 + 0xb0);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  uVar4 = FUN_00551f10(piVar1,puVar3,0,0);
  *(undefined4 *)(param_1 + 0xe4) = uVar4;
  puVar3 = *(undefined1 **)(param_1 + 0xb0);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_00566650(puVar3);
  if (*(int *)(param_1 + 0xe4) != 0) {
    puVar3 = *(undefined1 **)(param_1 + 0xb0);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    pcVar5 = DAT_005ec3f0;
    if (DAT_005ec3f0 == (char *)0x0) {
      pcVar5 = &DAT_005ea438;
    }
    iVar7 = -(int)pcVar5;
    do {
      cVar2 = *pcVar5;
      pcVar5[(int)(local_80 + iVar7)] = cVar2;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    pcVar5 = *(char **)(param_1 + 0xb0);
    if (pcVar5 == (char *)0x0) {
      pcVar5 = &DAT_005ea438;
    }
    uVar6 = 0xffffffff;
    do {
      pcVar10 = pcVar5;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar10 = pcVar5 + 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar10;
    } while (cVar2 != '\0');
    uVar6 = ~uVar6;
    iVar7 = -1;
    pcVar5 = local_80;
    do {
      pcVar9 = pcVar5;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar9 = pcVar5 + 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar9;
    } while (cVar2 != '\0');
    pcVar5 = pcVar10 + -uVar6;
    pcVar10 = pcVar9 + -1;
    for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar10 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar10 = pcVar10 + 1;
    }
    uVar4 = FUN_00551f10(piVar1,local_80,0,0);
    *(undefined4 *)(param_1 + 0xe4) = uVar4;
    if (*piVar1 != 0) {
      FUN_00551eb0(DAT_007cf2cc);
    }
  }
  return 0;
}


