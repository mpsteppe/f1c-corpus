// Function: FUN_00500f55 @ 00500f55
// Size (bytes): 89


void __fastcall FUN_00500f55(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x38) != 0)) {
    FUN_00587bcf(*(int *)(param_1 + 4));
  }
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0x3c) != 0)) {
    FUN_00587bcf(*(int *)(param_1 + 8));
  }
  iVar1 = *(int *)(param_1 + 0x4c);
  if (iVar1 != 0) {
    FUN_00500f55();
    FUN_00587bcf(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 0) {
    FUN_00500f55();
    FUN_00587bcf(iVar1);
  }
  return;
}


