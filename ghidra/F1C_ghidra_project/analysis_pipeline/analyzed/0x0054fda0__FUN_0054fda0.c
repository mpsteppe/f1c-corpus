// Function: FUN_0054fda0 @ 0054fda0
// Size (bytes): 77


void __thiscall FUN_0054fda0(int param_1,int param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x4c));
  }
  pvVar1 = operator_new(param_3 * 4);
  *(void **)(param_1 + 0x4c) = pvVar1;
  iVar2 = 0;
  if (0 < param_3) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x4c) + iVar2 * 4) = *(undefined4 *)(param_2 + iVar2 * 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  *(int *)(param_1 + 0x50) = param_3;
  return;
}


