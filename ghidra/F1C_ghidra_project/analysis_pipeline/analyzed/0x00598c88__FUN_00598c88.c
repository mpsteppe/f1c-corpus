// Function: FUN_00598c88 @ 00598c88
// Size (bytes): 57


uint __fastcall FUN_00598c88(uint param_1)

{
  int iVar1;
  
  FUN_0059a54d();
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) && (iVar1 != -1)) {
    *(int *)(param_1 + 4) = iVar1 + -1;
  }
  iVar1 = *(int *)(param_1 + 4);
  FUN_0059a5e9();
  return ~-(uint)(iVar1 != 0) & param_1;
}


