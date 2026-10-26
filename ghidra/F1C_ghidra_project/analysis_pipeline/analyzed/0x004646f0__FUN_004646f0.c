// Function: FUN_004646f0 @ 004646f0
// Size (bytes): 43


undefined4 * __thiscall FUN_004646f0(undefined4 *param_1,byte param_2)

{
  if (*(char *)(param_1 + 2) != '\0') {
    FUN_00587bcf(*param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


