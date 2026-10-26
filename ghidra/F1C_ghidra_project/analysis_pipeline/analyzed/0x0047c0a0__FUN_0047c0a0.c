// Function: FUN_0047c0a0 @ 0047c0a0
// Size (bytes): 36


void FUN_0047c0a0(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = FUN_00489920();
  if (iVar2 != 0) {
    pcVar3 = (char *)FUN_00489920();
    pcVar4 = &DAT_007cd880;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  return;
}


