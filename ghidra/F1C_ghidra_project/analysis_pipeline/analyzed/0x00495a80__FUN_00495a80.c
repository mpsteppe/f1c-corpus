// Function: FUN_00495a80 @ 00495a80
// Size (bytes): 87


void __thiscall FUN_00495a80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0) {
    FUN_00495a20(param_2);
    *(undefined4 *)(param_2 + 100) = 0;
    *(undefined4 *)(param_2 + 0x68) = 0;
    iVar1 = *(int *)(param_1 + 0x14);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x14) = param_2;
      *(int *)(param_1 + 0x18) = param_2;
      return;
    }
    for (iVar2 = *(int *)(iVar1 + 100); iVar2 != 0; iVar2 = *(int *)(iVar2 + 100)) {
      iVar1 = iVar2;
    }
    *(int *)(param_1 + 0x18) = param_2;
    *(int *)(iVar1 + 100) = param_2;
    *(int *)(param_2 + 0x68) = iVar1;
  }
  return;
}


