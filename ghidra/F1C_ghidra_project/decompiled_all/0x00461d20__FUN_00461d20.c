// Function: FUN_00461d20 @ 00461d20
// Strings:  [You have been booted, You have been booted]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00461d20(int *param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = FUN_00461cd0();
  if ((0 < iVar2) && (iVar2 < 4)) {
    *(float *)(*param_1 + 0x380) = *(float *)(*param_1 + 0x380) - (float)_DAT_008afe90;
    iVar2 = FUN_0057a900();
    if ((iVar2 == 0) && (*(char *)(*param_1 + 0x30) == '\0')) {
      iVar2 = FUN_00423a00(s_You_have_been_booted_005c5d54,&DAT_005ec4cc);
      if (iVar2 != 0) {
        iVar2 = 0;
        do {
          pcVar1 = s_You_have_been_booted_005c5d54 + iVar2;
          (&DAT_005ec4cc)[iVar2] = *pcVar1;
          iVar2 = iVar2 + 1;
        } while (*pcVar1 != '\0');
      }
      FUN_0045bd10(&DAT_005ec4cc,3,0x1020304);
      *(undefined1 *)(*param_1 + 0x30) = 1;
    }
  }
  return;
}


