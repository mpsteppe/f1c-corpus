// Function: FUN_00585f60 @ 00585f60
// Size (bytes): 40


int __fastcall FUN_00585f60(int param_1)

{
  DWORD DVar1;
  
  if (*(HANDLE *)(param_1 + 0x50) != (HANDLE)0x0) {
    DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x50),*(DWORD *)(param_1 + 0x54));
    if ((DVar1 == 0) || (DVar1 == 0x80)) {
      return param_1;
    }
  }
  return 0;
}


