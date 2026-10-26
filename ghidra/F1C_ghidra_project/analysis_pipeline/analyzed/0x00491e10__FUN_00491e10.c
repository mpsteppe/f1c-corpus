// Function: FUN_00491e10 @ 00491e10
// Size (bytes): 47


int * __thiscall FUN_00491e10(int *param_1,byte param_2)

{
  if (((char)param_1[2] != '\0') && (*param_1 != 0)) {
    FUN_00587bcf(*param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


