// Function: FUN_00448570 @ 00448570
// Size (bytes): 85


void __fastcall FUN_00448570(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x4c);
  iVar1 = 4;
  do {
    if (*piVar2 != 0) {
      FUN_00448570();
      FUN_00587bcf(*piVar2);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (*(int *)(param_1 + 0x5c) != 0) {
    FUN_00448570();
    FUN_00587bcf(*(undefined4 *)(param_1 + 0x5c));
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  return;
}


