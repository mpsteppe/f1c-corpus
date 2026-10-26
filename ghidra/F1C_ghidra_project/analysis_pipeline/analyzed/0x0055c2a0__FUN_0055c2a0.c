// Function: FUN_0055c2a0 @ 0055c2a0
// Size (bytes): 54


void __thiscall FUN_0055c2a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x1518);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x20); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
      iVar1 = iVar2;
    }
    *(int *)(param_2 + 0x1c) = iVar1;
    *(int *)(iVar1 + 0x20) = param_2;
    return;
  }
  *(int *)(param_1 + 0x1518) = param_2;
  return;
}


