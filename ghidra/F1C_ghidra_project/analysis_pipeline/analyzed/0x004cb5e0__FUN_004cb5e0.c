// Function: FUN_004cb5e0 @ 004cb5e0
// Size (bytes): 53


void __fastcall FUN_004cb5e0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 100);
  while (0 < iVar1) {
    *(int *)(param_1 + 100) = iVar1 + -1;
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x68) + (iVar1 + -1) * 4);
    puVar2[1] = 0xffffffff;
    FUN_00558b30(*puVar2);
    iVar1 = *(int *)(param_1 + 100);
  }
  return;
}


