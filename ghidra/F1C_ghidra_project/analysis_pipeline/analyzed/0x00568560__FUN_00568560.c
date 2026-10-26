// Function: FUN_00568560 @ 00568560
// Size (bytes): 70


void __fastcall FUN_00568560(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  
  if (param_1 != (char *)0x0) {
    cVar2 = *param_1;
    pcVar3 = param_1;
    while (cVar2 != '\0') {
      cVar2 = *pcVar3;
      if (('-' < cVar2) && ((cVar2 < '0' || (cVar2 == '\\')))) {
        *pcVar3 = '_';
      }
      pcVar1 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
      cVar2 = *pcVar1;
    }
    cVar2 = *param_1;
    while (cVar2 != '\0') {
      cVar2 = FUN_005685b0();
      if (cVar2 != '\0') {
        *param_1 = '-';
      }
      pcVar3 = param_1 + 1;
      param_1 = param_1 + 1;
      cVar2 = *pcVar3;
    }
  }
  return;
}


