// Function: FUN_005450e0 @ 005450e0
// Size (bytes): 111


undefined4 FUN_005450e0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    *param_1 = 0;
  }
  pvVar1 = operator_new(0x23c);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0054a600();
  }
  *(undefined4 *)(iVar2 + 0x3c) = param_4;
  iVar3 = FUN_0054a730(param_2,param_3);
  if (iVar3 != 0) {
    FUN_0054a710();
    FUN_00587bcf(iVar2);
    return 0xffffffff;
  }
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  return 0;
}


