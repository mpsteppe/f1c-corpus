// Function: FUN_0040aa20 @ 0040aa20
// Size (bytes): 474


void __fastcall FUN_0040aa20(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    pvVar1 = operator_new(200);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00456170();
    }
    *(int *)(param_1 + 0x10) = iVar2;
    *(undefined4 *)(iVar2 + 0x88) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x8c) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x90) = 0x43b40000;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    pvVar1 = operator_new(200);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00456170();
    }
    *(int *)(param_1 + 0x14) = iVar2;
    *(undefined4 *)(iVar2 + 0x88) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x8c) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x90) = 0x43b40000;
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    pvVar1 = operator_new(200);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00456170();
    }
    *(int *)(param_1 + 0x18) = iVar2;
    *(undefined4 *)(iVar2 + 0x88) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x8c) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x90) = 0x43b40000;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    pvVar1 = operator_new(200);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00456170();
    }
    *(int *)(param_1 + 0x1c) = iVar2;
    *(undefined4 *)(iVar2 + 0x88) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x8c) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x90) = 0x43b40000;
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    puVar3 = operator_new(0xcc);
    if (puVar3 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = puVar3 + 1;
      *puVar3 = 1;
      FUN_00456170();
    }
    *(undefined4 **)(param_1 + 0x20) = puVar4;
    FUN_00566650(&DAT_005ea438);
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    puVar4[8] = 0;
    puVar4[9] = 0;
    puVar4[10] = 0;
    puVar4[0xb] = 0;
    puVar4[0xe] = 0x42700000;
    puVar4[0xc] = 0x42700000;
    puVar4[0xf] = 0x42340000;
    puVar4[0xd] = 0x42340000;
    puVar4[0x10] = 0x3f000000;
    puVar4[0x11] = 0x43fa0000;
    puVar4[0x12] = 0x3f800000;
    puVar4[0x14] = 0x3f800000;
    puVar4[0x13] = 0x3f800000;
    puVar4[0x16] = 0x3f000000;
    puVar4[0x15] = 0x3f000000;
    puVar4[0x17] = 0;
    puVar4[0x1b] = 0;
    puVar4[0x1a] = 0;
    puVar4[0x19] = 0;
    puVar4[0x1e] = 0;
    puVar4[0x1d] = 0;
    puVar4[0x1c] = 0;
    *(undefined1 *)(puVar4 + 0x18) = 0;
    (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))();
    iVar2 = *(int *)(param_1 + 0x20);
    *(undefined4 *)(iVar2 + 0x88) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x8c) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x90) = 0x43b40000;
  }
  return;
}


