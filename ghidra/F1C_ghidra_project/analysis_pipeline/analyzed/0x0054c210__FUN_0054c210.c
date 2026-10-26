// Function: FUN_0054c210 @ 0054c210
// Size (bytes): 25


int __fastcall FUN_0054c210(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


