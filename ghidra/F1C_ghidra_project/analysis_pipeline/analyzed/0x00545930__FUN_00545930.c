// Function: FUN_00545930 @ 00545930
// Size (bytes): 155


undefined4 __thiscall FUN_00545930(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  pvVar3 = operator_new(0x38);
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_00560ba0(param_2,*(undefined4 *)(param_1 + 0x158));
  }
  iVar1 = *(int *)(param_1 + 0x15c);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x15c) = iVar4;
  }
  else {
    if ((param_3 == 0) || (iVar2 = *(int *)(param_3 + 0x230), iVar2 == 0)) {
      iVar5 = iVar1;
      for (iVar1 = *(int *)(iVar1 + 0x34); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x34)) {
        iVar5 = iVar1;
      }
    }
    else {
      iVar1 = *(int *)(iVar2 + 0x2c);
      if (iVar1 == 0) {
        *(int *)(iVar2 + 0x2c) = iVar4;
        goto LAB_005459b4;
      }
      iVar5 = iVar1;
      for (iVar1 = *(int *)(iVar1 + 0x34); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x34)) {
        iVar5 = iVar1;
      }
    }
    *(int *)(iVar5 + 0x34) = iVar4;
  }
LAB_005459b4:
  *(int *)(iVar4 + 0x30) = iVar5;
  *(undefined4 *)(iVar4 + 0x34) = 0;
  *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + 1;
  return 0;
}


