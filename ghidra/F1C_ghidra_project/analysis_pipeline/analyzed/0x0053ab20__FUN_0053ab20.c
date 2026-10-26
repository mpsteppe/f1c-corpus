// Function: FUN_0053ab20 @ 0053ab20
// Size (bytes): 78


int * __thiscall FUN_0053ab20(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = param_2;
  log2((float10)param_2);
  iVar1 = __ftol();
  param_1[1] = iVar1;
  pvVar2 = operator_new(param_2 * 8 + 0x10);
  param_1[3] = (int)pvVar2;
  param_1[5] = 0;
  param_1[4] = 0;
  FUN_0053ab80(param_3);
  return param_1;
}


