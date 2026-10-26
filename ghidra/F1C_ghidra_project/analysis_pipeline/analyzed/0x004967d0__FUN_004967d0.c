// Function: FUN_004967d0 @ 004967d0
// Size (bytes): 109


void __thiscall FUN_004967d0(int param_1,int param_2)

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
    if (*(int *)(param_1 + 0x18cc) == 0) {
      *(int **)(param_1 + 0x18cc) = piVar1;
      *(int **)(param_1 + 0x18d4) = piVar1;
    }
    else {
      *(int **)(*(int *)(param_1 + 0x18d0) + 4) = piVar1;
      piVar1[2] = *(int *)(param_1 + 0x18d0);
    }
    *(int **)(param_1 + 0x18d0) = piVar1;
    *(int *)(param_1 + 0x18d8) = *(int *)(param_1 + 0x18d8) + 1;
  }
  return;
}


