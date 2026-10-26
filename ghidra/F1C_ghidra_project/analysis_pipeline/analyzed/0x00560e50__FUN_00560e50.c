// Function: FUN_00560e50 @ 00560e50
// Size (bytes): 88


void __fastcall FUN_00560e50(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_004b0170();
    iVar1 = *(int *)(param_1 + 0xc);
    if (iVar1 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar1);
    }
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 != 0) {
    FUN_00557470();
    FUN_00587bcf(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 != 0) {
    FUN_00560b90();
    FUN_00587bcf(iVar1);
  }
  return;
}


