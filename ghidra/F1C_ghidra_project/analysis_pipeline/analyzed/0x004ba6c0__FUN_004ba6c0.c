// Function: FUN_004ba6c0 @ 004ba6c0
// Size (bytes): 119


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ba6c0(int *param_1)

{
  char cVar1;
  
  if (*param_1 == 1) {
    if (DAT_007c56ac == '\0') {
      FUN_004b9870(&DAT_0083ee60,&DAT_005ec6d8,(float)_DAT_008afea0);
    }
    cVar1 = FUN_00461db0();
    if ((cVar1 == '\0') && (DAT_007cc4c8 != 0)) {
      FUN_004b9890((float)DAT_007d0080,param_1);
    }
  }
  else if (*param_1 == 2) {
    cVar1 = FUN_004b9a00();
    if (cVar1 == '\0') {
      FUN_004cfcc0();
      return;
    }
  }
  return;
}


