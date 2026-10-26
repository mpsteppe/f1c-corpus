// Function: FUN_004bbc60 @ 004bbc60
// Strings:  [%s %s, Warning:, Warning:]


void __thiscall FUN_004bbc60(int *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char local_140 [63];
  undefined1 local_101;
  char local_100 [63];
  undefined1 local_c1;
  undefined1 local_c0 [192];
  
  if (((param_1[0xc] == 0) && (param_2 != (char *)0x0)) && (*(int *)(*param_1 + 13000) == 0)) {
    iVar3 = FUN_00423a00(s_Warning__005d2568,&DAT_005ec4cc);
    if (iVar3 != 0) {
      iVar3 = 0;
      do {
        pcVar1 = s_Warning__005d2568 + iVar3;
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
    FUN_0045bd10(local_c0,3,0x1020304);
  }
  return;
}


