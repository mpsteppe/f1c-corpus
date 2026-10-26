// Function: FUN_00452700 @ 00452700
// Size (bytes): 50


void __thiscall FUN_00452700(int param_1,int param_2)

{
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 0x10) = param_2;
    return;
  }
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  else if (*(int *)(param_1 + 0xc) == 0) {
    *(int *)(param_1 + 0x10) = param_2;
    *(undefined4 *)(param_1 + 0xc) = 1;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


