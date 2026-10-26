// Function: FUN_0057d660 @ 0057d660
// Size (bytes): 94


undefined4 FUN_0057d660(ushort *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  
  uVar1 = (uint)((*(uint *)(param_2 + 0x24) & 7) != 0) + (*(uint *)(param_2 + 0x24) >> 3);
  if (*param_1 == uVar1) {
    puVar3 = param_1 + 2;
    puVar4 = *(undefined4 **)(param_2 + 0x14);
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *(undefined4 *)puVar3;
      puVar3 = puVar3 + 2;
      puVar4 = puVar4 + 1;
    }
    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(char *)puVar4 = (char)*puVar3;
      puVar3 = (ushort *)((int)puVar3 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  FUN_00587510((undefined1 *)((uint)*param_1 + (int)(param_1 + 2)),param_1[1]);
  return 1;
}


