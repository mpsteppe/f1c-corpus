// Function: FUN_0041ef00 @ 0041ef00
// Size (bytes): 56


undefined4 __fastcall FUN_0041ef00(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    FUN_004c2850();
    iVar1 = FUN_004c11d0();
    if (-1 < iVar1) {
      piVar2 = (int *)(param_1 + 0xd8 + iVar1 * 4);
      do {
        if (*piVar2 == 10) {
          return 1;
        }
        iVar1 = iVar1 + -1;
        piVar2 = piVar2 + -1;
      } while (-1 < iVar1);
    }
  }
  return 0;
}


