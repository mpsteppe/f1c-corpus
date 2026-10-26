// Function: FUN_0054bf10 @ 0054bf10
// Size (bytes): 75


void __fastcall FUN_0054bf10(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  for (iVar1 = *(int *)(param_1 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    puVar2 = *(uint **)(iVar1 + 0x11c);
    iVar4 = 0;
    if (0 < *(int *)(iVar1 + 0x118)) {
      do {
        uVar3 = *puVar2;
        *puVar2 = uVar3 & 0xffff0000;
        *puVar2 = (int)*(short *)((int)puVar2 + 2) | uVar3 & 0xffff0000;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(iVar1 + 0x118));
    }
  }
  return;
}


