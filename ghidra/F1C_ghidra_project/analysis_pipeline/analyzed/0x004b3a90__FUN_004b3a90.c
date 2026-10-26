// Function: FUN_004b3a90 @ 004b3a90
// Size (bytes): 63


void __thiscall FUN_004b3a90(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  
  uVar1 = (*param_2 >> 8 & 0x3ff) + 8;
  if (uVar1 != 0) {
    puVar3 = param_2;
    puVar4 = param_1;
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(char *)puVar4 = (char)*puVar3;
      puVar3 = (uint *)((int)puVar3 + 1);
      puVar4 = (uint *)((int)puVar4 + 1);
    }
  }
  param_1[0x6b] = param_2[0x6b];
  return;
}


