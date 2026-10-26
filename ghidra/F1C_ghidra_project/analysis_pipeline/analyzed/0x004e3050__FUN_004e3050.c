// Function: FUN_004e3050 @ 004e3050
// Size (bytes): 56


void __fastcall FUN_004e3050(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 500);
  iVar2 = 4;
  do {
    piVar1[-1] = 0;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    *piVar1 = 0;
    piVar1 = piVar1 + 0x4a;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


