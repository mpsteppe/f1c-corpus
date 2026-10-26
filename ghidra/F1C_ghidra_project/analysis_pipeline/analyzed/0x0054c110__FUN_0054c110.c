// Function: FUN_0054c110 @ 0054c110
// Size (bytes): 58


void __thiscall FUN_0054c110(int param_1,undefined4 param_2,uint param_3)

{
  if ((param_3 & 0x800) != 0) {
    *(undefined4 *)(param_1 + 0x234) = param_2;
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x800;
    return;
  }
  if ((param_3 & 0x1000) != 0) {
    *(undefined4 *)(param_1 + 0x238) = param_2;
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1000;
  }
  return;
}


