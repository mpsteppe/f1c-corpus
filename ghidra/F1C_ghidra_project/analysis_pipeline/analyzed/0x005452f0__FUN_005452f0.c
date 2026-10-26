// Function: FUN_005452f0 @ 005452f0
// Size (bytes): 73


int __fastcall FUN_005452f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (iVar1 = *(int *)(param_1 + 0x100); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x104)) {
    for (iVar2 = *(int *)(iVar1 + 0xec); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
      iVar3 = iVar3 + 1;
    }
  }
  for (iVar1 = *(int *)(param_1 + 0x108); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}


