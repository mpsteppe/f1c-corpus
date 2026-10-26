// Function: FUN_004c69e0 @ 004c69e0
// Size (bytes): 45


char * __fastcall FUN_004c69e0(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  
  pcVar1 = (char *)(param_1 + 0x4714);
  uVar4 = 0xffffffff;
  pcVar3 = pcVar1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  pcVar3 = pcVar1 + (~uVar4 - 1);
  if (pcVar1 < pcVar3) {
    while (*pcVar3 != '\\') {
      pcVar3 = pcVar3 + -1;
      if (pcVar3 <= pcVar1) {
        return pcVar3;
      }
    }
    pcVar3 = pcVar3 + 1;
  }
  return pcVar3;
}


