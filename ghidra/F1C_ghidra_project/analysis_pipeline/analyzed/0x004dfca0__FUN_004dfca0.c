// Function: FUN_004dfca0 @ 004dfca0
// Size (bytes): 53


void __fastcall FUN_004dfca0(int param_1)

{
  int iVar1;
  
  iVar1 = 0xb;
  do {
    FUN_004ded20();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (*(int *)(param_1 + 0x90) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x90));
  }
  return;
}


