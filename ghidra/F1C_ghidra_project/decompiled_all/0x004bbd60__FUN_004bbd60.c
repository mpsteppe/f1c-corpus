// Function: FUN_004bbd60 @ 004bbd60
// Strings:  [%s %s, Stop/Go Penalty:, Stop/Go Penalty:]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004bbd60(int *param_1,char *param_2,undefined1 param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char local_140 [63];
  undefined1 local_101;
  char local_100 [63];
  undefined1 local_c1;
  undefined1 local_c0 [192];
  
  if (param_1[0xc] == 0) {
    if ((param_2 != (char *)0x0) && (*(int *)(*param_1 + 13000) == 0)) {
      iVar2 = FUN_00423a00(s_Stop_Go_Penalty__005d2574,&DAT_005ec4cc);
      if (iVar2 != 0) {
        iVar2 = 0;
        do {
          pcVar3 = s_Stop_Go_Penalty__005d2574 + iVar2;
          (&DAT_005ec4cc)[iVar2] = *pcVar3;
          iVar2 = iVar2 + 1;
        } while (*pcVar3 != '\0');
      }
      _strncpy(local_140,&DAT_005ec4cc,0x3f);
      local_101 = 0;
      iVar2 = FUN_00423a00(param_2,&DAT_005ec4cc);
      if (iVar2 != 0) {
        pcVar3 = param_2;
        do {
          cVar1 = *pcVar3;
          pcVar3[(int)&DAT_005ec4cc - (int)param_2] = cVar1;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
      }
      _strncpy(local_100,&DAT_005ec4cc,0x3f);
      local_c1 = 0;
      FUN_0058815f(local_c0,s__s__s_005c5d30,local_140,local_100);
      FUN_0045bd10(local_c0,3,0x1020304);
    }
    iVar2 = DAT_008aae64;
    if (DAT_0083ee60 < 0x3ff) {
      DAT_0083ee60 = DAT_0083ee60 + 1;
      DAT_008aae64 = DAT_008aae64 + 0x1b0;
    }
    FUN_004b33b0(4,0x17,1,param_1[1],(float)_DAT_008afea0,0);
    *(undefined1 *)(iVar2 + 8) = param_3;
    FUN_0041a720(*param_1,param_2);
  }
  return;
}


