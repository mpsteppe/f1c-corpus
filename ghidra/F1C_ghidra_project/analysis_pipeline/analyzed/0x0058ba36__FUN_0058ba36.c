// Function: FUN_0058ba36 @ 0058ba36
// Size (bytes): 63


undefined4 FUN_0058ba36(LPCSTR param_1,byte param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 != 0xffffffff) {
    if ((param_2 & 0x80) == 0) {
      DVar1 = DVar1 | 1;
    }
    else {
      DVar1 = DVar1 & 0xfffffffe;
    }
    BVar2 = SetFileAttributesA(param_1,DVar1);
    if (BVar2 != 0) {
      return 0;
    }
  }
  DVar1 = GetLastError();
  FUN_0058af5c(DVar1);
  return 0xffffffff;
}


