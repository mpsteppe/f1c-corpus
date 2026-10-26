// Function: FUN_004bd760 @ 004bd760
// Size (bytes): 34


void __fastcall FUN_004bd760(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0xe0);
  do {
    if (*piVar2 == -1) {
      *(undefined4 *)(param_1 + 0xe0 + iVar1 * 4) = *(undefined4 *)(param_1 + 8);
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 10);
  return;
}


