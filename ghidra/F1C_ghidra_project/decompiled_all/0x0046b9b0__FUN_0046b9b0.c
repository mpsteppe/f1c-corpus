// Function: FUN_0046b9b0 @ 0046b9b0
// Strings:  [Loading Grid..., Loading Grid...]


void __fastcall FUN_0046b9b0(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  FUN_00489cb0();
  *(undefined4 *)(param_1 + 0x178) = 0xffffffff;
  if (DAT_007d0410 == 5) {
    iVar2 = FUN_00423a00(s_Loading_Grid____005c6aa0,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar1 = s_Loading_Grid____005c6aa0 + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar1;
        iVar2 = iVar2 + 1;
      } while (*pcVar1 != '\0');
    }
    FUN_00489600(&DAT_005ec4cc,&DAT_005ea438,&DAT_005ea438,&DAT_005ea438,0);
  }
  return;
}


