// Function: FUN_004c8f80 @ 004c8f80
// Size (bytes): 55


undefined4 __thiscall FUN_004c8f80(int *param_1,int param_2)

{
  float *pfVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 != 0) {
    pfVar1 = (float *)(param_1 + 3);
    param_1[1] = param_2;
    FUN_0054b950(param_1 + 2,pfVar1,param_1 + 4);
    *pfVar1 = -*pfVar1;
    uVar2 = (**(code **)(*param_1 + 4))();
  }
  return uVar2;
}


