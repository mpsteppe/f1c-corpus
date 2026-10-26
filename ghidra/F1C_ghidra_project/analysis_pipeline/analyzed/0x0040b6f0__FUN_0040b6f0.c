// Function: FUN_0040b6f0 @ 0040b6f0
// Size (bytes): 24


void __thiscall FUN_0040b6f0(int *param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < param_1[4])) {
    param_1[5] = param_2;
    (**(code **)(*param_1 + 0x10))();
  }
  return;
}


