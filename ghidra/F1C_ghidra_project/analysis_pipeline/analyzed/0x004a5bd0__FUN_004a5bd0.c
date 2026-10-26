// Function: FUN_004a5bd0 @ 004a5bd0
// Size (bytes): 61


void __fastcall FUN_004a5bd0(int param_1)

{
  int iVar1;
  
  iVar1 = __ftol();
  if (iVar1 < 0) {
    *(undefined4 *)(param_1 + 0x6c) = 0;
    return;
  }
  if (*(int *)(param_1 + 0x68) <= iVar1) {
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x68) + -1;
    return;
  }
  *(int *)(param_1 + 0x6c) = iVar1;
  return;
}


