// Function: FUN_00551f10 @ 00551f10
// Size (bytes): 103


undefined4 FUN_00551f10(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00551a30();
    }
    *param_1 = iVar2;
    iVar2 = FUN_00551a50(param_2,param_3,param_4);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = *param_1;
    if (iVar2 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar2);
    }
    *param_1 = 0;
  }
  return 0xffffffff;
}


