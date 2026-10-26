// Function: FUN_004c9060 @ 004c9060
// Size (bytes): 42


undefined4 * __thiscall FUN_004c9060(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_005ace3c;
  FUN_004c91d0();
  *param_1 = &PTR_LAB_005ace2c;
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


