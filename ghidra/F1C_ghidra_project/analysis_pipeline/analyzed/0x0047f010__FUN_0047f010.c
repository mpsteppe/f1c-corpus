// Function: FUN_0047f010 @ 0047f010
// Size (bytes): 109


undefined4 FUN_0047f010(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar2 = (char *)FUN_00462e00();
  if (pcVar2 != (char *)0x0) {
    iVar3 = -1;
    pcVar4 = pcVar2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar3 != -2) {
      iVar3 = FUN_00423a00(pcVar2,&DAT_005ec4cc);
      if (iVar3 != 0) {
        iVar3 = (int)&DAT_005ec4cc - (int)pcVar2;
        do {
          cVar1 = *pcVar2;
          pcVar2[iVar3] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
      }
      FUN_00488b40(&DAT_005ec4cc);
      return 0;
    }
  }
  FUN_00488b40(&DAT_005ea438);
  return 0;
}


