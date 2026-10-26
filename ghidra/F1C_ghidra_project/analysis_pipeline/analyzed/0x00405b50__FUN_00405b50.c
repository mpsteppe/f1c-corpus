// Function: FUN_00405b50 @ 00405b50
// Size (bytes): 54


bool __fastcall FUN_00405b50(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    iVar1 = _AIL_sample_status_4(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x10));
    if ((iVar1 == 4) || (iVar1 == 0x10)) {
      return *(int *)(param_1 + 0x14) != 0;
    }
  }
  return (bool)2;
}


