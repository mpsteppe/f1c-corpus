// Function: FUN_004cb5a0 @ 004cb5a0
// Size (bytes): 60


void __thiscall FUN_004cb5a0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 100) + -1;
  *(int *)(param_1 + 100) = iVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x68) + *(int *)(param_2 + 4) * 4) =
       *(undefined4 *)(*(int *)(param_1 + 0x68) + iVar1 * 4);
  *(int *)(*(int *)(*(int *)(param_1 + 0x68) + *(int *)(param_2 + 4) * 4) + 4) =
       *(int *)(param_2 + 4);
  *(undefined4 *)(param_2 + 4) = 0xffffffff;
  FUN_00558b30();
  return;
}


