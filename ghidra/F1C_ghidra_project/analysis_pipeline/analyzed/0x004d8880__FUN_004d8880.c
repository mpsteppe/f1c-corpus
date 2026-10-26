// Function: FUN_004d8880 @ 004d8880
// Size (bytes): 39


void __thiscall FUN_004d8880(int param_1,int param_2)

{
  if (param_2 == -1) {
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
    return;
  }
  if ((*(int *)(param_1 + 0xc + param_2 * 4) != 0) && (DAT_007cf788 != 0)) {
    *(int *)(param_1 + 8) = param_2;
  }
  return;
}


