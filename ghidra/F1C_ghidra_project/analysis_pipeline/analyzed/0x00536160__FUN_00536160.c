// Function: FUN_00536160 @ 00536160
// Size (bytes): 112


void __fastcall FUN_00536160(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar3 = *(uint *)(*(int *)(param_1 + 0x1c) + 0x14);
  if (*(uint *)(param_1 + 0x10) < uVar3) {
    uVar3 = *(uint *)(param_1 + 0x10);
  }
  if (uVar3 != 0) {
    puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0x10);
    puVar5 = *(undefined4 **)(param_1 + 0xc);
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar3;
    *(uint *)(*(int *)(param_1 + 0x1c) + 0x10) = *(int *)(*(int *)(param_1 + 0x1c) + 0x10) + uVar3;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar3;
    *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - uVar3;
    *(uint *)(*(int *)(param_1 + 0x1c) + 0x14) = *(int *)(*(int *)(param_1 + 0x1c) + 0x14) - uVar3;
    iVar1 = *(int *)(param_1 + 0x1c);
    if (*(int *)(iVar1 + 0x14) == 0) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 8);
    }
  }
  return;
}


