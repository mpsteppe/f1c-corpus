// Function: FUN_004dd470 @ 004dd470
// Size (bytes): 74


void __fastcall FUN_004dd470(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 8));
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004dd4d0();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  return;
}


