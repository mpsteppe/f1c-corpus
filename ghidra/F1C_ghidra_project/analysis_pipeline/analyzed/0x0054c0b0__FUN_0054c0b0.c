// Function: FUN_0054c0b0 @ 0054c0b0
// Size (bytes): 44


void __thiscall FUN_0054c0b0(int param_1,uint *param_2,uint *param_3)

{
  if (param_2 != (uint *)0x0) {
    *param_2 = ~*(uint *)(param_1 + 0x3c) >> 1 & 1;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = ~*(uint *)(param_1 + 0x3c) >> 2 & 1;
  }
  return;
}


