// Function: FUN_00545250 @ 00545250
// Size (bytes): 85


void __thiscall FUN_00545250(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_2 + 0x4c) = 0;
  *(uint *)(param_2 + 0x3c) = *(uint *)(param_2 + 0x3c) | 8;
  FUN_00544c50(param_2);
  iVar1 = *(int *)(param_1 + 0x108);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x108) = param_2;
    *(undefined4 *)(param_2 + 0x48) = 0;
    return;
  }
  for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
    iVar1 = iVar2;
  }
  *(int *)(iVar1 + 0x4c) = param_2;
  *(int *)(param_2 + 0x48) = iVar1;
  return;
}


