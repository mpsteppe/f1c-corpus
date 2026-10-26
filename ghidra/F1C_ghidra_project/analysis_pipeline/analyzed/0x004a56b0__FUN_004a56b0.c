// Function: FUN_004a56b0 @ 004a56b0
// Size (bytes): 76


void __thiscall FUN_004a56b0(int param_1,char param_2)

{
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0x128) = 1;
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined4 *)(param_1 + 0x130) = 0;
  }
  else if (*(int *)(param_1 + 0x128) != 2) {
    *(undefined4 *)(param_1 + 0x128) = 2;
    *(undefined4 *)(param_1 + 300) = 1;
    *(undefined4 *)(param_1 + 0x130) = 1;
    return;
  }
  return;
}


