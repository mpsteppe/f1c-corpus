// Function: FUN_0058986e @ 0058986e
// Size (bytes): 42


undefined4 FUN_0058986e(LPCSTR param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = DeleteFileA(param_1);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = 0;
  }
  if (DVar2 != 0) {
    FUN_0058af5c(DVar2);
    return 0xffffffff;
  }
  return 0;
}


