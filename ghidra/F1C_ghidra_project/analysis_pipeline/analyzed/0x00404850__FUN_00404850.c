// Function: FUN_00404850 @ 00404850
// Size (bytes): 56


void __fastcall FUN_00404850(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  
  pcVar2 = *(char **)(param_1 + 0x38);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  iVar3 = -1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    puVar4 = *(undefined1 **)(param_1 + 0x38);
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_004b04e0(puVar4,1);
  }
  return;
}


