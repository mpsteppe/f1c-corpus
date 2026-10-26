// Function: FUN_005572b0 @ 005572b0
// Size (bytes): 149


void __fastcall FUN_005572b0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1b4);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x208);
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0x84;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = *(int *)(param_1 + 0x1c4);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x208);
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0x84;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = *(int *)(param_1 + 0x1bc);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x1c0) + 0x208);
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0x84;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = *(int *)(param_1 + 0x1cc);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x1d0) + 0x208);
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0x84;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


