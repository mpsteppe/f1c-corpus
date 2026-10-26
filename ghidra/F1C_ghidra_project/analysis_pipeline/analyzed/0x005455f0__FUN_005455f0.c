// Function: FUN_005455f0 @ 005455f0
// Size (bytes): 116


void __thiscall FUN_005455f0(int param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  uVar1 = *param_2 & 7;
  if (uVar1 == 1) {
    puVar2 = (uint *)(param_1 + 0x11c);
    puVar3 = (uint *)(param_1 + 0x120);
  }
  else if (uVar1 == 2) {
    puVar2 = (uint *)(param_1 + 300);
    puVar3 = (uint *)(param_1 + 0x130);
  }
  else {
    puVar2 = param_2;
    puVar3 = param_2;
    if (uVar1 == 4) {
      puVar2 = (uint *)(param_1 + 0x124);
      puVar3 = (uint *)(param_1 + 0x128);
    }
  }
  if (param_2[0x1a] != 0) {
    *(uint *)(param_2[0x1a] + 0x6c) = param_2[0x1b];
  }
  if (param_2[0x1b] != 0) {
    *(uint *)(param_2[0x1b] + 0x68) = param_2[0x1a];
  }
  if ((uint *)*puVar3 == param_2) {
    *puVar3 = param_2[0x1b];
  }
  *puVar2 = *puVar2 - 1;
  return;
}


