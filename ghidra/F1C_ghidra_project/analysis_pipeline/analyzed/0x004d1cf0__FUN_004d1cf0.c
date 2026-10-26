// Function: FUN_004d1cf0 @ 004d1cf0
// Size (bytes): 70


undefined4 __fastcall FUN_004d1cf0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __ftol();
  iVar1 = iVar1 + -1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + *(int *)(param_1 + 0x10c);
  }
  iVar2 = *(int *)(param_1 + 0x10c) + -1;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (iVar2 < iVar1) {
    return *(undefined4 *)(*(int *)(param_1 + 0x110) + iVar2 * 8);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x110) + iVar1 * 8);
}


