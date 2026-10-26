// Function: FUN_004492d0 @ 004492d0
// Size (bytes): 98


void __thiscall FUN_004492d0(int param_1,int param_2)

{
  int *piVar1;
  
  FUN_00449340();
  if (0 < param_2) {
    *(int *)(param_1 + 4) = param_2;
    piVar1 = operator_new(param_2 * 0x20 + 4);
    if (piVar1 != (int *)0x0) {
      *piVar1 = param_2;
      if (-1 < param_2 + -1) {
        do {
          FUN_00448e90();
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      *(int **)(param_1 + 8) = piVar1 + 1;
      return;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


