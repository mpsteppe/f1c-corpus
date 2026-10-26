// Function: FUN_004a5660 @ 004a5660
// Size (bytes): 65


void __thiscall FUN_004a5660(int param_1,char param_2)

{
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0x28) = 1;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  else if (*(int *)(param_1 + 0x28) != 2) {
    *(undefined4 *)(param_1 + 0x28) = 2;
    *(undefined4 *)(param_1 + 0x2c) = 1;
    *(undefined4 *)(param_1 + 0x30) = 1;
    FUN_004a55e0();
    return;
  }
  FUN_004a55e0();
  return;
}


