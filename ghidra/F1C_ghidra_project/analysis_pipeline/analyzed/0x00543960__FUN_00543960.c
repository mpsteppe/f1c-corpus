// Function: FUN_00543960 @ 00543960
// Size (bytes): 139


void __thiscall FUN_00543960(int param_1,int param_2)

{
  if (param_2 == 0x20000) {
    *(undefined4 *)(param_1 + 0x19c) = 0x20000;
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10000;
    return;
  }
  if (param_2 != 0x40000) {
    if (param_2 != 0x80000) {
      *(undefined4 *)(param_1 + 0x19c) = 0;
      *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10000;
      return;
    }
    *(undefined4 *)(param_1 + 0x19c) = 0x80000;
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10000;
    return;
  }
  *(undefined4 *)(param_1 + 0x19c) = 0x40000;
  *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10000;
  return;
}


