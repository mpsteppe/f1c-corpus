// Function: FUN_0044af20 @ 0044af20
// Size (bytes): 60


void FUN_0044af20(undefined4 *param_1,int *param_2)

{
  *param_1 = *(undefined4 *)*param_2;
  param_1[1] = *(undefined4 *)(*param_2 + 8);
  param_1[2] = *(undefined4 *)(param_2[1] + 8);
  param_1[3] = *(undefined4 *)(param_2[1] + 0x10);
  param_1[4] = *(undefined4 *)(param_2[2] + 0x10);
  param_1[5] = *(undefined4 *)param_2[2];
  return;
}


