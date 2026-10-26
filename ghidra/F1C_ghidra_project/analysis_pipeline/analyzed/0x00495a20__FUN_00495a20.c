// Function: FUN_00495a20 @ 00495a20
// Size (bytes): 90


void __thiscall FUN_00495a20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 != 0) && (iVar1 = *(int *)(param_1 + 0x14), iVar2 = iVar1, iVar1 != 0)) {
    while (iVar2 != param_2) {
      iVar2 = *(int *)(iVar2 + 100);
      if (iVar2 == 0) {
        return;
      }
    }
    if (*(int *)(param_2 + 0x68) == 0) {
      if (iVar1 == param_2) {
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 100);
      }
    }
    else {
      *(undefined4 *)(*(int *)(param_2 + 0x68) + 100) = *(undefined4 *)(param_2 + 100);
    }
    if (*(int *)(param_2 + 100) == 0) {
      if (*(int *)(param_1 + 0x18) == param_2) {
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x68);
        return;
      }
    }
    else {
      *(undefined4 *)(*(int *)(param_2 + 100) + 0x68) = *(undefined4 *)(param_2 + 0x68);
    }
  }
  return;
}


