// Function: FUN_0041f100 @ 0041f100
// Size (bytes): 71


undefined4 __fastcall FUN_0041f100(int param_1)

{
  int iVar1;
  
  FUN_004c2850();
  iVar1 = FUN_004c11d0();
  if ((((param_1 != 0) && (2 < iVar1)) && (*(int *)(param_1 + 0xd8 + iVar1 * 4) == 10)) &&
     ((*(int *)(param_1 + 0xd4 + iVar1 * 4) == 10 && (*(int *)(param_1 + 0xd0 + iVar1 * 4) == 10))))
  {
    return 1;
  }
  return 0;
}


