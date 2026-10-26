// Function: FUN_00567a30 @ 00567a30
// Size (bytes): 93


void __fastcall FUN_00567a30(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  FUN_00567f10();
  piVar3 = *(int **)(param_1 + 0x24);
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}


