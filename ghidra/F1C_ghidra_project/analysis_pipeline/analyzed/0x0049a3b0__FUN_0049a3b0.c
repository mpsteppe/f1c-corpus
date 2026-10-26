// Function: FUN_0049a3b0 @ 0049a3b0
// Size (bytes): 165


int __thiscall FUN_0049a3b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  
  FUN_00589901(param_2);
  iVar3 = FUN_0049a520(param_2);
  if (iVar3 != 0) {
    return -1;
  }
  iVar3 = FUN_0049a330(param_2);
  if (iVar3 == -1) {
    return -1;
  }
  iVar1 = *(int *)(param_1 + iVar3 * 4);
  pvVar4 = operator_new(0x1c);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_0049a250();
  }
  thunk_FUN_00566650(param_2);
  FUN_0049a2e0(param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + iVar3 * 4) = uVar5;
    return iVar3;
  }
  for (iVar2 = *(int *)(iVar1 + 0x18); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18)) {
    iVar1 = iVar2;
  }
  *(undefined4 *)(iVar1 + 0x18) = uVar5;
  return iVar3;
}


