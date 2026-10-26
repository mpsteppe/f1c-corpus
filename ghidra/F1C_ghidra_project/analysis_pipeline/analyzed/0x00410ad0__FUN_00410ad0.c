// Function: FUN_00410ad0 @ 00410ad0
// Size (bytes): 23


void __thiscall FUN_00410ad0(int *param_1,int *param_2)

{
  *(int **)(param_1[2] + *param_1 * 4) = param_2;
  *param_2 = *param_1;
  *param_1 = *param_1 + 1;
  return;
}


