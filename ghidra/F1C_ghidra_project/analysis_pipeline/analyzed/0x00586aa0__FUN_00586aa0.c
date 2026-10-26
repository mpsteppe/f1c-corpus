// Function: FUN_00586aa0 @ 00586aa0
// Size (bytes): 486


void __fastcall FUN_00586aa0(undefined4 *param_1)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  byte local_d;
  uint local_c;
  int local_8;
  uint local_4;
  
  *param_1 = 0;
  uVar5 = (uint)*(ushort *)(param_1[7] + 2 + param_1[0xd] * 4);
  local_4 = 0;
  uVar3 = 0;
  if (uVar5 != 0) {
    do {
      local_4 = local_4 | 1 << ((byte)uVar3 & 0x1f);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  local_4 = local_4 & 1;
  uVar3 = 0;
  local_8 = (*(ushort *)(param_1[7] + param_1[0xd] * 4) - 1) + uVar5;
  if (uVar5 != 0) {
    do {
      FUN_00585e80(local_8 - uVar3,&local_c,&local_d);
      if ((local_4 & 1 << ((byte)uVar3 & 0x1f)) == 0) {
        pbVar2 = (byte *)(local_c + param_1[5]);
        bVar4 = *pbVar2 & ~local_d;
      }
      else {
        pbVar2 = (byte *)(param_1[5] + local_c);
        bVar4 = *pbVar2 | local_d;
      }
      uVar3 = uVar3 + 1;
      *pbVar2 = bVar4;
    } while (uVar3 < uVar5);
  }
  uVar3 = 0;
  uVar5 = (uint)*(ushort *)(param_1[7] + 2 + param_1[0xe] * 4);
  if (uVar5 != 0) {
    do {
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  uVar3 = 0;
  local_4 = (*(ushort *)(param_1[7] + param_1[0xe] * 4) - 1) + uVar5;
  if (uVar5 != 0) {
    do {
      FUN_00586f70(local_4 - uVar3,0);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  uVar3 = 0;
  uVar5 = (uint)*(ushort *)(param_1[7] + 2 + param_1[0xf] * 4);
  if (uVar5 != 0) {
    do {
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  uVar3 = 0;
  local_4 = (*(ushort *)(param_1[7] + param_1[0xf] * 4) - 1) + uVar5;
  if (uVar5 != 0) {
    do {
      FUN_00586f70(local_4 - uVar3,0);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  iVar1 = param_1[0x10];
  local_c = 0;
  FUN_00586f40(iVar1,&local_c);
  uVar3 = 0;
  uVar5 = (uint)*(ushort *)(param_1[7] + iVar1 * 4 + 2);
  local_4 = (*(ushort *)(param_1[7] + iVar1 * 4) - 1) + uVar5;
  if (uVar5 != 0) {
    do {
      FUN_00586f70(local_4 - uVar3,
                   CONCAT31((int3)(uVar3 >> 8),(local_c & 1 << ((byte)uVar3 & 0x1f)) != 0));
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  FUN_00586fa0(param_1[0x11],0);
  FUN_00587500();
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  return;
}


