// Function: FUN_0057d5d0 @ 0057d5d0
// Size (bytes): 133


undefined4 FUN_0057d5d0(uint param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = param_2;
  puVar4 = *(undefined4 **)(param_1 + 0x14);
  uVar3 = (uint)((*(uint *)(param_1 + 0x24) & 7) != 0) + (*(uint *)(param_1 + 0x24) >> 3);
  *(short *)param_2 = (short)uVar3;
  uVar1 = FUN_0053d880();
  *(undefined2 *)((int)puVar5 + 2) = uVar1;
  puVar5 = puVar5 + 1;
  puVar6 = puVar5;
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  FUN_00587580(&param_2,&param_1);
  puVar4 = (undefined4 *)((int)puVar5 + uVar3);
  for (uVar2 = param_1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
  }
  for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {
    *(undefined1 *)puVar4 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  return CONCAT31((int3)((uint)puVar5 >> 8),1);
}


