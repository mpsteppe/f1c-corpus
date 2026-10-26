// Function: FUN_004bc2f0 @ 004bc2f0
// Size (bytes): 38


void __thiscall FUN_004bc2f0(undefined4 *param_1,int param_2)

{
  if (param_1[0xb] != param_2) {
    FUN_00419120(*param_1,param_1[0xb],param_2);
    param_1[0xb] = param_2;
  }
  return;
}


