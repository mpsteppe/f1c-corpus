// Function: FUN_004bba90 @ 004bba90
// Strings:  [%s %s, Penalty:, Penalty:, %s%d %s, Fined US$, Fined US$]


void __thiscall FUN_004bba90(int *param_1,char *param_2,float param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  char local_140 [63];
  undefined1 local_101;
  char local_100 [63];
  undefined1 local_c1;
  undefined1 local_c0 [192];
  
  if (param_1[0xc] == 0) {
    if ((param_2 != (char *)0x0) && (*(int *)(*param_1 + 13000) == 0)) {
      if (DAT_007d0b10 == '\0') {
        iVar3 = FUN_00423a00(s_Penalty__005d2548,&DAT_005ec4cc);
        if (iVar3 != 0) {
          iVar3 = 0;
          do {
            pcVar1 = s_Penalty__005d2548 + iVar3;
            (&DAT_005ec4cc)[iVar3] = *pcVar1;
            iVar3 = iVar3 + 1;
          } while (*pcVar1 != '\0');
        }
        _strncpy(local_140,&DAT_005ec4cc,0x3f);
        local_101 = 0;
        iVar3 = FUN_00423a00(param_2,&DAT_005ec4cc);
        if (iVar3 != 0) {
          iVar3 = (int)&DAT_005ec4cc - (int)param_2;
          do {
            cVar2 = *param_2;
            param_2[iVar3] = cVar2;
            param_2 = param_2 + 1;
          } while (cVar2 != '\0');
        }
        _strncpy(local_100,&DAT_005ec4cc,0x3f);
        local_c1 = 0;
        FUN_0058815f(local_c0,s__s__s_005c5d30,local_140,local_100);
      }
      else {
        iVar3 = FUN_00423a00(s_Fined_US__005d255c,&DAT_005ec4cc);
        if (iVar3 != 0) {
          iVar3 = 0;
          do {
            pcVar1 = s_Fined_US__005d255c + iVar3;
            (&DAT_005ec4cc)[iVar3] = *pcVar1;
            iVar3 = iVar3 + 1;
          } while (*pcVar1 != '\0');
        }
        _strncpy(local_140,&DAT_005ec4cc,0x3f);
        local_101 = 0;
        iVar3 = FUN_00423a00(param_2,&DAT_005ec4cc);
        if (iVar3 != 0) {
          iVar3 = (int)&DAT_005ec4cc - (int)param_2;
          do {
            cVar2 = *param_2;
            param_2[iVar3] = cVar2;
            param_2 = param_2 + 1;
          } while (cVar2 != '\0');
        }
        _strncpy(local_100,&DAT_005ec4cc,0x3f);
        local_c1 = 0;
        uVar4 = __ftol(local_100);
        FUN_0058815f(local_c0,s__s_d__s_005d2554,local_140,uVar4);
      }
      FUN_0045bd10(local_c0,3,0x1020304);
    }
    param_1[0x29] = (int)(param_3 + (float)param_1[0x29]);
  }
  return;
}


