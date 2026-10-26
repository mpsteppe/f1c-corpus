// Function: FUN_00558d80 @ 00558d80
// Size (bytes): 61


void __thiscall FUN_00558d80(int param_1,int param_2)

{
  if ((*(uint *)(param_1 + 0x20) & 0x100) != 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffeff;
    FUN_00540f90(*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x1c + param_2 * 0x40));
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x20 + param_2 * 0x40) = 0;
  }
  return;
}


