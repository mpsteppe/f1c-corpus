// Function: FUN_00448e50 @ 00448e50
// Size (bytes): 52


void __fastcall FUN_00448e50(int param_1)

{
  int iVar1;
  int *piVar2;
  
  do {
    FUN_00448e20();
    piVar2 = (int *)(param_1 + 0x4c);
    iVar1 = 4;
    do {
      if (*piVar2 != 0) {
        FUN_00448e50();
      }
      piVar2 = piVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    param_1 = *(int *)(param_1 + 0x5c);
  } while (param_1 != 0);
  return;
}


