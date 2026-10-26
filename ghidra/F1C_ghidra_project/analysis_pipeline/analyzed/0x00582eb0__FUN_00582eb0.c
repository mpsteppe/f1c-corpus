// Function: FUN_00582eb0 @ 00582eb0
// Size (bytes): 122


int __fastcall FUN_00582eb0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)*param_1;
  param_1[2] = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    *(undefined1 *)(piVar1 + 2) = 0;
    if (iVar2 != 0) {
      piVar1 = (int *)0x0;
      for (piVar3 = (int *)*param_1; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[1]) {
        if (*piVar3 == iVar2) {
          if (piVar3 == (int *)param_1[2]) {
            param_1[2] = piVar3[1];
          }
          if (piVar1 == (int *)0x0) {
            *param_1 = piVar3[1];
          }
          else {
            piVar1[1] = piVar3[1];
          }
          if ((int *)param_1[1] == piVar3) {
            param_1[1] = (int)piVar1;
          }
          param_1[3] = param_1[3] + -1;
          if (((char)piVar3[2] != '\0') && (*piVar3 != 0)) {
            FUN_00587bcf(*piVar3);
          }
          FUN_00587bcf(piVar3);
          return iVar2;
        }
        piVar1 = piVar3;
      }
    }
  }
  return 0;
}


