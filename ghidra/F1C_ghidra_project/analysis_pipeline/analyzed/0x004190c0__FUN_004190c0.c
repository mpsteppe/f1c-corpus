// Function: FUN_004190c0 @ 004190c0
// Size (bytes): 85


void __fastcall FUN_004190c0(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x1a0);
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[2] != '\0') && (*piVar2 != 0)) {
      FUN_00587bcf(*piVar2);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  return;
}


