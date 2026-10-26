// Function: FUN_00434030 @ 00434030
// Size (bytes): 90


undefined4 __thiscall FUN_00434030(int *param_1,int param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = 0;
  if (param_2 != 0) {
    piVar2 = operator_new(0xc);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      *piVar2 = param_2;
      piVar2[1] = 0;
      *(undefined1 *)(piVar2 + 2) = param_3;
    }
    if (*param_1 == 0) {
      *param_1 = (int)piVar2;
      param_1[2] = (int)piVar2;
      param_1[1] = (int)piVar2;
      param_1[3] = param_1[3] + 1;
      return 1;
    }
    *(int **)(param_1[1] + 4) = piVar2;
    param_1[1] = (int)piVar2;
    param_1[3] = param_1[3] + 1;
    uVar1 = 1;
  }
  return uVar1;
}


