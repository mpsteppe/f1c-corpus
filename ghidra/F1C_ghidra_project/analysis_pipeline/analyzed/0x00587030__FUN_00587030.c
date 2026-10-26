// Function: FUN_00587030 @ 00587030
// Size (bytes): 50


undefined4 * __thiscall
FUN_00587030(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4)

{
  FUN_00587460(0);
  param_1[4] = param_4;
  param_1[5] = param_2;
  *(undefined1 *)(param_1 + 6) = param_3;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *param_1 = &PTR_FUN_005b8c30;
  return param_1;
}


