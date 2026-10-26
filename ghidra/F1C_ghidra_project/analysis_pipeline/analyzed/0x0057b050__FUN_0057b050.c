// Function: FUN_0057b050 @ 0057b050
// Size (bytes): 114


undefined4 __thiscall FUN_0057b050(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  uVar2 = 0;
  if (param_2 != 0) {
    piVar3 = (int *)0x0;
    piVar4 = *(int **)(param_1 + 8);
    if (*(int **)(param_1 + 8) != (int *)0x0) {
      while (*piVar4 != param_2) {
        piVar1 = piVar4 + 1;
        piVar3 = piVar4;
        piVar4 = (int *)*piVar1;
        if ((int *)*piVar1 == (int *)0x0) {
          return uVar2;
        }
      }
      if (piVar4 == *(int **)(param_1 + 0x10)) {
        *(int *)(param_1 + 0x10) = piVar4[1];
      }
      if (piVar3 == (int *)0x0) {
        *(int *)(param_1 + 8) = piVar4[1];
      }
      else {
        piVar3[1] = piVar4[1];
      }
      if (*(int **)(param_1 + 0xc) == piVar4) {
        *(int **)(param_1 + 0xc) = piVar3;
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      if ((char)piVar4[2] != '\0') {
        FUN_00587bcf(*piVar4);
      }
      FUN_00587bcf(piVar4);
      uVar2 = 1;
    }
  }
  return uVar2;
}


