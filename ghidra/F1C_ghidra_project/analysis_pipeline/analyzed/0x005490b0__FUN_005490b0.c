// Function: FUN_005490b0 @ 005490b0
// Size (bytes): 84


void __thiscall FUN_005490b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xec);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0xec) = param_2;
    *(undefined4 *)(param_2 + 0x48) = 0;
    *(undefined4 *)(param_2 + 0x4c) = 0;
    *(undefined4 *)(param_2 + 0x44) = 0;
    return;
  }
  for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
    iVar1 = iVar2;
  }
  *(int *)(iVar1 + 0x4c) = param_2;
  *(int *)(param_2 + 0x48) = iVar1;
  *(undefined4 *)(param_2 + 0x4c) = 0;
  *(undefined4 *)(param_2 + 0x44) = 0;
  return;
}


