// Function: FUN_00496750 @ 00496750
// Size (bytes): 121


void __thiscall FUN_00496750(int param_1,int param_2,char param_3)

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
    if (*(int *)(param_1 + 0x18bc) == 0) {
      *(int **)(param_1 + 0x18bc) = piVar1;
      *(int **)(param_1 + 0x18c4) = piVar1;
    }
    else {
      *(int **)(*(int *)(param_1 + 0x18c0) + 4) = piVar1;
      piVar1[2] = *(int *)(param_1 + 0x18c0);
    }
    *(int **)(param_1 + 0x18c0) = piVar1;
    *(int *)(param_1 + 0x18c8) = *(int *)(param_1 + 0x18c8) + 1;
  }
  if (param_3 != '\0') {
    *(undefined1 *)(param_1 + 0x24) = 1;
  }
  return;
}


