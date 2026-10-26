// Function: FUN_0048faf0 @ 0048faf0
// Size (bytes): 52


void __thiscall FUN_0048faf0(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = *(int *)(param_1 + 0x178);
  }
  param_2 = *(int *)(param_1 + 0x168) - param_2;
  *(int *)(param_1 + 0x168) = param_2;
  if (param_2 < 0) {
    *(undefined4 *)(param_1 + 0x168) = 0;
  }
  FUN_0048f870();
  return;
}


