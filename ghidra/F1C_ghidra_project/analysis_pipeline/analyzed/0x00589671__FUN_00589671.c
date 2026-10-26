// Function: FUN_00589671 @ 00589671
// Size (bytes): 44


undefined4 FUN_00589671(LPCSTR param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = CreateDirectoryA(param_1,(LPSECURITY_ATTRIBUTES)0x0);
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


