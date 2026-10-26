// Function: FUN_0053d340 @ 0053d340
// Size (bytes): 85


void FUN_0053d340(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_008b8e20 != 0) {
    iVar3 = *(int *)(DAT_008b8e20 + 0x870);
    iVar2 = DAT_008b8e20;
    while (iVar1 = iVar3, iVar1 != 0) {
      iVar2 = iVar1;
      iVar3 = *(int *)(iVar1 + 0x870);
    }
    *(int *)(iVar2 + 0x870) = param_1;
    *(int *)(param_1 + 0x86c) = iVar2;
    *(undefined4 *)(param_1 + 0x870) = 0;
    return;
  }
  DAT_008b8e20 = param_1;
  *(undefined4 *)(param_1 + 0x86c) = 0;
  *(undefined4 *)(param_1 + 0x870) = 0;
  return;
}


