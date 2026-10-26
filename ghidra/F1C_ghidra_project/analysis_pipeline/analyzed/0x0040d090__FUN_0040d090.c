// Function: FUN_0040d090 @ 0040d090
// Size (bytes): 28


void __fastcall FUN_0040d090(int param_1)

{
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  }
  if (DAT_008afe88 != 0) {
    FUN_0054a1b0();
    return;
  }
  return;
}


