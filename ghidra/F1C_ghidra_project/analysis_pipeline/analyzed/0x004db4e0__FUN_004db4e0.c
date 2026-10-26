// Function: FUN_004db4e0 @ 004db4e0
// Size (bytes): 53


undefined4 * __thiscall FUN_004db4e0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_005ad0dc;
  if (param_1[4] != 0) {
    FUN_00587bcf(param_1[4]);
  }
  *param_1 = &PTR_LAB_005ad06c;
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


