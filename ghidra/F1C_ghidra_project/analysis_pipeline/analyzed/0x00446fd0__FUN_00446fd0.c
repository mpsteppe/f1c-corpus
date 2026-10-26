// Function: FUN_00446fd0 @ 00446fd0
// Size (bytes): 297


void __thiscall
FUN_00446fd0(int param_1,int param_2,double *param_3,undefined4 param_4,undefined4 param_5)

{
  FUN_004361d0(*(int *)(param_1 + 0x15f0) + 4,*(int *)(param_2 * 0x464 + 1000 + param_1) + 4,param_3
              );
  *param_3 = *param_3 - *(double *)(param_1 + 0x15fc);
  param_3[1] = param_3[1] - *(double *)(param_1 + 0x1604);
  param_3[2] = param_3[2] - *(double *)(param_1 + 0x160c);
  FUN_0056c740(param_4);
  FUN_0056c740(param_5);
  return;
}


