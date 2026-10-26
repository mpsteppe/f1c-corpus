// Function: FUN_004a4050 @ 004a4050
// Size (bytes): 71


void __thiscall FUN_004a4050(int param_1,float param_2)

{
  if (*(int *)(param_1 + 0x78) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x78) == 1) {
    *(undefined4 *)(param_1 + 0x84) = 0;
    FUN_004a2840();
    return;
  }
  *(float *)(param_1 + 0x84) = param_2 + *(float *)(param_1 + 0x84);
  FUN_004a2840();
  return;
}


