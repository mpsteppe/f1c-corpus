// Function: FUN_0049ecc0 @ 0049ecc0
// Size (bytes): 49


void __fastcall FUN_0049ecc0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005502c0();
    iVar1 = *(int *)(param_1 + 0xc);
    if (iVar1 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


