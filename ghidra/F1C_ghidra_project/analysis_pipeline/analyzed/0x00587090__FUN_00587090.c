// Function: FUN_00587090 @ 00587090
// Size (bytes): 55


undefined4 * __thiscall FUN_00587090(undefined4 *param_1,int param_2)

{
  FUN_00587490(param_2 + 4);
  param_1[4] = *(undefined4 *)(param_2 + 0x10);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  *(undefined1 *)(param_1 + 6) = *(undefined1 *)(param_2 + 0x18);
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *param_1 = &PTR_FUN_005b8c30;
  return param_1;
}


