// Function: FUN_005502c0 @ 005502c0
// Size (bytes): 55


undefined4 __fastcall FUN_005502c0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_00542e50();
    iVar1 = *(int *)(param_1 + 0x54);
    if (iVar1 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar1);
    }
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  *(undefined1 *)(param_1 + 4) = 0;
  return 0;
}


