// Function: FUN_0048fd80 @ 0048fd80
// Size (bytes): 47


undefined4 * __thiscall FUN_0048fd80(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_005a443c;
  if (param_1[1] != 0) {
    FUN_00587bcf(param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


