// Function: FUN_0049ec60 @ 0049ec60
// Size (bytes): 49


void __fastcall FUN_0049ec60(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005502c0();
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar1);
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


