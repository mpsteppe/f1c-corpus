// Function: FUN_00587730 @ 00587730
// Size (bytes): 323


void __thiscall FUN_00587730(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined1 local_8;
  
  uVar1 = FUN_00586a80();
  if (0xff < (int)uVar1) {
    FUN_00585380(param_2);
    return;
  }
  puVar3 = *(undefined4 **)(param_2 + 0x14);
  bVar5 = ((*(uint *)(param_2 + 0x24) & 7) != 0) + (char)(*(uint *)(param_2 + 0x24) >> 3);
  uVar8 = uVar1 & 0xff;
  iVar6 = *(int *)(*(int *)(param_1 + 0x414) + 0x80);
  iVar2 = FUN_00587880();
  if (iVar6 <= (int)(iVar2 + uVar8 + (uint)bVar5)) {
    FUN_005878a0(0);
  }
  *(byte *)(*(int *)(param_1 + 0x400) + param_1) = bVar5;
  iVar6 = *(int *)(param_1 + 0x400) + 1;
  *(int *)(param_1 + 0x400) = iVar6;
  puVar9 = (undefined4 *)(iVar6 + param_1);
  for (uVar7 = (uint)(bVar5 >> 2); uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar9 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar9 = puVar9 + 1;
  }
  for (uVar7 = bVar5 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  local_8 = (undefined1)uVar1;
  iVar6 = *(int *)(param_1 + 0x400) + (uint)bVar5;
  *(int *)(param_1 + 0x400) = iVar6;
  *(undefined1 *)(iVar6 + param_1) = local_8;
  *(int *)(param_1 + 0x400) = *(int *)(param_1 + 0x400) + 1;
  puVar3 = (undefined4 *)FUN_00586a90();
  puVar9 = (undefined4 *)(*(int *)(param_1 + 0x400) + param_1);
  for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar9 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar9 = puVar9 + 1;
  }
  for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  *(uint *)(param_1 + 0x400) = *(int *)(param_1 + 0x400) + uVar8;
  if (*(int *)(param_1 + 0x408) == 0) {
    uVar4 = FUN_00586de0();
    *(undefined4 *)(param_1 + 0x40c) = uVar4;
  }
  *(int *)(param_1 + 0x408) = *(int *)(param_1 + 0x408) + 1;
  return;
}


