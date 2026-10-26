// Function: FUN_004998e0 @ 004998e0
// Size (bytes): 44


void FUN_004998e0(int param_1)

{
  int iVar1;
  undefined4 *extraout_ECX;
  
  FUN_00499850();
  extraout_ECX[3] = param_1;
  if (param_1 != 0) {
    *extraout_ECX = 0;
    iVar1 = *(int *)(param_1 + 0x1c);
    extraout_ECX[2] = iVar1;
    extraout_ECX[4] = 0;
    extraout_ECX[5] = 0;
    if (iVar1 == 0) {
      FUN_00499910();
    }
  }
  return;
}


