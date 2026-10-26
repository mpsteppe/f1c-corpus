// Function: FUN_00586fa0 @ 00586fa0
// Size (bytes): 143


undefined4 __thiscall FUN_00586fa0(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = (uint)*(ushort *)(param_1[2] + 2 + param_2 * 4);
  uVar4 = 0;
  uVar5 = 0;
  if (uVar7 != 0) {
    do {
      uVar4 = uVar4 | 1 << ((byte)uVar5 & 0x1f);
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar7);
  }
  uVar8 = 0;
  uVar5 = (uint)*(ushort *)(param_1[2] + param_2 * 4);
  iVar1 = uVar5 - 1;
  if (uVar7 != 0) {
    do {
      uVar6 = (iVar1 + uVar7) - uVar8;
      bVar3 = '\x01' << ((byte)uVar6 & 7);
      uVar6 = uVar6 >> 3;
      iVar2 = *param_1;
      if ((param_3 & uVar4 & 1 << ((byte)uVar8 & 0x1f)) == 0) {
        bVar3 = *(byte *)(iVar2 + uVar6) & ~bVar3;
      }
      else {
        bVar3 = *(byte *)(iVar2 + uVar6) | bVar3;
      }
      uVar5 = uVar5 & 0xffffff00;
      uVar8 = uVar8 + 1;
      *(byte *)(iVar2 + uVar6) = bVar3;
    } while (uVar8 < uVar7);
  }
  return CONCAT31((int3)(uVar5 >> 8),1);
}


