// Function: FUN_0045ebd0 @ 0045ebd0
// Size (bytes): 243


void __fastcall FUN_0045ebd0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int local_4;
  
  if ((0x40 < *(int *)(param_1 + 0x1b77c)) &&
     (local_4 = *(int *)(param_1 + 0x1b77c) + -0x40, 0 < local_4)) {
    do {
      piVar1 = *(int **)(param_1 + 0x1b770);
      if (piVar1 != (int *)0x0) {
        piVar2 = (int *)*piVar1;
        *(undefined1 *)(piVar1 + 2) = 0;
        if (piVar2 != (int *)0x0) {
          piVar4 = *(int **)(param_1 + 0x1b770);
          piVar1 = (int *)0x0;
          while (piVar3 = piVar4, piVar3 != (int *)0x0) {
            if ((int *)*piVar3 == piVar2) {
              if (piVar3 == *(int **)(param_1 + 0x1b778)) {
                *(int *)(param_1 + 0x1b778) = piVar3[1];
              }
              if (piVar1 == (int *)0x0) {
                *(int *)(param_1 + 0x1b770) = piVar3[1];
              }
              else {
                piVar1[1] = piVar3[1];
              }
              if (*(int **)(param_1 + 0x1b774) == piVar3) {
                *(int **)(param_1 + 0x1b774) = piVar1;
              }
              *(int *)(param_1 + 0x1b77c) = *(int *)(param_1 + 0x1b77c) + -1;
              if (((char)piVar3[2] != '\0') && (piVar1 = (int *)*piVar3, piVar1 != (int *)0x0)) {
                if (*piVar1 != 0) {
                  FUN_00587bcf(*piVar1);
                }
                FUN_00587bcf(piVar1);
              }
              FUN_00587bcf(piVar3);
              if (*piVar2 != 0) {
                FUN_00587bcf(*piVar2);
              }
              FUN_00587bcf(piVar2);
              break;
            }
            piVar1 = piVar3;
            piVar4 = (int *)piVar3[1];
          }
        }
      }
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}


