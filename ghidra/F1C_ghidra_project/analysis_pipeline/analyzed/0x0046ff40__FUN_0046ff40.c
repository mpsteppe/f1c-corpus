// Function: FUN_0046ff40 @ 0046ff40
// Size (bytes): 57


undefined4 * __thiscall FUN_0046ff40(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_005a01a0;
  if (param_1[0x3b] != 0) {
    FUN_00587bcf(param_1[0x3b]);
  }
  FUN_0048feb0();
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


