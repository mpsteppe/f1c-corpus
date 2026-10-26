// Function: FUN_004c54f0 @ 004c54f0
// Strings:  [%s.AIW, %s.SCN]


void FUN_004c54f0(void)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char local_80 [128];
  
  iVar1 = DAT_008ac48c * 0x18c + DAT_008ac490;
  pcVar3 = (char *)(iVar1 + 0x104);
  iVar4 = (int)&DAT_008ac398 - (int)pcVar3;
  do {
    cVar2 = *pcVar3;
    pcVar3[iVar4] = cVar2;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  pcVar3 = (char *)(iVar1 + 4);
  iVar1 = -(int)pcVar3;
  do {
    cVar2 = *pcVar3;
    pcVar3[(int)(local_80 + iVar1)] = cVar2;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  FUN_0058815f(&DAT_008ac3e8,s__s_SCN_005d31c0,local_80);
  FUN_0058815f(&DAT_008ac438,s__s_AIW_005d31b8,local_80);
  FUN_00566650(&DAT_008ac3e8);
  FUN_00566650(&DAT_008ac398);
  FUN_00566650(&DAT_008ac438);
  return;
}


