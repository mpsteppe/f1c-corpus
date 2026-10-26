// Function: FUN_00547860 @ 00547860
// Size (bytes): 69


void __thiscall FUN_00547860(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x5c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x5c)) {
      iVar1 = iVar2;
    }
    *(int *)(iVar1 + 0x5c) = param_2;
    *(int *)(param_2 + 0x58) = iVar1;
    *(undefined4 *)(param_2 + 0x5c) = 0;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    return;
  }
  *(int *)(param_1 + 0x28) = param_2;
  *(undefined4 *)(param_2 + 0x58) = 0;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return;
}


