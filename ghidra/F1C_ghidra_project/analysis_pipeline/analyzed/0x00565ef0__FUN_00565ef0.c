// Function: FUN_00565ef0 @ 00565ef0
// Size (bytes): 46


char * FUN_00565ef0(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  pcVar2 = (char *)FUN_005662d0();
  pcVar3 = (char *)0x0;
  if (pcVar2 != (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar3 = pcVar2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = pcVar2 + (~uVar4 - 1);
    if (pcVar2 < pcVar3) {
      while (*pcVar3 != '\\') {
        pcVar3 = pcVar3 + -1;
        if (pcVar3 <= pcVar2) {
          return pcVar3;
        }
      }
      pcVar3 = pcVar3 + 1;
    }
  }
  return pcVar3;
}


