// Function: FUN_00541040 @ 00541040
// Size (bytes): 77


void __thiscall FUN_00541040(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 != 0) && (*(int *)(param_2 + 0x18) != 0)) {
    iVar1 = *(int *)(param_2 + 0xc);
    while (0 < iVar1) {
      FUN_005410f0(param_2);
      iVar1 = *(int *)(param_2 + 0xc);
    }
    *(undefined4 *)(param_2 + 0xc) = 0;
    uVar2 = (**(code **)(**(int **)(param_2 + 0x18) + 8))(*(int **)(param_2 + 0x18));
    *param_1 = uVar2;
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  return;
}


