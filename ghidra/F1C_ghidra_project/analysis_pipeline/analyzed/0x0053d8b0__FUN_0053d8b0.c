// Function: FUN_0053d8b0 @ 0053d8b0
// Size (bytes): 45


void __thiscall FUN_0053d8b0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_1 + 8) < 4) {
    puVar2 = (undefined4 *)(*(int *)(param_1 + 8) * 0x43c + 0xc + param_1);
    for (iVar1 = 0x10f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  return;
}


