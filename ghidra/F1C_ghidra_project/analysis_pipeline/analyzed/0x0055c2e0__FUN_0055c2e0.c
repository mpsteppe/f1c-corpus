// Function: FUN_0055c2e0 @ 0055c2e0
// Size (bytes): 78


void __thiscall FUN_0055c2e0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1518);
  if (iVar1 != 0) {
    while (iVar1 != param_2) {
      iVar1 = *(int *)(iVar1 + 0x20);
      if (iVar1 == 0) {
        return;
      }
    }
    if (*(int *)(iVar1 + 0x1c) != 0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x1c) + 0x20) = *(undefined4 *)(iVar1 + 0x20);
    }
    if (*(int *)(iVar1 + 0x20) != 0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    }
    if (*(int *)(param_1 + 0x1518) == iVar1) {
      *(undefined4 *)(param_1 + 0x1518) = *(undefined4 *)(iVar1 + 0x20);
    }
  }
  return;
}


