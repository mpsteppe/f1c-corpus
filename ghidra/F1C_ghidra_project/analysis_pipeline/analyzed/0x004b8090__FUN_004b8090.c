// Function: FUN_004b8090 @ 004b8090
// Size (bytes): 165


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004b8090(float param_1)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  ushort uVar6;
  undefined4 local_8;
  undefined1 local_4;
  
  FUN_00566d30();
  local_4 = DAT_005d2470;
  local_8 = DAT_005d246c;
  param_1 = -1.0;
  FUN_00566c00(&local_8,4);
  FUN_00566c00(&param_1,4);
  pbVar2 = (byte *)&local_8;
  pbVar4 = PTR_DAT_005d2434;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004b8109:
      uVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004b810e;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004b8109;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  uVar3 = 0;
LAB_004b810e:
  if (uVar3 == 0) {
    uVar6 = (ushort)(param_1 < _DAT_005d2438) << 8 |
            (ushort)(NAN(param_1) || NAN(_DAT_005d2438)) << 10 |
            (ushort)(param_1 == _DAT_005d2438) << 0xe;
    uVar3 = (uint)uVar6;
    if (param_1 == _DAT_005d2438) {
      return CONCAT31((uint3)(byte)(uVar6 >> 8),1);
    }
  }
  return uVar3 & 0xffffff00;
}


