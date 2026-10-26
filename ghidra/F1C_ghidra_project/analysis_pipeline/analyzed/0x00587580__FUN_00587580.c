// Function: FUN_00587580 @ 00587580
// Size (bytes): 50


undefined4 __thiscall FUN_00587580(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if ((int)param_1[1] < 1) {
    *param_2 = 0;
    *param_3 = 0;
    return 0;
  }
  *param_2 = *param_1;
  *param_3 = param_1[2];
  return 1;
}


