// Function: FUN_004f8ae0 @ 004f8ae0
// Size (bytes): 27


int __fastcall FUN_004f8ae0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f8b50();
  *param_1 = iVar1;
  if (iVar1 == 0) {
    iVar1 = FUN_004f8c70();
    *param_1 = iVar1;
  }
  return *param_1;
}


