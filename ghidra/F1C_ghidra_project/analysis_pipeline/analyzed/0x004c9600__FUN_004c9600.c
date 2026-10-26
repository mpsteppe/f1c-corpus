// Function: FUN_004c9600 @ 004c9600
// Size (bytes): 42


undefined4 * __thiscall FUN_004c9600(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_005ace5c;
  FUN_004c9790();
  *param_1 = &PTR_LAB_005ace2c;
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


