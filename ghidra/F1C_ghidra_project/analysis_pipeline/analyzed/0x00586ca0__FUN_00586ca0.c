// Function: FUN_00586ca0 @ 00586ca0
// Size (bytes): 96


undefined4 __fastcall FUN_00586ca0(int param_1)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_4;
  
  puVar1 = (ushort *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x3c) * 4);
  uVar3 = (uint)puVar1[1];
  uVar4 = 0;
  local_4 = 0;
  if (uVar3 != 0) {
    do {
      uVar2 = ((*puVar1 - 1) + uVar3) - uVar4;
      if ((*(byte *)((uVar2 >> 3) + *(int *)(param_1 + 0x14)) & '\x01' << ((byte)uVar2 & 7)) != 0) {
        local_4 = local_4 | 1 << ((byte)uVar4 & 0x1f);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  return CONCAT31((int3)(local_4 >> 8),local_4 != 0);
}


