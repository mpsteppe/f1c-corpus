// Function: FUN_00548d40 @ 00548d40
// Size (bytes): 143


undefined4 __thiscall FUN_00548d40(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x170);
  if (iVar4 == 0) {
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0x170) = 0;
    }
    else {
      uVar3 = FUN_00548aa0();
      *(undefined4 *)(param_1 + 0x170) = uVar3;
    }
  }
  else {
    for (iVar1 = *(int *)(iVar4 + 0x18); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
      iVar4 = iVar1;
    }
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_00548aa0();
    }
    *(undefined4 *)(iVar4 + 0x18) = uVar3;
  }
  iVar4 = FUN_00548ad0(param_2,param_3);
  if (iVar4 != 0) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 0x16c) = *(int *)(param_1 + 0x16c) + 1;
  return 0;
}


