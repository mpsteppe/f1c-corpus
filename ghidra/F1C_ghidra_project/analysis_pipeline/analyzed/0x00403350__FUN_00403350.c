// Function: FUN_00403350 @ 00403350
// Size (bytes): 378


void __fastcall FUN_00403350(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x150) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x150));
  }
  if (*(int *)(param_1 + 0x154) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x154));
  }
  if (*(int *)(param_1 + 0x158) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x158));
  }
  iVar1 = *(int *)(param_1 + 0x15c) + 1;
  iVar4 = *(int *)(param_1 + 0x160) + iVar1;
  *(int *)(param_1 + 0xc) = iVar1;
  *(int *)(param_1 + 0x10) = iVar4;
  *(undefined4 *)(param_1 + 8) = 1;
  *(int *)(param_1 + 0x14) = iVar4 + *(int *)(param_1 + 0x164);
  pvVar2 = operator_new(*(int *)(param_1 + 0x164) * 0x1c);
  *(void **)(param_1 + 0x154) = pvVar2;
  pvVar2 = operator_new(*(int *)(param_1 + 0x160) * 0x1c);
  *(void **)(param_1 + 0x150) = pvVar2;
  pvVar2 = operator_new(*(int *)(param_1 + 0x168) * *(int *)(param_1 + 0x164) * 0x1c);
  *(void **)(param_1 + 0x158) = pvVar2;
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x164)) {
    iVar4 = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x154) + iVar4);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0x164));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x160)) {
    iVar4 = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x150) + iVar4);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0x160));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x164)) {
    iVar4 = *(int *)(param_1 + 0x168);
    do {
      iVar5 = 0;
      if (0 < iVar4) {
        do {
          puVar3 = (undefined4 *)
                   ((*(int *)(param_1 + 0x164) * iVar5 + iVar1) * 0x1c + *(int *)(param_1 + 0x158));
          *puVar3 = 0;
          puVar3[1] = 0;
          puVar3[2] = 0;
          puVar3[3] = 0;
          puVar3[4] = 0;
          puVar3[5] = 0;
          puVar3[6] = 0;
          iVar4 = *(int *)(param_1 + 0x168);
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x164));
  }
  return;
}


