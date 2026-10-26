// Function: FUN_004bd900 @ 004bd900
// Size (bytes): 105


void __thiscall FUN_004bd900(int param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  
  if (*(int *)(param_1 + 0x10) == *(int *)(param_1 + 0xc)) {
    iVar1 = *(int *)(param_1 + 0xc) + 8;
    *(int *)(param_1 + 0xc) = iVar1;
    pvVar2 = operator_new(iVar1 * 4);
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x10)) {
      do {
        *(undefined4 *)((int)pvVar2 + iVar1 * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar1 * 4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x10));
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      FUN_00587bcf(*(int *)(param_1 + 0x14));
    }
    *(void **)(param_1 + 0x14) = pvVar2;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x10) * 4) = param_2;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return;
}


