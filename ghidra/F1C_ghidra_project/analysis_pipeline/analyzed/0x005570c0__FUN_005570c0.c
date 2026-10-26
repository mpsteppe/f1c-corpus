// Function: FUN_005570c0 @ 005570c0
// Size (bytes): 93


void __thiscall FUN_005570c0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  for (iVar1 = *(int *)(param_1 + 0x100); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x104)) {
    for (iVar2 = *(int *)(iVar1 + 0xec); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
      FUN_00556cd0(param_2,0);
    }
  }
  for (iVar1 = *(int *)(param_1 + 0x108); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
    FUN_00556cd0(param_2,0);
  }
  return;
}


