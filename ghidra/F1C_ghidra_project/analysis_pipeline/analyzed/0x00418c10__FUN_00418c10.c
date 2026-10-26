// Function: FUN_00418c10 @ 00418c10
// Size (bytes): 215


int * __thiscall FUN_00418c10(int *param_1,byte param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if (((char)param_1[2] != '\0') && (piVar2 = (int *)*param_1, piVar2 != (int *)0x0)) {
    FUN_00414d70();
    piVar4 = piVar2 + 0x2b;
    iVar3 = 2;
    do {
      piVar1 = piVar4 + -5;
      piVar4 = piVar4 + -5;
      if (*piVar1 != 0) {
        FUN_00587bcf(*piVar1);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    piVar4 = piVar2 + 0x21;
    iVar3 = 2;
    do {
      piVar1 = piVar4 + -5;
      piVar4 = piVar4 + -5;
      if (*piVar1 != 0) {
        FUN_00587bcf(*piVar1);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    piVar4 = piVar2 + 0x17;
    iVar3 = 2;
    do {
      piVar1 = piVar4 + -5;
      piVar4 = piVar4 + -5;
      if (*piVar1 != 0) {
        FUN_00587bcf(*piVar1);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    piVar4 = piVar2 + 0xd;
    iVar3 = 2;
    do {
      piVar1 = piVar4 + -5;
      piVar4 = piVar4 + -5;
      if (*piVar1 != 0) {
        FUN_00587bcf(*piVar1);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (*piVar2 != 0) {
      FUN_00587bcf(*piVar2);
    }
    FUN_00587bcf(piVar2);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


