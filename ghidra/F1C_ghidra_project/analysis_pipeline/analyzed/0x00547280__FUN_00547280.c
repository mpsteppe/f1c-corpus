// Function: FUN_00547280 @ 00547280
// Size (bytes): 44


void __thiscall FUN_00547280(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0x1000) {
    *(undefined4 *)(param_1 + 0x8c) = param_2;
    return;
  }
  if (param_3 == 0x2000) {
    *(undefined4 *)(param_1 + 0x90) = param_2;
  }
  return;
}


