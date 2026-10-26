// Function: FUN_00499b80 @ 00499b80
// Size (bytes): 48


void __thiscall FUN_00499b80(undefined4 *param_1,int param_2)

{
  param_1[8] = param_2;
  *param_1 = 0;
  param_1[2] = 0;
  if (param_2 != 0) {
    param_1[1] = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x1c);
    param_1[3] = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x20);
    return;
  }
  param_1[1] = 0;
  param_1[3] = 0;
  return;
}


