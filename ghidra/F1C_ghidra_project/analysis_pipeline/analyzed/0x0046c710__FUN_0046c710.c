// Function: FUN_0046c710 @ 0046c710
// Size (bytes): 58


int __fastcall FUN_0046c710(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (*(char *)(param_1 + 0x174) == '\0') {
    piVar2 = &DAT_007cd470;
    do {
      if (*piVar2 < 0) {
        return iVar1;
      }
      piVar2 = piVar2 + 1;
      iVar1 = iVar1 + 1;
    } while ((int)piVar2 < 0x7cd610);
  }
  else {
    piVar2 = &DAT_007cd2b8;
    while (-1 < *piVar2) {
      piVar2 = piVar2 + 1;
      iVar1 = iVar1 + 1;
      if (0x7cd457 < (int)piVar2) {
        return iVar1;
      }
    }
  }
  return iVar1;
}


