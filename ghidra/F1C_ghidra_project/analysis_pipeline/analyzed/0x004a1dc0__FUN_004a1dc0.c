// Function: FUN_004a1dc0 @ 004a1dc0
// Size (bytes): 92


void __thiscall FUN_004a1dc0(int *param_1,int param_2)

{
  int *piVar1;
  
  if (((char)param_1[4] != '\0') && (param_2 != 0)) {
    piVar1 = operator_new(0xc);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      *piVar1 = param_2;
      piVar1[1] = 0;
      *(undefined1 *)(piVar1 + 2) = 0;
    }
    if (*param_1 == 0) {
      *param_1 = (int)piVar1;
      param_1[2] = (int)piVar1;
      param_1[1] = (int)piVar1;
      param_1[3] = param_1[3] + 1;
      return;
    }
    *(int **)(param_1[1] + 4) = piVar1;
    param_1[1] = (int)piVar1;
    param_1[3] = param_1[3] + 1;
  }
  return;
}


