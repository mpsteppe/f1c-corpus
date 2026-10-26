// Function: FUN_00433e60 @ 00433e60
// Size (bytes): 77


int * __thiscall FUN_00433e60(int *param_1,byte param_2)

{
  FUN_00432cc0();
  if (param_1[5] != 0) {
    FUN_00587bcf(param_1[5]);
  }
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


