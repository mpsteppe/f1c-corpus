// Function: FUN_004e0e70 @ 004e0e70
// Size (bytes): 83


void __thiscall FUN_004e0e70(int param_1,int param_2)

{
  int *piVar1;
  
  param_1 = param_2 * 0x128 + param_1;
  FUN_004e0d70(param_1 + 0x144);
  FUN_004e2230(param_2,0);
  piVar1 = (int *)(param_1 + 0x188);
  FUN_004e0d70(piVar1);
  if (*piVar1 != 0) {
    FUN_0054c030(0,0,0,0);
  }
  return;
}


