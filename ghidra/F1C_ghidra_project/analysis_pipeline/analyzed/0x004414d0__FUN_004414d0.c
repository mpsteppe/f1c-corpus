// Function: FUN_004414d0 @ 004414d0
// Size (bytes): 300


void __thiscall FUN_004414d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_14;
  int local_10;
  int local_c;
  
  *(undefined4 *)(param_1 + 0x1c64) = *(undefined4 *)(param_1 + 0x1c5c);
  *(undefined4 *)(param_1 + 0x1e40) = *(undefined4 *)(param_1 + 0x1e38);
  *(undefined4 *)(param_1 + 0x1e44) = *(undefined4 *)(param_1 + 0x1e3c);
  *(undefined4 *)(param_1 + 0x1c68) = *(undefined4 *)(param_1 + 0x1c60);
  puVar1 = (undefined4 *)(param_1 + 0x340);
  iVar3 = 4;
  do {
    *puVar1 = puVar1[-2];
    puVar1[1] = puVar1[-1];
    puVar1[4] = puVar1[2];
    puVar1[5] = puVar1[3];
    puVar5 = puVar1 + 0xc;
    puVar4 = puVar1 + 0x14;
    puVar1 = puVar1 + 0x119;
    iVar3 = iVar3 + -1;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar4 = puVar4 + 1;
    }
  } while (iVar3 != 0);
  local_c = *(int *)(param_1 + 0x15ac);
  if (0 < local_c) {
    local_10 = 0;
    local_14 = 0;
    do {
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0x162c) + local_10);
      iVar3 = *(int *)(param_1 + 0x15b0) + local_14;
      puVar1 = (undefined4 *)(iVar3 + 0x134);
      puVar5 = puVar4;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar1 = (undefined4 *)(iVar3 + 0x14c);
      puVar5 = puVar4 + 6;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar5 = puVar5 + 1;
      }
      local_14 = local_14 + 0x244;
      local_10 = local_10 + 0x30;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  FUN_0043f7f0(param_2,param_3);
  FUN_0056ecf0();
  FUN_0056ee40();
  FUN_0056f020(param_2,param_3);
  FUN_00441450();
  return;
}


