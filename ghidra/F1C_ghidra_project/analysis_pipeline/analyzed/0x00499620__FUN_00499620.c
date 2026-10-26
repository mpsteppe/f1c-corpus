// Function: FUN_00499620 @ 00499620
// Size (bytes): 43


undefined4 * __thiscall FUN_00499620(undefined4 *param_1,byte param_2)

{
  if (*(char *)(param_1 + 3) != '\0') {
    FUN_00587bcf(*param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


