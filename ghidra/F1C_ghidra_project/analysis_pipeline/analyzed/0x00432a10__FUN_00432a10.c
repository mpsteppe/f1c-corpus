// Function: FUN_00432a10 @ 00432a10
// Size (bytes): 73


uint __fastcall FUN_00432a10(int *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar4 = *(char **)(*param_1 + 8);
  if (pcVar4 == (char *)0x0) {
    pcVar4 = &DAT_005ea438;
  }
  uVar3 = 0xffffffff;
  pcVar2 = (char *)0x0;
  pcVar5 = pcVar4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar3 - 1)) {
    pcVar2 = pcVar4 + (~uVar3 - 2);
    if (*pcVar2 == '\\') {
      pcVar2 = pcVar2 + -1;
    }
    if (pcVar4 < pcVar2) {
      while (*pcVar2 != '\\') {
        pcVar2 = pcVar2 + -1;
        if (pcVar2 <= pcVar4) {
          *pcVar2 = '\0';
          return (uint)pcVar2 & 0xffffff00;
        }
      }
      pcVar2 = pcVar2 + 1;
    }
    *pcVar2 = '\0';
  }
  return (uint)pcVar2 & 0xffffff00;
}


