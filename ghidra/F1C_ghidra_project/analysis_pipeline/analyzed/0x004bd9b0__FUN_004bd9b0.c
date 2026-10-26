// Function: FUN_004bd9b0 @ 004bd9b0
// Size (bytes): 105


void __thiscall FUN_004bd9b0(int param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  
  if (*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x18)) {
    iVar1 = *(int *)(param_1 + 0x18) + 8;
    *(int *)(param_1 + 0x18) = iVar1;
    pvVar2 = operator_new(iVar1 * 4);
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x1c)) {
      do {
        *(undefined4 *)((int)pvVar2 + iVar1 * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x20) + iVar1 * 4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x1c));
    }
    if (*(int *)(param_1 + 0x20) != 0) {
      FUN_00587bcf(*(int *)(param_1 + 0x20));
    }
    *(void **)(param_1 + 0x20) = pvVar2;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x1c) * 4) = param_2;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return;
}


