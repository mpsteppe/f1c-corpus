// Function: FUN_00547670 @ 00547670
// Size (bytes): 150


void __thiscall FUN_00547670(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x24);
  iVar3 = 0;
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x24) = param_2;
  }
  else {
    iVar3 = iVar1;
    for (iVar1 = *(int *)(iVar1 + 0xc0); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc0)) {
      iVar3 = iVar1;
    }
    *(int *)(iVar3 + 0xc0) = param_2;
  }
  *(int *)(param_2 + 0xbc) = iVar3;
  *(undefined4 *)(param_2 + 0xc0) = 0;
  uVar2 = *(uint *)(param_2 + 0x9c);
  iVar1 = *(int *)(param_1 + 0x10);
  if ((uVar2 & 0x20) != 0) {
    if ((uVar2 & 0x100) != 0) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      *(int *)(param_1 + 0x10) = iVar1 + 1;
      return;
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    *(int *)(param_1 + 0x10) = iVar1 + 1;
    return;
  }
  if ((uVar2 & 0x100) != 0) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x10) = iVar1 + 1;
    return;
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  *(int *)(param_1 + 0x10) = iVar1 + 1;
  return;
}


