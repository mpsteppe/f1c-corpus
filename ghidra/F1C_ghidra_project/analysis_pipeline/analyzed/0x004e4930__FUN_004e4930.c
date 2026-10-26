// Function: FUN_004e4930 @ 004e4930
// Size (bytes): 122


void __thiscall FUN_004e4930(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x32bc);
  if (iVar1 == 0) {
    FUN_004a6e50(param_2);
    FUN_00441650(param_2);
    *(undefined4 *)(param_1 + 0x34ac) = param_2;
    FUN_004e49b0();
  }
  else {
    if (iVar1 == 1) {
      FUN_004a6e50(param_2);
      FUN_004e4e60(param_2);
      return;
    }
    if (iVar1 == 2) {
      *(undefined4 *)(param_1 + 0x34ac) = param_2;
      FUN_004f03e0(param_2);
      return;
    }
  }
  return;
}


