// Function: FUN_00418d60 @ 00418d60
// Size (bytes): 64


int * __thiscall FUN_00418d60(int *param_1,byte param_2)

{
  int *piVar1;
  
  if (((char)param_1[2] != '\0') && (piVar1 = (int *)*param_1, piVar1 != (int *)0x0)) {
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    FUN_00587bcf(piVar1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


