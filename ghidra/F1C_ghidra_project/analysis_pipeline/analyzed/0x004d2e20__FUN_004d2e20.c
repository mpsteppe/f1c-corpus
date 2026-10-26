// Function: FUN_004d2e20 @ 004d2e20
// Size (bytes): 43


void __fastcall FUN_004d2e20(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xa4);
  if (iVar1 != 0) {
    FUN_004d0080();
    FUN_00587bcf(iVar1);
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  return;
}


