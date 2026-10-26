// Function: FUN_0054fb40 @ 0054fb40
// Size (bytes): 35


void __thiscall FUN_0054fb40(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x204);
  if (param_2 != 0) {
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x40;
    return;
  }
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xffffffbf;
  return;
}


