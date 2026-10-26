// Function: FUN_0054fae0 @ 0054fae0
// Size (bytes): 95


void __thiscall FUN_0054fae0(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x1e0);
  if (iVar1 != 0) {
    if (param_2 == 0x8000000) {
      puVar2 = *(uint **)(iVar1 + 8);
      iVar3 = 0;
      if (0 < *(int *)(iVar1 + 4)) {
        do {
          *puVar2 = *puVar2 & 0xfffffffe;
          puVar2[0x10] = 0;
          puVar2 = puVar2 + 0x1d;
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(*(int *)(param_1 + 0x1e0) + 4));
        return;
      }
    }
    else {
      puVar2 = (uint *)(param_2 * 0x74 + *(int *)(iVar1 + 8));
      *puVar2 = *(uint *)(param_2 * 0x74 + *(int *)(iVar1 + 8)) & 0xfffffffe;
      puVar2[0x10] = 0;
    }
  }
  return;
}


