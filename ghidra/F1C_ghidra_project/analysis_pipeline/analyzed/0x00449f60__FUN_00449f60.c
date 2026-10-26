// Function: FUN_00449f60 @ 00449f60
// Size (bytes): 260


undefined4 FUN_00449f60(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  uint *puVar8;
  uint local_298 [9];
  undefined2 local_272;
  uint local_26c [7];
  uint local_250;
  undefined2 local_24c;
  
  iVar4 = FUN_00566c00(local_26c,0x22);
  puVar7 = &stack0xfffffd58;
  if (iVar4 == 0x22) {
    FUN_00448e90();
    iVar4 = 0;
    do {
      puVar7 = puVar7 + 0x60;
      local_298[iVar4 + 3] = (uint)puVar7;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
    local_272 = local_24c;
    iVar4 = 0;
    puVar8 = local_298 + 4;
    do {
      uVar1 = *puVar8;
      *(uint *)(uVar1 + 0x10) = local_26c[iVar4 * 2];
      iVar3 = iVar4 * 2;
      iVar4 = iVar4 + 1;
      puVar8 = puVar8 + 2;
      *(uint *)(uVar1 + 0x14) = local_26c[iVar3 + 1];
    } while (iVar4 < 3);
    local_298[0] = local_26c[6] & 0x1fffff;
    local_298[1] = (local_250 & 0x3ff) * 0x800 + (local_26c[6] >> 0x15);
    local_298[2] = local_250 >> 10;
    iVar4 = 0;
    while( true ) {
      uVar1 = local_298[iVar4];
      puVar2 = (undefined4 *)local_298[iVar4 * 2 + 3];
      if (((int)uVar1 < 0) || (*(int *)(param_1 + 0x34) <= (int)uVar1)) break;
      puVar5 = (undefined4 *)(uVar1 * 0x10 + *(int *)(param_1 + 0x38));
      *puVar2 = *puVar5;
      puVar2[4] = puVar5[1];
      puVar2[5] = puVar5[2];
      iVar4 = iVar4 + 1;
      puVar2[3] = puVar5[3];
      if (2 < iVar4) {
        uVar6 = FUN_00449a80(local_298 + 3,1);
        return uVar6;
      }
    }
  }
  return 0xffffffff;
}


