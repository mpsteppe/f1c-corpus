// Function: FUN_00564690 @ 00564690
// Size (bytes): 53


void __fastcall FUN_00564690(char *param_1)

{
  char cVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_1 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    pvVar2 = _malloc(~uVar3);
    if (pvVar2 != (void *)0x0) {
      iVar4 = (int)pvVar2 - (int)param_1;
      do {
        cVar1 = *param_1;
        param_1[iVar4] = cVar1;
        param_1 = param_1 + 1;
      } while (cVar1 != '\0');
    }
  }
  return;
}


