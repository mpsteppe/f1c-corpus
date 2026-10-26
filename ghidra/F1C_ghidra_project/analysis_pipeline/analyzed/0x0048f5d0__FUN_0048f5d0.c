// Function: FUN_0048f5d0 @ 0048f5d0
// Size (bytes): 112


void __thiscall FUN_0048f5d0(int param_1,int param_2,undefined1 param_3)

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
      *(undefined1 *)(piVar1 + 3) = param_3;
    }
    if (*(int *)(param_1 + 0xf0) == 0) {
      *(int **)(param_1 + 0xf0) = piVar1;
      *(int **)(param_1 + 0xf8) = piVar1;
    }
    else {
      *(int **)(*(int *)(param_1 + 0xf4) + 4) = piVar1;
      piVar1[2] = *(int *)(param_1 + 0xf4);
    }
    *(int **)(param_1 + 0xf4) = piVar1;
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  }
  return;
}


