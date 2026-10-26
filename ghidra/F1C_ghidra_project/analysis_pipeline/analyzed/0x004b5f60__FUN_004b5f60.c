// Function: FUN_004b5f60 @ 004b5f60
// Size (bytes): 249


void __fastcall FUN_004b5f60(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x714);
  *(int **)(param_1 + 0x71c) = piVar2;
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    while (iVar1 != 0) {
      for (piVar2 = *(int **)(param_1 + 0x714); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
        if (*piVar2 == iVar1) {
          if (piVar2 == *(int **)(param_1 + 0x71c)) {
            *(int *)(param_1 + 0x71c) = piVar2[1];
          }
          if (piVar2[2] == 0) {
            *(int *)(param_1 + 0x714) = piVar2[1];
          }
          else {
            *(int *)(piVar2[2] + 4) = piVar2[1];
          }
          if (piVar2[1] != 0) {
            *(int *)(piVar2[1] + 8) = piVar2[2];
          }
          if (*(int **)(param_1 + 0x718) == piVar2) {
            *(int *)(param_1 + 0x718) = piVar2[2];
          }
          *(int *)(param_1 + 0x720) = *(int *)(param_1 + 0x720) + -1;
          if ((char)piVar2[3] != '\0') {
            FUN_00587bcf(*piVar2);
          }
          FUN_00587bcf(piVar2);
          break;
        }
      }
      FUN_004b4460();
      piVar2 = operator_new(0xc);
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        *piVar2 = iVar1;
        piVar2[1] = 0;
        *(undefined1 *)(piVar2 + 2) = 0;
      }
      if (*(int *)(param_1 + 0x30) == 0) {
        *(int **)(param_1 + 0x34) = piVar2;
        *(int **)(param_1 + 0x38) = piVar2;
      }
      else {
        piVar2[1] = *(int *)(param_1 + 0x30);
      }
      *(int **)(param_1 + 0x30) = piVar2;
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      if (*(int **)(param_1 + 0x71c) == (int *)0x0) {
        return;
      }
      iVar1 = **(int **)(param_1 + 0x71c);
    }
  }
  return;
}


