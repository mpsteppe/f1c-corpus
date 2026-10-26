// Function: FUN_004b20d0 @ 004b20d0
// Size (bytes): 39


void __thiscall FUN_004b20d0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  if (*(int *)(param_1 + 0x14) < *(int *)(param_1 + 0x1c)) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x1c);
    return;
  }
  if (*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x20);
  }
  return;
}


