// Function: FUN_00491f60 @ 00491f60
// Size (bytes): 70


undefined4 __fastcall FUN_00491f60(int *param_1)

{
  if (*param_1 != 0) {
    FUN_005355a0();
  }
  if (param_1[1] != 0) {
    FUN_00587d02(param_1[1]);
  }
  if (param_1[2] != 0) {
    FUN_00587d02(param_1[2]);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return 0;
}


