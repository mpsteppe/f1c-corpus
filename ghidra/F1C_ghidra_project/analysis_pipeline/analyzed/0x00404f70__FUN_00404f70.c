// Function: FUN_00404f70 @ 00404f70
// Size (bytes): 40


int * __thiscall FUN_00404f70(int *param_1,byte param_2)

{
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


