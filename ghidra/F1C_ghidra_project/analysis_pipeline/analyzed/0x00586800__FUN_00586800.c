// Function: FUN_00586800 @ 00586800
// Size (bytes): 499


void __thiscall
FUN_00586800(int param_1,uint param_2,uint param_3,char param_4,uint param_5,uint param_6)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  int local_c;
  int local_8;
  uint local_4;
  
  uVar5 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + 2 + *(int *)(param_1 + 0x34) * 4);
  local_4 = 0;
  uVar4 = 0;
  if (uVar5 != 0) {
    do {
      local_4 = local_4 | 1 << ((byte)uVar4 & 0x1f);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar5);
  }
  uVar4 = 0;
  local_4 = local_4 & param_2;
  local_8 = (*(ushort *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x34) * 4) - 1) + uVar5;
  if (uVar5 != 0) {
    do {
      FUN_00585e80(local_8 - uVar4,&local_c,&param_2);
      if ((local_4 & 1 << ((byte)uVar4 & 0x1f)) == 0) {
        pbVar3 = (byte *)(local_c + *(int *)(param_1 + 0x14));
        bVar6 = *pbVar3 & ~(byte)param_2;
      }
      else {
        pbVar3 = (byte *)(*(int *)(param_1 + 0x14) + local_c);
        bVar6 = *pbVar3 | (byte)param_2;
      }
      uVar4 = uVar4 + 1;
      *pbVar3 = bVar6;
    } while (uVar4 < uVar5);
  }
  uVar5 = 0;
  uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + 2 + *(int *)(param_1 + 0x38) * 4);
  uVar4 = 0;
  if (uVar7 != 0) {
    do {
      uVar4 = uVar4 | 1 << ((byte)uVar5 & 0x1f);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar7);
  }
  uVar5 = 0;
  uVar4 = uVar4 & param_3;
  param_2 = (*(ushort *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x38) * 4) - 1) + uVar7;
  if (uVar7 != 0) {
    do {
      FUN_00586f70(param_2 - uVar5,(uVar4 & 1 << ((byte)uVar5 & 0x1f)) != 0);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar7);
  }
  uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + 2 + *(int *)(param_1 + 0x40) * 4);
  uVar4 = 0;
  uVar5 = 0;
  if (uVar7 != 0) {
    do {
      uVar4 = uVar4 | 1 << ((byte)uVar5 & 0x1f);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar7);
  }
  uVar5 = 0;
  uVar4 = uVar4 & param_5;
  param_2 = (*(ushort *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x40) * 4) - 1) + uVar7;
  if (uVar7 != 0) {
    do {
      FUN_00586f70(param_2 - uVar5,(uVar4 & 1 << ((byte)uVar5 & 0x1f)) != 0);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar7);
  }
  param_2 = param_6;
  iVar2 = *(int *)(param_1 + 0x44);
  FUN_00586f40(iVar2,&param_2);
  uVar4 = 0;
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x1c) + iVar2 * 4);
  uVar5 = (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + iVar2 * 4 + 2);
  if (uVar5 != 0) {
    do {
      FUN_00586f70(((uVar1 - 1) + uVar5) - uVar4,(1 << ((byte)uVar4 & 0x1f) & param_2) != 0);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar5);
  }
  FUN_00586fa0(*(undefined4 *)(param_1 + 0x3c),param_4 != '\0');
  return;
}


