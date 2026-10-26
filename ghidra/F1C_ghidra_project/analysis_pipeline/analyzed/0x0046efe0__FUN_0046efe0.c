// Function: FUN_0046efe0 @ 0046efe0
// Size (bytes): 42


undefined4 __fastcall FUN_0046efe0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00432a60();
  if (*(int *)(param_1 + 0x174) != iVar1) {
    FUN_0046f170();
    *(int *)(param_1 + 0x174) = iVar1;
  }
  return 0;
}


