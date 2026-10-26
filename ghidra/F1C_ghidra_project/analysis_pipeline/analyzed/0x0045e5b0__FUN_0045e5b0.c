// Function: FUN_0045e5b0 @ 0045e5b0
// Size (bytes): 26


int __fastcall FUN_0045e5b0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x1d4);
  do {
    if (*piVar2 == -1) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x68);
  return -1;
}


