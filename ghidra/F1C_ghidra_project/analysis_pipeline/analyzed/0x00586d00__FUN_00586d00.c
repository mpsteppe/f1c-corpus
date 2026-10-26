// Function: FUN_00586d00 @ 00586d00
// Size (bytes): 100


uint __fastcall FUN_00586d00(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_4;
  
  uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x34) * 4 + 2);
  local_4 = 0;
  uVar3 = 0;
  uVar1 = 0;
  if (uVar2 != 0) {
    do {
      uVar1 = ((*(ushort *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x34) * 4) - 1) + uVar2) -
              uVar3;
      if ((*(byte *)((uVar1 >> 3) + *(int *)(param_1 + 0x14)) & '\x01' << ((byte)uVar1 & 7)) != 0) {
        local_4 = local_4 | 1 << ((byte)uVar3 & 0x1f);
      }
      uVar3 = uVar3 + 1;
      uVar1 = local_4;
    } while (uVar3 < uVar2);
  }
  return uVar1;
}


