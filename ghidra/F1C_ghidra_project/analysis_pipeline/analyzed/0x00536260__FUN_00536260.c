// Function: FUN_00536260 @ 00536260
// Size (bytes): 145


void __fastcall FUN_00536260(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  *(int *)(param_1 + 0x32) = *(int *)(param_1 + 0x22) * 2;
  *(undefined2 *)(*(int *)(param_1 + 0x3a) + -2 + *(int *)(param_1 + 0x42) * 2) = 0;
  uVar4 = *(int *)(param_1 + 0x42) * 2 - 2;
  puVar5 = *(undefined4 **)(param_1 + 0x3a);
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  iVar2 = *(int *)(param_1 + 0x7a) * 0xc;
  *(uint *)(param_1 + 0x76) = (uint)*(ushort *)(&DAT_005b77ea + iVar2);
  *(uint *)(param_1 + 0x82) = (uint)*(ushort *)(&DAT_005b77e8 + iVar2);
  *(uint *)(param_1 + 0x86) = (uint)*(ushort *)(&DAT_005b77ec + iVar2);
  uVar1 = *(ushort *)(&DAT_005b77ee + iVar2);
  *(undefined4 *)(param_1 + 0x62) = 0;
  *(undefined4 *)(param_1 + 0x52) = 0;
  *(undefined4 *)(param_1 + 0x6a) = 0;
  *(undefined4 *)(param_1 + 0x5e) = 0;
  *(undefined4 *)(param_1 + 0x3e) = 0;
  *(uint *)(param_1 + 0x72) = (uint)uVar1;
  *(undefined4 *)(param_1 + 0x6e) = 2;
  *(undefined4 *)(param_1 + 0x56) = 2;
  return;
}


