// Function: FUN_00476080 @ 00476080
// Size (bytes): 69


undefined4 * __thiscall FUN_00476080(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_005a4450;
  if (param_1[0xc] != 0) {
    FUN_00587bcf(param_1[0xc]);
  }
  *param_1 = &PTR_FUN_005a443c;
  if (param_1[1] != 0) {
    FUN_00587bcf(param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


