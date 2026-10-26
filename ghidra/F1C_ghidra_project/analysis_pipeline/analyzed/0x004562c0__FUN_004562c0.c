// Function: FUN_004562c0 @ 004562c0
// Size (bytes): 47


undefined4 * __thiscall FUN_004562c0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_0059efcc;
  if (param_1[1] != 0) {
    FUN_00587bcf(param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


