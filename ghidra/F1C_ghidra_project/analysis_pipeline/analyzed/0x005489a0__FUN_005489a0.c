// Function: FUN_005489a0 @ 005489a0
// Size (bytes): 86


void __thiscall FUN_005489a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  
  pvVar3 = operator_new(0x18);
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_0053ab20(0x400,param_2);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
      iVar1 = iVar2;
    }
    *(int *)(iVar1 + 0x14) = iVar4;
    *(int *)(iVar4 + 0x10) = iVar1;
    return;
  }
  *(int *)(param_1 + 0x2c) = iVar4;
  *(undefined4 *)(iVar4 + 0x10) = 0;
  return;
}


