// Function: FUN_0054c1b0 @ 0054c1b0
// Size (bytes): 91


void __thiscall FUN_0054c1b0(int param_1,int param_2,uint param_3,uint param_4)

{
  if ((*(int *)(param_1 + 0x44) != 0) && (param_3 != 0)) {
    FUN_0054c1b0(param_2,param_3,1);
  }
  if ((*(int *)(param_1 + 0x4c) != 0) && ((param_4 & param_3) != 0)) {
    FUN_0054c1b0(param_2,param_3,1);
  }
  if (*(int *)(param_1 + 0x230) != 0) {
    if (param_2 != 0) {
      FUN_00560fc0();
      return;
    }
    FUN_00560fd0();
  }
  return;
}


