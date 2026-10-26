// Function: FUN_004c0850 @ 004c0850
// Size (bytes): 190


void __fastcall FUN_004c0850(undefined4 *param_1)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 0x6c) != '\0') {
    puVar2 = (undefined1 *)param_1[2];
    iVar5 = param_1[0x69] * 0x48c0 + DAT_007d2e48;
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_004c3f80(puVar2);
    FUN_004c78f0(DAT_008ac38c);
    pcVar3 = (char *)*param_1;
    if (pcVar3 == (char *)0x0) {
      pcVar3 = &DAT_005ea438;
    }
    pcVar4 = (char *)(iVar5 + 0x4620);
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar3 = (char *)param_1[2];
    if (pcVar3 == (char *)0x0) {
      pcVar3 = &DAT_005ea438;
    }
    pcVar4 = (char *)(iVar5 + 0x4714);
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_004bc2f0(param_1[0x6a] + 1);
    FUN_004ef5a0(param_1[0x6b],0);
    *(int *)(iVar5 + 0x4058) = param_1[0x6a] + 1;
  }
  return;
}


