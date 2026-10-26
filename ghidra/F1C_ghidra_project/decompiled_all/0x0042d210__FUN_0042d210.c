// Function: FUN_0042d210 @ 0042d210
// Strings:  [PAUSED, PAUSED]


void __thiscall FUN_0042d210(int param_1,char param_2)

{
  char *pcVar1;
  int iVar2;
  
  *(char *)(param_1 + 0x10) = param_2;
  if (param_2 == '\0') {
    iVar2 = FUN_00423a00(s_PAUSED_005c35c8,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar1 = s_PAUSED_005c35c8 + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar1;
        iVar2 = iVar2 + 1;
      } while (*pcVar1 != '\0');
    }
    FUN_0045bde0(&DAT_005ec4cc,0);
  }
  return;
}


