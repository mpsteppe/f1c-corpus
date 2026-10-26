// Function: FUN_00497510 @ 00497510
// Size (bytes): 121


int __thiscall FUN_00497510(int param_1,int param_2)

{
  int *piVar1;
  
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  FUN_0054fdf0(param_1);
  FUN_0054fc40(1);
  if (param_2 != 0) {
    piVar1 = operator_new(0x10);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      *piVar1 = param_2;
      piVar1[1] = 0;
      piVar1[2] = 0;
      *(undefined1 *)(piVar1 + 3) = 1;
    }
    if (*(int *)(param_1 + 4) == 0) {
      *(int **)(param_1 + 4) = piVar1;
      *(int **)(param_1 + 0xc) = piVar1;
      *(int **)(param_1 + 8) = piVar1;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      return param_2;
    }
    *(int **)(*(int *)(param_1 + 8) + 4) = piVar1;
    piVar1[2] = *(int *)(param_1 + 8);
    *(int **)(param_1 + 8) = piVar1;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  }
  return param_2;
}


