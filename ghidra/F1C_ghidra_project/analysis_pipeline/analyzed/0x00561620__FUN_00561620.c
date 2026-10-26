// Function: FUN_00561620 @ 00561620
// Size (bytes): 62


void FUN_00561620(int param_1)

{
  if ((*(byte *)(param_1 + 0x3c) & 2) == 0) {
    if (*(int *)(param_1 + 0x44) != 0) {
      FUN_00561620(*(int *)(param_1 + 0x44));
    }
    if ((*(int *)(param_1 + 0x40) != 0) && (*(int *)(param_1 + 0x4c) != 0)) {
      FUN_00561620(*(int *)(param_1 + 0x4c));
    }
    FUN_00561660(param_1);
  }
  return;
}


