// Function: FUN_0049c700 @ 0049c700
// Strings:  [FUEL:, FUEL:]


undefined4 FUN_0049c700(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = PTR_DAT_005ccbd8;
  iVar2 = FUN_00423a00(PTR_DAT_005ccbd8,&DAT_005ec4cc);
  if (iVar2 != 0) {
    if (pcVar3 == (undefined *)0x0) {
      DAT_005ec4cc = 0;
    }
    else {
      iVar2 = (int)&DAT_005ec4cc - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    }
  }
  _strncpy(param_1,&DAT_005ec4cc,param_2 - 1U);
  param_1[param_2 - 1U] = '\0';
  return 0;
}


