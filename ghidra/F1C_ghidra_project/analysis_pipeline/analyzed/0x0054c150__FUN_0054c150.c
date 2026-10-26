// Function: FUN_0054c150 @ 0054c150
// Size (bytes): 60


void __thiscall FUN_0054c150(int param_1,undefined4 *param_2,uint param_3)

{
  if (((param_3 & 0x800) != 0) && ((*(uint *)(param_1 + 0x3c) & 0x800) != 0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x234);
    return;
  }
  if (((param_3 & 0x1000) != 0) && ((*(uint *)(param_1 + 0x3c) & 0x1000) != 0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x238);
  }
  return;
}


