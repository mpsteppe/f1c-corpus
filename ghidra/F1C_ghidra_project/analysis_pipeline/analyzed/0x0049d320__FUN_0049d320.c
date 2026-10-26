// Function: FUN_0049d320 @ 0049d320
// Size (bytes): 204


void __fastcall FUN_0049d320(uint param_1)

{
  char *pcVar1;
  int iVar2;
  uint local_4;
  
  local_4 = param_1;
  iVar2 = FUN_0049b8f0();
  if (iVar2 < 0) {
    iVar2 = FUN_00423a00(&DAT_005ccec4,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar1 = &DAT_005ccec4 + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar1;
        iVar2 = iVar2 + 1;
      } while (*pcVar1 != '\0');
    }
    _strncpy((char *)&local_4,&DAT_005ec4cc,3);
    local_4 = local_4 & 0xffffff;
  }
  else if (iVar2 == 0) {
    iVar2 = FUN_00423a00(&DAT_005c36fc,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar1 = &DAT_005c36fc + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar1;
        iVar2 = iVar2 + 1;
      } while (*pcVar1 != '\0');
    }
    _strncpy((char *)&local_4,&DAT_005ec4cc,3);
    local_4 = local_4 & 0xffffff;
  }
  else {
    FUN_0058815f(&local_4,&DAT_005c3280,iVar2);
  }
  FUN_00553070(&local_4,0x31,0x2b,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x54));
  return;
}


