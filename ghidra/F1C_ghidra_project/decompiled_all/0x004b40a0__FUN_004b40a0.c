// Function: FUN_004b40a0 @ 004b40a0
// Strings:  [Screen Saved, Screen Saved]


void FUN_004b40a0(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  
  iVar4 = 0;
  if (0 < DAT_007cb218) {
    psVar5 = &DAT_007cb21c;
    do {
      if (*psVar5 == 0x58) {
        puVar2 = DAT_005ec478;
        if (DAT_005ec478 == (undefined1 *)0x0) {
          puVar2 = &DAT_005ea438;
        }
        iVar3 = FUN_00551fd0(0,0,DAT_008b8dd4,DAT_008b8dd8,puVar2);
        if (iVar3 == 0) {
          iVar3 = FUN_00423a00(s_Screen_Saved_005d240c,&DAT_005ec4cc);
          if (iVar3 != 0) {
            iVar3 = 0;
            do {
              pcVar1 = s_Screen_Saved_005d240c + iVar3;
              (&DAT_005ec4cc)[iVar3] = *pcVar1;
              iVar3 = iVar3 + 1;
            } while (*pcVar1 != '\0');
          }
          FUN_0045bd10(&DAT_005ec4cc,3,0x1020304);
        }
      }
      iVar4 = iVar4 + 1;
      psVar5 = psVar5 + 1;
    } while (iVar4 < DAT_007cb218);
  }
  FUN_004fbd70();
  FUN_004b3dc0();
  FUN_00557120();
  return;
}


