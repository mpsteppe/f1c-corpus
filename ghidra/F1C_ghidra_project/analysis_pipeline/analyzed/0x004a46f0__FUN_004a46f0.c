// Function: FUN_004a46f0 @ 004a46f0
// Size (bytes): 31


void __thiscall FUN_004a46f0(int param_1,int param_2,char param_3)

{
  if (param_3 != '\0') {
    *(int *)(param_1 + *(int *)(param_2 + 4) * 4) = param_2;
    return;
  }
  *(undefined4 *)(param_1 + *(int *)(param_2 + 4) * 4) = 0;
  return;
}


