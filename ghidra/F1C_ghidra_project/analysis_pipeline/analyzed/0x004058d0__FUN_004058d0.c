// Function: FUN_004058d0 @ 004058d0
// Size (bytes): 47


undefined4 * __thiscall FUN_004058d0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_0059e4b4;
  if (param_1[1] != 0) {
    FUN_00587bcf(param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


