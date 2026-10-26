// Function: FUN_0053cb20 @ 0053cb20
// Size (bytes): 97


undefined4 FUN_0053cb20(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x3c);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_005426a0();
  }
  *param_1 = iVar2;
  iVar2 = FUN_005429b0(param_2,0,0,param_3,param_4);
  if (iVar2 != 0) {
    iVar2 = *param_1;
    if (iVar2 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar2);
    }
    return 0xffffffff;
  }
  return 0;
}


