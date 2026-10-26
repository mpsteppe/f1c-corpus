// Function: FUN_00415900 @ 00415900
// Size (bytes): 175


int * __thiscall FUN_00415900(int *param_1,byte param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_004149a0();
  piVar3 = param_1 + 0x2c;
  iVar2 = 2;
  do {
    piVar1 = piVar3 + -5;
    piVar3 = piVar3 + -5;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar3 = param_1 + 0x22;
  iVar2 = 2;
  do {
    piVar1 = piVar3 + -5;
    piVar3 = piVar3 + -5;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar3 = param_1 + 0x18;
  iVar2 = 2;
  do {
    piVar1 = piVar3 + -5;
    piVar3 = piVar3 + -5;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar3 = param_1 + 0xe;
  iVar2 = 2;
  do {
    piVar1 = piVar3 + -5;
    piVar3 = piVar3 + -5;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


