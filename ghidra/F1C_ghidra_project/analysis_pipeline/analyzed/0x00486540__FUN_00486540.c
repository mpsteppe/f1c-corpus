// Function: FUN_00486540 @ 00486540
// Size (bytes): 49


void __thiscall FUN_00486540(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xd8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xd8) = param_2;
    return;
  }
  for (iVar2 = *(int *)(iVar1 + 0x18); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18)) {
    iVar1 = iVar2;
  }
  *(undefined4 *)(iVar1 + 0x18) = param_2;
  return;
}


