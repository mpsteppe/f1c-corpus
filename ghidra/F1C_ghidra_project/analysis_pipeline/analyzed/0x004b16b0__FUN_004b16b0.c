// Function: FUN_004b16b0 @ 004b16b0
// Size (bytes): 203


void __fastcall FUN_004b16b0(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  
  pcVar2 = *(char **)(param_1 + 0x2d50);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  iVar4 = -1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar4 != -2) {
    puVar3 = *(undefined1 **)(param_1 + 0x2d50);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_004b1410(puVar3);
    FUN_00566650(&DAT_005ea438);
  }
  pcVar2 = *(char **)(param_1 + 0x2d6c);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  iVar4 = -1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar4 != -2) {
    puVar3 = *(undefined1 **)(param_1 + 0x2d5c);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    puVar3 = *(undefined1 **)(param_1 + 0x2d64);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    puVar3 = *(undefined1 **)(param_1 + 0x2d6c);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    FUN_00566650(&DAT_005ea438);
  }
  return;
}


