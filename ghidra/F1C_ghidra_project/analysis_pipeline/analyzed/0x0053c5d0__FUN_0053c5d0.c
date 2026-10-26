// Function: FUN_0053c5d0 @ 0053c5d0
// Size (bytes): 85


void FUN_0053c5d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_008b8f28 != 0) {
    iVar3 = *(int *)(DAT_008b8f28 + 0x1e8);
    iVar2 = DAT_008b8f28;
    while (iVar1 = iVar3, iVar1 != 0) {
      iVar2 = iVar1;
      iVar3 = *(int *)(iVar1 + 0x1e8);
    }
    *(int *)(iVar2 + 0x1e8) = param_1;
    *(int *)(param_1 + 0x1e4) = iVar2;
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    return;
  }
  DAT_008b8f28 = param_1;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  return;
}


