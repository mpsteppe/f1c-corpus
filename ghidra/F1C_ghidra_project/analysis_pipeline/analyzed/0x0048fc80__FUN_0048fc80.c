// Function: FUN_0048fc80 @ 0048fc80
// Size (bytes): 28


void __thiscall FUN_0048fc80(int param_1,int param_2)

{
  *(int *)(param_1 + 0x38) = param_2;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x1c);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x20);
  return;
}


