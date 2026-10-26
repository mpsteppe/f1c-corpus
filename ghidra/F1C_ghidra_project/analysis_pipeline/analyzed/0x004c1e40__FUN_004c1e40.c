// Function: FUN_004c1e40 @ 004c1e40
// Size (bytes): 56


int * __thiscall FUN_004c1e40(int *param_1,byte param_2)

{
  if (param_1[2] != 0) {
    FUN_00587bcf(param_1[2]);
  }
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


