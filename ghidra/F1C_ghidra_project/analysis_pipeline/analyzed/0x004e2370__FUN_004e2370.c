// Function: FUN_004e2370 @ 004e2370
// Size (bytes): 58


void __thiscall FUN_004e2370(int param_1,int param_2)

{
  *(undefined1 *)(param_1 + 0xb6c) = 0;
  if (param_2 == 4) {
    *(undefined1 *)(param_1 + 0xb6c) = 1;
    FUN_004e23ad();
    return;
  }
  if (param_2 == 5) {
    *(undefined1 *)(param_1 + 0xb6c) = 2;
    FUN_004e23ad();
    return;
  }
  if (param_2 == 6) {
    *(undefined1 *)(param_1 + 0xb6c) = 3;
    FUN_004e23ad();
    return;
  }
  FUN_0059db09();
  return;
}


