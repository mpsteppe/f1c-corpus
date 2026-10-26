// Function: FUN_004966e0 @ 004966e0
// Size (bytes): 109


void __thiscall FUN_004966e0(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 != 0) {
    piVar1 = operator_new(0x10);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      *piVar1 = param_2;
      piVar1[1] = 0;
      piVar1[2] = 0;
      *(undefined1 *)(piVar1 + 3) = 0;
    }
    if (*(int *)(param_1 + 0x18dc) == 0) {
      *(int **)(param_1 + 0x18dc) = piVar1;
      *(int **)(param_1 + 0x18e4) = piVar1;
    }
    else {
      *(int **)(*(int *)(param_1 + 0x18e0) + 4) = piVar1;
      piVar1[2] = *(int *)(param_1 + 0x18e0);
    }
    *(int **)(param_1 + 0x18e0) = piVar1;
    *(int *)(param_1 + 0x18e8) = *(int *)(param_1 + 0x18e8) + 1;
  }
  return;
}


