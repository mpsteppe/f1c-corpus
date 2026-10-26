// Function: FUN_005458d0 @ 005458d0
// Size (bytes): 83


void __thiscall FUN_005458d0(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) & 0xff9fffff;
    return;
  }
  if (param_2 == 1) {
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) & 0xffbfffff | 0x200000;
    return;
  }
  if (param_2 == 2) {
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) & 0xffdfffff | 0x400000;
  }
  return;
}


