// Function: FUN_0040c8d0 @ 0040c8d0
// Size (bytes): 54


bool __fastcall FUN_0040c8d0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((iVar1 == 0) && (iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 0x34), iVar1 == 0)) {
    return (bool)3;
  }
  if (iVar1 == 1) {
    return true;
  }
  if (iVar1 != 2) {
    return false;
  }
  return DAT_007cfcc8 == 0;
}


