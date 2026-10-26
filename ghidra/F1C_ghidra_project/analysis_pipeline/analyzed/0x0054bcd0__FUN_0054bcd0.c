// Function: FUN_0054bcd0 @ 0054bcd0
// Size (bytes): 83


void __thiscall FUN_0054bcd0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_0054bcd0(param_2,param_3,param_4);
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_0054bcd0(param_2,param_3,param_4);
  }
  if (param_4 != 0) {
    FUN_0054bf10(param_4);
    return;
  }
  FUN_0054bdc0(param_2,param_3,0);
  return;
}


