// Function: FUN_0059a428 @ 0059a428
// Size (bytes): 20


void __thiscall FUN_0059a428(int param_1,int param_2)

{
  **(int **)(param_1 + 0x30) = **(int **)(param_1 + 0x30) - param_2;
  **(int **)(param_1 + 0x20) = **(int **)(param_1 + 0x20) + param_2 * 2;
  return;
}


