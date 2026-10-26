// Function: FUN_004618d0 @ 004618d0
// Size (bytes): 37


char * __fastcall FUN_004618d0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = param_1 + (~uVar3 - 1);
  if (param_1 < pcVar2) {
    while (*pcVar2 != '\\') {
      pcVar2 = pcVar2 + -1;
      if (pcVar2 <= param_1) {
        return pcVar2;
      }
    }
    pcVar2 = pcVar2 + 1;
  }
  return pcVar2;
}


