// Function: FUN_0049aa30 @ 0049aa30
// Size (bytes): 51


void __thiscall FUN_0049aa30(int param_1,int param_2,int param_3)

{
  param_3 = param_3 - *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_3;
  param_2 = param_2 - *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_2;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_2;
  return;
}


