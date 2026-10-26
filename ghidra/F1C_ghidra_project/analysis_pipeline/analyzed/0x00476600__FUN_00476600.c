// Function: FUN_00476600 @ 00476600
// Size (bytes): 91


undefined4 * __thiscall FUN_00476600(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_005a448c;
  if (param_1[0xf] != 0) {
    FUN_00587bcf(param_1[0xf]);
  }
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


