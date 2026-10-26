// Function: FUN_0048d2b0 @ 0048d2b0
// Size (bytes): 169


undefined4 __thiscall FUN_0048d2b0(int *param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0048c9a0();
  }
  FUN_0048c9e0(param_2);
  if (iVar2 != 0) {
    piVar3 = operator_new(0x10);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      *piVar3 = iVar2;
      piVar3[1] = 0;
      piVar3[2] = 0;
      *(undefined1 *)(piVar3 + 3) = 1;
    }
    if (param_1[199] == 0) {
      param_1[199] = (int)piVar3;
      param_1[0xc9] = (int)piVar3;
    }
    else {
      *(int **)(param_1[200] + 4) = piVar3;
      piVar3[2] = param_1[200];
    }
    param_1[200] = (int)piVar3;
    param_1[0xca] = param_1[0xca] + 1;
    FUN_0048cc20();
    (**(code **)(*param_1 + 0x2c))(1);
    return 1;
  }
  return 0;
}


