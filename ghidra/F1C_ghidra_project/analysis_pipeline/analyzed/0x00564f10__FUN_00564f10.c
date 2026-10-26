// Function: FUN_00564f10 @ 00564f10
// Size (bytes): 366


void __fastcall FUN_00564f10(int param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar5 = *(uint *)(param_1 + 0x4cc);
  iVar4 = *(int *)(param_1 + 0x4c0);
  uVar7 = *(uint *)(param_1 + 0x4c8);
  puVar1 = param_2 + param_3;
  uVar3 = *(uint *)(param_1 + 0x4c4);
  while (param_2 < puVar1) {
    if (uVar5 < 0x10000) {
      puVar6 = (uint *)(param_1 + 0x440 + iVar4 * 4);
      do {
        iVar2 = uVar3 + uVar5;
        puVar6[0x10] = uVar5;
        uVar7 = uVar7 + iVar2;
        uVar5 = uVar5 * 2;
        uVar3 = iVar2 + uVar7;
        *puVar6 = uVar7;
        puVar6[-0x10] = uVar3;
        iVar4 = iVar4 + 1;
        puVar6 = puVar6 + 1;
        uVar3 = uVar3 ^ *(uint *)(param_1 + (uVar3 & 0xff) * 4);
        uVar7 = (uVar7 * 0x1000000 | uVar7 >> 8) ^ *(uint *)(param_1 + (uVar7 >> 8 & 0xff) * 4);
        uVar8 = uVar7 >> 8;
        uVar9 = uVar3 >> 0x18;
        uVar3 = (uVar9 | uVar3 << 8) ^ *(uint *)(param_1 + uVar9 * 4);
        uVar7 = (uVar7 << 0x18 | uVar8) ^ *(uint *)(param_1 + (uVar8 & 0xff) * 4);
        uVar3 = uVar3 >> 0x18 | uVar3 << 8;
      } while (uVar5 < 0x10000);
    }
    *param_2 = uVar7 ^ uVar3;
    param_2 = param_2 + 1;
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    uVar5 = *(uint *)(param_1 + 0x440 + iVar4 * 4);
    uVar7 = ~*(uint *)(param_1 + 0x400 + iVar4 * 4);
    uVar3 = uVar7 >> 8;
    uVar7 = (uVar7 << 0x18 | uVar3) ^ *(uint *)(param_1 + (uVar3 & 0xff) * 4);
    uVar3 = uVar7 >> 8;
    uVar5 = uVar5 ^ *(uint *)(param_1 + (uVar5 & 0xff) * 4);
    uVar8 = uVar5 >> 0x18;
    uVar3 = (uVar7 << 0x18 | uVar3) ^ *(uint *)(param_1 + (uVar3 & 0xff) * 4);
    uVar5 = (uVar8 | uVar5 << 8) ^ *(uint *)(param_1 + uVar8 * 4);
    uVar7 = uVar5 >> 0x18 | uVar5 << 8;
    uVar5 = *(int *)(param_1 + 0x480 + iVar4 * 4) * 2 + 1;
  }
  *(uint *)(param_1 + 0x4c8) = uVar7;
  *(uint *)(param_1 + 0x4cc) = uVar5;
  *(int *)(param_1 + 0x4c0) = iVar4;
  *(uint *)(param_1 + 0x4c4) = uVar3;
  return;
}


