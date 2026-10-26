// Function: FUN_004e0e20 @ 004e0e20
// Size (bytes): 69


void __thiscall FUN_004e0e20(int param_1,int param_2)

{
  int *piVar1;
  
  param_1 = param_2 * 0x128 + param_1;
  FUN_004e0d00(param_1 + 0x144);
  piVar1 = (int *)(param_1 + 0x188);
  FUN_004e0d00(piVar1);
  if (*piVar1 != 0) {
    FUN_0054c030(1,1,0,0);
  }
  return;
}


