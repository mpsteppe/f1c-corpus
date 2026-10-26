// Function: FUN_005408f0 @ 005408f0
// Size (bytes): 69


void __thiscall FUN_005408f0(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x13e0) = 0;
    *(undefined4 *)(param_1 + 0x13dc) = 0;
    return;
  }
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0x13e0) = 1;
    *(undefined4 *)(param_1 + 0x13dc) = 1;
    return;
  }
  if (param_2 == 2) {
    *(undefined4 *)(param_1 + 0x13e0) = 2;
    *(undefined4 *)(param_1 + 0x13dc) = 1;
  }
  return;
}


