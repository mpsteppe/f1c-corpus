// Function: FUN_004874e0 @ 004874e0
// Size (bytes): 79


undefined4 FUN_004874e0(void)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int extraout_ECX;
  int iVar4;
  
  cVar1 = FUN_00486710();
  if (cVar1 != '\0') {
    return 0;
  }
  if (*(char *)(extraout_ECX + 0xe1) != '\0') {
    puVar2 = *(undefined1 **)(extraout_ECX + 0xa0);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    pcVar3 = (char *)FUN_0049a460(puVar2);
    if (pcVar3 != (char *)0x0) {
      iVar4 = -1;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (iVar4 == -2) {
        return 0;
      }
    }
  }
  return 1;
}


