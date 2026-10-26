// Function: FUN_0048fb30 @ 0048fb30
// Size (bytes): 52


void __thiscall FUN_0048fb30(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = *(int *)(param_1 + 0x178);
  }
  param_2 = *(int *)(param_1 + 0x168) + param_2;
  *(int *)(param_1 + 0x168) = param_2;
  if (*(int *)(param_1 + 0x16c) < param_2) {
    *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x16c);
  }
  FUN_0048f870();
  return;
}


