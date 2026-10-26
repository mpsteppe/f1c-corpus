// Function: FUN_004f8f10 @ 004f8f10
// Size (bytes): 60


void __thiscall FUN_004f8f10(int *param_1,int param_2)

{
  if (*param_1 != 0) {
    param_1[1] = param_2;
    FUN_00556440();
    param_1[3] = 0;
    if (param_2 == 0) {
      FUN_0053d1d0();
      return;
    }
  }
  return;
}


