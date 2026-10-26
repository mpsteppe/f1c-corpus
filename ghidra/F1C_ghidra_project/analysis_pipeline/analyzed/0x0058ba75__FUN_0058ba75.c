// Function: FUN_0058ba75 @ 0058ba75
// Size (bytes): 70


undefined4 FUN_0058ba75(LPCSTR param_1,byte param_2)

{
  DWORD DVar1;
  undefined4 *puVar2;
  
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    FUN_0058af5c(DVar1);
  }
  else {
    if (((DVar1 & 1) == 0) || ((param_2 & 2) == 0)) {
      return 0;
    }
    puVar2 = (undefined4 *)FUN_0058afcf();
    *puVar2 = 0xd;
    puVar2 = (undefined4 *)FUN_0058afd8();
    *puVar2 = 5;
  }
  return 0xffffffff;
}


