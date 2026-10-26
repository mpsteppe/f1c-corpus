// Function: FUN_005510f0 @ 005510f0
// Size (bytes): 166


undefined4 * __thiscall FUN_005510f0(undefined4 *param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = param_2;
  FUN_0053c2a0();
  pvVar2 = operator_new(0x4c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00556220();
  }
  *param_1 = uVar3;
  FUN_00556260(1);
  piVar4 = operator_new(param_2 * 0x88 + 4);
  if (piVar4 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = piVar4 + 1;
    *piVar4 = param_2;
    if (-1 < param_2 + -1) {
      do {
        FUN_00550760();
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[6] = piVar5;
  param_1[5] = iVar1;
  param_1[1] = 0x20000;
  return param_1;
}


